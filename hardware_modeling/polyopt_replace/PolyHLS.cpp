/*
 * PolyHLS.cpp: This file is part of the PolyOpt project.
 *
 * PolyOpt: a Polyhedral Optimizer for the ROSE compiler
 *
 * Copyright (C) 2011 the Ohio State University
 *
 * This program can be redistributed and/or modified under the terms
 * of the license specified in the LICENSE.txt file at the root of the
 * project.
 *
 * Contact: P. Sadayappan <saday@cse.ohio-state.edu>
 *
 */
/**
 * @file: PolyHLS.cpp
 * @author: Louis-Noel Pouchet <pouchet@cse.ohio-state.edu>
 */


#include <getopt.h>
#include <string.h>
#include <stdio.h>

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

// LNP: To avoid redefined macro errors in pocc.
/// LNP: FIXME: Find a better solution!
#undef PACKAGE_BUGREPORT
#undef PACKAGE_STRING
#undef PACKAGE_TARNAME
#undef PACKAGE_NAME
#undef PACKAGE_VERSION
#include <polyopt/helper.hpp>
#include <rose.h>
#include <Cxx_Grammar.h>
#include <AstTraversal.h>

#ifndef SCOPLIB_INT_T_IS_LONGLONG
# define SCOPLIB_INT_T_IS_LONGLONG
#endif
#include <scoplib/scop.h>
#ifndef CLOOG_INT_GMP
# define CLOOG_INT_GMP
#endif
#include <cloog/cloog.h>
#ifndef LINEAR_VALUE_IS_LONGLONG
# define LINEAR_VALUE_IS_LONGLONG
#endif
#include <candl/candl.h>
#include <pocc/options.h>
#include <pocc/exec.h>
#include <pocc-utils/options.h>

#include <past/past.h>

#include <polyopt/PolyOpt.hpp>

#include <polyopt/ScopExtractor.hpp>
#include <polyopt/ClastToSage.hpp>
#include <polyopt/PastToSage.hpp>
#include <polyopt/PoCCOptimize.hpp>
#include <polyopt/PolyRoseOptions.hpp>
#include <polyopt/SageNodeAnnotation.hpp>
#include <polyopt/SageTools.hpp>



#include <hlsir/hlsir.h>
#include <pocc/driver-hlsir.h>
#include <past/pprint.h>

#include <lmp/lmp_driver.h>
#include <lmp/options.h>

// #include <issres/issres_driver.h>
// #include <issres/options.h>


#include <Outliner.hh>
#include <pre.h>

int counter = 0;
std::string proto = "__tmp_scal__";

/**
 * Perform AST simplifications on all inner loops of the tree 'root'.
 *
 * lbhoist: true => simplify loop bounds, hoisting them outside the inner loop
 *
 * refhoist: true => hoist array references that are loop-invariant outside the loop.
 *
 * refgvn: true => perform basic GVN on array references, to limit the
 * number of load/stores to the same array cell.
 *
 * modsimpl: true => replace modulo expressions (eg, "i % 8") by an
 * addition+offset, which is tested/reset at each loop iteration.
 *
 * NOTE: some comments/code may be outdated.
 */
