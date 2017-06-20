/*
 * PolyOpt.cpp: This file is part of the PolyOpt project.
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
 * @file: PolyOpt.cpp
 * @author: Louis-Noel Pouchet <pouchet@cse.ohio-state.edu>
 */

#include <getopt.h>
#include <string.h>
#include <stdio.h>

#include <string>
#include <iostream>

#include <iterator>
#include <algorithm>
#include <sstream>

// LNP: To avoid redefined macro errors in pocc.
/// LNP: FIXME: Find a better solution!
#undef PACKAGE_BUGREPORT
#undef PACKAGE_STRING
#undef PACKAGE_TARNAME
#undef PACKAGE_NAME
#undef PACKAGE_VERSION
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

#include <polyopt/PolyHLS.hpp>


#include <hlsir/hlsir.h>
#include <pocc/driver-hlsir.h>
#include <past/pprint.h>


//#include <polyopt/SystemcTransform.hpp>
#include <SystemcTransform.cpp>


void optimizeSingleScop(scoplib_scop_p scoplibScop,
			int scopId,
			s_pocc_options_t* poptions,
			s_pocc_utils_options_t* puoptions,
			PolyRoseOptions& polyoptions);


/******************************************************************************/
/************************ PolyOpt Optimization routines ***********************/
/******************************************************************************/

/**
 * Transform a full Rose project using Polyhedral techniques.
 *
 *
 */
int PolyOptOptimizeProject(SgProject* project, PolyRoseOptions& polyoptions)
{
  int scopId;

  //PolyRoseOptions polyoptions_cp = polyoptions;

  // 1- Retrieve pocc_options_t from PolyRoseOptions.
  s_pocc_options_t* poptions = polyoptions.buildPoccOptions ();

  s_pocc_utils_options_t* puoptions = pocc_utils_options_malloc ();
  if (poptions->letsee == 0 && poptions->pluto == 0)
    if (! poptions->quiet)
      std::cout <<
	"[PoCC] INFO: pass-thru compilation, no optimization enabled\n";


  // 2- Extract Scops from source tree.
  ScopExtractor extractor (project, polyoptions);
  std::vector<scoplib_scop_p> scops = extractor.getScoplibs();

  if (! polyoptions.getQuiet())
    std::cout << "[PolyOpt] Number of SCoPs: " << scops.size() << std::endl;
  std::vector<scoplib_scop_p>::iterator sage_scop_iterator;
  // 3- Iterate on each scop:
  for (sage_scop_iterator = scops.begin (), scopId = 1;
       sage_scop_iterator != scops.end ();
       ++sage_scop_iterator, ++scopId)
    {
      //   4- Process it:
      // 4.1- Optimize the scop with PoCC
      // 4.2- Generate the new Sage AST with CLooG CLAST output
      // 4.3- Plug the new AST in place of the old one.
      optimizeSingleScop(*sage_scop_iterator, scopId, poptions,
			 puoptions, polyoptions);
    }



  // Clear PoCC-wide options.
  /// LNP: FIXME: Reactivate this.
  //pip_close ();

  // 4- Compute scop-wide ddv, if required.
  if (polyoptions.getComputeDDV())
    PolyOptAnnotateProject(project, polyoptions);

  // 5- Annotate inner-most loops, if required.
  if (polyoptions.getAnnotateInnerLoops())
    PolyOptInnerLoopsAnnotateProject(project, polyoptions);


  // Run SystemC translation
  if(polyoptions.getSCTargetFunc() != "")// && polyoptions.getSCTestbenchFunc() != "")
  {
	  using namespace std;
	  string tbfunc = (polyoptions.getSCTestbenchFunc() == "") ? "main" : polyoptions.getSCTestbenchFunc();
	  int depth = atoi(polyoptions.getSCDepth().c_str());
	  //string preprocess = polyoptions.getSCPreprocess();
	  bool preprocess = polyoptions.getSCPreprocess();
	  bool no_pretile = !polyoptions.getSCPretile();
	  //std::cout << "preprocess is " << preprocess << endl;
	  if(!no_pretile){
	    const char* unroll_factor_file_name = "unroll_factor";
	    ifstream unroll_factor_file(unroll_factor_file_name);
	    assert(unroll_factor_file.good());
	    string line;
	    cout << "[SYSTEMC_GENERATION]: Unroll factor ";
	    std::getline(unroll_factor_file, line);
	    assert(line !="");
	    istringstream iss(line);
	    vector<int> unroll_factors;
	    //copy(istream_iterator<string>(iss),
	      //istream_iterator<string>(),
	      //back_inserter(unroll_factors));
	    int num;
	    while (iss >> num) unroll_factors.push_back(num);
	    for(vector<int>::iterator it =  unroll_factors.begin(); it != unroll_factors.end(); ++it){
	      printf("%d\n", *it);
	    }
	    //TransformToSystemC(project, polyoptions.getSCTargetFunc(), tbfunc, depth, unroll_factors, preprocess!="0", no_pretile);
	    TransformToSystemC(project, polyoptions.getSCTargetFunc(), tbfunc, depth, unroll_factors, preprocess, no_pretile);
	  }
	  else{
	    vector<int> unroll_factors;
	    //TransformToSystemC(project, polyoptions.getSCTargetFunc(), tbfunc, depth, unroll_factors, preprocess!="0", no_pretile);
	    TransformToSystemC(project, polyoptions.getSCTargetFunc(), tbfunc, depth, unroll_factors, preprocess, no_pretile);
	  }
  }

  // Translate parallel loops to parfor/vectorfor, and insert the
  // associated pragmas.
  /// LNP: Right now, it is done syntactically with annotations in the
  /// Sage, not by using new Sage node types for parallel
  /// loops/pragmas.
//   if (polyoptions.getGeneratePragmas())
//     PolyOptAnnotateProject(project, polyoptions);
  pocc_options_free (poptions);

  return EXIT_SUCCESS;
}


