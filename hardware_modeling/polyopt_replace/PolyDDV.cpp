/*
 * PolyDDV.cpp: This file is part of the PolyOpt project.
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
 * @file: PolyDDV.cpp
 * @author: Louis-Noel Pouchet <pouchet@cse.ohio-state.edu>
 */

#include <vector>
#include <iostream>
#include <ostream>

#include <polyopt/PolyDDV.hpp>

#include <Cxx_Grammar.h>
#include <AstTraversal.h>
#include <polyopt/SageNodeAnnotation.hpp>
#ifndef LINEAR_VALUE_IS_LONGLONG
# define LINEAR_VALUE_IS_LONGLONG
#endif
#include <candl/candl.h>



PolyDDV::PolyDDV(int size)
{
  _dep_type = poly_ddv_undef;
  _types = std::vector<e_poly_ddv_type>(size);
  _values = std::vector<int>(size);
  int i;
  for (i = 0; i < size; ++i)
    {
      _types[i] = poly_ddv_star;
      _values[i] = 0;
    }
  _loop_ptr = NULL;
}

PolyDDV::PolyDDV(int size, void* ptr)
{
  _dep_type = poly_ddv_undef;
  _types = std::vector<e_poly_ddv_type>(size);
  _values = std::vector<int>(size);
  int i;
  for (i = 0; i < size; ++i)
    {
      _types[i] = poly_ddv_star;
      _values[i] = 0;
    }
  _loop_ptr = ptr;
}


PolyDDV::~PolyDDV()
{

}


void PolyDDV::setLoopPtr(void* ptr)
{
  _loop_ptr = ptr;
}

void* PolyDDV::getLoopPtr() const
{
  return _loop_ptr;
}

int PolyDDV::getSize() const
{
  return _types.size();
}


void PolyDDV::setRAW()
{
  _dep_type = poly_ddv_raw;
}

void PolyDDV::setWAR()
{
  _dep_type = poly_ddv_war;
}

void PolyDDV::setWAW()
{
  _dep_type = poly_ddv_waw;
}

void PolyDDV::setRAR()
{
  _dep_type = poly_ddv_rar;
}

bool PolyDDV::isRAW() const
{
  return _dep_type == poly_ddv_raw;
}

bool PolyDDV::isWAR() const
{
  return _dep_type == poly_ddv_war;
}

bool PolyDDV::isWAW() const
{
  return _dep_type == poly_ddv_waw;
}

bool PolyDDV::isRAR() const
{
  return _dep_type == poly_ddv_rar;
}


void PolyDDV::setPlus(int pos)
{
  _types[pos] = poly_ddv_plus;
}

void PolyDDV::setMinus(int pos)
{
  _types[pos] = poly_ddv_minus;
}

void PolyDDV::setStar(int pos)
{
  _types[pos] = poly_ddv_star;
}

void PolyDDV::setEq(int pos)
{
  _types[pos] = poly_ddv_eq;
}

void PolyDDV::setScalar(int pos, int value)
{
  _types[pos] = poly_ddv_scalar;
  _values[pos] = value;
}

bool PolyDDV::isPlus(int pos) const
{
  return _types[pos] == poly_ddv_plus;
}

bool PolyDDV::isMinus(int pos) const
{
  return _types[pos] == poly_ddv_minus;
}

bool PolyDDV::isStar(int pos) const
{
  return _types[pos] == poly_ddv_star;
}

bool PolyDDV::isEq(int pos) const
{
  return _types[pos] == poly_ddv_eq;
}

bool PolyDDV::isScalar(int pos) const
{
  return _types[pos] == poly_ddv_scalar;
}

int PolyDDV::getScalar(int pos) const
{
  return _values[pos];
}

bool PolyDDV::isIdenticalVector(PolyDDV& ddv)
{
  if (ddv.getSize() != _types.size())
    return false;
  int i;
  for (i = 0; i < ddv.getSize(); ++i)
    {
      if (ddv.isPlus(i) && ! isPlus(i))
	return false;
      else if (ddv.isMinus(i) && ! isMinus(i))
	return false;
      else if (ddv.isStar(i) && ! isStar(i))
	return false;
      else if (ddv.isEq(i) && ! isEq(i))
	return false;
      else if (ddv.isScalar(i))
	{
	  if (! isScalar(i) || getScalar(i) != ddv.getScalar(i))
	    return false;
	}
    }

  return true;
}

bool PolyDDV::isPureIdentical(PolyDDV& ddv)
{
  if (! isIdenticalVector(ddv))
    return false;
  if (ddv.isRAW() && ! isRAW())
    return false;
  else if (ddv.isWAR() && ! isWAR())
    return false;
  else if (ddv.isWAW() && ! isWAW())
    return false;
  else if (ddv.isRAR() && ! isRAR())
    return false;

  return true;
}