void ASTSimplifications(SgNode* root, bool lbhoist, bool refhoist,
			bool refgvn, bool modsimpl)
{
  // (1) Collect all inner-most loops.
  // (2) For each loops, collect all array references.
  // (3) For all ref, create a map of unique expressions
  // (4) For each unique expr,
  // 4.a if loop iv not in expr, hoist the expr to outside the loop, replace
  //     by var
  // 4.b else, hoist outside, replace by var+iv
  // (5) Replace all occurences of loop iv by loop iv + start
  // (6) Change the loop bounds to 0, ub - start


  /// Impl:
  int debug = 0;
  int vc = 0;
  int vc2 = 0;
  int vc3 = 0;
  int vc4 = 0;
  std::string proto("__local__af_");
  std::string protolb("__local__loop_lb_");
  std::string protoub("__local__loop_ub_");
  std::string protocomp("__local__val_");

   // Collect all inner loops.
  std::vector<SgNode*> forLoops =
    NodeQuery::querySubTree(root, V_SgForStatement);
  std::vector<SgForStatement*> inForLoops;
  for (std::vector<SgNode*>::iterator i = forLoops.begin(); i != forLoops.end();
       ++i)
    {
      SgForStatement* f = isSgForStatement(*i);
      ROSE_ASSERT(f);
        std::vector<SgNode*> hasIn =
	  NodeQuery::querySubTree(f->get_loop_body(), V_SgForStatement);
	if (hasIn.size() == 0)
	  inForLoops.push_back(f);
    }

  // For each loop,
  for (std::vector<SgForStatement*>::iterator i = inForLoops.begin();
       i != inForLoops.end(); ++i)
    {
      if (debug > 2)
	{
	  std::cout << "Loop to be optimized:" << std::endl;
	  std::cout << (*i)->unparseToCompleteString() << std::endl;
	}

      SgScopeStatement* local_scope =
	isSgScopeStatement((*i)->get_parent());
      SgForStatement* forLoop = isSgForStatement(*i);
      SgVariableSymbol* loop_iterator_sym =
	SageTools::getLoopIteratorSymbol(*i);

      /// LNP: FIXME: encode that loops are either with ++ or += 2 increment.
      int inc_val = 1;
      if (isSgPlusPlusOp(forLoop->get_increment()) == NULL)
	{
	  SgPlusAssignOp* sop = isSgPlusAssignOp(forLoop->get_increment());
	  if (sop && isSgIntVal(sop->get_rhs_operand()))
	    inc_val = SageTools::getIntegerTypeValue(sop->get_rhs_operand());
	  else
	    {
	      std::cout << "[PolyHLS][ERROR] Loop does not have constant integer stride"
			<< std::endl;
	      ROSE_ASSERT(0);
	    }
	}


      /// (1) Massage the loop bounds.
      if (lbhoist)
	{
	  // Hoist the loop lower bound.
	  SgForInitStatement* lb = forLoop->get_for_init_stmt();
	  SgStatementPtrList initList = lb->get_init_stmt();
	  SgStatement* init = *(initList.begin());
	  SgExprStatement* einit = isSgExprStatement(init);
	  ROSE_ASSERT(einit);
	  SgExpression* initass = einit->get_expression();
	  SgAssignOp* aop = isSgAssignOp(initass);
	  ROSE_ASSERT(aop);

	  std::ostringstream oss;
	  oss << vc2++;
	  std::string newit(protolb);
	  newit += oss.str();
	  SgVariableDeclaration* decllb =
	    SageBuilder::buildVariableDeclaration
	    (newit, SageBuilder::buildIntType(), NULL, local_scope);
	  SgStatement* stm = SageBuilder::buildExprStatement
	    (SageBuilder::buildBinaryExpression<SgAssignOp>
	     (SageBuilder::buildVarRefExp
	      (SageInterface::getFirstVarSym(decllb)),
	      isSgExpression(SageInterface::deepCopy(aop->get_rhs_operand()))));
	  SageInterface::insertStatementBefore(*i, decllb);
	  SageInterface::insertStatementBefore(*i, stm);
	  SgStatement* stmlb = SageBuilder::buildExprStatement
	    (SageBuilder::buildBinaryExpression<SgAssignOp>
	     (SageBuilder::buildVarRefExp(loop_iterator_sym),
	      SageBuilder::buildVarRefExp(SageInterface::getFirstVarSym(decllb))));
	  SageInterface::insertStatementBefore(*i, stmlb);
	  // Replace the lb by 0.
	  SageInterface::replaceExpression(aop->get_rhs_operand(),
					   SageBuilder::buildIntVal(0));


	  // Hoist the loop ub.
	  SgExprStatement* test = isSgExprStatement(forLoop->get_test());
	  ROSE_ASSERT(test);
	  SgLessOrEqualOp* lop = isSgLessOrEqualOp(test->get_expression());
	  if (lop)
	    {
	      std::ostringstream oss;
	      oss << vc3++;
	      std::string newit(protoub);
	      newit += oss.str();
	      SgVariableDeclaration* declub =
		SageBuilder::buildVariableDeclaration
		(newit, SageBuilder::buildIntType(), NULL, local_scope);
	      SgVarRefExp* vref = isSgVarRefExp(lop->get_lhs_operand());
	      ROSE_ASSERT(vref);
	      SgExpression* test = isSgExpression(lop->get_rhs_operand());
	      ROSE_ASSERT(test);
	      // replace the ub by ub-lb
	      SgStatement* stm = SageBuilder::buildExprStatement
		(SageBuilder::buildBinaryExpression<SgAssignOp>
		 (SageBuilder::buildVarRefExp
		  (SageInterface::getFirstVarSym(declub)),
		  SageBuilder::buildBinaryExpression<SgSubtractOp>
		  (SageInterface::deepCopy(test),
		   SageBuilder::buildVarRefExp
		   (SageInterface::getFirstVarSym(decllb)))));
	      SageInterface::insertStatementBefore(forLoop, declub);
	      SageInterface::insertStatementBefore(forLoop, stm);
	      SageInterface::replaceExpression
		(test, SageBuilder::buildVarRefExp
		 (SageInterface::getFirstVarSym(declub)), true);
	    }
	  if (debug > 2)
	    {
	      std::cout << "After loop bound hoisting:" << std::endl;
	      std::cout << (*i)->get_parent()->unparseToCompleteString() << std::endl;
	    }
	  /// (2) Replace all references to the loop iterator
	  std::vector<SgNode*> varrefs =
	    NodeQuery::querySubTree(forLoop->get_loop_body(), V_SgVarRefExp);
	  for (std::vector<SgNode*>::iterator j = varrefs.begin();
	       j != varrefs.end(); ++j)
	    {
	      SgVarRefExp* vref = isSgVarRefExp(*j);
	      if (vref == NULL)
		continue;
	      if (vref->get_symbol() != loop_iterator_sym)
		continue;
	      // replace it by it+lb for iterator ref. not in array ref.
	      SgNode* arr = SageInterface::getEnclosingNode<SgPntrArrRefExp>(*j);
	      /// FIXME: LNP: replace everywhere instead?
	      if (arr == NULL || 1)
		{
		  SageInterface::replaceExpression
		    (vref,
		     SageBuilder::buildBinaryExpression<SgAddOp>
		     (SageBuilder::buildVarRefExp(vref->get_symbol()),
		      SageBuilder::buildVarRefExp
		      (SageInterface::getFirstVarSym(decllb))), true);
		}
	    }
	  if (debug > 2)
	    {
	      std::cout << "After iterator update:" << std::endl;
	      std::cout << (*i)->get_parent()->unparseToCompleteString() << std::endl;
	    }
	}

      // (3) Hoist memory read/writes that are loop-invariant outside the loop.
      if (refhoist)
	{
	  // collect all array refs exprs.
	  std::vector<SgNode*> arefs =
	    NodeQuery::querySubTree(*i, V_SgPntrArrRefExp);
	  // Collect all r/w refs.
	  std::vector<SgNode*> readRefs;
	  std::vector<SgNode*> writeRefs;
	  SageTools::collectReadWriteRefs(forLoop, readRefs, writeRefs, true);
	  std::map<SgNode*,SgNode*> repls;
	  std::vector<SgNode*> readRepl;
	  std::vector<SgNode*> writeRepl;
	  for (std::vector<SgNode*>::iterator l = arefs.begin(); l != arefs.end(); ++l)
	    {
	      // Skip non-top array references (eg, skip C[i] in C[i][j]).
	      if (isSgPntrArrRefExp((*l)->get_parent()))
		continue;
	      std::vector<SgNode*> s =
		NodeQuery::querySubTree(*l, V_SgVarRefExp);
	      std::vector<SgNode*>::iterator ls;
	      for (ls = s.begin(); ls != s.end(); ++ls)
		{
		  SgVariableSymbol* v = isSgVarRefExp(*ls)->get_symbol();
		  if (v->get_name().getString() == loop_iterator_sym->get_name().getString())
		    break;
		}
	      if (ls != s.end())
		continue;
	      std::map<SgNode*,SgNode*>::iterator mit;
	      SgNode* replExpr = NULL;
	      for (mit = repls.begin(); mit != repls.end(); ++mit)
		{
		  if (SageTools::checkTreeAreEquivalent(mit->first, *l))
		    {
		      replExpr = mit->second;
		      break;
		    }
		}
	      if (replExpr == NULL)
		{
		  std::ostringstream oss;
		  oss << vc4++;
		  std::string newtmp(protocomp);
		  newtmp += oss.str();
		  SgType* type = isSgPntrArrRefExp(*l)->get_type();
		  if (isSgArrayType(type))
		    type = isSgArrayType(type)->get_base_type();
		  SgVariableDeclaration* decllb =
		    SageBuilder::buildVariableDeclaration
		    (newtmp, SageInterface::deepCopy(type), NULL,  local_scope);
		  SageInterface::insertStatementBefore(*i, decllb);
		  replExpr =
		    SageBuilder::buildVarRefExp(SageInterface::getFirstVarSym(decllb));
		  repls.insert(std::pair<SgNode*,SgNode*>(*l, replExpr));
		}
	      SgStatement* stm;
	      if (std::find(readRefs.begin(), readRefs.end(), *l) != readRefs.end() &&
		  std::find(readRepl.begin(), readRepl.end(), replExpr) == readRepl.end())
		{
		  stm = SageBuilder::buildExprStatement
		    (SageBuilder::buildBinaryExpression<SgAssignOp>
		     (isSgExpression(SageInterface::deepCopy(replExpr)),
		      isSgExpression(SageInterface::deepCopy(*l))));
		  SageInterface::insertStatementBefore(*i, stm);
		  readRepl.push_back(replExpr);
		}
	      if (std::find(writeRefs.begin(), writeRefs.end(), *l) != writeRefs.end() &&
		  std::find(writeRepl.begin(), writeRepl.end(), replExpr) == writeRepl.end())
		{
		  stm = SageBuilder::buildExprStatement
		    (SageBuilder::buildBinaryExpression<SgAssignOp>
		     (isSgExpression(SageInterface::deepCopy(*l)),
		      isSgExpression(SageInterface::deepCopy(replExpr))));
		  SageInterface::insertStatementAfter(*i, stm);
		  writeRepl.push_back(replExpr);
		}
	      SageInterface::replaceExpression(isSgExpression(*l),
					       isSgExpression(SageInterface::deepCopy(replExpr)),
					       true);
	    }
	  if (debug > 2)
	    {
	      std::cout << "After reference hoisting:" << std::endl;
	      std::cout << (*i)->get_parent()->unparseToCompleteString() << std::endl;
	    }
	}

      // (4) Do mini-GVN on array references.
      if (refgvn)
	{
	  // collect all array refs exprs.
	  std::vector<SgNode*> arefs =
	    NodeQuery::querySubTree(*i, V_SgPntrArrRefExp);
	  // Collect all r/w refs.
	  std::vector<SgNode*> readRefs;
	  std::vector<SgNode*> writeRefs;
	  SageTools::collectReadWriteRefs(forLoop, readRefs, writeRefs, true);
	  std::map<SgNode*,SgNode*> repls;
	  std::vector<SgNode*> readRepl;
	  std::vector<SgNode*> writeRepl;
	  std::vector<SgNode*> declsToInsert;
	  for (std::vector<SgNode*>::iterator l = arefs.begin(); l != arefs.end(); ++l)
	    {
	      // Skip non-top array references (eg, skip C[i] in C[i][j]).
	      if (isSgPntrArrRefExp((*l)->get_parent()))
		continue;
	      if (debug > 3)
		std::cout << "Considered ref: " << (*l)->unparseToCompleteString() << std::endl;

	      std::vector<SgNode*> s =
		NodeQuery::querySubTree(*l, V_SgVarRefExp);
	      std::vector<SgNode*>::iterator ls;
	      // for (ls = s.begin(); ls != s.end(); ++ls)
	      // 	{
	      // 	  SgVariableSymbol* v = isSgVarRefExp(*ls)->get_symbol();
	      // 	  if (v->get_name().getString() == loop_iterator_sym->get_name().getString())
	      // 	    break;
	      // 	}
	      // if (ls != s.end())
	      // 	continue;
	      std::map<SgNode*,SgNode*>::iterator mit;
	      SgNode* replExpr = NULL;
	      for (mit = repls.begin(); mit != repls.end(); ++mit)
		{
		  if (SageTools::checkTreeAreEquivalent(mit->first, *l))
		    {
		      replExpr = mit->second;
		      break;
		    }
		}
	      if (replExpr == NULL)
		{
		  std::ostringstream oss;
		  oss << vc4++;
		  std::string newtmp(protocomp);
		  newtmp += oss.str();
		  SgType* type = isSgPntrArrRefExp(*l)->get_type();
		  if (isSgArrayType(type))
		    type = isSgArrayType(type)->get_base_type();
		  SgVariableDeclaration* decllb =
		    SageBuilder::buildVariableDeclaration
		    (newtmp, SageInterface::deepCopy(type), NULL,  local_scope);
		  declsToInsert.push_back(decllb);
		  replExpr =
		    SageBuilder::buildVarRefExp(SageInterface::getFirstVarSym(decllb));
		  repls.insert(std::pair<SgNode*,SgNode*>(*l, replExpr));
		}
	      SgStatement* stm;
	      if (std::find(readRefs.begin(), readRefs.end(), *l) != readRefs.end() &&
		  std::find(readRepl.begin(), readRepl.end(), replExpr) == readRepl.end())
		{
		  stm = SageBuilder::buildExprStatement
		    (SageBuilder::buildBinaryExpression<SgAssignOp>
		     (isSgExpression(SageInterface::deepCopy(replExpr)),
		      isSgExpression(SageInterface::deepCopy(*l))));
		  SgBasicBlock* bb = isSgBasicBlock(forLoop->get_loop_body());
		  if (isSgBasicBlock(bb->get_statements()[0])
		    && bb->get_statements().size() == 1)
		    bb = isSgBasicBlock(bb->get_statements()[0]);
		  bb->prepend_statement(stm);
		  readRepl.push_back(replExpr);
		}
	      if (std::find(writeRefs.begin(), writeRefs.end(), *l) != writeRefs.end() &&
		  std::find(writeRepl.begin(), writeRepl.end(), replExpr) == writeRepl.end())
		{
		  stm = SageBuilder::buildExprStatement
		    (SageBuilder::buildBinaryExpression<SgAssignOp>
		     (isSgExpression(SageInterface::deepCopy(*l)),
		      isSgExpression(SageInterface::deepCopy(replExpr))));
		  SgBasicBlock* bb = isSgBasicBlock(forLoop->get_loop_body());
		  if (isSgBasicBlock(bb->get_statements()[0])
		    && bb->get_statements().size() == 1)
		    bb = isSgBasicBlock(bb->get_statements()[0]);
		  bb->append_statement(stm);
		  writeRepl.push_back(replExpr);
		}
	      SageInterface::replaceExpression(isSgExpression(*l),
					       isSgExpression(SageInterface::deepCopy(replExpr)),
					       true);
	    }
	  SgBasicBlock* mybb = isSgBasicBlock(forLoop->get_loop_body());
	  if (isSgBasicBlock(mybb->get_statements()[0])
	      && mybb->get_statements().size() == 1)
	    mybb = isSgBasicBlock(mybb->get_statements()[0]);
	  for (std::vector<SgNode*>::iterator m = declsToInsert.begin();
	       m != declsToInsert.end(); ++m)
	    mybb->prepend_statement(isSgStatement(*m));
	  if (debug > 2)
	    {
	      std::cout << "After reference GVN:" << std::endl;
	      std::cout << (*i)->get_parent()->unparseToCompleteString() << std::endl;
	    }
	}

	  /// (2) replace mod expressions by inc. expressions. (Note: must be done last)
	  if (modsimpl)
	    {
	      // collect all array refs exprs.
	      std::vector<SgNode*> refs =
		NodeQuery::querySubTree(*i, V_SgPntrArrRefExp);
	      // collect all associated exprs.
	      std::map<SgNode*, std::vector<SgNode*> > mapExpr;
	      std::vector<SgNode*> exprs;
	      for (std::vector<SgNode*>::iterator j = refs.begin(); j != refs.end();
		   ++j)
		{
		  SgPntrArrRefExp* e = isSgPntrArrRefExp(*j);
		  ROSE_ASSERT(e);
		  exprs.push_back(e->get_rhs_operand());
		}
	      // make a map.
	      for (std::vector<SgNode*>::iterator j = exprs.begin(); j != exprs.end();
		   ++j)
		{
		  if (mapExpr.size() == 0)
		    mapExpr[*j].push_back(*j);
		  else
		    {
		      std::map<SgNode*, std::vector<SgNode*> >::iterator k;
		      for (k = mapExpr.begin(); k != mapExpr.end(); ++k)
			{
			  if (SageTools::checkTreeAreEquivalent(k->first, *j))
			    {
			      k->second.push_back(*j);
			      break;
			    }
			}
		      if (k == mapExpr.end())
			mapExpr[*j].push_back(*j);
		    }
		}
	      // For each map entry,
	      for (std::map<SgNode*, std::vector<SgNode*> >::iterator
		     j = mapExpr.begin(); j != mapExpr.end(); ++j)
		{
		  // check if the loop iv is in the expression.
		  std::vector<SgNode*> hasIv =
		    NodeQuery::querySubTree(j->first, V_SgVarRefExp);
		  std::vector<SgNode*>::iterator k;
		  for (k = hasIv.begin(); k != hasIv.end(); ++k)
		    {
		      SgVarRefExp* e = isSgVarRefExp(*k);
		      ROSE_ASSERT(e);
		      SgVariableSymbol* s = e->get_symbol();
		      if (s == loop_iterator_sym)
			break;
		    }

		  // create a scalar for the exp.
		  std::ostringstream oss;
		  oss << vc++;
		  std::string newit(proto);
		  newit += oss.str();
		  SgVariableDeclaration* decl =
		    SageBuilder::buildVariableDeclaration
		    (newit, SageBuilder::buildIntType(), NULL, local_scope);
		  SgExprStatement* stm = SageBuilder::buildExprStatement
		    (SageBuilder::buildBinaryExpression<SgAssignOp>
		     (SageBuilder::buildVarRefExp
		      (SageInterface::getFirstVarSym(decl)),
		      isSgExpression(SageInterface::deepCopy(j->first))));
		  SageInterface::insertStatementBefore(*i, decl);

		  // Reset the value of the loop iterator to 0 before the expression
		  // computation if loop bound hoisting has been performed.
		  /// FIXME: the behavior of modsimpl w/o lbhoist is undetermined.
		  if (k != hasIv.end() && lbhoist)
		    {
		      SgExprStatement* stm2 = SageBuilder::buildExprStatement
			(SageBuilder::buildBinaryExpression<SgAssignOp>
			 (SageBuilder::buildVarRefExp(loop_iterator_sym),
			  SageBuilder::buildIntVal(0)));
		      SageInterface::insertStatementBefore(*i, stm2);
		    }
		 
		  SageInterface::insertStatementBefore(*i, stm);
		  // SgExpression* newe = SageBuilder::buildVarRefExp
		  //   (SageInterface::getFirstVarSym(decl));


		  if (k == hasIv.end())
		    {
		      // Simply replace the access function by the constant scalar.
		      for (std::vector<SgNode*>::iterator l = j->second.begin();
			   l != j->second.end(); ++l)
			{
			  SgExpression* newe = SageBuilder::buildVarRefExp
			    (SageInterface::getFirstVarSym(decl));
			  SgExpression* olde = isSgExpression(*l);
			  ROSE_ASSERT(olde);
			  SageInterface::replaceExpression(olde, newe);
			}
		    }
		  else
		    {

		      // replace by constant + loop_iv
		      for (std::vector<SgNode*>::iterator l = j->second.begin();
			   l != j->second.end(); ++l)
			{
			  SgExpression* newe = SageBuilder::buildVarRefExp
			    (SageInterface::getFirstVarSym(decl));
			  newe =
			    SageBuilder::buildBinaryExpression<SgAddOp>
			    (newe, SageBuilder::buildVarRefExp(loop_iterator_sym));
			  SgExpression* olde = isSgExpression(*l);
			  ROSE_ASSERT(olde);
			  SageInterface::replaceExpression(olde, newe);
			}
		      // add "resume" code at the end of each loop iteration,
		      // for the %.
		      // if (constant+loop_iv+stride>=modval) then constant -= modval
		      /// LNP: FIXME: good def: constant+loop_iv+1==modval
		      SgExpression* e1 = stm->get_expression();
		      SgAssignOp* e1aop = isSgAssignOp(e1);
		      ROSE_ASSERT(e1aop);
		      SgModOp* mop = isSgModOp(e1aop->get_rhs_operand());
		      if (mop)
			{
			  SgExpression* modval = mop->get_rhs_operand();
			  SgExpression* newe =
			    SageBuilder::buildBinaryExpression<SgAddOp>
			    (SageBuilder::buildVarRefExp
			     (SageInterface::getFirstVarSym(decl)),
			     SageBuilder::buildIntVal(inc_val)); //1
			  newe =
			    SageBuilder::buildBinaryExpression<SgAddOp>
			    (newe, SageBuilder::buildVarRefExp(loop_iterator_sym));
			  SgExpression* testexpr =
			    //SageBuilder::buildBinaryExpression<SgEqualityOp>
			    SageBuilder::buildBinaryExpression<SgGreaterOrEqualOp>
			    (newe, SageInterface::deepCopy(modval));
			  SgExprStatement* thenstmt =
			    SageBuilder::buildExprStatement
			    (SageBuilder::buildBinaryExpression<SgMinusAssignOp>
			     (SageBuilder::buildVarRefExp
			      (SageInterface::getFirstVarSym(decl)),
			      SageInterface::deepCopy(modval)));
			  SgStatement* s =
			    SageBuilder::buildIfStmt(testexpr, thenstmt, NULL);

			  SgBasicBlock* bb = isSgBasicBlock(forLoop->get_loop_body());
			  ROSE_ASSERT(bb);
			  bb->append_statement(s);
			}
		    }
		}
	      if (debug > 2)
		{
		  std::cout << "After mod optimization:" << std::endl;
		  std::cout << (*i)->get_parent()->unparseToCompleteString() << std::endl;
		}
	    }
	}


}


/**
 * Insert the AP ap_bus et al. pragmas.
 *
 *
 */
void createAPMemBusFuncPragmas(SgNode* root)
{
  SgNode* funcDef = SageInterface::getEnclosingNode<SgFunctionDefinition>(root);
  ROSE_ASSERT(funcDef);
  SgFunctionDefinition* fd = isSgFunctionDefinition(funcDef);
  std::string p1("#pragma AP INTERFACE ap_ctrl_hs port = return");
  std::string p2("#pragma AP INTERFACE ap_bus port = mem_bus");

  //SageInterface::ensureBasicBlockAsBdoyOfFor(fs);
  // Get the first statement in the bb.
  SgStatementPtrList stmts = fd->get_body()->get_statements();
  ROSE_ASSERT(stmts.size());
  SgStatement* first = *(stmts.begin());
  SageInterface::attachArbitraryText(first, p2,
				     PreprocessingInfo::before);
  SageInterface::attachArbitraryText(first, p1,
				     PreprocessingInfo::before);
}