/**
 * Transform a sub-tree using Polyhedral techniques.
 *
 *
 */
int PolyOptOptimizeSubTree(SgNode* root, PolyRoseOptions& polyoptions)
{
  int scopId;

  // 1- Retrieve pocc_options_t from PolyRoseOptions.
  s_pocc_options_t* poptions = polyoptions.buildPoccOptions ();

  s_pocc_utils_options_t* puoptions = pocc_utils_options_malloc ();
  if (poptions->letsee == 0 && poptions->pluto == 0)
    if (! poptions->quiet)
      std::cout <<
	"[PoCC] INFO: pass-thru compilation, no optimization enabled\n";

  // 2- Extract Scops from source tree.
  ScopExtractor extractor (polyoptions);
  extractor.extractScops(root);
  std::vector<scoplib_scop_p> scops = extractor.getScoplibs();

  if (! polyoptions.getQuiet())
    std::cout << "[PolyOpt] Number of SCoPs: " << scops.size() << std::endl;
  std::vector<scoplib_scop_p>::const_iterator sage_scop_iterator;
  // 3- Iterate on each scop:
  for (sage_scop_iterator = scops.begin (), scopId = 1;
       sage_scop_iterator != scops.end ();
       ++sage_scop_iterator, ++scopId)
    {
      //   4- Process it:
      // 4.1- Optimize the scop with PoCC
      // 4.2- Generate the new Sage AST with CLooG CLAST output
      // 4.3- Plug the new AST in place of the old one.
      optimizeSingleScop(*sage_scop_iterator, scopId, poptions,
			 puoptions, polyoptions);
    }

  // Clear PoCC-wide options.
  /// LNP: FIXME: Reactivate this.
  //pip_close ();
  pocc_options_free (poptions);

  // 4- Annotate inner-most loops, if required.
  if (polyoptions.getAnnotateInnerLoops())
    PolyOptInnerLoopsAnnotateSubTree(root, polyoptions);


  return EXIT_SUCCESS;
}