void PolyDDV::computeHull(PolyDDV& ddv)
{
  if (ddv.getSize() != _types.size())
    return;
  int i;
  for (i = 0; i < ddv.getSize(); ++i)
    {
      if (ddv.isPlus(i))
	{
	  if (isEq(i) || isScalar(i))
	    setPlus(i);
	  else if (isMinus(i))
	    setStar(i);
	}
      else if (ddv.isMinus(i))
	{
	  if (isEq(i) || isScalar(i))
	    setMinus(i);
	  else if (isPlus(i))
	    setStar(i);
	}
      else if (ddv.isStar(i))
	setStar(i);
      else if (ddv.isScalar(i) && ! isStar(i))
	{
	  int s1 = ddv.getScalar(i);
	  if (isScalar(i) || isEq(i))
	    {
	      int s2 = 0;
	      if (isScalar(i))
		s2 = getScalar(i);
	      if (s1 > 0 && s2 < 0 || s1 < 0 && s2 > 0)
		setStar(i);
	      else if (s1 > 0 && s1 != s2)
		setPlus(i);
	      else if (s1 < 0 && s1 != s2)
		setMinus(i);
	    }
	  else
	    {
	      if (s1 > 0 && isMinus(i) || s1 < 0 && isPlus(i))
		setStar(i);
	    }
	}
    }
}



std::ostream& operator<<(std::ostream& out, PolyDDV const& rhs)
{
  int i;
  if (rhs.isRAW())
    out << "RAW: ";
  else if (rhs.isWAR())
    out << "WAR: ";
  else if (rhs.isWAW())
    out << "WAW: ";
  else if (rhs.isRAR())
    out << "RAR: ";
  else
    out << "[undef dep type]: ";
  out << "(";
  for (i = 0; i < rhs.getSize(); ++i)
    {
      if (rhs.isEq(i))
	out << "=";
      else if (rhs.isPlus(i))
	out << "<";
      else if (rhs.isMinus(i))
	out << ">";
      else if (rhs.isStar(i))
	out << "*";
      else if (rhs.isScalar(i))
	out << rhs.getScalar(i);
      if (i < rhs.getSize() - 1)
	out << ",";
    }
  out << ")";

  return out;
}


/******************************************************************************/
/*************************** PolyOpt DDV computation **************************/
/******************************************************************************/


/**
 * Annotate the AST to reflect the schedule. Simple prefix visit.
 *
 */
static
std::vector<SgForStatement*>
mapForLoopToId(SgNode* root)
{
  class ScopVisitor : public AstPrePostOrderTraversal {
    public:
    // top-down parsing.
    virtual void preOrderVisit(SgNode* node) {
      SgForStatement* fornode = isSgForStatement(node);
      if (fornode)
	loopMap.push_back(fornode);
      else
	{
	  // Deal with the special case of statements not surrounded
	  // by any loop.
	  ScopStatementAnnotation* annot =
	    (ScopStatementAnnotation*)(node->getAttribute("ScopStmt"));
	  if (annot)
	    {
	      SgForStatement* encloseFor =
		SageInterface::getEnclosingNode<SgForStatement>(node);
	      if (encloseFor)
		{
		  std::vector<SgForStatement*>::const_iterator i;
		  for (i = loopMap.begin(); i != loopMap.end(); ++i)
		    if (*i == encloseFor)
		      break;
		  if (i != loopMap.end())
		    return;
		}
	      loopMap.push_back (NULL);
	    }
	}
    };
    virtual void postOrderVisit(SgNode* node) {};
    std::vector<SgForStatement*> loopMap;
  };

  ScopVisitor sv;

  sv.traverse(root);

  return sv.loopMap;
}


static
bool
check_ddv_exists(std::vector<PolyDDV>& refs, PolyDDV& ddv,
		 bool consider_only_pure_identical)
{
  std::vector<PolyDDV>::iterator i;
  for (i = refs.begin(); i != refs.end(); ++i)
    {
      if (consider_only_pure_identical)
	{
	  if ((*i).isPureIdentical(ddv))
	    return true;
	}
      else
	if ((*i).isIdenticalVector(ddv))
	  return true;
    }

  return false;
}


/**
 * Create Poly DDV from Candl ddv structure.
 *
 */