/**
 * Insert the AP tripcount pragmas.
 *
 *
 */
void createAPPTripCountPragmas(SgNode* root)
{
 // Collect all loops.
  std::vector<SgNode*> forLoops =
    NodeQuery::querySubTree(root, V_SgForStatement);
  for (std::vector<SgNode*>::iterator i = forLoops.begin(); i != forLoops.end();
       ++i)
    {
      SgForStatement* fs = isSgForStatement(*i);
      ROSE_ASSERT(fs);
      SageAPForInfo* annot = (SageAPForInfo*)fs->getAttribute("SageAPForInfo");
      if (annot == NULL)
	continue;

      std::string appragma("#pragma AP loop tripcount min ");
      std::ostringstream min;
      min << annot->minTripCount;
      appragma += min.str();
      appragma += " avg ";
      std::ostringstream avg;
      avg << annot->avgTripCount;
      appragma += avg.str();
      appragma += " max ";
      std::ostringstream max;
      max << annot->maxTripCount;
      appragma += max.str();

      //SageInterface::ensureBasicBlockAsBdoyOfFor(fs);
      SgBasicBlock* bb = isSgBasicBlock(fs->get_loop_body());
      ROSE_ASSERT(bb);
      SageInterface::attachArbitraryText(bb, appragma,
					 PreprocessingInfo::before);
    }

}


/**
 * Insert the AP tripcount pragmas.
 *
 *
 */
void createAPPTripCountPragmasV2()
{
  SgProject* project = SageInterface::getProject();
  SgFilePtrList& file_list = project->get_fileList();
  SgFilePtrList::const_iterator file_iter;
  // Iterate on all files of the project.
  for (file_iter = file_list.begin(); file_iter != file_list.end(); file_iter++)
    {
      SgSourceFile* file = isSgSourceFile(*file_iter);
      SgNodePtrList funcDefnList =
	NodeQuery::querySubTree(file, V_SgFunctionDefinition);
      SgNodePtrList::const_iterator iter;
      for (iter = funcDefnList.begin(); iter != funcDefnList.end(); ++iter)
	{
	  SgFunctionDefinition *fun = isSgFunctionDefinition(*iter);
	  if (!fun)
	    continue; // with the next function definition
	  SgName name = fun->get_declaration()->get_name();
	  SgBasicBlock* body = fun->get_body();

	  // Collect all loops.
	  std::vector<SgNode*> forLoops =
	    NodeQuery::querySubTree(body, V_SgForStatement);
	  for (std::vector<SgNode*>::iterator i = forLoops.begin(); i != forLoops.end();
	       ++i)
	    {
	      SgForStatement* fs = isSgForStatement(*i);
	      ROSE_ASSERT(fs);
	      SageAPForInfo* annot = (SageAPForInfo*)fs->getAttribute("SageAPForInfo");
	      if (annot == NULL)
		continue;

	      std::string appragma("#pragma AP loop tripcount min ");
	      std::ostringstream min;
	      min << annot->minTripCount;
	      appragma += min.str();
	      appragma += " avg ";
	      std::ostringstream avg;
	      avg << annot->avgTripCount;
	      appragma += avg.str();
	      appragma += " max ";
	      std::ostringstream max;
	      max << annot->maxTripCount;
	      appragma += max.str();

	      //SageInterface::ensureBasicBlockAsBdoyOfFor(fs);
	      SgBasicBlock* bb = isSgBasicBlock(fs->get_loop_body());
	      ROSE_ASSERT(bb);
	      SageInterface::attachArbitraryText(bb, appragma,
						 PreprocessingInfo::inside);

	      fs->removeAttribute("SageAPForInfo");
	    }
	}
    }
}



/**
 * Insert the AP dependence false pragmas.
 *
 *
 */
void createAPNoDepPragmas()
{
  SgProject* project = SageInterface::getProject();
  SgFilePtrList& file_list = project->get_fileList();
  SgFilePtrList::const_iterator file_iter;
  // Iterate on all files of the project.
  for (file_iter = file_list.begin(); file_iter != file_list.end(); file_iter++)
    {
      SgSourceFile* file = isSgSourceFile(*file_iter);
      SgNodePtrList funcDefnList =
	NodeQuery::querySubTree(file, V_SgFunctionDefinition);
      SgNodePtrList::const_iterator iter;
      for (iter = funcDefnList.begin(); iter != funcDefnList.end(); ++iter)
	{
	  SgFunctionDefinition *fun = isSgFunctionDefinition(*iter);
	  if (!fun)
	    continue; // with the next function definition
	  SgName name = fun->get_declaration()->get_name();
	  SgBasicBlock* body = fun->get_body();

	  // Collect all loops.
	  std::vector<SgNode*> forLoops =
	    NodeQuery::querySubTree(body, V_SgForStatement);
	  for (std::vector<SgNode*>::iterator i = forLoops.begin(); i != forLoops.end();
	       ++i)
	    {
	      SgForStatement* fs = isSgForStatement(*i);
	      ROSE_ASSERT(fs);

	      // Ensure it's a scop loop.
	      SageAPForInfo* annot =
		(SageAPForInfo*)fs->getAttribute("SageAPForInfo");
	      if (annot == NULL)
		continue;

	      // Ensure it's a parallel loop.
	      SageForInfo* polyannot =
		(SageForInfo*)fs->getAttribute("SageForInfo");
	      if (polyannot == NULL || !polyannot->isParallel)
		continue;

	      // Ensure it is an inner loop.
	      std::vector<SgNode*> inLoops =
		NodeQuery::querySubTree(fs->get_loop_body(), V_SgForStatement);

	      if (inLoops.size())
		continue;

	      // Collect all written arrays.
	      std::vector<SgNode*> readRefs;
	      std::vector<SgNode*> writeRefs;
	      if (!SageTools::collectReadWriteRefs(fs->get_loop_body(),
						  readRefs, writeRefs, true))
		continue;

	      std::set<SgVariableSymbol*> syms;
	      for (std::vector<SgNode*>::iterator j = writeRefs.begin();
		   j != writeRefs.end(); ++j)
		{
		  SgPntrArrRefExp* pa = isSgPntrArrRefExp(*j);
		  if (! pa)
		    continue;

		  SgPntrArrRefExp* last;
		  while ((last = isSgPntrArrRefExp(pa->get_lhs_operand())))
		    pa = last;
		  SgVarRefExp* ref = isSgVarRefExp(pa->get_lhs_operand());
		  syms.insert(ref->get_symbol());
		}


	      for (std::set<SgVariableSymbol*>::iterator j = syms.begin();
		   j != syms.end(); ++j)
		{
		  std::string appragma;
		  appragma += "#pragma AP dependence variable=";
		  appragma += (*j)->get_name().getString();
		  appragma += " inter false";

		  //SageInterface::ensureBasicBlockAsBdoyOfFor(fs);
		  SgBasicBlock* bb = isSgBasicBlock(fs->get_loop_body());
		  ROSE_ASSERT(bb);
		  SageInterface::attachArbitraryText(bb, appragma,
						     PreprocessingInfo::before);

		}

	    }
	}
    }
}




/**
 * Insert the AP Pipeline pragmas.
 *
 *
 */
void createAPPipelinePragmas(SgNode* root)
{
  // Collect all inner-most loops.
  std::vector<SgNode*> forLoops =
    NodeQuery::querySubTree(root, V_SgForStatement);
  std::vector<SgNode*> innerForLoops;
  for (std::vector<SgNode*>::iterator i = forLoops.begin(); i != forLoops.end();
       ++i)
    {
      SgForStatement* fs = isSgForStatement(*i);
      ROSE_ASSERT(fs);
      std::vector<SgNode*> query =
	NodeQuery::querySubTree(fs->get_loop_body(), V_SgForStatement);
      if (query.size() == 0)
	innerForLoops.push_back(*i);
    }

  // For all inner-most loops in the scop, insert
  // '#pragma AP pipeline II=1'
  std::string appragma("#pragma AP pipeline II=1");
  for (std::vector<SgNode*>::iterator i = innerForLoops.begin();
       i != innerForLoops.end(); ++i)
    {
      SgForStatement* fs = isSgForStatement(*i);
      ROSE_ASSERT(fs);
      //SageInterface::ensureBasicBlockAsBdoyOfFor(fs);
      SgBasicBlock* bb = isSgBasicBlock(fs->get_loop_body());
      ROSE_ASSERT(bb);
      // Get the first statement in the bb.
      SgStatementPtrList stmts = bb->get_statements();
      if (stmts.size())
	{
	  SgStatement* first = *(stmts.begin());
	  SageInterface::attachArbitraryText(bb, appragma,
					     PreprocessingInfo::before);
	}
    }
}


std::vector<SgNode*> getAddr(SgNode* root)
{

  class OBBVisitor : public AstPrePostOrderTraversal {
  public:
    virtual void preOrderVisit(SgNode* node) {};
    virtual void postOrderVisit(SgNode* node) {
      SgAddressOfOp* op = isSgAddressOfOp(node);
      if (op)
	{
	  _res.push_back(op);
  	}
    }
    std::vector<SgNode*> _res;
  };

  std::vector<SgNode*> res;
  OBBVisitor lookupOutlinableBB;
  lookupOutlinableBB._res = res;
  lookupOutlinableBB.traverse(root);

  return lookupOutlinableBB._res;
}

std::vector<SgNode*> getDeref(SgNode* root)
{

  class OBBVisitor : public AstPrePostOrderTraversal {
  public:
    virtual void preOrderVisit(SgNode* node) {};
    virtual void postOrderVisit(SgNode* node) {
      SgPointerDerefExp* op = isSgPointerDerefExp(node);
      if (op)
	{
	  _res.push_back(op);
  	}
    }
    std::vector<SgNode*> _res;
  };

  std::vector<SgNode*> res;
  OBBVisitor lookupOutlinableBB;
  lookupOutlinableBB._res = res;
  lookupOutlinableBB.traverse(root);

  return lookupOutlinableBB._res;
}


std::vector<SgBasicBlock*> computeOutlinableBB(SgNode* root)
{

  class OBBVisitor : public AstPrePostOrderTraversal {
  public:
    virtual void preOrderVisit(SgNode* node) {};
    virtual void postOrderVisit(SgNode* node) {
      SgBasicBlock* bb = isSgBasicBlock(node);
      if (bb)
	{
	  SageAPCopyBlockInfo* annot1 =
	    (SageAPCopyBlockInfo*)(bb)->getAttribute("SageAPCopyBlockInfo");
	  SageAPComputeBlockInfo* annot2 =
	    (SageAPComputeBlockInfo*)(bb)->getAttribute
	    ("SageAPComputeBlockInfo");
	  if (annot1 || annot2)
	    {
	      if (Outliner::isOutlineable(bb))
		_res.push_back(bb);
	    }
  	}
    }
    std::vector<SgBasicBlock*> _res;
  };

  std::vector<SgBasicBlock*> res;
  OBBVisitor lookupOutlinableBB;
  lookupOutlinableBB._res = res;
  lookupOutlinableBB.traverse(root);

  return lookupOutlinableBB._res;
}



std::set<SgBasicBlock*>
computeOutlinableBBpass2(SgNode* root,
			 std::set<SgBasicBlock*>& toOutline)
{
  class OBBVisitor : public AstPrePostOrderTraversal {
  public:
    virtual void preOrderVisit(SgNode* node) {};
    virtual void postOrderVisit(SgNode* node) {
      SgBasicBlock* bb = isSgBasicBlock(node);
      if (bb)
	{
	  if (_toOutline.find(bb) != _toOutline.end())
	    {
	      if (Outliner::isOutlineable(bb))
		_final.insert(bb);
	    }
  	}
    }
    std::set<SgBasicBlock*> _final;
    std::set<SgBasicBlock*> _toOutline;
  };
  std::set<SgBasicBlock*> res;
  OBBVisitor lookupOutlinableBB;
  lookupOutlinableBB._final = res;
  lookupOutlinableBB._toOutline = toOutline;
  lookupOutlinableBB.traverse(root);

  return lookupOutlinableBB._final;
}

static
void setLoopIncrementToTwo(SgForStatement* f)
{
  SgPlusPlusOp* op = isSgPlusPlusOp(f->get_increment());
  if (op)
    {
      SgExpression* newinc =
	SageBuilder::buildBinaryExpression<SgPlusAssignOp>
	(SageInterface::deepCopy(op->get_operand_i()),
	 SageBuilder::buildIntVal(2));
      SageInterface::replaceExpression(op, newinc);
      //f->set_increment(newinc); /// Doesnt work!
      SageAPForInfo* annot = (SageAPForInfo*)f->getAttribute("SageAPForInfo");
      if (annot != NULL)
	{
	  annot->minTripCount /= 2;
	  annot->avgTripCount /= 2;
	  annot->maxTripCount /= 2;
	}
    }
  /// LNP: if the increment is > 1 (2 or more), then do nothing:
  /// packedfloat fetches two consecutive floats in main memory, no
  /// striding is supported for the moment. Over-approximations in the
  /// buffer size computation will ensure code is correct and w/o OOB.
}



/**
 * simu: set to true to add special latency-consuming instruction for
 * better precision of AP metrics.
 *
 * @FIXME: Needs to be simplified. Very ad-hoc code...
 */