/******************************************************************************/
/************************* PolyOpt Annotation routines ************************/
/******************************************************************************/

/**
 * Annotate inner-most loops of a whole ROSE project with
 * dependence/vectorization information (no transformation is
 * performed).
 *
 *
 */
int PolyOptInnerLoopsAnnotateProject(SgProject* project,
				     PolyRoseOptions& polyoptions)
{
  // 1- Retrieve pocc_options_t from PolyRoseOptions.
  s_pocc_options_t* poptions = polyoptions.buildPoccOptions ();
  s_pocc_utils_options_t* puoptions = pocc_utils_options_malloc ();
  if (! poptions->quiet && ! polyoptions.getQuiet())
    std::cout << "[PolyOpt] Annotate polyhedral inner loops with vectorizability info"
	      << std::endl;

  // 2- Extract all inner-most loops in the project.
  std::vector<SgNode*> innerLoops;
  SgFilePtrList& file_list = project->get_fileList();
  SgFilePtrList::const_iterator file_iter;
  // Iterate on all files of the project.
  for (file_iter = file_list.begin(); file_iter != file_list.end(); file_iter++)
    {
      SgSourceFile* file = isSgSourceFile(*file_iter);
      if (polyoptions.getScVerboseLevel())
	std::cout << "[Extr] File: " << file->getFileName() << std::endl;
      SgNodePtrList forLoops =
	NodeQuery::querySubTree(file, V_SgForStatement);
      SgNodePtrList::const_iterator iter;
      // Iterate on all for loops in a file.
      for (iter = forLoops.begin(); iter != forLoops.end(); ++iter)
	{
	  SgNodePtrList loops =
	    NodeQuery::querySubTree(*iter, V_SgForStatement);
	  if (loops.size() == 1)
	    innerLoops.push_back(*iter);
	}
    }

  std::vector<SgNode*>::iterator i;
  int scopId;
  int numInnerLoops = 0;
  for (i = innerLoops.begin(); i != innerLoops.end(); ++i)
    {
      // 3- Annotate all inner-most loop which are polyhedral.
      bool oldQuiet = polyoptions.getQuiet();
      polyoptions.setQuiet(true);
      ScopExtractor extractor (polyoptions);
      extractor.extractScops(*i);
      std::vector<scoplib_scop_p> scops = extractor.getScoplibs();
      polyoptions.setQuiet(oldQuiet);

      std::vector<scoplib_scop_p>::const_iterator sage_scop_iterator;
      // Iterate on each scop (should be exactly zero or one):
      for (sage_scop_iterator = scops.begin (), scopId = 1;
	   sage_scop_iterator != scops.end ();
	   ++sage_scop_iterator, ++scopId)
	{
	  ++numInnerLoops;
	  SageForInfo* annot = new SageForInfo();
	  scoplib_scop_p scop = *sage_scop_iterator;
	  // Process it with PoCC:
	  annot->isParallel =
	    PoCCIsLoopParallel (scop, poptions, puoptions);
	  if (polyoptions.getScVerboseLevel() >= PolyRoseOptions::VERBOSE_FULL)
	    {
	      std::cout << "Loop is parallel? " << annot->isParallel;
	      std::cout << ((SgNode*)(scop->usr))->unparseToCompleteString()
			<< std::endl;
	    }
	  if (annot->isParallel)
	    {
	      annot->isStrideOne =
		PoCCIsLoopStrideOneAccesses(scop, poptions, puoptions);
	      if (polyoptions.getScVerboseLevel() >=
		  PolyRoseOptions::VERBOSE_FULL)
		{
		  std::cout << "Loop has stride-1? " << annot->isStrideOne;
		  std::cout << ((SgNode*)(scop->usr))->unparseToCompleteString()
			    << std::endl;
		}
	    }
	  else
	    annot->isStrideOne = 0;

	  SgNode* loop = (SgNode*) scop->usr;
	  std::vector<SgNode*> loops =
	    NodeQuery::querySubTree(loop, V_SgForStatement);
	  ROSE_ASSERT(loops.size() == 1);
          SgForStatement* forLoop = isSgForStatement(*(loops.begin()));
	  SageForInfo* oldannot =
	    (SageForInfo*) forLoop->getAttribute(SageForInfo::name());
	  if (oldannot)
	    delete oldannot;
	  /// LNP: loop-local annotation.
	  forLoop->setAttribute(SageForInfo::name(), annot->copy());

	  // Compute the DDVs for the scop, if required.
	  if (polyoptions.getComputeDDV())
	    computeDDVinScop(*sage_scop_iterator, polyoptions);
	}
    }

  if (! polyoptions.getQuiet())
    std::cout << "[PolyOpt] Created vectorizability annotation for " << numInnerLoops
	      << " inner loop(s)" << std::endl;


  // Clear PoCC-wide options.
  /// LNP: FIXME: Reactivate this.
  //pip_close ();
  //pocc_options_free (poptions);

  return EXIT_SUCCESS;
}


