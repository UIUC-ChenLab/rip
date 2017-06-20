/*
 * ScopExtractor.cpp: This file is part of the PolyOpt project.
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
 * @file: ScopExtractor.cpp
 * @author: Louis-Noel Pouchet <pouchet@cse.ohio-state.edu>
 */


// LNP: To avoid redefined macro errors in pocc.
/// LNP: FIXME: Find a better solution!
#undef PACKAGE_BUGREPORT
#undef PACKAGE_STRING
#undef PACKAGE_TARNAME
#undef PACKAGE_NAME
#undef PACKAGE_VERSION
#include <rose.h>
#ifndef SCOPLIB_INT_T_IS_LONGLONG
# define SCOPLIB_INT_T_IS_LONGLONG
#endif
#include <scoplib/scop.h>


#include <polyopt/ScopExtractor.hpp>
#include <polyopt/ScopExtractorVisitor.hpp>
#include <polyopt/SageNodeAnnotation.hpp>
#include <polyopt/AffineConverter.hpp>


using namespace std;
using namespace SageInterface;


ScopExtractor::ScopExtractor(PolyRoseOptions& polyopts)
{
  this->polyoptions = polyopts;
  isVerbose = ! polyopts.getQuiet();
}


ScopExtractor::ScopExtractor(SgProject* project, PolyRoseOptions& polyopts)
{
  //   this->project = project;
  this->polyoptions = polyopts;
  isVerbose = ! polyopts.getQuiet();
  if (! polyoptions.getQuiet())
    std::cout << "[PolyOpt] Start SCoP extraction" << std::endl;
  if (isVerbose)
    std::cout << "[PolyOpt] Using generic scop extractor" << std::endl;
  SgFilePtrList& file_list = project->get_fileList();
  SgFilePtrList::const_iterator file_iter;
  // Iterate on all files of the project.
  for (file_iter = file_list.begin(); file_iter != file_list.end(); file_iter++)
    {
      SgSourceFile* file = isSgSourceFile(*file_iter);
      if (polyoptions.getScVerboseLevel())
	cout << "[Extr] File: " << file->getFileName() << endl;
      SgNodePtrList funcDefnList =
	NodeQuery::querySubTree(file, V_SgFunctionDefinition);
      SgNodePtrList::const_iterator iter;
      // Iterate on all function defined in a file.
      for (iter = funcDefnList.begin(); iter != funcDefnList.end(); ++iter)
	{
	  SgFunctionDefinition *fun = isSgFunctionDefinition(*iter);
	  if (!fun)
	    {
	      cout << "[Extr] Warning: Expected SgFunctionDefinition in " <<
		file->getFileName() << endl;
	      continue; // with the next function definition
	    }
	  SgName name = fun->get_declaration()->get_name();
	  if (polyoptions.getScVerboseLevel())
	    cout << "[Extr] Function: " << name.getString() << endl;
	  SgBasicBlock* body = fun->get_body();

	  // Ensure the function is a candidate (no (unsafe) function
	  // calls).
	  if (assertFunctionIsCandidate(project, body))
	    {
	      // Proceed recursively, bottom up.
	      inspectBottomUpFunctionBody(project, body);
	    }
	}
    }
  if (isVerbose)
    std::cout << "[ScopExtraction] Generic: done" << std::endl;
  if (! polyoptions.getQuiet())
    std::cout << "[PolyOpt] Done SCoP extraction" << std::endl;
}

ScopExtractor::~ScopExtractor()
{


}

/**
 * Create scops for a sub-tree.
 *
 */