void createAPFifoCode(SgNode* root, s_hlsir_t* pIR, bool simu, bool doOutline,
		      bool usePackedFloatAPI, PolyRoseOptions& polyoptions)
{
  // Nothing to translate.
  if (pIR->bufferized_symbols.size() == 0)
    return;

  int verbose = 0;

  //std::set<SgVariableSymbol*> buffer_symbols;
  // 1- Collect all array references.
  Rose_STL_Container<SgNode*> arrefs =
    NodeQuery::querySubTree(root, V_SgPntrArrRefExp);
  std::vector<SgNode*> readRefs;
  std::vector<SgNode*> writeRefs;
  if (! SageTools::collectReadWriteRefs(isSgStatement(root),
					readRefs, writeRefs, true))
    ROSE_ASSERT(0);
  std::set<SgNode*> isReadRef;
  isReadRef.insert(readRefs.begin(), readRefs.end());
  SgScopeStatement* scope = isSgScopeStatement(root);

  // std::cout << "Run consistency tests (1): " << std::endl;
  // AstTests::runAllTests(SageInterface::getProject());

  if (verbose >= 1)
    std::cout << "Stage 1" << std::endl;

  // 1- Replace array references with the FIFO framework.
  std::set<SgForStatement*> toPipeline;
  for (Rose_STL_Container<SgNode*>::iterator i = arrefs.begin();
       i != arrefs.end(); ++i)
    {
      SgPntrArrRefExp* ref = isSgPntrArrRefExp(*i);
      // Find symbol.
      SgNode* tmp = ref;
      while (isSgPntrArrRefExp(tmp))
  	tmp = isSgPntrArrRefExp(tmp)->get_lhs_operand();
      SgVarRefExp* vref = isSgVarRefExp(tmp);
      /// FIXME: Should never be null, but it seems it can be (dotexp?)
      if (vref == NULL)
  	continue;
      ROSE_ASSERT(vref);
      if (pIR->bufferized_symbols.find(vref->get_symbol()) !=
  	  pIR->bufferized_symbols.end())
  	{
	  // Find the surrounding AP annotation.
	  SgNode* parent = vref->get_parent();
	  SageAPCopyBlockInfo* annot =
	    (SageAPCopyBlockInfo*)parent->getAttribute("SageAPCopyBlockInfo");
	  while (parent && ! annot)
	    {
	      annot = (SageAPCopyBlockInfo*)
		parent->getAttribute("SageAPCopyBlockInfo");
	      parent = parent->get_parent();
	    }
	  if (! annot)
	    {
	      continue;
	      if (verbose >= 1)
		{
		  //std::cout << vref->get_symbol()->get_name() << std::endl;
		  std::cout << std::string(vref->get_symbol()->get_name());
		  std::cout << std::endl;
		}
	      SgNode* sss = SageInterface::getEnclosingNode<SgBasicBlock>(ref);
	      if (verbose >= 1)
		{
		  //std::cout << sss->unparseToCompleteString() << std::endl;
		  std::cout << std::string(sss->unparseToCompleteString());
		  std::cout << std::endl;
		}
	    }
	  ROSE_ASSERT(annot);

	  SgNode* f =
	    SageInterface::getEnclosingNode<SgForStatement>(ref);
	  if (f)
	    toPipeline.insert(isSgForStatement(f));

	  // Compute the various names, currently hard-wired.
	  std::string basename = vref->get_symbol()->get_name().getString();
	  std::string start_addr = basename;
	  start_addr += "_start_addr";
	  std::string i_size = basename;
	  i_size += "_sz_1";
	  std::string req_fifo = "req_fifo_";
	  req_fifo += basename;
	  std::string rsp_fifo = "rsp_fifo_";
	  rsp_fifo += basename;

  	  std::vector<SgExpression*> exprs;
  	  SgNode* tmp2 = ref;
  	  SgName fname;
	  SgExprListExp* explist = NULL;

	  // We are doing a load.
  	  if (isReadRef.find(ref) != isReadRef.end())
	    {
	      if (annot->type == 0)
		{
		  // We are doing a blocking load.
		  // Scan the array reference.
		  while (isSgPntrArrRefExp(tmp2))
		    {
		      exprs.insert(exprs.begin(),
				   SageInterface::deepCopy
				   (isSgPntrArrRefExp
				    (tmp2)->get_rhs_operand()));
		      tmp2 = isSgPntrArrRefExp(tmp2)->get_lhs_operand();
		    }
		  // Push the array size.
		  if (annot->dim)
		    {
		      for (int c = annot->dim - 1; c > 0; --c)
			{
			  std::ostringstream oss;
			  oss << c;
			  std::string sz(basename);
			  sz += "_sz_";
			  sz += oss.str();
			  exprs.insert(exprs.begin(),
				       SageBuilder::buildOpaqueVarRefExp
				       (sz, scope));
			}
		    }
		  // Push the starting address.
		  exprs.insert(exprs.begin(), SageBuilder::buildOpaqueVarRefExp
			       (start_addr, scope));
		  // Push the fifo names.
		  req_fifo += "_r";
		  rsp_fifo += "_r";
		  exprs.insert(exprs.begin(), SageBuilder::buildOpaqueVarRefExp
			       (rsp_fifo, scope));
		  exprs.insert(exprs.begin(), SageBuilder::buildOpaqueVarRefExp
			       (req_fifo, scope));
		  explist = SageBuilder::buildExprListExp(exprs);
		  std::ostringstream oss;
		  oss << annot->dim;
		  std::string funcnames("read_fifo_");
		  funcnames += oss.str();
		  funcnames += "df_sync";
		  fname = SgName(funcnames);
		  SgFunctionSymbol* fs =
		    SageInterface::lookupFunctionSymbolInParentScopes
		    (fname, scope);
		  SgFunctionCallExp* fc =
		    SageBuilder::buildFunctionCallExp(fs, explist);
		  SageInterface::replaceExpression(ref, fc);
		}
	      else
		{

		  if (usePackedFloatAPI)
		    {
		      SgForStatement* fl = isSgForStatement
			(SageInterface::getEnclosingNode<SgForStatement>
			 (ref));
		      setLoopIncrementToTwo(fl);
		    }


		  // We are doing a fifo load.
		  if (annot->type == 1)
		    {
		      // The data has been pre-fetched already, read
		      // the fifo.
		      rsp_fifo += "_r";
		      std::ostringstream oss;
		      oss << annot->dim;
		      std::string funcnames("pop_fifo_");
		      funcnames += oss.str();
		      funcnames += "df_async";
		      if (usePackedFloatAPI)
			funcnames += "_2_macro";

		      fname = SgName(funcnames);

		      SgExpression* stmt = isSgExpression
			(SageInterface::getEnclosingNode<SgAssignOp>(ref));
		      if (usePackedFloatAPI)
			{
			  ROSE_ASSERT(stmt);
			  SgExpression* lhs = SageInterface::deepCopy
			    (isSgAssignOp(stmt)->get_lhs_operand());
			  exprs.insert(exprs.begin(), lhs);
			}

		      exprs.insert(exprs.begin(),
				   SageBuilder::buildOpaqueVarRefExp
				   (rsp_fifo, scope));

		      explist = SageBuilder::buildExprListExp(exprs);
		      SgFunctionSymbol* fs =
			SageInterface::lookupFunctionSymbolInParentScopes
			(fname, scope);
		      SgFunctionCallExp* fc =
			SageBuilder::buildFunctionCallExp(fs, explist);

		      if (usePackedFloatAPI)
			SageInterface::replaceExpression(stmt, fc);
		      else
			SageInterface::replaceExpression(ref, fc);
		    }
		  else
		    {
		      // We are doing a pre-fetch.
		      // Scan the array reference.
		      while (isSgPntrArrRefExp(tmp2))
			{
			  exprs.insert(exprs.begin(),
				       SageInterface::deepCopy
				       (isSgPntrArrRefExp
					(tmp2)->get_rhs_operand()));
			  tmp2 = isSgPntrArrRefExp(tmp2)->get_lhs_operand();
			}
		      // Push the array size.
		      if (annot->dim)
			{
			  for (int c = annot->dim - 1; c > 0; --c)
			    {
			      std::ostringstream oss;
			      oss << c;
			      std::string sz(basename);
			      sz += "_sz_";
			      sz += oss.str();
			      exprs.insert(exprs.begin(),
					   SageBuilder::buildOpaqueVarRefExp
					   (sz, scope));
			    }
			}
		      // Push the starting address.
		      exprs.insert(exprs.begin(),
				   SageBuilder::buildOpaqueVarRefExp
				   (start_addr, scope));
		      // Push the fifo names.
		      req_fifo += "_r";
		      exprs.insert(exprs.begin(),
				   SageBuilder::buildOpaqueVarRefExp
				   (req_fifo, scope));
		      explist = SageBuilder::buildExprListExp(exprs);
		      std::ostringstream oss;
		      oss << annot->dim;
		      std::string funcnames("push_read_fifo_");
		      funcnames += oss.str();
		      funcnames += "df_async";
		      fname = SgName(funcnames);
		      SgFunctionSymbol* fs =
			SageInterface::lookupFunctionSymbolInParentScopes
			(fname, scope);
		      SgFunctionCallExp* fc =
			SageBuilder::buildFunctionCallExp(fs, explist);
		      // Get the surrounding assignment statement.
		      SgExpression* stmt = isSgExpression
			(SageInterface::getEnclosingNode<SgAssignOp>(ref));
		      ROSE_ASSERT(stmt);
		      SageInterface::replaceExpression(stmt, fc);
		    }
		}
	    }
  	  else
	    {
	      // We are doing a store.
	      // Get the surrounding assignment statement.
	      SgExpression* stmt = isSgExpression
		(SageInterface::getEnclosingNode<SgAssignOp>(ref));
	      ROSE_ASSERT(stmt);
	      SgExpression* rhs = SageInterface::deepCopy
		(isSgAssignOp(stmt)->get_rhs_operand());
	      exprs.insert(exprs.begin(), rhs);

	      // Scan the array reference.
	      while (isSgPntrArrRefExp(tmp2))
		{
		  exprs.insert(exprs.begin(),
			       SageInterface::deepCopy
			       (isSgPntrArrRefExp(tmp2)->get_rhs_operand()));
		  tmp2 = isSgPntrArrRefExp(tmp2)->get_lhs_operand();
		}
	      // Push the array size.
	      if (annot->dim)
		{
		  for (int c = annot->dim - 1; c > 0; --c)
		    {
		      std::ostringstream oss;
		      oss << c;
		      std::string sz(basename);
		      sz += "_sz_";
		      sz += oss.str();
		      exprs.insert(exprs.begin(),
				   SageBuilder::buildOpaqueVarRefExp
				   (sz, scope));
		    }
		}
	      // Push the starting address.
	      exprs.insert(exprs.begin(), SageBuilder::buildOpaqueVarRefExp
			   (start_addr, scope));
	      // Push the fifo names.
	      req_fifo += "_w";
	      exprs.insert(exprs.begin(), SageBuilder::buildOpaqueVarRefExp
			   (req_fifo, scope));
	      explist = SageBuilder::buildExprListExp(exprs);
	      std::ostringstream oss;
	      oss << annot->dim;
	      std::string funcnames("write_fifo_");
	      funcnames += oss.str();
	      funcnames += "df_sync";
	      fname = SgName(funcnames);
	      SgFunctionSymbol* fs =
		SageInterface::lookupFunctionSymbolInParentScopes(fname, scope);
	      SgFunctionCallExp* fc =
		SageBuilder::buildFunctionCallExp(fs, explist);
	      SageInterface::replaceExpression(stmt, fc);
	    }
  	}
    }


  if (verbose >= 1)
    std::cout << "Stage 1b" << std::endl;

  // 1b- Insert pipeline pragma for the pop_fifo.
  std::string appragma("#pragma AP pipeline II=1");
  for (std::set<SgForStatement*>::iterator i = toPipeline.begin();
       i != toPipeline.end(); ++i)
    {
      SgForStatement* fs = isSgForStatement(*i);
      ROSE_ASSERT(fs);

      Rose_STL_Container<SgNode*> fl =
	NodeQuery::querySubTree(fs->get_loop_body(), V_SgForStatement);
      if (fl.size())
	continue;
      //SageInterface::ensureBasicBlockAsBdoyOfFor(fs);
      SgBasicBlock* bb = isSgBasicBlock(fs->get_loop_body());
      ROSE_ASSERT(bb);
      // Get the first statement in the bb.
      SgStatementPtrList stmts = bb->get_statements();
      if (stmts.size())
	{
	  SgStatement* first = *(stmts.begin());
	  SageInterface::attachArbitraryText(bb, appragma,
					     PreprocessingInfo::before);
	}
    }



  if (verbose >= 1)
    std::cout << "Stage 2" << std::endl;

  // std::cout << "Run consistency tests (2): " << std::endl;
  // AstTests::runAllTests(SageInterface::getProject());

  // 2- Insert memory access latency macro.
  if (simu)
    {
      Rose_STL_Container<SgNode*> cpbb =
	NodeQuery::querySubTree(root, V_SgBasicBlock);
      std::map<SgVariableSymbol*, SgVariableSymbol*> sems;
      for (Rose_STL_Container<SgNode*>::iterator i = cpbb.begin();
	   i != cpbb.end(); ++i)
	{
	  SageAPCopyBlockInfo* annot =
	    (SageAPCopyBlockInfo*)(*i)->getAttribute("SageAPCopyBlockInfo");
	  if (annot && isSgArrayType(annot->orig_sym->get_type()))
	    {
	      // Replace all ifs by if-then-else
	      {
		std::vector<SgNode*> allBBinBB =
		  NodeQuery::querySubTree(*i, V_SgBasicBlock);
		for (std::vector<SgNode*>::iterator k = allBBinBB.begin();
		     k != allBBinBB.end(); ++k)
		  {
		    SgBasicBlock* bb = isSgBasicBlock(*k);
		    SgStatementPtrList stmts = bb->get_statements();
		    std::vector<std::vector<SgIfStmt*> > toMerge;
		    int count = 0;
		    bool move_next = true;
		    for (SgStatementPtrList::iterator j = stmts.begin();
			 j != stmts.end(); ++j)
		      {
			SgIfStmt* ifs = isSgIfStmt(*j);
			if (ifs)
			  {
			    if (move_next)
			      toMerge.push_back(std::vector<SgIfStmt*>());
			    toMerge[toMerge.size() - 1].push_back(ifs);
			    move_next = false;
			  }
			else
			  move_next = true;
		      }
		    for (int l = 0 ; l < toMerge.size(); ++l)
		      {
			if (toMerge[l].size() <= 1)
			  continue;
			SgIfStmt* newif = NULL;
			for (std::vector<SgIfStmt*>::reverse_iterator j =
			       toMerge[l].rbegin(); j != toMerge[l].rend(); ++j)
			  {
			    if (*j == NULL)
			      continue;
			    if (newif == NULL)
			      {
				newif = SageInterface::deepCopy(*j);
				SageInterface::removeStatement(*j);
			      }
			    else
			      {
				newif = SageBuilder::buildIfStmt
				  (SageInterface::deepCopy
				   ((*j)->get_conditional()),
				   SageInterface::deepCopy
				   ((*j)->get_true_body()),
				   newif);
				if (*j != *(toMerge[l].begin()))
				  SageInterface::removeStatement(*j);
			      }
			  }
			SageInterface::replaceStatement(*(toMerge[l].begin()),
							newif, true);
		      }
		  }
	      }

	      if (annot->type == 4 || annot->type == 0 || annot->type == 3)
		{
		  SgVariableSymbol* sym = annot->orig_sym;
		  std::string basename = sym->get_name().getString();
		  std::string req_fifo = "req_fifo_";
		  req_fifo += basename;
		  req_fifo += "_r";
		  std::vector<SgExpression*> exprs;
		  exprs.insert(exprs.begin(),
			       SageBuilder::buildOpaqueVarRefExp
			       (req_fifo, scope));
		  SgExprListExp* explist = NULL;
		  explist = SageBuilder::buildExprListExp(exprs);
		  SgName fname = SgName("CommLatencyIncrease");
		  SgFunctionSymbol* fs =
		    SageInterface::lookupFunctionSymbolInParentScopes
		    (fname, scope);
		  ROSE_ASSERT(fs);
		  SgFunctionCallExp* fc =
		    SageBuilder::buildFunctionCallExp(fs, explist);
		  SgBasicBlock* bb = isSgBasicBlock(*i);
		  ROSE_ASSERT(bb);
		  bb->prepend_statement(SageBuilder::buildExprStatement(fc));
		  /// XXX YYY
		}
	      if (annot->type == 4 && 0) // De-activated as not needed.
		{
		  // Insert a dependency between the prefetch and the end
		  // of the iteration.

		  // Create the local semaphore, if needed.
		  if (sems.find(annot->orig_sym) == sems.end())
		    {
		      SgBasicBlock* bb = isSgBasicBlock(root);
		      ROSE_ASSERT(bb);
		      std::string ssym(annot->orig_sym->get_name().getString());
		      ssym += "_local_semaphore";
		      SgVariableDeclaration* decl =
			SageBuilder::buildVariableDeclaration
			(ssym, SageBuilder::buildIntType(),
			 SageBuilder::buildAssignInitializer
			 (SageBuilder::buildIntVal(0),
			  SageBuilder::buildIntType()), bb);
		      bb->prepend_statement(decl);
		      sems[annot->orig_sym] =
			SageInterface::getFirstVarSym(decl);
		    }
		  // Create the source of the dependence.
		  SgVariableSymbol* sem = sems[annot->orig_sym];
		  SgName fname = SgName("ap_helper_set_semaphore");
		  SgFunctionSymbol* fs =
		    SageInterface::lookupFunctionSymbolInParentScopes
		    (fname, scope);
		  ROSE_ASSERT(fs);
		  std::vector<SgExpression*> es;
		  es.insert(es.begin(), SageBuilder::buildVarRefExp(sem));
		  SgExprListExp* explist = SageBuilder::buildExprListExp(es);
		  SgFunctionCallExp* fc =
		    SageBuilder::buildFunctionCallExp(fs, explist);
		  SgBasicBlock* bb = isSgBasicBlock(*i);
		  ROSE_ASSERT(bb);
		  bb->append_statement(SageBuilder::buildExprStatement(fc));
		  /// XXX YYY
		  // Create the target of the dependence.
		  fname = SgName("ap_helper_wait_semaphore");
		  fs = SageInterface::lookupFunctionSymbolInParentScopes
		    (fname, scope);
		  ROSE_ASSERT(fs);
		  std::vector<SgExpression*> es2;
		  es2.insert(es2.begin(), SageBuilder::buildVarRefExp(sem));
		  explist = SageBuilder::buildExprListExp(es2);
		  fc = SageBuilder::buildFunctionCallExp(fs, explist);
		  SgBasicBlock* pbb = isSgBasicBlock(bb->get_parent());
		  ROSE_ASSERT(pbb);
		  pbb->append_statement(SageBuilder::buildExprStatement(fc));
		  /// XXX YYY
		}
	    }
	}
    }


  std::set<SgStatement*> allComputes;
  std::set<SgBasicBlock*> toOutline;
  std::map<SgBasicBlock*, SgBasicBlock*> parCalls;
  std::map<SgBasicBlock*, SgStatement*> mapCall;
  std::map<SgBasicBlock*, SgFunctionDefinition*> mapDecl;
  std::map<SgBasicBlock*, std::vector<SgStatement*> > allCalls;
  std::vector<SgFunctionDefinition*> topre;
  std::vector<SgFunctionDeclaration*> vecDecl;

  if (doOutline)
    {
      if (verbose >= 1)
	std::cout << "Stage 3" << std::endl;

      // 3- Outline copy statement functions.
      std::vector<SgBasicBlock*> bbs = computeOutlinableBB(root);
      for (std::vector<SgBasicBlock*>::iterator i = bbs.begin(); i != bbs.end();
	   ++i)
	{
	  Outliner::enable_classic=true;
	  /// FIXME: liveness was set to true, but causes an assert
	  /// for gemm/128/basic tile size & polyhls options.
	  Outliner::enable_liveness=false;
	  Outliner::enable_debug=false;


	  // // use a wrapper for all variables or one parameter for a variable or a wrapper for all variables
	  //     Outliner::useParameterWrapper=false;  // use an array of pointers wrapper for parameters of the outlined function
	  //     Outliner::useStructureWrapper=false;  // use a structure wrapper for parameters of the outlined function
	  //Outliner::temp_variable=true; // use temporary variables to reduce pointer derefer
	  SageAPCopyBlockInfo* annot1 =
	    (SageAPCopyBlockInfo*)(*i)->getAttribute("SageAPCopyBlockInfo");
	  SageAPComputeBlockInfo* annot2 =
	    (SageAPComputeBlockInfo*)(*i)->getAttribute("SageAPComputeBlockInfo");
	  Outliner::preprocess(*i);
	  if (verbose >= 1)
	    {
	      std::cout << "outline: start" << std::endl;
	      std::cout << (*i)->unparseToCompleteString() << std::endl;
	      std::cout << (*i)->get_parent()->unparseToCompleteString() << std::endl;
	    }
	  // SageInterface::fixVariableReferences(isSgStatement((*i)->get_parent()));
	  // SageInterface::fixStatement(isSgStatement((*i)->get_parent()),
	  // 			      isSgScopeStatement((*i)->get_parent()->get_parent()));

	  Outliner::Result r = Outliner::outline(*i);

	  if (verbose >= 1)
	    std::cout << "outline: done" << std::endl;
	  if (annot1)
	    r.call_->setAttribute("SageAPCopyBlockInfo", annot1);
	  else
	    r.call_->setAttribute("SageAPComputeBlockInfo", annot2);
	  SgNode* enclosingBB =
	    SageInterface::getEnclosingNode<SgBasicBlock>(r.call_);
	  ROSE_ASSERT(enclosingBB);
	  allCalls[isSgBasicBlock(enclosingBB)].push_back(r.call_);
	  vecDecl.push_back(r.decl_);

	  // Run PRE on compute blocks.
	  if (annot2)
	    {
	      // std::cout << "PRE: "
	      // 	    << r.decl_->get_definition()->unparseToCompleteString()
	      // 	    << std::endl;
	      topre.push_back(r.decl_->get_definition());
	    }

	  // Insert pragma no-unroll.
	  SgStatementPtrList stmts =
	    r.decl_->get_definition()->get_body()->get_statements();
	  if (stmts.size())
	    {
	      std::string p1("#pragma AP inline self off");
	      SgStatement* first = *(stmts.begin());
	      SageInterface::attachArbitraryText(first, p1,
						 PreprocessingInfo::before);
	    }
	}

      std::map<SgBasicBlock*, std::vector<SgStatement*> >::iterator ii;
      for (ii = allCalls.begin(); ii != allCalls.end(); ++ii)
	{
	  for (std::vector<SgStatement*>::iterator j = ii->second.begin();
	       j != ii->second.end(); ++j)
	    {
	      // 1- Collect all compute functions.
	      SageAPCopyBlockInfo* annot1 =
		(SageAPCopyBlockInfo*)(*j)->getAttribute("SageAPCopyBlockInfo");
	      SageAPComputeBlockInfo* annot2 =
		(SageAPComputeBlockInfo*)(*j)->getAttribute("SageAPComputeBlockInfo");
	      if (annot2)
		allComputes.insert(*j);
	    }
	}


      if (verbose >= 1)
	std::cout << "Stage 4" << std::endl;
      for (std::set<SgStatement*>::iterator i = allComputes.begin();
	   i != allComputes.end(); ++i)
	{
	  // 2- For each compute function, get the enclosing BB.
	  SgNode* n = SageInterface::getEnclosingNode<SgBasicBlock>(*i);
	  if (! n)
	    continue;
	  SgBasicBlock* bb = isSgBasicBlock(n);
	  ROSE_ASSERT(bb);
	  // 2b- Ensure there is no loop in the BB.
	  std::vector<SgNode*> forLoops =
	    NodeQuery::querySubTree(bb, V_SgForStatement);
	  if (forLoops.size())
	    continue;


	  // 3- Inside the BB, collect all copy functions.
	  std::vector<SgNode*> calls =
	    NodeQuery::querySubTree(bb, V_SgFunctionCallExp);
	  // 4- Move all next-iter-prefetch in a bb
	  // 5- Move all other functions into another bb.
	  std::vector<SgNode*> prefetch;
	  std::vector<SgNode*> copyin;
	  std::vector<SgNode*> copyout;
	  std::vector<SgNode*> compute;

	  for (std::vector<SgNode*>::iterator j = calls.begin(); j != calls.end();
	       ++j)
	    {
	      SgStatement* s = SageInterface::getEnclosingNode<SgStatement>(*j);
	      ROSE_ASSERT(s);
	      SageAPCopyBlockInfo* annot1 =
		(SageAPCopyBlockInfo*)(s)->getAttribute("SageAPCopyBlockInfo");
	      SageAPComputeBlockInfo* annot2 =
		(SageAPComputeBlockInfo*)(s)->getAttribute
		("SageAPComputeBlockInfo");
	      if (!annot1 && !annot2)
		{
		  if (verbose >= 1)
		    std::cout << "NO ANNOT!" << std::endl;
		  continue;
		}
	      if (annot1 && annot1->type == 4)
		{
		  prefetch.push_back(s);
		}
	      else if (annot2)
		{
		  compute.push_back(s);
		}
	      else if (annot1 && annot1->type == 2)
		{
		  copyout.push_back(s);
		}
	      else
		{
		  copyin.push_back(s);
		}
	    }
	  if (! prefetch.size() || ! compute.size())
	    continue;
	  SgBasicBlock* bbf = SageBuilder::buildBasicBlock();
	  for (std::vector<SgNode*>::iterator j = prefetch.begin();
	       j != prefetch.end(); ++j)
	    bbf->prepend_statement(isSgStatement(*j));
	  SgBasicBlock* bbo = SageBuilder::buildBasicBlock();
	  for (std::vector<SgNode*>::iterator j = copyout.begin();
	       j != copyout.end(); ++j)
	    bbo->prepend_statement(isSgStatement(*j));
	  for (std::vector<SgNode*>::iterator j = compute.begin();
	       j != compute.end(); ++j)
	    bbo->prepend_statement(isSgStatement(*j));
	  for (std::vector<SgNode*>::iterator j = copyin.begin();
	       j != copyin.end(); ++j)
	    bbo->prepend_statement(isSgStatement(*j));
	  // 6- Mark both BB as outlinable.
	  toOutline.insert(bbf);
	  toOutline.insert(bbo);
	  parCalls[bbf] = bbo;
	  // 7- Re-insert.
	  SgBasicBlock* newbb = SageBuilder::buildBasicBlock
	    (SageBuilder::buildBasicBlock(bbf), SageBuilder::buildBasicBlock(bbo));
	  SageInterface::replaceStatement(bb, newbb, true);
	}

      // 8- Outline them.
      std::set<SgBasicBlock*> outL;
      for (std::set<SgBasicBlock*>::iterator i = toOutline.begin();
	   i != toOutline.end(); ++i)
	{
	  SgNode* s = SageInterface::getEnclosingNode<SgFunctionDefinition>(*i);
	  ROSE_ASSERT(s);
	  std::set<SgBasicBlock*> res = computeOutlinableBBpass2(s, toOutline);
	  outL.insert(res.begin(), res.end());
	}
      for (std::set<SgBasicBlock*>::iterator i = outL.begin(); i != outL.end();
	   ++i)
	{
	  Outliner::enable_classic=true;
	  //  Outliner::enable_liveness=true;
	  Outliner::enable_liveness=false;
	  // Outliner::preprocess(*i);
	  Outliner::Result r = Outliner::outline(*i);
	  mapCall[*i] = r.call_;
	  vecDecl.push_back(r.decl_);
	  // Insert pragma no-unroll.
	  SgStatementPtrList stmts =
	    r.decl_->get_definition()->get_body()->get_statements();
	  if (stmts.size())
	    {
	      std::string p1("#pragma AP inline self off");
	      SgStatement* first = *(stmts.begin());
	      SageInterface::attachArbitraryText(first, p1,
						 PreprocessingInfo::before);
	    }
	}


      if (verbose >= 1)
	std::cout << "Stage 5" << std::endl;
    }


  // 4- Produce dependence graph.
  std::ofstream depgraph;
  depgraph.open("depgraph.txt");
  std::map<SgBasicBlock*, SgBasicBlock*>::iterator mit2;
  for (mit2 = parCalls.begin(); mit2 != parCalls.end(); ++mit2)
    {
      SgNode* n1 = mapCall[mit2->first];
      SgNode* n2 = mapCall[mit2->second];
      if (! n1 || ! n2)
	continue;
      // SgFunctionDeclaration* f1 = isSgFunctionDeclaration(n1);
      // SgFunctionDeclaration* f2 = isSgFunctionDeclaration(n1);
      // ROSE_ASSERT(f1 && f2);
      std::cout << (n1)->unparseToCompleteString()
		<< " ASYNC "
		<< (n2)->unparseToCompleteString()
		<< std::endl;
      depgraph << (n1)->unparseToCompleteString()
	       << " ASYNC "
	       << (n2)->unparseToCompleteString()
	       << std::endl;
    }

  // std::map<SgBasicBlock*, std::vector<SgStatement*> >::iterator mit;
  // for (mit = allCalls.begin(); mit != allCalls.end(); ++mit)
  //   {
  //     std::vector<SgNode*> forLoops =
  // 	NodeQuery::querySubTree(mit->first, V_SgForStatement);
  //     std::vector<SgNode*> ifS =
  // 	NodeQuery::querySubTree(mit->first, V_SgIfStmt);
  //     // Skip bb which contain loops or conditionals.
  //     if (forLoops.size() || ifS.size())
  // 	continue;

  //     // Collect the async prefetches and computes.
  //     std::vector<SgNode*> calls =
  // 	NodeQuery::querySubTree(mit->first, V_SgStatement);
  //     //std::vector<SgStatement*> calls = mit->second;
  //     std::vector<SgStatement*> async_pref;
  //     std::vector<SgStatement*> compute;
  //     std::vector<SgStatement*> others;
  //     for (std::vector<SgNode*>::iterator i = calls.begin();
  // 	   i != calls.end(); ++i)
  // 	{
  // 	  SgStatement* stm = isSgStatement(*i);
  // 	  ROSE_ASSERT(stm);
  // 	  SageAPCopyBlockInfo* annot1 =
  // 	    (SageAPCopyBlockInfo*)(stm)->getAttribute("SageAPCopyBlockInfo");
  // 	  SageAPComputeBlockInfo* annot2 =
  // 	    (SageAPComputeBlockInfo*)(stm)->getAttribute
  // 	    ("SageAPComputeBlockInfo");
  // 	  if (annot1 && annot1->type == 4)
  // 	    async_pref.push_back(stm);
  // 	  else if (annot2)
  // 	    compute.push_back(stm);
  // 	  else
  // 	    others.push_back(stm);
  // 	}
  //     // Check if we have a non-blocking prefetch and computation to
  //     // parallelize.
  //     if (async_pref.size() == 0 || compute.size() == 0)
  // 	continue;

  //     // Dependences:
  //     // (1) all pre-fetch are parallel with all computes.
  //     // (2) all wait_sems depends on their respective pre-fetch.
  //     std::cout << "Parallel calls: " << std::endl;
  //     for (std::vector<SgStatement*>::iterator i = async_pref.begin();
  // 	   i != async_pref.end(); ++i)
  // 	for (std::vector<SgStatement*>::iterator j = compute.begin();
  // 	     j != compute.end(); ++j)
  // 	  {
  // 	    SgFunctionCallExp* f1 =
  // 	      isSgFunctionCallExp(isSgExprStatement(*i)->get_expression());
  // 	    SgFunctionCallExp* f2 =
  // 	      isSgFunctionCallExp(isSgExprStatement(*j)->get_expression());
  // 	    std::cout << (f1)->unparseToCompleteString()
  // 		      << " ASYNC "
  // 		      << (f2)->unparseToCompleteString()
  // 		      << std::endl;
  // 	    depgraph << (f1)->unparseToCompleteString()
  // 		      << " ASYNC "
  // 		      << (f2)->unparseToCompleteString()
  // 		      << std::endl;
  // 	  }
  //     // std::cout << "BB: " << std::endl;
  //     // std::cout << mit->first->unparseToCompleteString() << std::endl;
  //   }
  depgraph.close();

  // // Remove all bb containing only 1 bb.
  // for (std::vector<SgFunctionDeclaration*>::iterator i = vecDecl.begin();
  //      i != vecDecl.end(); ++i)
  //   {
  //     SgFunctionDefinition* f = isSgFunctionDeclaration(*i)->get_definition();
  //     ROSE_ASSERT(f);
  //     std::vector<SgNode*> allbbs =
  // 	NodeQuery::querySubTree(f->get_body(), V_SgBasicBlock);
  //     for (std::vector<SgNode*>::iterator j = allbbs.begin();
  // 	   j != allbbs.end(); ++j)
  // 	{
  // 	  SgBasicBlock* bb = isSgBasicBlock(*j);
  // 	  ROSE_ASSERT(bb);
  // 	  SgStatementPtrList stmts = bb->get_statements();
  // 	  if (stmts.size() == 1)
  // 	    {
  // 	      SgBasicBlock* inbb = isSgBasicBlock(*(stmts.begin()));
  // 	      if (inbb)
  // 		SageInterface::replaceStatement(bb, inbb, true);
  // 	    }
  // 	}
  //   }
  // SgNode* funcDefMain2 =
  //   SageInterface::getEnclosingNode<SgFunctionDefinition>(root);
  // ROSE_ASSERT(funcDefMain2);
  // SgFunctionDefinition* fdM2 = isSgFunctionDefinition(funcDefMain2);
  // ROSE_ASSERT(fdM2);
  // std::vector<SgNode*> allbbs =
  //   NodeQuery::querySubTree(fdM2->get_body(), V_SgBasicBlock);
  // for (std::vector<SgNode*>::iterator j = allbbs.begin();
  //      j != allbbs.end(); ++j)
  //   {
  //     SgBasicBlock* bb = isSgBasicBlock(*j);
  //     ROSE_ASSERT(bb);
  //     SgStatementPtrList stmts = bb->get_statements();
  //     if (stmts.size() == 1)
  // 	{
  // 	  SgBasicBlock* inbb = isSgBasicBlock(*(stmts.begin()));
  // 	  if (inbb)
  // 	    {
  // 	      SageInterface::replaceStatement(bb, inbb, true);
  // 	    }
  // 	}
  //   }

  // Remove all dereference in the function bodies.
  for (std::vector<SgFunctionDeclaration*>::iterator i = vecDecl.begin();
       i != vecDecl.end(); ++i)
    {
      SgFunctionDefinition* f = isSgFunctionDeclaration(*i)->get_definition();
      ROSE_ASSERT(f);
      std::vector<SgNode*> ptrs = getAddr(f->get_body());
      for (std::vector<SgNode*>::iterator j = ptrs.begin(); j != ptrs.end();
	   ++j)
	{
	  SgAddressOfOp* op = isSgAddressOfOp(*j);
	  ROSE_ASSERT(op);
	  SageInterface::replaceExpression(op, op->get_operand_i(), true);
	}
      ptrs = getDeref(f->get_body());
      for (std::vector<SgNode*>::iterator j = ptrs.begin(); j != ptrs.end();
	   ++j)
	{
	  SgPointerDerefExp* op = isSgPointerDerefExp(*j);
	  ROSE_ASSERT(op);
	  SageInterface::replaceExpression(op, op->get_operand_i(), true);
	}
    }
  SgNode* funcDefMain =
    SageInterface::getEnclosingNode<SgFunctionDefinition>(root);
  ROSE_ASSERT(funcDefMain);
  SgFunctionDefinition* fdM = isSgFunctionDefinition(funcDefMain);
  std::vector<SgNode*> ptrs = getAddr(fdM->get_body());
  for (std::vector<SgNode*>::iterator j = ptrs.begin(); j != ptrs.end();
       ++j)
    {
      SgAddressOfOp* op = isSgAddressOfOp(*j);
      ROSE_ASSERT(op);
      SageInterface::replaceExpression(op, op->get_operand_i(), true);
    }
  ptrs = getDeref(fdM->get_body());
  for (std::vector<SgNode*>::iterator j = ptrs.begin(); j != ptrs.end();
       ++j)
    {
      SgPointerDerefExp* op = isSgPointerDerefExp(*j);
      ROSE_ASSERT(op);
      SageInterface::replaceExpression(op, op->get_operand_i(), true);
    }


  if (verbose >= 1)
    std::cout << "Stage 6" << std::endl;


  // Replace all loop upper bounds with a constant expression.
  // Remove all dereference in the function bodies.
  int varcount = 0;
  std::string proto("__local__ub_");
  for (std::vector<SgFunctionDeclaration*>::iterator i = vecDecl.begin();
       i != vecDecl.end(); ++i)
    {


      SgFunctionDefinition* f = isSgFunctionDeclaration(*i)->get_definition();
      ROSE_ASSERT(f);

      // Start by some simplifications of the AST.
      ASTSimplifications(f->get_body(),
			 polyoptions.getHLSLoopBoundSimplification(),
			 polyoptions.getHLSLoopInvariantRefHoisting(),
			 polyoptions.getHLSRefGVN(),
			 polyoptions.getHLSModuloSimplification());
    }
}