/**
 * Annotate inner-most loops of a sub-tree with
 * dependence/vectorization information (no transformation is
 * performed).
 *
 *
 */
int PolyOptInnerLoopsAnnotateSubTree(SgNode* root, PolyRoseOptions& polyoptions)
{
  // 1- Retrieve pocc_options_t from PolyRoseOptions.
  s_pocc_options_t* poptions = polyoptions.buildPoccOptions ();
  s_pocc_utils_options_t* puoptions = pocc_utils_options_malloc ();
  if (! poptions->quiet)
    std::cout << "[PoCC] INFO: pass-thru compilation, no optimization enabled"
	      << std::endl;

  // 2- Extract all inner-most loops in the subtree.
  std::vector<SgNode*> innerLoops;
  SgNodePtrList forLoops =
    NodeQuery::querySubTree(root, V_SgForStatement);
  SgNodePtrList::const_iterator iter;
  // Iterate on all for loops in a file.
  for (iter = forLoops.begin(); iter != forLoops.end(); ++iter)
    {
      SgNodePtrList loops =
	NodeQuery::querySubTree(*iter, V_SgForStatement);
      if (loops.size() == 1)
	innerLoops.push_back(*iter);
    }

  std::vector<SgNode*>::iterator i;
  int scopId;
  for (i = innerLoops.begin(); i != innerLoops.end(); ++i)
    {
      // 3- Annotate all inner-most loop which are polyhedral.
      ScopExtractor extractor (polyoptions);
      extractor.extractScops(*i);
      std::vector<scoplib_scop_p> scops = extractor.getScoplibs();

      std::vector<scoplib_scop_p>::const_iterator sage_scop_iterator;
      // Iterate on each scop (should be exactly zero or one):
      for (sage_scop_iterator = scops.begin (), scopId = 1;
	   sage_scop_iterator != scops.end ();
	   ++sage_scop_iterator, ++scopId)
	{
	  SageForInfo* annot = new SageForInfo();
	  scoplib_scop_p scop = *sage_scop_iterator;
	  // Process it with PoCC:
	  annot->isParallel =
	    PoCCIsLoopParallel (scop, poptions, puoptions);
	  if (polyoptions.getScVerboseLevel() >=
	      PolyRoseOptions::VERBOSE_COMPREHENSIVE)
	    {
	      std::cout << "Loop is parallel? " << annot->isParallel;
	      std::cout << ((SgNode*)(scop->usr))->unparseToCompleteString()
			<< std::endl;
	    }
	  if (annot->isParallel)
	    {
	      annot->isStrideOne =
		PoCCIsLoopStrideOneAccesses(scop, poptions, puoptions);
	      if (polyoptions.getScVerboseLevel() >=
		  PolyRoseOptions::VERBOSE_FULL)
		{
		  std::cout << "Loop has stride-1? " << annot->isStrideOne;
		  std::cout << ((SgNode*)(scop->usr))->unparseToCompleteString()
			    << std::endl;
		}
	    }
	  else
	    annot->isStrideOne = 0;

	  SgNode* loop = (SgNode*) scop->usr;
	  std::vector<SgNode*> loops =
	    NodeQuery::querySubTree(loop, V_SgForStatement);
	  ROSE_ASSERT(loops.size() == 1);
          SgForStatement* forLoop = isSgForStatement(*(loops.begin()));
	  SageForInfo* oldannot =
	    (SageForInfo*) forLoop->getAttribute(SageForInfo::name());
	  if (oldannot)
	    delete oldannot;
	  /// LNP: loop-local annotation.
	  forLoop->setAttribute(SageForInfo::name(), annot);

	  // Compute the DDVs for the scop, if required.
	  if (polyoptions.getComputeDDV())
	    computeDDVinScop(*sage_scop_iterator, polyoptions);
	}
    }

  // Clear PoCC-wide options.
  /// LNP: FIXME: Reactivate this.
  //pip_close ();
  //pocc_options_free (poptions);

  return EXIT_SUCCESS;
}




