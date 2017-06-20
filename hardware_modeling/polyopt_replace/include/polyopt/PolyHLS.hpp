/*
 * PolyHLS.hpp: This file is part of the PolyOpt project.
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
 * @file: PolyHLS.hpp
 * @author: Louis-Noel Pouchet <pouchet@cse.ohio-state.edu>
 */

#ifndef POLYOPT_POLYHLS_HPP
# define POLYOPT_POLYHLS_HPP

#undef PACKAGE_BUGREPORT
#undef PACKAGE_STRING
#undef PACKAGE_TARNAME
#undef PACKAGE_NAME
#undef PACKAGE_VERSION
#include <rose.h>

#include <polyopt/PolyRoseOptions.hpp>



/**
 * Transform a (sub-)Scop using HLS pass.
 *
 *
 */
void optimizeSingleScopHLS(SgNode* scopRoot,
			   s_pocc_options_t* poptions,
			   s_pocc_utils_options_t* puoptions,
			   PolyRoseOptions& polyoptions, 
			   bool ScHLS);


#endif