/**
 *
 *
 *
 */
void createAPMemBufMacroReferences(SgNode* root,
				   s_hlsir_t* pIR)
{
  // Nothing to translate.
  if (pIR->bufferized_symbols.size() == 0)
    return;


  //std::set<SgVariableSymbol*> buffer_symbols;
  // 1- Collect all array references.
  Rose_STL_Container<SgNode*> arrefs =
    NodeQuery::querySubTree(root, V_SgPntrArrRefExp);
  std::vector<SgNode*> readRefs;
  std::vector<SgNode*> writeRefs;
  if (! SageTools::collectReadWriteRefs(isSgStatement(root),
					readRefs, writeRefs, true))
    ROSE_ASSERT(0);
  std::set<SgNode*> isReadRef;
  isReadRef.insert(readRefs.begin(), readRefs.end());

  SgScopeStatement* scope = isSgScopeStatement(root);
  std::map<SgVariableSymbol*, SgFunctionDeclaration*> declMapR;
  std::map<SgVariableSymbol*, SgFunctionDeclaration*> declMapW;

  // std::cout << "Run consistency tests: " << std::endl;
  // AstTests::runAllTests(SageInterface::getProject());

  // Compute fake function prototypes to emulate the macro call.
  for (std::set<SgVariableSymbol*>::iterator i = pIR->bufferized_symbols.begin();
       i != pIR->bufferized_symbols.end(); ++i)
    {
      SgVariableSymbol* s = *i;
      SgType* array_type = isSgArrayType(s->get_type());
      if (! array_type)
  	continue;
      SgType* tmp = array_type;
      int array_dim = 0;
      std::vector<SgExpression*> tlist;
      tlist.push_back(SageBuilder::buildVarRefExp(s));
      while (tmp && isSgArrayType(tmp))
  	{
  	  tmp = isSgArrayType(tmp)->get_base_type();
  	  ++array_dim;
  	  tlist.push_back(isSgExpression(SageBuilder::buildIntVal(0)));
  	}
      std::string readd("MemBusRead");
      std::ostringstream oss;
      oss << array_dim;
      readd += oss.str();
      readd += "D";
      std::string writed ("MemBusWrite");
      writed += oss.str();
      writed += "D";
      SgName fnR(readd);
      SgName fnW(writed);
      SgType* basetype = isSgType(SageInterface::deepCopy(tmp));
      SgExprListExp* alist = SageBuilder::buildExprListExp(tlist);
      SgFunctionParameterTypeList* ptl =
  	SageBuilder::buildFunctionParameterTypeList(alist);
      SgFunctionParameterList* plist1 =
  	SageBuilder::buildFunctionParameterList(ptl);
      SgFunctionParameterList* plist2 =
  	SageBuilder::buildFunctionParameterList(ptl);
      SgFunctionDeclaration* fdeclR =
  	SageBuilder::buildNondefiningFunctionDeclaration(fnR, basetype,
  							 plist1, scope);
      SgFunctionDeclaration* fdeclW =
  	SageBuilder::buildNondefiningFunctionDeclaration(fnW, basetype,
  							 plist2, scope);
      declMapR[*i] = fdeclR;
      declMapW[*i] = fdeclW;
    }
  // 2- Replace them with the MemBusRead/Write macro.
  for (Rose_STL_Container<SgNode*>::iterator i = arrefs.begin();
       i != arrefs.end(); ++i)
    {
      SgPntrArrRefExp* ref = isSgPntrArrRefExp(*i);
      // Find symbol.
      SgNode* tmp = ref;
      while (isSgPntrArrRefExp(tmp))
  	tmp = isSgPntrArrRefExp(tmp)->get_lhs_operand();
      SgVarRefExp* vref = isSgVarRefExp(tmp);
      /// FIXME: Should never be null, but it seems it can be (dotexp?)
      if (vref == NULL)
  	continue;
      ROSE_ASSERT(vref);
      if (pIR->bufferized_symbols.find(vref->get_symbol()) !=
  	  pIR->bufferized_symbols.end())
  	{
  	  std::vector<SgExpression*> exprs;
  	  SgNode* tmp2 = ref;
  	  while (isSgPntrArrRefExp(tmp2))
  	    {
  	      exprs.insert(exprs.begin(),
  			   SageInterface::deepCopy
  			   (isSgPntrArrRefExp(tmp2)->get_rhs_operand()));
  	      tmp2 = isSgPntrArrRefExp(tmp2)->get_lhs_operand();
  	    }
  	  exprs.insert(exprs.begin(), NULL);
  	  exprs[0] = isSgExpression(SageInterface::deepCopy(tmp2));
  	  ROSE_ASSERT(exprs[0]);
  	  SgExprListExp* explist = SageBuilder::buildExprListExp(exprs);
  	  SgName name;
  	  if (isReadRef.find(ref) != isReadRef.end())
  	    name = declMapR[vref->get_symbol()]->get_name();
  	  else
  	    name = declMapW[vref->get_symbol()]->get_name();
  	  SgFunctionSymbol* fs =
  	    SageInterface::lookupFunctionSymbolInParentScopes(name, scope);
  	  SgFunctionCallExp* fc =
  	    SageBuilder::buildFunctionCallExp(fs, explist);
  	  SageInterface::replaceExpression(ref, fc);


	  // SgExpression* nexpr = NULL;
	  // for (std::vector<SgExpression*>::iterator l = exprs.begin();
	  //      l != exprs.end(); ++l)
	  //   {
	  //     if (nexpr == NULL)
	  // 	nexpr = *l;
	  //     else
	  // 	nexpr = SageBuilder::buildBinaryExpression<SgAddOp>
	  // 	  (nexpr, SageBuilder::buildBinaryExpression<SgMultiplyOp>
	  // 	   (SageBuilder::buildOpaqueVarRefExp("__offset", isSgScopeStatement(root)), *l));

	  //   }
  	  // SageInterface::replaceExpression(ref, nexpr);


  	}
    }

  // 3- Insert memory access latency macro.
  Rose_STL_Container<SgNode*> cpbb =
    NodeQuery::querySubTree(root, V_SgBasicBlock);
  for (Rose_STL_Container<SgNode*>::iterator i = cpbb.begin(); i != cpbb.end();
       ++i)
    {
      SageAPCopyBlockInfo* annot =
  	(SageAPCopyBlockInfo*)(*i)->getAttribute("SageAPCopyBlockInfo");
      if (annot)
  	{
  	  SgExprStatement* s =
  	    SageBuilder::buildExprStatement
  	    (SageBuilder::buildOpaqueVarRefExp("CommLatencyIncrease",
  					       isSgScopeStatement(root)));
  	  SgBasicBlock* bb = isSgBasicBlock(*i);
  	  ROSE_ASSERT(bb);
  	  bb->prepend_statement(s);
  	}
    }
}