/**
 * Annotate a whole ROSE project with dependence/permutability
 * information (no transformation is performed).
 *
 *
 */
int PolyOptAnnotateProject(SgProject* project, PolyRoseOptions& polyoptions)
{
  if (! polyoptions.getQuiet())
    std::cout << "[PolyOpt] Annotate polyhedral loops with DDV info" << std::endl;

  int scopId;
  // 1- Extract Scops from source tree.
  bool oldQuiet = polyoptions.getQuiet();
  polyoptions.setQuiet(true);
  ScopExtractor extractor (project, polyoptions);
  std::vector<scoplib_scop_p> scops = extractor.getScoplibs();
  polyoptions.setQuiet(oldQuiet);

  if (! polyoptions.getQuiet())
    std::cout << "[PolyOpt] Create annotation for " << scops.size()
	      << " SCoP(s)" << std::endl;
  std::vector<scoplib_scop_p>::const_iterator sage_scop_iterator;
  // 3- Iterate on each scop:
  for (sage_scop_iterator = scops.begin (), scopId = 1;
       sage_scop_iterator != scops.end ();
       ++sage_scop_iterator, ++scopId)
    {
      // Compute the DDVs for the scop, if required.
      if (polyoptions.getComputeDDV())
	computeDDVinScop(*sage_scop_iterator, polyoptions);
    }

  return EXIT_SUCCESS;
}


/**
 * Annotate a sub-tree with dependence/permutability information (no
 * transformation is performed).
 *
 *
 */
int PolyOptAnnotateSubTree(SgNode* root, PolyRoseOptions& polyoptions)
{
  // 1- Extract Scops from source tree.
  int scopId;
  bool oldQuiet = polyoptions.getQuiet();
  polyoptions.setQuiet(true);
  ScopExtractor extractor (polyoptions);
  extractor.extractScops(root);
  std::vector<scoplib_scop_p> scops = extractor.getScoplibs();
  polyoptions.setQuiet(oldQuiet);

  if (! polyoptions.getQuiet())
    std::cout << "[PolyOpt] Number of SCoPs to annotate: " << scops.size() << std::endl;
  std::vector<scoplib_scop_p>::const_iterator sage_scop_iterator;
  // 3- Iterate on each scop:
  for (sage_scop_iterator = scops.begin (), scopId = 1;
       sage_scop_iterator != scops.end ();
       ++sage_scop_iterator, ++scopId)
    {
      // Compute the DDVs for the scop, if required.
      if (polyoptions.getComputeDDV())
	computeDDVinScop(*sage_scop_iterator, polyoptions);
    }

  return EXIT_SUCCESS;
}





/******************************************************************************/
/*************************** PolyOpt SCoP Processing **************************/
/******************************************************************************/


static
void
erasePlutoFiles()
{
  std::remove(".pragmas");
  std::remove(".unroll");
  std::remove(".vectorize");
}