static
std::vector<PolyDDV>
create_ddv_from_candl(CandlDDV* cddv,
		      std::vector<SgForStatement*>& loop_ids,
		      bool remove_duplicates,
		      bool consider_only_pure_identical)
{
  CandlDDV* tmp;
  std::vector<PolyDDV> output;

  for (tmp = cddv; tmp; tmp = tmp->next)
    {
      PolyDDV ddv(tmp->length, loop_ids[tmp->loop_id]);
      // Set the dependence type.
      switch (tmp->deptype)
	{
	case CANDL_RAW:
	  ddv.setRAW();
	  break;
	case CANDL_WAR:
	  ddv.setWAR();
	  break;
	case CANDL_WAW:
	  ddv.setWAW();
	  break;
	case CANDL_RAR:
	  ddv.setRAR();
	  break;
	case CANDL_UNSET:
	default:
	  break;
	}
      // Set the components of the vector.
      int i;
      for (i = 0; i < tmp->length; ++i)
	{
	  switch (tmp->data[i].type)
	    {
	    case candl_dv_eq:
	      ddv.setEq(i);
	      break;
	    case candl_dv_plus:
	      //ddv.setPlus(i);
	      ddv.setMinus(i);
	      break;
	    case candl_dv_minus:
	      //ddv.setMinus(i);
	      ddv.setPlus(i);
	      break;
	    case candl_dv_star:
	      ddv.setStar(i);
	      break;
	    case candl_dv_scalar:
	      ddv.setScalar(i, - tmp->data[i].value);
	      break;
	    default:
	      ROSE_ASSERT(0);
	    }
	}
      // Check if an identical ddv was already created.
      if (remove_duplicates)
	{
	  if (! check_ddv_exists(output, ddv, consider_only_pure_identical))
	    output.push_back(ddv);
	}
      else
	output.push_back(ddv);
    }

  return output;
}

static
std::vector<PolyDDV>
hullifyDDV(std::vector<PolyDDV>& ddvs)
{
  std::vector<PolyDDV> output;
  std::vector<PolyDDV>::iterator i = ddvs.begin();
  if (i != ddvs.end())
    {
      PolyDDV base = *i;
      ++i;
      for (; i != ddvs.end(); ++i)
	base.computeHull(*i);
      output.push_back(base);
    }

  return output;
}

void
computeDDVinScop(scoplib_scop_p scop, PolyRoseOptions& polyoptions)
{
  // 4- Process it:
  // 4.1- Compute dependence polyhedra
  CandlOptions* coptions = candl_options_malloc ();
  CandlProgram* cprogram = candl_program_convert_scop (scop, NULL);
  CandlDependence* cdeps = candl_dependence (cprogram, coptions);
  //candl_dependence_pprint (stdout, cdeps);
  /// FIXME: LNP: This may be enough?
  ///candl_dependence_isl_simplify(cdeps, cprogram);
  // 4.2- Map each loop in the scop to its candl id.
  std::vector<SgForStatement*> loopMap =
    mapForLoopToId((SgNode*)(scop)->usr);

  // 4.3- Traverse all loops, and create the DDVs.
  std::vector<SgForStatement*>::const_iterator i;
  int id;

  // Search for the smallest loop id. It should always be 0, but just to
  /// be sure...
  int smallestLoopId = -1;
  for (int c = 0; c < cprogram->nb_statements; ++c)
    for (int lid = 0; lid < cprogram->statement[c]->depth; ++lid)
      {
	int val = cprogram->statement[c]->index[lid];
	if (smallestLoopId == -1)
	  smallestLoopId = val;
	else
	  smallestLoopId = val < smallestLoopId ? val : smallestLoopId;
      }
  if (smallestLoopId == -1)
    // Program with no loop. Should never happen as fake 1-time loop
    // are inserted automatically around loop-less statements.
    return;

  // Iterate on all loops.
  for (id = 0, i = loopMap.begin(); i != loopMap.end(); ++i, ++id)
    {
      // Skipping fake loops (ie, statement surrounded by no loop).
      if (*i == NULL)
	continue;

      if (polyoptions.getScVerboseLevel() >=
	  PolyRoseOptions::VERBOSE_COMPREHENSIVE)
	{
	  std::cout << "For loop: " << std::endl;
	  std::cout << (*i)->unparseToCompleteString() << std::endl;
	}
      CandlDDV* cddv = candl_ddv_extract_in_loop (cprogram, cdeps,
						  id + smallestLoopId);
      //candl_ddv_print (stdout, cddv);

      std::vector<PolyDDV> ddvs =
	create_ddv_from_candl(cddv, loopMap, true, true);

      candl_ddv_free (cddv);

      SageForInfo* annot =
	(SageForInfo*) (*i)->getAttribute(SageForInfo::name());
      if (annot == NULL)
	annot = new SageForInfo();
      if (polyoptions.getHullifyDDV())
	annot->ddvs = hullifyDDV(ddvs);
      else
	annot->ddvs = ddvs;
      (*i)->setAttribute(SageForInfo::name(), annot);

      if (polyoptions.getScVerboseLevel() >=
	  PolyRoseOptions::VERBOSE_COMPREHENSIVE)
	{
	  if (annot->ddvs.size())
	    {
	      std::cout << "Dependence vectors for the loop nest(s): " <<
		std::endl;
	      std::vector<PolyDDV>::const_iterator j;
	      for (j = annot->ddvs.begin(); j != annot->ddvs.end(); ++j)
		std::cout << *j << std::endl;
	    }
	}
    }
  candl_program_free (cprogram);
  candl_dependence_free (cdeps);
  candl_options_free (coptions);
}