std::vector<SgNode*>
postTraversalCollect(SgNode* dup, VariantT thetype)
{
  class OBBVisitor : public AstPrePostOrderTraversal {
  public:
    virtual void preOrderVisit(SgNode* node) {};
    virtual void postOrderVisit(SgNode* node) {
      if (node->variantT() == _type)
	_res.push_back(node);
    }
    std::vector<SgNode*> _res;
    VariantT _type;
  };

  std::vector<SgNode*> res;
  OBBVisitor vis;
  vis._res = res;
  vis._type = thetype;
  vis.traverse(dup);

  return vis._res;
}



/**
 *
 *
 */
static
SgNode* createAddrGenCode(SgNode* scopRoot)
{

  // 1- Duplicate.
  SgNode* dup = SageInterface::deepCopy(scopRoot);

  // 2- Remove array declarations.
  std::vector<SgNode*> decls =
    NodeQuery::querySubTree(dup, V_SgVariableDeclaration);
  for (std::vector<SgNode*>::iterator i = decls.begin(); i != decls.end();
       ++i)
    {
      SageAPDeclarationInfo* annot = (SageAPDeclarationInfo*)
	(*i)->getAttribute("SageAPDeclarationInfo");
      if (annot)
      	SageInterface::removeStatement(isSgStatement(*i), true);
    }

  // 3- Remove all compute statements.
  std::vector<SgNode*> cps =
    NodeQuery::querySubTree(dup, V_SgExprStatement);
  for (std::vector<SgNode*>::iterator i = cps.begin(); i != cps.end(); ++i)
    {
      SageAPCopyStmtInfo* annotc = (SageAPCopyStmtInfo*)
	(*i)->getAttribute("SageAPCopyStmtInfo");
      if (! annotc)
	{
	  SgNode* parent = (*i)->get_parent();
	  // Check if it is a statement in a copy block.
	  while (parent && parent != dup)
	    {
	      while (parent && ! isSgBasicBlock(parent))
		parent = parent->get_parent();
	      SageAPCopyBlockInfo* annotc = (SageAPCopyBlockInfo*)
		parent->getAttribute("SageAPCopyBlockInfo");
	      if (annotc)
		break;
	      parent = parent->get_parent();
	    }
	  if (! parent || parent == dup)
	    if (SageInterface::getEnclosingNode<SgForInitStatement>(*i) == NULL)
	      SageInterface::removeStatement(isSgStatement(*i), true);
	}
    }
  // Clean loops/conditionals/bbs with empty body.
  std::vector<SgNode*> flps =
    postTraversalCollect(dup, V_SgForStatement);
  for (std::vector<SgNode*>::iterator i = flps.begin(); i != flps.end(); ++i)
    {
      SgForStatement* fs = isSgForStatement(*i);
      ROSE_ASSERT(fs);
      std::vector<SgNode*> stmts =
  	NodeQuery::querySubTree(fs->get_loop_body(), V_SgExprStatement);
      if (stmts.size() == 0)
  	SageInterface::removeStatement(fs, true);
    }
  std::vector<SgNode*> ifs =
    postTraversalCollect(dup, V_SgIfStmt);
  for (std::vector<SgNode*>::iterator i = ifs.begin(); i != ifs.end(); ++i)
    {
      SgIfStmt* ifs = isSgIfStmt(*i);
      ROSE_ASSERT(ifs);
      std::vector<SgNode*> stmts =
  	NodeQuery::querySubTree(ifs->get_true_body(), V_SgExprStatement);
      if (stmts.size() == 0)
  	SageInterface::removeStatement(ifs, true);
    }
  std::vector<SgNode*> ebbs =
    postTraversalCollect(dup, V_SgBasicBlock);
  for (std::vector<SgNode*>::iterator i = ebbs.begin(); i != ebbs.end(); ++i)
    {
      SgBasicBlock* bb = isSgBasicBlock(*i);
      ROSE_ASSERT(bb);
      SgStatementPtrList& stmts = bb->get_statements();
      if (stmts.size() == 0)
  	SageInterface::removeStatement(bb, true);
    }

  // 4- Remove all copy-out blocks.
  std::vector<SgNode*> bbs =
    NodeQuery::querySubTree(dup, V_SgBasicBlock);
  for (std::vector<SgNode*>::iterator i = bbs.begin(); i != bbs.end(); ++i)
    {
      SageAPCopyBlockInfo* annotc = (SageAPCopyBlockInfo*)
  	(*i)->getAttribute("SageAPCopyBlockInfo");
      if (annotc && annotc->type == 2)
      	SageInterface::removeStatement(isSgStatement(*i), true);
    }

  // 5- Change all types to async.
  std::vector<SgNode*> bbs2 =
    NodeQuery::querySubTree(dup, V_SgBasicBlock);
  for (std::vector<SgNode*>::iterator i = bbs2.begin(); i != bbs2.end(); ++i)
    {
      SageAPCopyBlockInfo* annotc = (SageAPCopyBlockInfo*)
  	(*i)->getAttribute("SageAPCopyBlockInfo");
      if (annotc)
	annotc->type = 3;
    }

  // 6- Outline the new BB.
  SgBasicBlock* ret = isSgBasicBlock(dup); //SageBuilder::buildBasicBlock(isSgStatement(dup));
  SageInterface::insertStatementBefore(isSgStatement(scopRoot), ret);

  // 7- Change all reads to async fetch in the original code.
  std::vector<SgNode*> bbs3 =
    NodeQuery::querySubTree(scopRoot, V_SgBasicBlock);
  for (std::vector<SgNode*>::iterator i = bbs3.begin(); i != bbs3.end(); ++i)
    {
      SageAPCopyBlockInfo* annotc = (SageAPCopyBlockInfo*)
  	(*i)->getAttribute("SageAPCopyBlockInfo");
      if (annotc && annotc->type == 0)
	annotc->type = 1;
    }


  // 8- hoist loop bounds.
  int varcount = 0;
  std::string proto("__local__ub_");
  std::vector<SgNode*> forLoops =
    NodeQuery::querySubTree(ret, V_SgForStatement);
  for (std::vector<SgNode*>::iterator j = forLoops.begin();
       j != forLoops.end(); ++j)
    {
      SgForStatement* fs = isSgForStatement(*j);
      ROSE_ASSERT(fs);
      SgExprStatement* test = isSgExprStatement(fs->get_test());
      ROSE_ASSERT(test);
      SgLessOrEqualOp* lop = isSgLessOrEqualOp(test->get_expression());
      if (lop)
	{

	  // std::cout <<fs->unparseToCompleteString() << std::endl;
	  SgScopeStatement* local_scope =
	    isSgScopeStatement(fs->get_parent());
	  std::ostringstream oss;
	  oss << varcount++;
	  std::string newit(proto);
	  newit += oss.str();
	  SgVariableDeclaration* decl =
	    SageBuilder::buildVariableDeclaration
	    (newit, SageBuilder::buildIntType(), NULL, local_scope);
	  // std::cout << "lop: " << std::endl;
	  // std::cout <<lop->unparseToCompleteString() << std::endl;
	  SgVarRefExp* vref = isSgVarRefExp(lop->get_lhs_operand());
	  ROSE_ASSERT(vref);
	  SgExpression* test = isSgExpression(lop->get_rhs_operand());
	  ROSE_ASSERT(test);
	  SgStatement* stm = SageBuilder::buildExprStatement
	    (SageBuilder::buildBinaryExpression<SgAssignOp>
	     (SageBuilder::buildVarRefExp
	      (SageInterface::getFirstVarSym(decl)),
	      SageInterface::deepCopy(test)));
	  SageInterface::replaceExpression
	    (test, SageBuilder::buildVarRefExp
	     (SageInterface::getFirstVarSym(decl)), true);
	  SageInterface::insertStatementBefore(fs, decl);
	  SageInterface::insertStatementBefore(fs, stm);
	}
    }

  return ret;
}


