
/*
 * lmp_driver.cc: This file is part of the LMP project.
 *
 * LMP: A ROSE-based Local Memory Promotion module.
 *
 * Copyright (C) 2012 Louis-Noel Pouchet/Ohio State University
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 *
 * The complete GNU Lesser General Public Licence Notice can be found
 * as the `COPYING.LESSER' file in the root directory.
 *
 * Author:
 * Louis-Noel Pouchet <pouchet@cse.ohio-state.edu>
 *
 */
#ifndef _HELPER_H_
#define _HELPER_H_
#if HAVE_CONFIG_H
# include <lmp/config.h>
#endif


#include <lmp/lmp_driver.h>
#include <lmp/BGPastToSage.h>


#include <AstTraversal.h>

#include <polylib/polylibgmp.h>

#include <isl/ctx.h>
#include <isl/map.h>
#include <isl/union_map.h>
#include <isl/set.h>
#include <isl/union_set.h>
#include <isl/constraint.h>
#include <isl/aff.h>
#include <isl/val.h>

// Becomes space in 0.09.
#include <isl/space.h>


#include <cloog/isl/cloog.h>

#include <past/past.h>
#include <past/past_api.h>
#include <past/pprint.h>
#include <clasttools/clast2past.h>

//#include <barvinok/isl.h>

#include <gmp.h>

//#include <lmp/isl_private.h>


#include <lmp/polynomial.h>

//weiwei
#include <polyopt/SageTools.hpp>
#include <polyopt/SageNodeAnnotation.hpp>

#if HAVE_CONFIG_H
# include <pocc-utils/config.h>
#endif

#include <pocc/driver-pluto.h>
#include <pocc/driver-candl.h>
#include <pocc/driver-cloog.h>
#include <pluto/pocc-driver.h>

//weiwei end

static
isl_map* compute_data_space_helper (std::vector<scoplib_statement_p>& sstmts,
				    scoplib_scop_p scop,
				    int array_id,
				    int nia, // number of iterator(s) active
				    int offset,
				    int has_read,
				    int has_write,
				    isl_space** given_space);

static
void traverse_collectfors(s_past_node_t* node, void* data);

static
char** get_loop_iters_in_past(s_past_node_t* root);

static
void traverse_variable(s_past_node_t* node, void* data);

static void substitute_name_in_past (s_past_node_t* root,
			 SgNode* scope,
			 scoplib_scop_p scop);

static
s_past_node_t* create_scanning_code (isl_map* diff,
				     SgNode* scope,
				     scoplib_scop_p scop);

static
s_past_node_t* isl_codegen (isl_union_map* umap,
			    SgNode* scope,
			    scoplib_scop_p scop);

static
int traverse_cst(isl_constraint* cst, void* arg);

static
int traverse_count_cst(isl_constraint* cst, void* arg);

static
int traverse_rm_cst(isl_basic_set* bset, void*);

static
isl_set* traverse_bset_remove_cst(isl_set* myset);

static
s_past_node_t* create_scanning_code (isl_set* diff,
				     SgNode* scope,
				     scoplib_scop_p scop);

static
isl_map* compute_data_space (SgNode* node,
			     scoplib_scop_p scop,
			     int array_id,
			     int offset,
			     bool write_out_mode,
			     bool read_only_references,
			     isl_space** isl_space_desc);

static
Polynomial computeCard(isl_set* aset, scoplib_scop_p scop, bool approx);

static
Polynomial computeCard(isl_map* amap, scoplib_scop_p scop, bool approx);


static
SgNode* createCopyStatement(SgVariableSymbol* array_global,
			    SgVariableSymbol* array_local,
			    std::vector<SgVariableSymbol*> iters,
			    bool isCopyIn,
			    std::vector<SgNode*> local_array_dims);

void removeEmptyBasicBlocks(SgNode* root);

static
bool isTileLoop(SgNode* n);

static
std::vector<SgNode*>
computeBestSolution(std::map<SgNode*, std::pair<isl_set*, isl_set*> > sol_set,
		    isl_map* full_dspace,
		    int max_buff_size,
		    std::map<SgNode*, isl_map*>& buffer_desc,
		    scoplib_scop_p scop,
		    SgNode* scopRoot,
		    int commsched_mode);

static
std::set<SgVariableSymbol*>
convertVarRefExpVectorToSymbolSet(std::vector<SgNode*>& refs);

void replaceSymbol(SgNode* root,
		   SgVariableSymbol* sorig,
		   SgVariableSymbol* snew);

static
SgNode* addIteratorNextVal(SgNode* preload, SgNode* loop);

static
void addIteratorLb(SgNode* preload, SgNode* loop);

static
isl_set* convert_partial_domain_to_isl_set(scoplib_statement_p s, int nia);

static
isl_set* project_set_onto_dim(isl_set* set, int dim);

static
void annotateLoopTripCount(SgNode* root,
			   scoplib_scop_p scop,
			   std::map<SgNode*, isl_set*>& loopTCmap);

static
int traverse_aff_compbuffdim(isl_set* set, isl_aff* aff, void* user);

static
std::vector<Polynomial> compute_buffer_dims(isl_map* buffer_map,
					    int array_dim, int nparams);

int
lmp_driver_wei (s_hlsir_t* input, s_lmp_options_t* options);

//int insertMemoryCycle(SgNode* commRoot, std::map<SgNode*, isl_set*>& loopTCmap, scoplib_scop_p scop);
int insertMemoryCycle(SgNode* commRoot, std::map<SgNode*, isl_set*>& loopTCmap, scoplib_scop_p scop, std::map<std::string, int> &ArrayDimMap);

//void insertForEachBlock(SgNode* Root, int cnt);
//void insertForEachBlock(SgNode* Root, int acc_Num, int inputBlockType, int cnt);
void insertForEachBlock(SgNode* Root, int acc_Num, int inputBlockType, std::map<std::string, int> &ArrayDimMap, int cnt);

int roundUp(int x);
bool tiledLoop(SgForStatement* forLoop, std::set<std::string> tLoops);
#endif