void
ScopExtractor::extractScops(SgNode* root)
{
  if (isVerbose)
    std::cout << "[PolyOpt] Using generic scop extractor" << std::endl;

  SgNodePtrList funcDefnList =
    NodeQuery::querySubTree(root, V_SgFunctionDefinition);
  SgNodePtrList::const_iterator iter;
  // Iterate on all functions defined in a sub-tree.
  for (iter = funcDefnList.begin(); iter != funcDefnList.end(); ++iter)
    {
      SgFunctionDefinition *fun = isSgFunctionDefinition(*iter);
      if (!fun)
	{
	  cout << "[Extr] Warning: Expected SgFunctionDefinition" << endl;
	  continue; // with the next function definition
	}
      SgName name = fun->get_declaration()->get_name();
      if (polyoptions.getScVerboseLevel())
	cout << "[Extr] Function: " << name.getString() << endl;
      SgBasicBlock* body = fun->get_body();

      // Ensure the function is a candidate (no (unsafe) function
      // calls).
      if (assertFunctionIsCandidate(NULL, body))
	{
	  // Proceed recursively, bottom up.
	  inspectBottomUpFunctionBody(NULL, body);
	}
    }

  // If no function is defined in the subtree, simply process it
  // as-is.
  if (funcDefnList.size() == 0)
    if (assertFunctionIsCandidate(NULL, root))
      // Proceed recursively, bottom up.
      inspectBottomUpFunctionBody(NULL, root);

  if (isVerbose)
    std::cout << "[ScopExtraction] Generic: done" << std::endl;
}


/**
 * Extract SCoPs from a function body
 * - normalize the BB
 * - perform bottom-up extraction
 * - remove dummy scops containing no loop
 *
 */
void
ScopExtractor::inspectBottomUpFunctionBody(SgProject* project, SgNode* root)
{
  /// FIXME: This has no effect on complex affine loops.
  // 1- Normalize and clean the sub-tree.

  // a- Normalize for loops.
  std::vector<SgNode*> forNodes =
    NodeQuery::querySubTree(root, V_SgForStatement);
  std::vector<SgNode*>::const_iterator i;
  /// FIXME: These normalizations simplifies the conditionals for
  /// min/max/ceil/floor emulation generated by clasttosage. It makes
  /// the problem of recognizing them much harder.
  //   for (i = forNodes.begin(); i != forNodes.end(); ++i)
  //     {
  //       SageInterface::normalizeForLoopInitDeclaration(isSgForStatement(*i));
  //       SageInterface::forLoopNormalization(isSgForStatement(*i));
  //     }

  // b- Remove jumps whose label is immediately after the jump.  Used to
  // clean up inlined code fragments.
  SageInterface::removeJumpsToNextStatement(root);

  // c- Remove labels which are not targets of any goto statements
  SageInterface::removeUnusedLabels(root);

  // d- Ensure all loops/conditionals bodies are a BB.
  //SageInterface::changeAllLoopBodiesToBlocks(root);

  // 2- Traverse the sub-tree.
  ScopExtractorVisitor scopTraversal(root, polyoptions);
  scopTraversal.reinitializeAttributes();
  scopTraversal.traverse(root);

  // 3- Remove scops not containing any loop.
  // This step is a pre-requesite on AffineConverter.
  scopTraversal.pruneScopWithoutLoop();

  // If there are any scop(s) discovered, process them.
  if (scopTraversal.getScopRoots().size() > 0)
    {
      // 4- Finalize control info (fakeiter trick, build schedules, etc.)
      scopTraversal.buildControlInformation();

      // 5- Create ScopLib structures for all scops.
      std::vector<SgNode*> roots = scopTraversal.getScopRoots();
      std::map<SgNode*, std::vector<SgNode*> > controlMap =
	scopTraversal.getControlMap();
      AffineConverter affconv(polyoptions);
      std::vector<scoplib_scop_p> scops =
	affconv.createScopLibFromScops(roots, controlMap);

      // 6- Append the built scop into the list.
      _scopRoots.insert(_scopRoots.end(), roots.begin(), roots.end());
      _scoplibs.insert(_scoplibs.end(), scops.begin(), scops.end());
    }
}


/**
 *
 *
 *
 */
bool
ScopExtractor::assertFunctionIsCandidate(SgProject* project, SgNode* root)
{

  return true;
}


/**
 * Accessor.
 *
 */
std::vector<scoplib_scop_p>&
ScopExtractor::getScoplibs() {
  return _scoplibs;
}


/**
 * Accessor.
 *
 */
std::vector<SgNode*>&
ScopExtractor:: getScopRoots() {
  return _scopRoots;
}