void eliminateBBinBB()
{
  SgProject* project = SageInterface::getProject();
  SgFilePtrList& file_list = project->get_fileList();
  SgFilePtrList::const_iterator file_iter;
  // Iterate on all files of the project.
  for (file_iter = file_list.begin(); file_iter != file_list.end(); file_iter++)
    {
      SgSourceFile* file = isSgSourceFile(*file_iter);
      SgNodePtrList funcDefnList =
	NodeQuery::querySubTree(file, V_SgFunctionDefinition);
      SgNodePtrList::const_iterator iter;
      for (iter = funcDefnList.begin(); iter != funcDefnList.end(); ++iter)
	{
	  SgFunctionDefinition *fun = isSgFunctionDefinition(*iter);
	  if (!fun)
	    continue; // with the next function definition
	  SgName name = fun->get_declaration()->get_name();
	  SgBasicBlock* body = fun->get_body();

	  std::vector<SgNode*> bbs = postTraversalCollect(body, V_SgBasicBlock);
	  for (std::vector<SgNode*>::iterator i = bbs.begin(); i != bbs.end();
	       ++i)
	    {
	      SgBasicBlock* bb = isSgBasicBlock(*i);
	      ROSE_ASSERT(bb);
	      SgStatementPtrList& stmts = bb->get_statements();
	      if (stmts.size() == 0)
		SageInterface::removeStatement(bb);
	      else if (stmts.size() == 1)
		{
		  SgBasicBlock* n = isSgBasicBlock(*(stmts.begin()));
		  if (n)
		    {
		      SageInterface::moveStatementsBetweenBlocks(n, bb);
		      SageInterface::removeStatement(n, true);
		    }
		}
	    }
	}
    }
}


void removeDerefInFdeclFdef(SgFunctionDeclaration* fundecl,
			    SgFunctionDefinition* funcDefMain)
{
  // Remove all dereference in the function bodies.
  SgFunctionDefinition* f = fundecl->get_definition();
  ROSE_ASSERT(f);
  {
    std::vector<SgNode*> ptrs = getAddr(f->get_body());
    for (std::vector<SgNode*>::iterator j = ptrs.begin(); j != ptrs.end();
	 ++j)
      {
	SgAddressOfOp* op = isSgAddressOfOp(*j);
	ROSE_ASSERT(op);
	SageInterface::replaceExpression(op, op->get_operand_i(), true);
      }
    ptrs = getDeref(f->get_body());
    for (std::vector<SgNode*>::iterator j = ptrs.begin(); j != ptrs.end();
	 ++j)
      {
	SgPointerDerefExp* op = isSgPointerDerefExp(*j);
	ROSE_ASSERT(op);
	SageInterface::replaceExpression(op, op->get_operand_i(), true);
      }
  }
  ROSE_ASSERT(funcDefMain);
  SgFunctionDefinition* fdM = isSgFunctionDefinition(funcDefMain);
  std::vector<SgNode*> ptrs = getAddr(fdM->get_body());
  for (std::vector<SgNode*>::iterator j = ptrs.begin(); j != ptrs.end();
       ++j)
    {
      SgAddressOfOp* op = isSgAddressOfOp(*j);
      ROSE_ASSERT(op);
      SageInterface::replaceExpression(op, op->get_operand_i(), true);
    }
  ptrs = getDeref(fdM->get_body());
  for (std::vector<SgNode*>::iterator j = ptrs.begin(); j != ptrs.end();
       ++j)
    {
      SgPointerDerefExp* op = isSgPointerDerefExp(*j);
      ROSE_ASSERT(op);
      SageInterface::replaceExpression(op, op->get_operand_i(), true);
    }
}