/**
 * Helper. Process a single scop with PoCC.
 *
 */
void
optimizeSingleScop(scoplib_scop_p scoplibScop,
		   int scopId,
		   s_pocc_options_t* poptions,
		   s_pocc_utils_options_t* puoptions,
		   PolyRoseOptions& polyoptions)
{
  if (! polyoptions.getQuiet())
    std::cout << "[PolyOpt] Optimizing Scop #"<< scopId << std::endl;
  if (polyoptions.isVerbose() && 0)
    {
      std::cout << "--- Printing SCoP ---" << std::endl;
      scoplib_scop_print_dot_scop_options (stdout,
					   scoplibScop,
					   SCOPLIB_SCOP_PRINT_ARRAYSTAG);
      std::cout << "--- End SCoP ---" << std::endl;
    }
  if (polyoptions.getScVerboseLevel() >=
      PolyRoseOptions::VERBOSE_COMPREHENSIVE)
    std::cout << ((SgNode*)(scoplibScop->usr))->unparseToCompleteString()
	      << std::endl;
  if (polyoptions.getScVerboseLevel() >= PolyRoseOptions::VERBOSE_FULL)
    scoplib_scop_print (stdout, scoplibScop);

  // 1- Call PoCC optimizations.
  erasePlutoFiles();
  if (polyoptions.getCodegenUsePAST())
    {
      s_past_node_t* pastRoot =
	OptimizeSingleScopWithPoccPast (scoplibScop, poptions, puoptions,
					polyoptions);
      if (! polyoptions.getQuiet())
	std::cout << "[PolyOpt] Processing with the PAST back-end"
		  << std::endl;

      // 2- Translate back Clast to Sage.
      // 2.1- Translate.
      SgStatement* scopRoot = isSgStatement((SgNode*)(scoplibScop->usr));
      ROSE_ASSERT(scopRoot);
      SgScopeStatement* scope = scopRoot->get_scope();
      PastToSage sageScop (scope, pastRoot, scoplibScop, polyoptions, scopId);
      ScopRootAnnotation* annot = 
	(ScopRootAnnotation*)sageScop.getBasicBlock()->getAttribute("ScopRoot");
      if (! annot)
	annot = new ScopRootAnnotation();
      annot->scopId = scopId;
      sageScop.getBasicBlock()->setAttribute("ScopRoot", annot);

      // 2.2- Reinsert.
      SageInterface::replaceStatement(scopRoot, sageScop.getBasicBlock(), true);
      past_deep_free (pastRoot);

      // HLS pass.
      if (polyoptions.getHLS() || polyoptions.getScHLS())
	{
	  SgNode* newRoot = sageScop.getBasicBlock();
	  std::cout <<"[PolyOpt] Using HLS mode..." <<std::endl;
	  optimizeSingleScopHLS(newRoot, poptions, puoptions, polyoptions, polyoptions.getScHLS());
	  std::cout <<"[PolyOpt] Using HLS mode...DONE" <<std::endl;
	}
      }
  else
    {
      clast_stmt* clastRoot =
	OptimizeSingleScopWithPocc (scoplibScop, poptions, puoptions,
				    polyoptions);
      if (! polyoptions.getQuiet())
	std::cout << "[PolyOpt] Processing with the CLAST back-end"
		  << std::endl;

      // 2- Translate back Clast to Sage.
      // 2.1- Translate.
      SgStatement* scopRoot = isSgStatement((SgNode*)(scoplibScop->usr));
      ROSE_ASSERT(scopRoot);
      SgScopeStatement* scope = scopRoot->get_scope();
      ClastToSage sageScop (scope, clastRoot, scoplibScop, polyoptions);

      // 2.2- Reinsert.
      SageInterface::replaceStatement(scopRoot, sageScop.getBasicBlock(), true);
      //cloog_clast_free (clastRoot);
    }
  if (! polyoptions.getQuiet())
    std::cout << "[PolyOpt] Scop #"<< scopId << " successfully optimized"
	      << std::endl;
}