/**
 * Entry point for the High-Level Synthesis module.
 *
 *
 */
void optimizeSingleScopHLS(SgNode* scopRoot,
			   s_pocc_options_t* poptions,
			   s_pocc_utils_options_t* puoptions,
			   PolyRoseOptions& polyoptions, 
			   bool ScHLS)
{
  if (! polyoptions.getQuiet() && polyoptions.getASTConsistencyCheck())
    {
      std::cout << "Run consistency tests (1): " << std::endl;
      AstTests::runAllTests(SageInterface::getProject());
    }

  // (A) Get the polyhedral representation of the transformed code.
  ScopExtractor extractor (polyoptions);
  extractor.extractScops (scopRoot);
  std::vector<scoplib_scop_p> scops = extractor.getScoplibs();
  if (! polyoptions.getQuiet())
    std::cout << "[PolyOpt] Number of Sub-SCoPs: " << scops.size()
	      << std::endl;
  std::vector<scoplib_scop_p>::const_iterator sage_scop_iterator;

  // (B) Iterate on each sub-scop detected:
  int subScopId;
  s_hlsir_t* pIR = new s_hlsir_t();
  for (sage_scop_iterator = scops.begin (), subScopId = 1;
       sage_scop_iterator != scops.end ();
       ++sage_scop_iterator, ++subScopId)
    {
      // (B.1) Compute the HLSIR representation (past,sage,scop)
      scoplib_scop_p scop = *sage_scop_iterator;
      // s_pocc_options_t* passthru_poccopts = pocc_options_malloc ();
      // PolyRoseOptions passthru_polyopts;
      // s_past_node_t* pastRoot =
      // 	OptimizeSingleScopWithPoccPast (scop, passthru_poccopts,
      // 					puoptions, passthru_polyopts);
      // SgNode* tt = (SgNode*)scop->usr;
      pIR->sage = (SgNode*)scop->usr;
      // pIR->past = pastRoot;
      pIR->scop = scop;
      pIR->scope = scopRoot;


      // Re-extract the scop, to maintain pointer coherency in the
      // SCoP data structures.
      ScopExtractor extractorLocal (polyoptions);
      extractorLocal.extractScops (pIR->sage);
      std::vector<scoplib_scop_p> scops = extractorLocal.getScoplibs();
      if (scops.size() != 1)
	std::cout << "[PolyOpt][HLS] WARNING: more than 1 sub-scop!"
		  << std::endl;
      int pos = 1;
      for (std::vector<scoplib_scop_p>::iterator q = scops.begin();
	   q != scops.end(); ++q, ++pos)
	{
	  // Compute the DDVs for the scop.
	  bool bk = polyoptions.getHullifyDDV();
	  polyoptions.setHullifyDDV(true);
	  computeDDVinScop(*q, polyoptions);
	  polyoptions.setHullifyDDV(bk);
	  // Annotate parallel loops.
	  std::vector<SgNode*> forLoops =
	    NodeQuery::querySubTree((SgNode*)((*q)->usr), V_SgForStatement);
	  for (std::vector<SgNode*>::iterator pp = forLoops.begin(); 
	       pp != forLoops.end(); ++pp)
	    {
	      SageForInfo* annot =
		(SageForInfo*) (*pp)->getAttribute(SageForInfo::name());
	      if (annot == NULL)
		  continue;
	      if (annot->ddvs.size())
		  if (annot->ddvs[0].isEq(annot->ddvs[0].getSize() - 1))
		      annot->isParallel = true;
	    }

	  std::cout << "[PolyOpt][HLS] Do Local Memory Promotion (LMP) on sub-scop #"
		    << subScopId << ", " << pos << std::endl;

	  scop = *q;
	  //passthru_poccopts = pocc_options_malloc ();
	  s_past_node_t* pastRootT = NULL;
	  // OptimizeSingleScopWithPoccPast (scop, passthru_poccopts,
	  // 				    puoptions, passthru_polyopts);

	  pIR->scop = scop;
	  pIR->past = pastRootT;
	  pIR->max_buffer_size_per_array =
	    polyoptions.getHLSMaxBuffSizePerArray();

	  pIR->sage = (SgNode*)scop->usr;

	   //std::cout << "BEFORE ALL:" << std::endl;
	   //std::cout << pIR->sage->unparseToCompleteString() << std::endl;
	  SageInterface::rebuildSymbolTable(isSgScopeStatement(pIR->sage));
	   //std::cout << "BEFORE AP:" << std::endl;
	   //std::cout << pIR->sage->unparseToCompleteString() << std::endl;

	  // Insert Autopilot Pipeline pragmas to all inner-most loops.
	  if (polyoptions.getHLSautopilot())
	    {
	      if (! polyoptions.getQuiet())
		std::cout << "[PolyOpt][HLS] Format the program for AutoPilot"
			  << std::endl;
	      createAPPipelinePragmas(pIR->sage);
	    }

	  // std::cout << "AFTER AP:" << std::endl;
	  // std::cout << pIR->sage->unparseToCompleteString() << std::endl;

	  // (B.4) Apply Local Memory Promotion.
	  if (polyoptions.getHLSLMP())
	    {
	      if (! polyoptions.getQuiet())
		std::cout << "[PolyOpt][HLS] Apply Local Memory Promotion"
			  << std::endl;
	      s_lmp_options_t* lmp_opts = lmp_options_malloc();
	      if (polyoptions.getHLSPrefetchFun())
		{
		  std::cout << "[PolyOpt][HLS] Warning: the use of a prefetch function is incompatible with the CPU FIFO simulation harness"
			    << std::endl;
		  lmp_opts->use_prefetch = 0;
		}

	      /// FIXME: LNP: simple hull may lead to over-approximate
	      /// comm, that does not fit into the originally declared
	      /// array. So, no hull should be used!
	      /// FIXME2: Now hull is embedded in lmp by default where
	      /// appropriate, option is now useless.
	      lmp_opts->simple_hull = 0;

	      lmp_opts->commsched_mode = LMP_COMMSCHED_TILEBOUND;
	      if (polyoptions.getHLSCostFunctionBSL())
		{
		  std::cout << "[PolyOpt][HLS] Warning: BSL objective is experimental"
			    << std::endl;
		  lmp_opts->commsched_mode = LMP_COMMSCHED_BSL;
		}

	      if (! polyoptions.getQuiet() && polyoptions.getASTConsistencyCheck())
		{
		  std::cout << "Run consistency tests (2.1): " << std::endl;
		  AstTests::runAllTests(SageInterface::getProject());
		}
	      /// Call LMP module of PoCC.
	      if(ScHLS){
	      	lmp_driver_wei (pIR, lmp_opts);
	      }
	      else 
	      	lmp_driver(pIR, lmp_opts);

	      if (! polyoptions.getQuiet())
		std::cout << "[PolyOpt][HLS] Done with Local Memory Promotion"
			  << std::endl;
	      if (! polyoptions.getQuiet() && polyoptions.getASTConsistencyCheck())
		{
		  std::cout << "Run consistency tests (2.2): " << std::endl;
		  AstTests::runAllTests(SageInterface::getProject());
		}
	    }
	  // Be clean.
	  //past_deep_free (pastRoot);
	}
    }
    if (polyoptions.getHLSAPPragmaTripcount() )
      {
	if (! polyoptions.getQuiet())
	  std::cout << "[PolyOpt][HLS] Insert AutoPilot pragmas for tripcount"
		    << std::endl;
	createAPPTripCountPragmasV2();
      }


  /*
  /// Hard-coded options.
  bool use2float = polyoptions.getHLSUsefloat2();
  if (polyoptions.getHLSautopilot())
    {
      if (polyoptions.getHLSautopilotMembus())
  	{
  	    std::cout << "[PolyOpt][HLS] WARNING membus generation is not supported anymore. Result is unpredictable"
  		      << std::endl;
	  createAPPTripCountPragmas(scopRoot);
  	  if (! polyoptions.getQuiet())
  	    std::cout << "[PolyOpt][HLS] Use the MemBuf macro"
  		      << std::endl;
  	  // Use the MemBuf macro instead of the original array references.
  	  createAPMemBufMacroReferences(scopRoot, pIR);
  	  createAPMemBusFuncPragmas(scopRoot);
  	}
      if (polyoptions.getHLSautopilotFifo())
  	{
  	  if (! polyoptions.getQuiet())
  	    std::cout << "[PolyOpt][HLS] Use the FIFO AP framework"
  		      << std::endl;

	  if (polyoptions.getHLSPrefetchFun())
	    {
	      if (! polyoptions.getQuiet())
		std::cout << "[PolyOpt][HLS] Create FIFO calls for communication prefetch"
			  << std::endl;
	      // Deal with the prefetch function here.
	      SgNode* addrgen = createAddrGenCode(scopRoot);
	      createAPFifoCode(addrgen, pIR,
			       polyoptions.getHLSautopilotFifoSimu(),
			       false,
			       use2float, polyoptions);
	      SgBasicBlock* bbcp = isSgBasicBlock(addrgen);

	      ROSE_ASSERT(bbcp);
	      if (Outliner::isOutlineable(bbcp))
		{
		  if (! polyoptions.getQuiet())
		    {
		      std::cout << "[PolyOpt][HLS] Outline communication calls in separate functions"
				<< std::endl;
		      std::cout << "[PolyOpt][HLS] INFO: the message \"error in side effect analysis!\" can be safely ignored"
				<< std::endl;
		    }

  	      // std::cout << "to outline: " << std::endl;
  	      // std::cout << bbcp->unparseToCompleteString() << std::endl;
		  Outliner::enable_classic=true;
		  //Outliner::enable_liveness=true;
		  Outliner::enable_liveness=false;
		  Outliner::preprocess(bbcp);
		  Outliner::Result r = Outliner::outline(bbcp);
		  removeDerefInFdeclFdef
		    (r.decl_, SageInterface::getEnclosingNode
		     <SgFunctionDefinition>(r.call_));

		  // std::cout << "prefecth_funcs: " << r.call_->unparseToCompleteString() << std::endl;

		  ASTSimplifications(r.decl_,
				     polyoptions.getHLSLoopBoundSimplification(),
				     polyoptions.getHLSLoopInvariantRefHoisting(),
				     polyoptions.getHLSRefGVN(),
				     polyoptions.getHLSModuloSimplification());
		}
	    }

	  if (! polyoptions.getQuiet())
	    {
	      std::cout << "[PolyOpt][HLS] Create FIFO calls for communications"
			<< std::endl;
	      std::cout << "[PolyOpt][HLS] INFO: the message \"error in side effect analysis!\" can be safely ignored"
			<< std::endl;
	    }
  	  // Use the AP Fifo mechanism instead of the original array
  	  //references. Assumption: there is a fifo named xx_r and
  	  //xx_w for all array xx which is being read and written.
  	  createAPFifoCode(scopRoot, pIR,
  			   polyoptions.getHLSautopilotFifoSimu(), true,
			   use2float, polyoptions);
	  if (! polyoptions.getQuiet())
	    {
	      std::cout << "[PolyOpt][HLS] Outline communication calls in separate functions"
			<< std::endl;
	      std::cout << "[PolyOpt][HLS] INFO: the message \"error in side effect analysis!\" can be safely ignored"
			<< std::endl;
	    }
  	  SgBasicBlock* bbcp2 = isSgBasicBlock(scopRoot);

  	  ROSE_ASSERT(bbcp2);
  	  if (Outliner::isOutlineable(bbcp2))
  	    {
	      if (! polyoptions.getQuiet())
		std::cout << "[PolyOpt][HLS] Outline communication calls in separate functions"
			  << std::endl;

  	      Outliner::enable_classic=true;
  	      //Outliner::enable_liveness=true;
	      Outliner::enable_liveness=false;
  	      Outliner::preprocess(bbcp2);
  	      Outliner::Result r = Outliner::outline(bbcp2);
  	      removeDerefInFdeclFdef
  		(r.decl_, SageInterface::getEnclosingNode
  		 <SgFunctionDefinition>(r.call_));

	      if (! polyoptions.getQuiet())
		std::cout << "[PolyOpt][HLS] AST simplifications"
			  << std::endl;
	      ASTSimplifications(r.decl_,
				 polyoptions.getHLSLoopBoundSimplification(),
				 polyoptions.getHLSLoopInvariantRefHoisting(),
				 polyoptions.getHLSRefGVN(),
				 polyoptions.getHLSModuloSimplification());

  	    }

	  // Useless now?
  	  eliminateBBinBB();


	  if (polyoptions.getHLSAPPragmaDepFalse())
	    {
	      if (! polyoptions.getQuiet())
		std::cout << "[PolyOpt][HLS] Insert AutoPilot pragmas dep=false"
			  << std::endl;
	      createAPNoDepPragmas();
	    }
	  if (polyoptions.getHLSAPPragmaTripcount())
	    {
	      if (! polyoptions.getQuiet())
		std::cout << "[PolyOpt][HLS] Insert AutoPilot pragmas for tripcount"
			  << std::endl;
	      createAPPTripCountPragmasV2();
	    }

  	  // SageInterface::insertStatementBefore(isSgStatement(scopRoot),
  	  // 				       isSgStatement(addrgen));
  	}
    }
*/
}
