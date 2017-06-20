
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
#include <polyopt/helper.hpp>


#if HAVE_CONFIG_H
# include <pocc-utils/config.h>
#endif

#include <pocc/driver-pluto.h>
#include <pocc/driver-candl.h>
#include <pocc/driver-cloog.h>
#include <pluto/pocc-driver.h>

using namespace SageInterface;


/// LNP: note: sageinterface::wrapfunction



/**
 * Magic function :-)
 * (c) L-N Pouchet, 2012.
 *
 * Compute U_F { F | x+offset } where x is a parametric iteration vector, with
 *                              \vec x = (1,..,d-nia,..,d)
 * The output map is embedded in a common space of max. dimensionality.
 *
 */
static
isl_map* compute_data_space_helper (std::vector<scoplib_statement_p>& sstmts,
				    scoplib_scop_p scop,
				    int array_id,
				    int nia, // number of iterator(s) active
				    int offset,
				    int has_read,
				    int has_write,
				    isl_space** given_space)
{
  // Compute the number of iterators, parameters and array dimension.
  scoplib_statement_p fs;
  int din = 0;
  for (std::vector<scoplib_statement_p>::iterator i = sstmts.begin();
       i != sstmts.end(); ++i)
    if (din < (*i)->nb_iterators)
      {
	din = (*i)->nb_iterators;
	fs = *i;
      }

  int nparam = fs->domain->elt->NbColumns - 2 - fs->nb_iterators;
  int i;
  int d = 0;
  scoplib_matrix_p m = fs->read;
  for (i = 0; i < m->NbRows; ++i)
    if (SCOPVAL_get_si(m->p[i][0]) == array_id)
      {
	++d; ++i;
	while (i < m->NbRows && SCOPVAL_get_si(m->p[i][0]) == 0)
	  {
	    ++i; ++d;
	  }
	break;
      }
  if (d == 0)
    {
      m = fs->write;
      for (i = 0; i < m->NbRows; ++i)
	if (SCOPVAL_get_si(m->p[i][0]) == array_id)
	  {
	    ++d; ++i;
	    while (i < m->NbRows && SCOPVAL_get_si(m->p[i][0]) == 0)
	      {
		++i; ++d;
	      }
	    break;
	  }
    }
  // Ensure the array was found in the statement.
  /// FIXME: ???
  ROSE_ASSERT(d > 0);
  int dout = d;

  // Initialize the ISL map.
  isl_ctx* ctxt = isl_ctx_alloc();
  // Adjust to the number of iterators 'nia' we are considering.
  isl_space* space;

  ROSE_ASSERT(din>=nia);
  // Special value for nia when we want all iterators active.
  if (nia == -1)
    nia = din;

  // Use a pre-existing space, if given.
  if (*given_space)
    space = *given_space;
  else
    {
      space = isl_space_alloc(ctxt, nparam + (din - nia) + 1, nia, dout);
      const char* name;
      // Set the names.
      for (i = 0; i < din - nia; ++i)
	{
	  name = ((SgVariableSymbol*)(fs->iterators[i]))->get_name().str();
	  space = isl_space_set_dim_name (space, isl_dim_param, i, name);
	}
      for (; i < din; ++i)
	{
	  name = ((SgVariableSymbol*)(fs->iterators[i]))->get_name().str();
	  space = isl_space_set_dim_name (space, isl_dim_in, i - (din - nia), name);
	}
      for (i = 0; i < scop->nb_parameters; ++i)
	{
	  name = ((SgVariableSymbol*)(scop->parameters[i]))->get_name().str();
	  space = isl_space_set_dim_name (space, isl_dim_param, i + (din-nia), name);
	}
      name = "FkP";
      space =
	isl_space_set_dim_name (space, isl_dim_param, i + (din-nia), name);
      for (i = 0; i < dout; ++i)
	{
	  char buff[32];
	  sprintf (buff, "__it%d", i);
	  space = isl_space_set_dim_name (space, isl_dim_out, i, buff);
	}
      *given_space = space;
    }

  // Declare output map.
  isl_map* umap = isl_map_empty (isl_space_copy(space));

  isl_val* tmp = isl_val_int_from_si(ctxt, 0);
  isl_val* cstoffset = isl_val_int_from_si(ctxt, 0);
  isl_val* tmp2 = isl_val_int_from_si(ctxt, 0);
  isl_val* ioffset = isl_val_int_from_si(ctxt, offset);
  isl_printer* pr = isl_printer_to_file (ctxt, stdout);

  // Iterate on all access functions, that reference the array.
  for (std::vector<scoplib_statement_p>::iterator i = sstmts.begin();
       i != sstmts.end(); ++i)
    {
      // std::cout << "STATEMENT: " << std::endl;
      // std::cout << ((SgNode*)((*i)->body))->unparseToCompleteString() << std::endl;

      isl_map* lmap = isl_map_universe (isl_space_copy(space));
      // 1- fill-in the domain of the statement.
      scoplib_matrix_p dom = (*i)->domain->elt;
      int j, k;
      isl_constraint* cst;
      for (j = 0; j < dom->NbRows; ++j)
      	{
	  cstoffset = isl_val_set_si(cstoffset, 0);
	  isl_local_space* ls =
	    isl_local_space_from_space(isl_space_copy(space));
      	  if (SCOPVAL_get_si(dom->p[j][0]) == 0)
      	    cst = isl_equality_alloc (isl_local_space_copy(ls));
      	  else
      	    cst = isl_inequality_alloc (isl_local_space_copy(ls));

	  // iterators in the original domain.
	  bool need_offset = false;
	  // Check if the constraint is involving an inner-loop
	  // iterator. If so, we need to propagate the offset in the
	  // domain constraint.
      	  for (k = din - nia + 1; k <= (*i)->nb_iterators; ++k)
      	    if (SCOPVAL_get_si(dom->p[j][k]) != 0)
	      {
		need_offset = true;
		break;
	      }
	  // fill-in the iterator part.
	  int ioff = 0;
      	  for (k = 1; k <= (*i)->nb_iterators; ++k)
	    {
	      // Correctly skip missing iterators wrt. full embedding
	      // space (fs).
	      while (ioff < din && (*i)->iterators[k-1] != fs->iterators[ioff])
		{
		  // std::cout << "fssize: " << fs->nb_iterators << "  iof:" << ioff;
		  // const char* name1 = ((SgVariableSymbol*)(fs->iterators[ioff]))->get_name().str();
		  // const char* name2 = ((SgVariableSymbol*)((*i)->iterators[k-1]))->get_name().str();
		  // std::cout << "iter1=" << name1 << " iter2=" << name2 << std::endl;
		  ioff++;
		}
	      ROSE_ASSERT(ioff < din);
	      ioff++;
	      tmp = isl_val_set_si (tmp, SCOPVAL_get_si(dom->p[j][k]));

	      // Deal with the offset.
	      if (need_offset && ioff == din - nia)
		  cstoffset = isl_val_mul(isl_val_copy(tmp), isl_val_copy(ioffset));
	      if (ioff <= din - nia)
		cst = isl_constraint_set_coefficient_val (cst, isl_dim_param,
							  ioff-1, isl_val_copy(tmp));
	      else
		cst = isl_constraint_set_coefficient_val (cst, isl_dim_in,
							  ioff-1 - (din-nia), isl_val_copy(tmp));
      	    }

      	  int off = (*i)->nb_iterators;
	  // parameters in the original domain.
      	  for (k = 1; k <= nparam; ++k)
      	    {
	      tmp = isl_val_set_si(tmp, SCOPVAL_get_si(dom->p[j][k + off]));
      	      cst = isl_constraint_set_coefficient_val (cst, isl_dim_param,
							k + (din - nia) - 1, isl_val_copy(tmp));
      	    }
	  tmp = isl_val_set_si(tmp, SCOPVAL_get_si(dom->p[j][dom->NbColumns - 1]));
	  tmp2 = isl_val_add(isl_val_copy(tmp), isl_val_copy(cstoffset));
      	  cst = isl_constraint_set_constant_val (cst, isl_val_copy(tmp2));
      	  lmap = isl_map_add_constraint (lmap, cst);
      	}

      // fill-in missing iterators (imperfectly nested statements).
      for (k = (*i)->nb_iterators + 1; k <= din; ++k)
      	{
      	  isl_local_space* ls =
      	    isl_local_space_from_space(isl_space_copy(space));
      	  cst = isl_equality_alloc (isl_local_space_copy(ls));
      	  tmp = isl_val_set_si(tmp, 1);
      	  if (k <= din - nia)
      	    cst = isl_constraint_set_coefficient_val (cst, isl_dim_param, k-1, isl_val_copy(tmp));
      	  else
      	    cst = isl_constraint_set_coefficient_val (cst, isl_dim_in,
						k-1 - (din-nia), isl_val_copy(tmp));
      	  lmap = isl_map_add_constraint (lmap, cst);
      	}

      // 2- Fill-in the access functions.
      scoplib_matrix_p m = (*i)->read;
      if (has_read)
      for (j = 0; m && j < m->NbRows; ++j)
      	{
      	  if (SCOPVAL_get_si(m->p[j][0]) == array_id)
      	    {
      	      int pos = 0;
      	      isl_map* tmap = isl_map_universe(isl_space_copy(space));
      	      do
      	      	{
      	      	  isl_constraint* cst;
		  isl_local_space* ls =
		    isl_local_space_from_space(isl_space_copy(space));
      	      	  cst = isl_equality_alloc (isl_local_space_copy(ls));
		  int ioff = 0;
      	      	  for (k = 1; k <= (*i)->nb_iterators; ++k)
      	      	    {
		      // Correctly skip missing iterators wrt. full embedding
		      // space (fs).
      	      	      tmp = isl_val_set_si(tmp, SCOPVAL_get_si(m->p[j][k]));
		      while (ioff < din &&
			     (*i)->iterators[k-1] != fs->iterators[ioff])
			ioff++;
		      ROSE_ASSERT(ioff < din);
		      ioff++;

		      if (ioff <= din - nia)
			cst = isl_constraint_set_coefficient_val (cst, isl_dim_param,
								  ioff-1, isl_val_copy(tmp));
		      else
			cst = isl_constraint_set_coefficient_val
			  (cst, isl_dim_in, ioff-1 - (din-nia), isl_val_copy(tmp));
		      // Propagate the offset in the access function.
		      if (ioff == din - nia)
		      	{
		      	  isl_val* t = isl_val_int_from_si
			    (isl_local_space_get_ctx(ls), 0);
		      	  t = isl_val_set_si(t, offset);
		      	  isl_val* t2 = isl_val_int_from_si
			    (isl_local_space_get_ctx(ls), 0);
		      	  t2 = isl_val_mul(isl_val_copy(tmp), isl_val_copy(t));
		      	  cst = isl_constraint_set_constant_val (cst, isl_val_copy(t2));
		      	  isl_val_free(t2);
		      	  isl_val_free(t);
		      	}
      	      	    }
      	      	  int off = (*i)->nb_iterators;
      	      	  for (k = 1; k <= nparam; ++k)
      	      	    {
      	      	      tmp = isl_val_set_si(tmp, SCOPVAL_get_si(m->p[j][k + off]));
      	      	      cst = isl_constraint_set_coefficient_val
		      	(cst, isl_dim_param, k + (din - nia) - 1, isl_val_copy(tmp));
	      	    }
      	      	  tmp = isl_val_set_si(tmp, SCOPVAL_get_si(m->p[j][m->NbColumns-1]));
		  // Add the constant part to the existing one.
		  isl_val* c = isl_val_int_from_si
		    (isl_local_space_get_ctx(ls), 0);
		  isl_val* tmp2 = isl_val_int_from_si
		    (isl_local_space_get_ctx(ls), 0);
		  c = isl_constraint_get_constant_val (cst);
		  tmp2 = isl_val_add(isl_val_copy(c), isl_val_copy(tmp));
      	      	  cst = isl_constraint_set_constant_val (cst, isl_val_copy(tmp2));
		  // isl_val_free(c);
		  // isl_val_free(tmp2);
		  // Fill-in the equality to output dimension part.
      	      	  tmp = isl_val_set_si(tmp, -1);
      	      	  cst = isl_constraint_set_coefficient_val (cst, isl_dim_out,
		  				      pos, isl_val_copy(tmp));
		  tmap = isl_map_add_constraint (tmap, cst);
	      	  ++pos;
      	      	  ++j;
      	      	}
      	      while (j < m->NbRows && SCOPVAL_get_si(m->p[j][0]) == 0);
      	      --j;

	      // std::cout << "UNIVERSE MAP: " << std::endl;
	      // isl_printer_print_map (pr, lmap);
	      // printf ("\n");
	      // std::cout << "STATEMENT MAP: " << std::endl;
	      // isl_printer_print_map (pr, tmap);
	      // printf ("\n");
	      // std::cout << "UNION MAP BEFORE: " << std::endl;
	      // isl_printer_print_map (pr, umap);
	      // printf ("\n");
	      umap = isl_map_union(umap,
				   isl_map_intersect(isl_map_copy(tmap), isl_map_copy(lmap)));

	      // std::cout << "UNION MAP AFTER: " << std::endl;
	      // isl_printer_print_map (pr, umap);
	      // printf ("\n");

      	    }
	}

      m = (*i)->write;
      if (has_write)
      for (j = 0; m && j < m->NbRows; ++j)
      	{
      	  if (SCOPVAL_get_si(m->p[j][0]) == array_id)
      	    {
      	      int pos = 0;
      	      isl_map* tmap = isl_map_universe(isl_space_copy(space));
      	      do
      	      	{
      	      	  isl_constraint* cst;
		  isl_local_space* ls =
		    isl_local_space_from_space(isl_space_copy(space));
      	      	  cst = isl_equality_alloc (isl_local_space_copy(ls));
		  int ioff = 0;
      	      	  for (k = 1; k <= (*i)->nb_iterators; ++k)
      	      	    {
		      // Correctly skip missing iterators wrt. full embedding
		      // space (fs).
      	      	      tmp = isl_val_set_si(tmp, SCOPVAL_get_si(m->p[j][k]));
		      while (ioff < din &&
			     (*i)->iterators[k-1] != fs->iterators[ioff])
			ioff++;
		      ROSE_ASSERT(ioff < din);
		      ioff++;

		      if (ioff <= din - nia)
			cst = isl_constraint_set_coefficient_val (cst, isl_dim_param,
							    ioff-1, isl_val_copy(tmp));
		      else
			{
			  cst = isl_constraint_set_coefficient_val
			    (cst, isl_dim_in, ioff-1 - (din-nia), isl_val_copy(tmp));
			}
		      // Propagate the offset in the access function.
		      if (ioff == din - nia)
		      	{
		      	  isl_val* t = isl_val_int_from_si
			    (isl_local_space_get_ctx(ls), 0);
		      	  t = isl_val_set_si(t, offset);
		      	  isl_val* t2 = isl_val_int_from_si
			    (isl_local_space_get_ctx(ls), 0);
		      	  t2 = isl_val_mul(isl_val_copy(tmp), isl_val_copy(t));
		      	  cst = isl_constraint_set_constant_val (cst, isl_val_copy(t2));
		      	  // isl_val_free(t2);
		      	  // isl_val_free(t);
		      	}
      	      	    }
      	      	  int off = (*i)->nb_iterators;
      	      	  for (k = 1; k <= nparam; ++k)
      	      	    {
      	      	      tmp = isl_val_set_si(tmp, SCOPVAL_get_si(m->p[j][k + off]));
      	      	      cst = isl_constraint_set_coefficient_val
			(cst, isl_dim_param, k + (din - nia) - 1, isl_val_copy(tmp));
	      	    }
      	      	  tmp = isl_val_set_si(tmp, SCOPVAL_get_si(m->p[j][m->NbColumns-1]));
		  // Add the constant part to the existing one.
		  isl_val* c = isl_val_int_from_si
		    (isl_local_space_get_ctx(ls), 0);
		  isl_val* tmp2 = isl_val_int_from_si
		    (isl_local_space_get_ctx(ls), 0);
		  c = isl_constraint_get_constant_val (cst);
		  tmp2 = isl_val_add(isl_val_copy(c), isl_val_copy(tmp));
      	      	  cst = isl_constraint_set_constant_val (cst, isl_val_copy(tmp2));
		  isl_val_free(c);
		  isl_val_free(tmp2);
		  // Fill-in the equality to output dimension part.
      	      	  tmp = isl_val_set_si(tmp, -1);
      	      	  cst = isl_constraint_set_coefficient_val (cst, isl_dim_out,
						      pos, isl_val_copy(tmp));
      	      	  tmap = isl_map_add_constraint (tmap, cst);
	      	  ++pos;
      	      	  ++j;
      	      	}
      	      while (j < m->NbRows && SCOPVAL_get_si(m->p[j][0]) == 0);
      	      --j;

	      umap = isl_map_union(umap,
				   isl_map_intersect(isl_map_copy(tmap), isl_map_copy(lmap)));
      	    }
	}
      isl_map_free (lmap);
    }

  return umap;
}

/**
 * void
 * substitute_name_in_past (s_past_node_t* root,
 *			    SgNode* scope,
 *			    scoplib_scop_p scop)
 *
 * Replace names (as char*) in a past tree with the corresponding
 * SgVariableSymbol in the Sage tree.
 *
 */
static
void traverse_collectfors(s_past_node_t* node, void* data)
{
  if (past_node_is_a(node, past_for))
    {
      PAST_DECLARE_TYPED(for, pf, node);
      int i;
      char** loops = (char**)data;
      for (i = 0; loops && loops[i]; ++i)
	if (pf->iterator->symbol->is_char_data)
	  if (! strcmp((char*)pf->iterator->symbol->data, loops[i]))
	    break;
      loops[i] = (char*)pf->iterator->symbol->data;
    }
}
static
char** get_loop_iters_in_past(s_past_node_t* root)
{
  int num_for_loops = past_count_for_loops (root);
  char** loops = (char**)malloc(sizeof(char*) * (num_for_loops + 1));
  int i;
  for (i = 0; i < num_for_loops + 1; ++i)
    loops[i] = NULL;
  past_visitor(root, traverse_collectfors, loops, NULL, NULL);

  return loops;
}
static
void traverse_variable(s_past_node_t* node, void* data)
{
  if (past_node_is_a(node, past_variable))
    {
      PAST_DECLARE_TYPED(variable, v, node);
      if (v->symbol->is_char_data)
	{
	  void** vals = (void**) data;
	  SgVariableSymbol** params = (SgVariableSymbol**) vals[0];
	  SgScopeStatement* scope = isSgScopeStatement((SgNode*)vals[1]);
	  char** loop_iters = (char**)vals[2];
	  ROSE_ASSERT(scope);
	  int i;
	  char* name = (char*) v->symbol->data;
	  SgVariableSymbol* sym = NULL;

	  // Skip loop iterators.
	  for (i = 0; loop_iters && loop_iters[i]; ++i)
	    if (! strcmp(name, loop_iters[i]))
	      return;

	  // Seek for an actual SCoP parameter.
	  for (i = 0; params && params[i]; ++i)
	    if (! strcmp(name, params[i]->get_name().getString().c_str()))
	      {
		sym = params[i];
		break;
	      }
	  if (sym == NULL)
	    {
	      // Seek for an iterator interpreted as a parameter.
	      // Find back the variable symbol from the symbol table.
	      SgName iterName(name);
	      Rose_STL_Container<SgNode*> scopes =
		NodeQuery::querySubTree(scope, V_SgScopeStatement);
	      SgSymbol* iterSymb = scope->lookup_symbol(iterName);
	      Rose_STL_Container<SgNode*>::iterator i = scopes.begin();
	      while (i != scopes.end() && iterSymb == NULL)
		{
		  iterSymb = isSgScopeStatement(*i)->lookup_symbol(iterName);
		  ++i;
		}
	      sym = isSgVariableSymbol(iterSymb);
	    }
	  if (sym)
	    {
	      v->symbol->is_char_data = 0;
	      v->symbol->data = sym;
	    }
	}
    }
}
static
void
substitute_name_in_past (s_past_node_t* root,
			 SgNode* scope,
			 scoplib_scop_p scop)
{
  void* data[3];
  if (scop->nb_parameters)
    {
      //data[0] = (void*)(scop->parameters);

      /// FIXME: Explicit copy into a NULL-terminated array.
      void** params = (void**)malloc((scop->nb_parameters + 1) * sizeof(void*));
      int i;
      for (i = 0; i < scop->nb_parameters; ++i)
	params[i] = scop->parameters[i];
      params[i] = NULL;
      data[0] = (void*)params;
    }
  else
    data[0] = NULL;
  data[1] = scope;
  data[2] = get_loop_iters_in_past(root);
  past_visitor (root, traverse_variable, data, NULL, NULL);
  free(data[2]);
}


/**
 * Scan a map.
 *
 * FIXME: unused.
 */
static
s_past_node_t* create_scanning_code (isl_map* diff,
				     SgNode* scope,
				     scoplib_scop_p scop)
{
  isl_space *dim;
  isl_union_map *umap = isl_union_map_from_map (isl_map_copy(diff));
  isl_ctx *ctx = isl_union_map_get_ctx(umap);
  CloogState *state;
  CloogOptions *options;
  CloogDomain *context;
  CloogUnionDomain *ud;
  CloogInput *input;
  struct clast_stmt *stmt;

  state = cloog_isl_state_malloc(ctx);
  options = cloog_options_malloc(state);
  options->language = CLOOG_LANGUAGE_C;
  options->strides = 1;
  options->sh = 1;

  ud = cloog_union_domain_from_isl_union_map(isl_union_map_copy(umap));

  dim = isl_union_map_get_space(umap);
  context = cloog_domain_from_isl_set(isl_set_universe(dim));

  input = cloog_input_alloc(context, ud);

  stmt = cloog_clast_create_from_input(input, options);


  // isl_printer* pr = isl_printer_to_file (ctx, stdout);
  // isl_printer_print_union_map (pr, umap);
  // printf ("\n");

  // clast_pprint(stdout, stmt, 0, options);

  s_past_node_t* ret = clast2past (stmt, 1);

  substitute_name_in_past (ret, scope, scop);


  cloog_clast_free(stmt);
  cloog_options_free(options);
  cloog_state_free(state);
  isl_union_map_free(umap);

  return ret;
}

/**
 * Scan a union map, according to the schedules in scop.
 *
 * FIXME: unused.
 */
static
s_past_node_t* isl_codegen (isl_union_map* umap,
			    SgNode* scope,
			    scoplib_scop_p scop)
{
  isl_space *dim;
  //isl_union_map *umap = isl_union_map_from_map (isl_map_copy(diff));
  isl_ctx *ctx = isl_union_map_get_ctx(umap);
  CloogState *state;
  CloogOptions *options;
  CloogDomain *context;
  CloogUnionDomain *ud;
  CloogInput *input;
  struct clast_stmt *stmt;

  state = cloog_isl_state_malloc(ctx);
  options = cloog_options_malloc(state);
  options->language = CLOOG_LANGUAGE_C;
  options->strides = 1;
  // options->sh = 1;
  // options->l = -1;
  // options->f = 1;
  // options->otl = 1;

  ud = cloog_union_domain_from_isl_union_map(isl_union_map_copy(umap));

  dim = isl_union_map_get_space(umap);
  context = cloog_domain_from_isl_set(isl_set_universe(dim));

  input = cloog_input_alloc(context, ud);

  stmt = cloog_clast_create_from_input(input, options);


  // isl_printer* pr = isl_printer_to_file (ctx, stdout);
  // isl_printer_print_union_map (pr, umap);
  // printf ("\n");

  clast_pprint(stdout, stmt, 0, options);

  s_past_node_t* ret = clast2past (stmt, 1);

  substitute_name_in_past (ret, scope, scop);


  cloog_clast_free(stmt);
  cloog_options_free(options);
  cloog_state_free(state);
  isl_union_map_free(umap);

  return ret;
}


/**
 * isl_set* traverse_bset_remove_cst(isl_set* myset)
 *
 * Remove redundant constraints on loop iterators introduced by the
 * iterator-as-parameter trick.
 *
 */
static
int traverse_cst(isl_constraint* cst, void* arg)
{
  isl_basic_set* bs = (isl_basic_set*)arg;
  if (isl_constraint_involves_dims(cst, isl_dim_param, 0,
				    isl_space_dim(isl_basic_set_get_space(bs),
						 isl_dim_param)))
    if (! isl_constraint_involves_dims
	(cst, isl_dim_set, 0,isl_space_dim(isl_basic_set_get_space(bs),
					   isl_dim_set)))
      {
	isl_basic_set_drop_constraint(bs, cst);
	int i;
	isl_constraint** data = (isl_constraint**)arg;
	for (i = 0; data[i]; ++i)
	  ;
	data[i] = cst;
      }
  return 0;
}
static
int traverse_count_cst(isl_constraint* cst, void* arg)
{
  int* i = (int*)arg;
  (*i)++;
  return 0;
}
static
int traverse_rm_cst(isl_basic_set* bset, void*)
{
  int nb_cst = 0;
  isl_basic_set_foreach_constraint(bset, traverse_count_cst, &nb_cst);
  isl_constraint* to_delete[nb_cst + 1];
  int i;
  for (i = 0; i <= nb_cst; ++i)
    to_delete[i] = NULL;
  isl_basic_set_foreach_constraint(bset, traverse_cst, to_delete);
  for (i = 0; to_delete[i]; ++i)
    isl_basic_set_drop_constraint(bset, to_delete[i]);
  return 0;
}
static
isl_set* traverse_bset_remove_cst(isl_set* myset)
{
  isl_set_foreach_basic_set(myset, traverse_rm_cst, NULL);
  return myset;
}


/**
 *
 * Scan a polyhedron with CLooG, and map past_variables with the
 * appropriate SgVariableSymbol*.
 *
 */
static
s_past_node_t* create_scanning_code (isl_set* diff,
				     SgNode* scope,
				     scoplib_scop_p scop)
{
  // Simplify the constraints.
  // std::cout << "Start CG" << std::endl;
  isl_set* cset = traverse_bset_remove_cst(isl_set_copy(diff));
  diff = cset;

  isl_space *dim;
  isl_union_set *uset = isl_union_set_from_set(diff);
  isl_set *set;
  isl_ctx *ctx = isl_union_set_get_ctx(uset);
  CloogState *state;
  CloogOptions *options;
  CloogDomain *context;
  CloogUnionDomain *ud;
  CloogInput *input;
  struct clast_stmt *stmt;

  // isl_printer* pr = isl_printer_to_file (ctx, stdout);
  // isl_printer_print_union_set (pr, uset);
  // printf ("\n");
  s_past_node_t* ret = NULL;

  if (isl_union_set_n_set(uset) > 1)
    isl_die(ctx, isl_error_invalid,
	    "code generation for more than one domain "
	    "requires a schedule", goto error);

  state = cloog_isl_state_malloc(ctx);
  options = cloog_options_malloc(state);
  options->language = CLOOG_LANGUAGE_C;
  options->strides = 1;
  options->sh = 1;

  set = isl_set_from_union_set(isl_union_set_copy(uset));
  ud = cloog_union_domain_from_isl_set(set);

  dim = isl_union_set_get_space(uset);
  context = cloog_domain_from_isl_set(isl_set_universe(dim));

  input = cloog_input_alloc(context, ud);

  stmt = cloog_clast_create_from_input(input, options);
  //clast_pprint(stdout, stmt, 0, options);

  ret = clast2past (stmt, 1);

  substitute_name_in_past (ret, scope, scop);

  cloog_clast_free(stmt);
  cloog_options_free(options);
  cloog_state_free(state);
 error:
  isl_union_set_free(uset);

  // std::cout << "CG: done" << std::endl;

  return ret;
}


/**
 * Compute the data space of an iteration of a SgStatement 'node'.
 *
 */
static
isl_map* compute_data_space (SgNode* node,
			     scoplib_scop_p scop,
			     int array_id,
			     int offset,
			     bool write_out_mode,
			     bool read_only_references,
			     isl_space** isl_space_desc)
{
  // If node is a loop, get a pointer to its body, otherwise keep node
  // as-is.
  SgStatement* curnode = isSgForStatement(node);
  bool is_loop = true;
  if (!curnode)
    {
      curnode = isSgStatement(node);
      ROSE_ASSERT(curnode);
      is_loop = false;
    }
  else
    curnode = isSgForStatement(curnode)->get_loop_body();
  // Collect the statements in the tree.
  std::vector<SgNode*> query =
    NodeQuery::querySubTree(curnode, V_SgExprStatement);
  std::vector<SgNode*> polystmts;
  for (std::vector<SgNode*>::iterator j = query.begin(); j != query.end(); ++j)
    {
      ScopStatementAnnotation* annot =
	(ScopStatementAnnotation*)(*j)->getAttribute("ScopStmt");
      if (annot)
	polystmts.push_back(*j);
    }
  // Collect the scoplib statements associated with the ROSE
  // statements, and compute the maximal dimensionality (for common
  // embedding).
  std::vector<scoplib_statement_p> sstmts;
  int max_dim = 0;
  for (std::vector<SgNode*>::iterator j = polystmts.begin();
       j != polystmts.end(); ++j)
    {
      scoplib_statement_p s;
      for (s = scop->statement; s && s->body != (char*)(*j);
	   s = s->next)
	;
      if (! s)
	{
	  std::cout << "ERROR: statement not found" << std::endl;
	  ROSE_ASSERT(0);
	}
      else
	{
	  int k;
	  bool was_found = false;
	  for (k = 0; k < s->read->NbRows; ++k)
	    if (SCOPVAL_get_si(s->read->p[k][0]) == array_id)
	      {
		was_found = true;
		break;
	      }
	  if (!was_found)
	    for (k = 0; k < s->write->NbRows; ++k)
	      if (SCOPVAL_get_si(s->write->p[k][0]) == array_id)
		{
		  was_found = true;
		  break;
		}
	  if (was_found)
	    {
	      if (s->nb_iterators > max_dim)
		max_dim = s->nb_iterators;
	      sstmts.push_back(s);
	    }
	}
    }
  // Skip the tree if the array is never referenced.
  if (sstmts.size() == 0)
    return NULL;

  int loop_level = -1;
  if (is_loop)
    {
      // Compute the loop active level.
      scoplib_statement_p tmp = *(sstmts.begin());
      ScopForAnnotation* annot =
	(ScopForAnnotation*)(node)->getAttribute("ScopFor");
      ROSE_ASSERT(annot);
      for (loop_level = 0; loop_level < tmp->nb_iterators &&
	     tmp->iterators[loop_level] != (char*)annot->iterator;
	   ++loop_level)
	;
      loop_level = max_dim - (loop_level + 1);
    }

  // din == loop_level if all iter active.


  /// LNP: DEBUG:
// 	  isl_map* dspace = compute_data_space (fs, scop, array_id,
// 						0, false, true, &dim);
// isl_map* compute_data_space (SgNode* node,
// 			     scoplib_scop_p scop,
// 			     int array_id,
// 			     int offset,
// 			     bool write_out_mode = false,
// 			     bool read_only_references = true,
// 			     isl_space** isl_space_desc)

  int has_read = write_out_mode ? 0 : 1;
  int has_write = read_only_references ? 0 : 1;


  // if (write_out_mode)
  //   loop_level++;
  // Compute actual data space.
  isl_map* data_space = compute_data_space_helper (sstmts, scop, array_id,
						   loop_level, offset,
						   has_read,
						   has_write,
						   isl_space_desc);

  return data_space;
}


/**
 * Compute the Polynomial associated to a set.
 *
 */
static
Polynomial computeCard(isl_set* aset, scoplib_scop_p scop, bool approx)
{
  ROSE_ASSERT(aset);
  // Use rectangular hull + lexmin/max to compute the size of the set.
  // if (approx)
  isl_set* myset = isl_set_remove_divs(isl_set_copy(aset));
  myset = isl_set_coalesce(myset);

  // Debug.
  // isl_ctx* ctxt = isl_ctx_alloc();
  // isl_printer* pr = isl_printer_to_file (ctxt, stdout);
  // std::cout << "CC: Input set after coalescing: " << std::endl;
  // isl_printer_print_set(pr, myset);
  // printf ("\n");

  if (isl_set_n_basic_set(myset) > 1)
    {
      isl_basic_set* bsun = isl_set_unshifted_simple_hull(isl_set_copy(myset));
      isl_set_free(myset);
      myset = isl_set_from_basic_set (bsun);
    }

  // // Debug.
  // std::cout << "CC: Base set: " << std::endl;
  // isl_printer_print_set(pr, myset);
  // printf ("\n");

  // For each dimension l, compute its size as lexmax(s,l) - lexmin(s,l)
  std::vector<Polynomial> dim_sols;
  int ndim = isl_set_dim(isl_set_copy(myset), isl_dim_set);
  for (int l = 0; l < ndim; ++l)
    {
      isl_pw_aff* min = isl_set_dim_min(isl_set_copy(myset), l);
      isl_pw_aff* max = isl_set_dim_max(isl_set_copy(myset), l);

      
      isl_pw_aff* diff2 = isl_pw_aff_sub(isl_pw_aff_copy(max),
					isl_pw_aff_copy(min));
      // std::cout << "min: ";
      // isl_printer_print_pw_aff(pr, min);
      // std::cout << "\nmax: ";
      // isl_printer_print_pw_aff(pr, max);
      // std::cout << "\ndiff2: ";
      // isl_printer_print_pw_aff(pr, diff2);
      isl_pw_aff* diff = isl_pw_aff_coalesce (isl_pw_aff_copy (diff2));
      // std::cout << "\ndiff: ";
      // isl_printer_print_pw_aff(pr, diff);
      // // isl_val* vmin = isl_set_min_val(myset, minaff);

      // printf ("\n");
      Polynomial p(diff);
      p.max += 1;
      p.min += 1;
      p.avg += 1;
      p.coef[0] += 1;
      // p.print();
      dim_sols.push_back(p);
    }
  if (dim_sols.size() == 0)
    {
      Polynomial p;
      p.coef.push_back(0);
      p.power.push_back(0);
      p.sym.push_back(NULL);
      return p;
    }

  Polynomial sol(dim_sols[0]);
  sol.zero();
  sol.setConstant(1);
  for (int l = 0; l < ndim; ++l)
    {
      /// FIXME: ambiguous.
      // std::cout << "dim_sols[l].max=" << dim_sols[l].max << std::endl;
      sol.max *= dim_sols[l].max;
      sol.min *= dim_sols[l].min;
      sol.avg *= dim_sols[l].avg;
    }
  // std::cout << "POLY FOUND: " << std::endl;
  //  sol.print();

  return sol;
}


/**
 * Compute the Polynomial associated to the range of a map.
 *
 */
static
Polynomial computeCard(isl_map* amap, scoplib_scop_p scop, bool approx)
{
  isl_set* ran = isl_map_range(isl_map_copy(amap));
  Polynomial p = computeCard(ran, scop, approx);
  isl_set_free(ran);

  return p;
}


/**
 * Create a copy statement from a local/global array to a global/local
 * array.
 *
 *
 */
static
SgNode* createCopyStatement(SgVariableSymbol* array_global,
			    SgVariableSymbol* array_local,
			    std::vector<SgVariableSymbol*> iters,
			    bool isCopyIn,
			    std::vector<SgNode*> local_array_dims)
{
  // Build LHS
  SgExpression* curnode_l = SageBuilder::buildVarRefExp(array_local);
  int pos = 0;
  SgTreeCopy treeCopy;
  if (isSgArrayType(array_global->get_type()))
    for (std::vector<SgVariableSymbol*>::iterator i = iters.begin();
	 i != iters.end(); ++i, ++pos)
      {
	SgExpression* modexp;
	SgIntVal* iv = isSgIntVal(local_array_dims[pos]);
	if ((iv && iv->get_value() != 1) || !iv)
	  {
	    modexp = SageInterface::copyExpression
	      (isSgExpression(local_array_dims[pos]));
	    modexp = SageBuilder::buildBinaryExpression<SgModOp>
	      (SageBuilder::buildVarRefExp(*i), modexp);
	  }
	else
	  modexp = SageBuilder::buildIntVal(0);
	curnode_l = SageBuilder::buildPntrArrRefExp
	  (curnode_l, modexp);
      }

  // Build RHS
  SgExpression* curnode_r = SageBuilder::buildVarRefExp(array_global);
  if (isSgArrayType(array_global->get_type()))
    for (std::vector<SgVariableSymbol*>::iterator i = iters.begin();
	 i != iters.end(); ++i)
      {
	curnode_r = SageBuilder::buildPntrArrRefExp
	  (curnode_r, SageBuilder::buildVarRefExp(*i));
      }

  SgExpression* assign;
  if (isCopyIn)
    assign = SageBuilder::buildBinaryExpression<SgAssignOp>
      (curnode_l, curnode_r);
  else
    assign = SageBuilder::buildBinaryExpression<SgAssignOp>
      (curnode_r, curnode_l);

  return SageBuilder::buildExprStatement(assign);
}


/**
 * Remove empty basic blocks in the tree.
 *
 */
void removeEmptyBasicBlocks(SgNode* root)
{
  // Collect all loops.
  std::vector<SgNode*> bbs =
    NodeQuery::querySubTree(isSgStatement(root), V_SgBasicBlock);
  for (std::vector<SgNode*>::iterator i = bbs.begin(); i != bbs.end(); ++i)
    {
      std::vector<SgNode*> s =
	NodeQuery::querySubTree(isSgStatement(*i), V_SgVarRefExp);
      if (s.size() == 0)
	SageInterface::removeStatement(isSgStatement(*i));
    }
}

/**
 * Returns true of the loop surrounds at least 3 loops. Some kind of
 * way to fake a loop is a 'tile loop' and push the communications
 * outside a 3D nest when using the 'LMP_COMMSCHED_TILEBOUND' mode. 
 *
 * Fixme: sort of useless now, should be removed.
 */
static
bool isTileLoop(SgNode* n)
{
  SgForStatement* fs = isSgForStatement(n);
  if (fs == NULL)
    return false;

  /// LNP: FIXME: implement the real thing...
  std::vector<SgNode*> s =
    NodeQuery::querySubTree(fs->get_loop_body(), V_SgForStatement);
  int max_loop_depth = 0;
  for (std::vector<SgNode*>::iterator i = s.begin(); i != s.end(); ++i)
    {
      if (isSgForStatement(*i))
	{
	  SgNode* tmp = *i;
	  int depth = 0;
	  while (tmp != n)
	    {
	      if (isSgForStatement(tmp))
		depth++;
	      tmp = tmp->get_parent();
	    }
	  if (depth > max_loop_depth)
	    max_loop_depth = depth;
	}
    }
  if (max_loop_depth == 3)
    return true;
  return false;
}





/**
 * Compute the set of loops along which we are bufferizing.
 *
 * mode LMP_COMMSCHED_TILEBOUND is putting the comm. outside a 3D
 * nest, BSL mode attempts to maximize BS under max. BS constraint.
 */
static
std::vector<SgNode*>
computeBestSolution(std::map<SgNode*, std::pair<isl_set*, isl_set*> > sol_set,
		    isl_map* full_dspace,
		    int max_buff_size,
		    std::map<SgNode*, isl_map*>& buffer_desc,
		    scoplib_scop_p scop,
		    SgNode* scopRoot,
		    int commsched_mode)
{
  // // DBG:
  // for (j = sol_set.begin(); j != sol_set.end(); ++j)
  // 	{
  // 	  ScopForAnnotation* annot =
  // 	    (ScopForAnnotation*)(j->first->getAttribute("ScopFor"));
  // 	  std::cout << "Considering loop " << annot->iterator->get_name()
  // 		    << std::endl;
  // 	  std::cout << "set for comm: " << std::endl;
  // 	  isl_printer_print_set(pr, j->second.first);
  // 	  create_scanning_code(isl_set_copy(j->second.first));
  // 	  std::cout << "set for preload: " << std::endl;
  // 	  isl_printer_print_set(pr, j->second.second);
  // 	  create_scanning_code(isl_set_copy(j->second.second));
  // 	  std::cout << "Compute ops: " << std::endl;
  // 	  isl_printer_print_pw_qpolynomial(pr, op_cost[j->first]);
  // 	  std::cout << std::endl;
  // 	  std::cout << "Buffer size: " << std::endl;
  // 	  int cnt = 1;
  // 	  for (std::vector<isl_pw_qpolynomial*>::iterator
  // 		 p = buffer_size[j->first].begin();
  // 	       p != buffer_size[j->first].end(); ++p, ++cnt)
  // 	    {
  // 	      std::cout << "dim " << cnt << std::endl;
  // 	      isl_printer_print_pw_qpolynomial(pr, (*p));
  // 	      std::cout << std::endl;

  // 	      isl_pw_qpolynomial* np = isl_pw_qpolynomial_to_polynomial
  // 	      	(isl_pw_qpolynomial_copy(*p), 1);
  // 	      SgNode* t = convert_pw_qpoly_to_sage(np, scop, root);

  // 	      std::cout << "CONVERTED EXPR: " << std::endl;
  // 	      std::cout << t->unparseToCompleteString() << std::endl;

  // 	      std::cout << "CONVERTED Poly: " << std::endl;
  // 	      Polynomial p = convert_pw_qpoly_to_poly(np, scop);
  // 	      p.print();
  // 	    }
  // 	}

  // Compute the (best?) solution.
  std::vector<SgNode*> outputsol;
  std::map<SgNode*, std::pair<isl_set*, isl_set*> >::iterator j;

  // If in tiling mode: prune the set of candidate loops.
  if (commsched_mode == LMP_COMMSCHED_TILEBOUND)
    {
      // Remove from the initial set all non-inner-most-tile-loops.
      std::map<SgNode*, std::pair<isl_set*, isl_set*> >::iterator lp;

      std::vector<SgNode*> toErase;
      std::vector<SgNode*> allLoops;
      bool hasTileLoops = false;
      for (lp = sol_set.begin(); lp != sol_set.end(); ++lp)
	{
	  if (isTileLoop(lp->first))
	    hasTileLoops = true;
	  allLoops.push_back(lp->first);
	}
      if (hasTileLoops)
	{
	  for (std::vector<SgNode*>::iterator lp = allLoops.begin();
	       lp != allLoops.end(); ++lp)
	    {
	      bool eraseLoop = true;
	      if (isTileLoop(*lp))
		{
		  SgForStatement* forLoop = isSgForStatement(*lp);
		  if (forLoop)
		    {
		      std::vector<SgNode*> inForLoops =
			NodeQuery::querySubTree(forLoop->get_loop_body(),
						V_SgForStatement);
		      std::vector<SgNode*>::iterator ip;
		      for (ip = inForLoops.begin(); ip != inForLoops.end();
			   ++ip)
			{
			  if (isTileLoop(*ip))
			    break;
			}
		      if (inForLoops.size() && ip == inForLoops.end())
			eraseLoop = false;
		    }
		}
	      if (eraseLoop)
		toErase.push_back(*lp);
	    }

	}
      for (std::vector<SgNode*>::iterator lp = toErase.begin();
	   lp != toErase.end(); ++lp)
	sol_set.erase(*lp);
      ROSE_ASSERT(sol_set.size() > 0);
    }


  int iterId = 1;
  do
    {
      // std::cout << "ITERATION #" << iterId++ << std::endl;

      // Compute the data space polynomial.
      Polynomial ds = computeCard(full_dspace, scop, true);
      // std::cout << "full space poly: " << std::endl;
      // ds.print();

      Polynomial thresold = Polynomial(ds);
      thresold.zero();
      thresold.setConstant(max_buff_size);

      std::map<SgNode*, Polynomial> sols_volume;
      std::map<SgNode*, Polynomial> sols_volume_valid;

      ROSE_ASSERT(sol_set.size() > 0);
      // Compute the polynomial of each solution.
      for (j = sol_set.begin(); j != sol_set.end(); ++j)
	{
	  isl_map* buffer_loop = buffer_desc[j->first];
	  //buffer_loop = isl_map_coalesce(buffer_loop);
	  // isl_ctx* ctxt = isl_ctx_alloc();
	  // isl_printer* pr = isl_printer_to_file (ctxt, stdout);
	  // isl_printer_print_map(pr, buffer_loop);
	  // printf ("\n");

	  Polynomial s = computeCard(buffer_loop, scop, true);
	  // std::cout << "Sol card: ok" << std::endl;
	  // s.print();
	  sols_volume[j->first] = s;
	  if (s.isLessThan(thresold) && !s.isInfinite())
	    sols_volume_valid[j->first] = s;
	}
      // Find the solution that maximizes the buffer size, and
      // minimizes the comm.
      std::vector<SgNode*> best_sols;

	  // std::cout << "ds: " << std::endl;
	  // ds.print();

      Polynomial bestP(ds);

	  // std::cout << "bestP: " << std::endl;
	  // bestP.print();

      bestP.zero();

	  // std::cout << "bestP zeroed: " << std::endl;
	  // bestP.print();

      ROSE_ASSERT(sols_volume_valid.size() > 0);
      for (std::map<SgNode*, Polynomial>::iterator k =
	     sols_volume_valid.begin(); k != sols_volume_valid.end(); ++k)
	{
	  // std::cout << "ITER" << std::endl;
	  // k->first->unparseToCompleteString();
	  // std::cout << "poly: " << std::endl;
	  // k->second.print();
	  // std::cout << "base: " << std::endl;
	  // bestP.print();
	  if (bestP.isLessThan(k->second))
	    {
	      // std::cout << "OK, found one sol!" << std::endl;
	      bestP = k->second;
	    }
	  // else
	  //   std::cout << "BOO it doesn't work!" << std::endl;
	}
      // std::cout << "BestP: " << std::endl;
      // bestP.print();
      for (std::map<SgNode*, Polynomial>::iterator k =
	     sols_volume_valid.begin(); k != sols_volume_valid.end(); ++k)
	{
	  if (bestP.isEqualTo(k->second))
	    best_sols.push_back(k->first);
	}
      // In the optimally-sized solutions, find the ones that minimizes
      // the communication.
      Polynomial bestS(bestP);
      std::vector<SgNode*> really_best_sols;
      ROSE_ASSERT(best_sols.size() > 0);
      for (std::vector<SgNode*>::iterator k = best_sols.begin();
	   k != best_sols.end(); ++k)
	{
	  std::pair<isl_set*, isl_set*> sp = sol_set[*k];
	  Polynomial pc = computeCard(sp.first, scop, true);
	  if (pc.isLessOrEqual(bestS))
	    {
	      really_best_sols.push_back(*k);
	      bestS = pc;
	    }
	}
      if (really_best_sols.size() == 0)
	{
	  ROSE_ASSERT(best_sols.size() > 0);
	  really_best_sols.push_back(*(best_sols.begin()));
	}
      // In the best solution sets, find the outer-most loop.
      SgNode* bestLoop = NULL;
      for (std::vector<SgNode*>::iterator k = really_best_sols.begin();
	   k != really_best_sols.end(); ++k)
	{
	  bestLoop = *k;
	  /// FIXME: implement that.
	}
      // std::cout << "FOUND a sol!" << std::endl;

      ROSE_ASSERT(bestLoop);
      // outputsol.push_back(bestLoop);

      // For imperfectly-nest loops, we have to bufferize all
      // loops at the same loop level as the solution.

      // a- get all loops at the same loop level.
      SgNode* enclosingContext = getEnclosingNode<SgForStatement>(bestLoop);
      Rose_STL_Container<SgNode*> qloops;
      if (enclosingContext == NULL)
	{
	  enclosingContext = scopRoot;
	  qloops = NodeQuery::querySubTree(enclosingContext, V_SgForStatement);
	}
      else
	{
	  SgForStatement* fs = isSgForStatement(enclosingContext);
	  qloops = NodeQuery::querySubTree(fs->get_loop_body(),
					   V_SgForStatement);
	}
      for (Rose_STL_Container<SgNode*>::iterator r = qloops.begin();
      	   r != qloops.end(); ++r)
      	{

      	  // Ensure there is no loop between bestLoop.parent and the
      	  // loop.
	  SgNode* enclosingFor = getEnclosingNode<SgForStatement>(*r);
	  if (!enclosingFor || enclosingFor == enclosingContext)
	    if (sol_set.find(*r) != sol_set.end())
	      outputsol.push_back(*r);
      	}

      // b- remove from the solution set all loops within the loop nest.
      for (Rose_STL_Container<SgNode*>::iterator r = qloops.begin();
      	   r != qloops.end(); ++r)
	sol_set.erase(*r);
      sol_set.erase(enclosingContext);

      SgNode* enclosingF = getEnclosingNode<SgForStatement>(enclosingContext);
      while (enclosingF)
	{
	  // Remove inner loops from the loops we have already marked
	  // for bufferization.
	  Rose_STL_Container<SgNode*> qloops =
	    NodeQuery::querySubTree
	    (isSgForStatement(enclosingF)->get_loop_body(), V_SgForStatement);
	  bool has_live_loop = false;
	  if (qloops.size())
	    {
	      for (Rose_STL_Container<SgNode*>::iterator r = qloops.begin();
		   r != qloops.end(); ++r)
		{
		  if (sol_set.find(*r) != sol_set.end())
		    {
		      has_live_loop = true;
		      break;
		    }
		}
	    }
	  if (!has_live_loop)
	    sol_set.erase(enclosingF);
	  enclosingF = getEnclosingNode<SgForStatement>(enclosingF);
	}

  // ScopForAnnotation* annot =
  //   (ScopForAnnotation*)(bestLoop->getAttribute("ScopFor"));
  // ROSE_ASSERT(annot);
  // std::cout << "Best loop: " << annot->iterator->get_name()
  // 	    << std::endl;
    }
  while (sol_set.size());


  // std::cout << "XXXXXXXXXXXXXX SOLUTION FOUND XXXXXXXXXXXXXX" << std::endl;


  return outputsol;
}


/**
 * Helper. Convert std::vector<SgNode*> constaining references to
 * std::set<SgVariableSymbol*>
 *
 *
 */
static
std::set<SgVariableSymbol*>
convertVarRefExpVectorToSymbolSet(std::vector<SgNode*>& refs)
{
  std::set<SgVariableSymbol*> result;

  std::vector<SgNode*>::const_iterator i;
  for (i = refs.begin(); i != refs.end(); ++i)
    {
      if (*i == NULL)
	continue;
      SgVarRefExp* v = isSgVarRefExp(*i);
      ROSE_ASSERT(v);
      SgVariableSymbol* symbol = v->get_symbol();
      if (symbol)
	result.insert(symbol);
    }

  return result;
}

/**
 *
 *
 */
void replaceSymbol(SgNode* root,
		   SgVariableSymbol* sorig,
		   SgVariableSymbol* snew)
{
  Rose_STL_Container<SgNode*> vrefs =
    NodeQuery::querySubTree(root, V_SgVarRefExp);
  for (Rose_STL_Container<SgNode*>::iterator i = vrefs.begin();
       i != vrefs.end(); ++i)
    {
      SgVarRefExp* v = isSgVarRefExp(*i);
      ROSE_ASSERT(v);
      if (v->get_symbol() == sorig)
	v->set_symbol(snew);
    }
}


/**
 * Add the initial value of the surrounded loop iterator before the
 * preload code.
 *
 */
static
SgNode* addIteratorNextVal(SgNode* preload, SgNode* loop)
{
  Rose_STL_Container<SgNode*> vrefs =
    NodeQuery::querySubTree(preload, V_SgVarRefExp);
  std::set<SgVariableSymbol*> symsp = convertVarRefExpVectorToSymbolSet(vrefs);

  vrefs = NodeQuery::querySubTree(loop, V_SgVarRefExp);
  std::set<SgVariableSymbol*> symsl = convertVarRefExpVectorToSymbolSet(vrefs);

  std::set<SgVariableSymbol*> inter;
  set_intersection(symsl.begin(), symsl.end(), symsp.begin(), symsp.end(),
		   std::inserter(inter, inter.begin()));

  SgNode* ret = NULL;
  SgBasicBlock* bb = isSgBasicBlock(preload);
  ROSE_ASSERT(bb);
  if (inter.size())
    {
      Rose_STL_Container<SgNode*> qloops =
	NodeQuery::querySubTree(loop, V_SgForStatement);
      for (Rose_STL_Container<SgNode*>::iterator i = qloops.begin();
	   i != qloops.end(); ++i)
	{
	  ScopForAnnotation* annot =
	    (ScopForAnnotation*)(*i)->getAttribute("ScopFor");
	  if (annot)
	    {
	      SgForStatement* fs = isSgForStatement(*i);
	      ROSE_ASSERT(fs);
	      if (inter.find(annot->iterator) != inter.end())
		{
		  SgBasicBlock* newbb = SageBuilder::buildBasicBlock();
		  std::string newit(annot->iterator->get_name().getString());
		  newit += "__local__";
		  SgVariableDeclaration* decl =
		    SageBuilder::buildVariableDeclaration
		    (newit, SageBuilder::buildIntType(), NULL, newbb);
		  SgStatement* inc = SageBuilder::buildExprStatement
		    (SageBuilder::buildBinaryExpression<SgAssignOp>
		     (SageBuilder::buildVarRefExp
		      (SageInterface::getFirstVarSym(decl)),
		      SageBuilder::buildBinaryExpression<SgAddOp>
		      (SageBuilder::buildVarRefExp(annot->iterator),
		       SageBuilder::buildIntVal(1))));
		  newbb->prepend_statement(inc);
		  newbb->prepend_statement(decl);
		  SgExpression* cond = SageInterface::deepCopy(annot->ub);
		  replaceSymbol(bb, annot->iterator,
				SageInterface::getFirstVarSym(decl));
		  replaceSymbol(cond, annot->iterator,
				SageInterface::getFirstVarSym(decl));
		  SgIfStmt* ifs = SageBuilder::buildIfStmt
		    (cond, SageBuilder::buildBasicBlock(bb), NULL);
		  newbb->append_statement(ifs);
		  ret = newbb;
		}
	    }
	}
    }
  return ret;
}


/**
 * Add the initial value of the surrounded loop iterator before the
 * preload code.
 *
 */
static
void addIteratorLb(SgNode* preload, SgNode* loop)
{
  Rose_STL_Container<SgNode*> vrefs =
    NodeQuery::querySubTree(preload, V_SgVarRefExp);
  std::set<SgVariableSymbol*> symsp = convertVarRefExpVectorToSymbolSet(vrefs);

  vrefs = NodeQuery::querySubTree(loop, V_SgVarRefExp);
  std::set<SgVariableSymbol*> symsl = convertVarRefExpVectorToSymbolSet(vrefs);

  std::set<SgVariableSymbol*> inter;
  set_intersection(symsl.begin(), symsl.end(), symsp.begin(), symsp.end(),
		   std::inserter(inter, inter.begin()));

  SgBasicBlock* bb = isSgBasicBlock(preload);
  ROSE_ASSERT(bb);
  if (inter.size())
    {
      Rose_STL_Container<SgNode*> qloops =
	NodeQuery::querySubTree(loop, V_SgForStatement);
      for (Rose_STL_Container<SgNode*>::iterator i = qloops.begin();
	   i != qloops.end(); ++i)
	{
	  ScopForAnnotation* annot =
	    (ScopForAnnotation*)(*i)->getAttribute("ScopFor");
	  if (annot)
	    {
	      SgForStatement* fs = isSgForStatement(*i);
	      ROSE_ASSERT(fs);
	      if (inter.find(annot->iterator) != inter.end())
		{
		  std::string newit(annot->iterator->get_name().getString());
		  newit += "__local__";
		  SgVariableDeclaration* decl =
		    SageBuilder::buildVariableDeclaration
		    (newit, SageBuilder::buildIntType(), NULL, bb);
		  SgStatement* init = SageBuilder::buildExprStatement
		    (SageBuilder::buildBinaryExpression<SgAssignOp>
		     (SageBuilder::buildVarRefExp
		      (SageInterface::getFirstVarSym(decl)),
		      SageInterface::deepCopy(annot->lb)));
		  replaceSymbol(bb, annot->iterator,
				SageInterface::getFirstVarSym(decl));
		  bb->prepend_statement(init);
		  bb->prepend_statement(decl);
		}
	    }
	}
    }
}


/**
 *
 * void annotateLoopTripCount(SgNode* root,
 *			      scoplib_scop_p scop,
 *			      std::map<SgNode*, isl_set*>& loopTCmap)
 *
 * Annotate each loop with an estimator of its trip count.
 *
 */
static
isl_set* convert_partial_domain_to_isl_set(scoplib_statement_p s, int nia)
{
/**
 * nia -> number of outer loop made inactive (different semantics).
 *
 */
  // Initialize the ISL map.
  isl_ctx* ctxt = isl_ctx_alloc();
  int nparam = s->domain->elt->NbColumns - 2 - s->nb_iterators;
  int dim = s->nb_iterators;
  isl_space* space = isl_space_set_alloc(ctxt, nparam + nia, dim - nia);

  // Declare output map.
  isl_set* domain = isl_set_universe (isl_space_copy(space));

  isl_val* tmp = isl_val_int_from_si(ctxt, 0);

  // fill-in the domain of the statement.
  scoplib_matrix_p dom = s->domain->elt;
  int j, k;
  isl_constraint* cst;
  for (j = 0; j < dom->NbRows; ++j)
    {
      isl_local_space* ls =
	isl_local_space_from_space(isl_space_copy(space));
      if (SCOPVAL_get_si(dom->p[j][0]) == 0)
	cst = isl_equality_alloc (isl_local_space_copy(ls));
      else
	cst = isl_inequality_alloc (isl_local_space_copy(ls));

      // iterators in the original domain.
      for (k = 1; k <= s->nb_iterators; ++k)
	{
	  tmp = isl_val_set_si(tmp, SCOPVAL_get_si(dom->p[j][k]));
	  if (k <= nia)
	    cst = isl_constraint_set_coefficient_val (cst, isl_dim_param, k-1,
						isl_val_copy(tmp));
	  else
	    cst = isl_constraint_set_coefficient_val (cst, isl_dim_set,
						      k-1 - nia,
						      isl_val_copy(tmp));
	}
      // Skip missing dimensions.
      int off = k;
      // parameters in the original domain.
      for (; k <= dim + nparam; ++k)
	{
	  tmp = isl_val_set_si(tmp, SCOPVAL_get_si(dom->p[j][k]));
	  cst = isl_constraint_set_coefficient_val (cst, isl_dim_param,
						    k-off + nia, isl_val_copy(tmp));
	}
      tmp = isl_val_set_si(tmp, SCOPVAL_get_si(dom->p[j][k]));
      cst = isl_constraint_set_constant_val (cst, isl_val_copy(tmp));
      domain = isl_set_add_constraint (domain, cst);
    }

  return domain;
}
static
isl_set* project_set_onto_dim(isl_set* set, int dim)
{
  isl_set* ret = isl_set_copy(set);
  // Eliminate dimensions 0..dim-1.
  if (dim)
    ret = isl_set_project_out (ret, isl_dim_set, 0, dim);
  // Eliminate dimensions dim+1..n.
  int ndim = isl_set_dim(isl_set_copy(ret), isl_dim_set);
  if (ndim > 1)
    ret = isl_set_project_out (isl_set_copy(ret),
				   isl_dim_set, 1, ndim - 1);
  return ret;
}
static
void annotateLoopTripCount(SgNode* root,
			   scoplib_scop_p scop,
			   std::map<SgNode*, isl_set*>& loopTCmap)
{
  // Get all loops.
  std::vector<SgNode*> forLoops =
    NodeQuery::querySubTree(root, V_SgForStatement);

  for (std::vector<SgNode*>::iterator i = forLoops.begin(); i != forLoops.end();
       ++i)
    {
      SgForStatement* fs = isSgForStatement(*i);
      ROSE_ASSERT(fs);
      // Find a polyhedral statement in this loop.
      std::vector<SgNode*> stmts =
	NodeQuery::querySubTree(fs, V_SgExprStatement);
      SgNode* ps = NULL;
      for (std::vector<SgNode*>::iterator j = stmts.begin(); j != stmts.end();
	   ++j)
	{
	  ScopStatementAnnotation* annot =
	    (ScopStatementAnnotation*)(*j)->getAttribute("ScopStmt");
	  if (annot)
	    {
	      ps = *j;
	      break;
	    }
	}
      isl_set* domain = NULL;
      if (ps)
	{
	  // Polyhedral loop.
	  scoplib_statement_p s = scop->statement;
	  for (; s && s->body != (char*)ps; s = s->next)
	    ;
	  ROSE_ASSERT(s);
	  // Compute the number of surrounding loop.
	  SgNode* tmp = fs->get_parent();
	  int num_outer_loops = 0;
	  while (tmp && tmp != root)
	    {
	      if (isSgForStatement(tmp))
		++num_outer_loops;
	      tmp = tmp->get_parent();
	    }
	  // isl_pw_aff* min = isl_set_dim_min(isl_set_copy(domain),
	  // 				    num_outer_loops);
	  // isl_pw_aff* max = isl_set_dim_max(isl_set_copy(domain),
	  // 				    num_outer_loops);
	  // isl_pw_aff* diff = isl_pw_aff_sub(isl_pw_aff_copy(max),
	  // 				    isl_pw_aff_copy(min));
	  // Polynomial p(diff);
	  // p.coef[0] += 1;
	  // tripCount = p;
	  // isl_pw_aff_free(min);
	  // isl_pw_aff_free(max);
	  // isl_pw_aff_free(diff);

	  // Convert the statement domain into an isl_set.
	  // Eliminate dimensions 0..l-1.
	  domain = convert_partial_domain_to_isl_set(s, num_outer_loops);

	  // Eliminate dimensions l+1..n.
	  int ndim = isl_set_dim(domain, isl_dim_set);
	  if (num_outer_loops + 1 < s->nb_iterators)
	    domain = isl_set_project_out (isl_set_copy(domain), isl_dim_set,
	  				  1, ndim - 1);
	}
      else
	{
	  // Communication/preload loop.
	  isl_set* scanned = loopTCmap[fs];
	  ROSE_ASSERT(scanned);
	  // Compute the number of surrounding loops.
	  SgNode* tmp = fs->get_parent();
	  int num_outer_loops = 0;
	  while (tmp && tmp != root)
	    {
	      if (isSgForStatement(tmp))
		{
		  ScopForAnnotation* annot =
		    (ScopForAnnotation*)(tmp)->getAttribute("ScopFor");
		  if (annot)
		    break;
		  else
		    ++num_outer_loops;
		}
	      tmp = tmp->get_parent();
	    }

	  // Skip zero dimensions.
	  int array_dim = isl_set_dim(scanned, isl_dim_set);
	  isl_set* s = NULL;
	  for (int j = 0; num_outer_loops >= 0 && j < array_dim; ++j)
	    {
	      s = project_set_onto_dim(scanned, j);
	      Polynomial p = computeCard(s, scop, true);
	      if (p.max != 1)
		--num_outer_loops;
	    }
	  domain = s;
	}
      ROSE_ASSERT(domain);

      // Get the loop trip count.
      Polynomial tripCount = computeCard(domain, scop, true);

      // Annotate the tree.
      SageAPForInfo* annot = (SageAPForInfo*)fs->getAttribute("SageAPForInfo");
      if (annot == NULL)
	    annot = new SageAPForInfo();
      annot->minTripCount = tripCount.min;
      annot->maxTripCount = tripCount.max;
      annot->avgTripCount = tripCount.max; // Estimate we do full
					   // loops on average.
      fs->setAttribute("SageAPForInfo", annot);

      isl_set_free(domain);
    }

}

static
int traverse_aff_compbuffdim(isl_set* set, isl_aff* aff, void* user)
{
  Polynomial* p = (Polynomial*)user;
  //*((int*)user)++;
  Polynomial tmp(aff);
  tmp.overapprox();
  if (tmp.isConstant())
    {
      // std::cout << "ONE DIM: " << tmp.coef[0] << " " << p->coef[0] << std::endl;
      p->maxOf(tmp);
      p->coef[0] = p->coef[0] < tmp.coef[0] ? tmp.coef[0] : p->coef[0];
    }
  else
    {
      ROSE_ASSERT(! "NOT SUPPORTED!");
    }
}
/**
 * Compute the buffer size, in each dimension.
 *
 * Use rectangular hull + lexmin/max approximation.
 *
 */
static
std::vector<Polynomial> compute_buffer_dims(isl_map* buffer_map,
					    int array_dim, int nparams)
{
  std::vector<Polynomial> ret;
  // Get the buffer set.
  isl_map* buffer_map_c =
    isl_map_coalesce(isl_map_copy(buffer_map));
  isl_set* tmp = isl_map_range(buffer_map_c);
  isl_set* myset = isl_set_coalesce(tmp);

  if (isl_set_n_basic_set(myset) > 1)
    {
      isl_basic_set* bsun = isl_set_unshifted_simple_hull(isl_set_copy(myset));
      isl_set_free(myset);
      myset = isl_set_from_basic_set (bsun);
    }

    
  myset = isl_set_from_basic_set(isl_set_unshifted_simple_hull(isl_set_copy(myset)));
  for (int l = 0; l < array_dim; ++l)
    {
      isl_pw_aff* min = isl_set_dim_min(isl_set_copy(myset), l);
      isl_pw_aff* max = isl_set_dim_max(isl_set_copy(myset), l);

      isl_pw_aff* diff = isl_pw_aff_sub(isl_pw_aff_copy(max),
					isl_pw_aff_copy(min));

      Polynomial p(diff);

      if (! p.isConstant())
	{
	  std::cout << "[LMP][WARNING] Buffer size description is parametric!"
		    << std::endl;
	  /// Ooops, the polynomial is parametric. May need to
	  /// reprocess the set
	  if (p.overapprox() == -1)
	    {
	      // This code should not be needed anymore.
	      ROSE_ASSERT(0);
	      // need to re-integrate loop bounds in comm. set evaluation.
	      nparams = 0;
	      int num_set_dim = isl_set_dim(isl_set_copy(myset), isl_dim_set);
	      int num_par = isl_set_dim(isl_set_copy(myset), isl_dim_param) - nparams;
	      isl_set* myset2 = isl_set_move_dims(isl_set_copy(myset),  isl_dim_set, num_set_dim,
						  isl_dim_param, 0, num_par);
	      isl_pw_aff_free (min);
	      isl_pw_aff_free (max);
	      isl_pw_aff_free (diff);
	      min = isl_set_dim_min(isl_set_copy(myset2), l);
	      max = isl_set_dim_max(isl_set_copy(myset2), l);

	      diff = isl_pw_aff_sub(isl_pw_aff_copy(max),
					isl_pw_aff_copy(min));
	      Polynomial p2(diff);
	      p = p2;
	      isl_set_free (myset2);
	    }
	}

      // Resize by +1, as the actual number of points is #diff + 1.
      p.coef[0] += 1;
      p.min = p.max = p.avg = p.coef[0];

      ret.push_back(p);

      isl_pw_aff_free(min);
      isl_pw_aff_free(max);
      isl_pw_aff_free(diff);
    }

  return ret;
}



/**
 * Entry point for Local Memory Promotion of a polyhedral Sage tree.
 *
 */
int
lmp_driver_wei (s_hlsir_t* input, s_lmp_options_t* options)
{
  std::cout << "[LMP] Start Local Memory Promotion" << std::endl;
  //std::cout <<"weiwei 1111" << std::endl;


  SgStatement* root = isSgStatement(input->sage);
  SgScopeStatement* scopSuperScope = isSgScopeStatement(input->scope);

  // std::cout << "considered scope: " << std::endl;
  // std::cout << scopSuperScope->unparseToCompleteString() << std::endl;

  int acc_num = 0;
  //std::set<SgNode*> bestLoopsCopy;
  //std::map<SgNode*, bool> bestLoopsCopyAcc;
  std::map<std::string, int> arrayDimMap;

  // Debug.
  isl_ctx* ctxt = isl_ctx_alloc();
  isl_printer* pr = isl_printer_to_file (ctxt, stdout);
  int debug_level = options->verbose_level;
  //debug_level = 5;
  bool use_prefetch = options->use_prefetch == 0 ? false : true;
  bool use_simple_hull = options->simple_hull == 0 ? false : true;
  // It is now safe to always use this hull, as the same is used to
  // compute the buffer dimensions.
  use_simple_hull = true;

  if (debug_level > 0)
    {
      std::cout << "[LMP] considered loop nest: " << std::endl;
      std::cout << root->unparseToCompleteString() << std::endl;
    }

  if (options->buffsize_limit == 0)
    options->buffsize_limit = input->max_buffer_size_per_array;

  // Collect all loops.
  std::vector<SgNode*> forLoops =
    NodeQuery::querySubTree(root, V_SgForStatement);

  // Encapsulate compute loop bodies into a second a basic block, for
  // future outlining. Store a map between compute loop and their old
  // body.
  std::map<SgNode*, SgNode*> loopToComputeBody;
  for (std::vector<SgNode*>::iterator i = forLoops.begin(); i != forLoops.end();
       ++i)
    {
      SgBasicBlock* loopbb = SageBuilder::buildBasicBlock();
      SgForStatement* fs = isSgForStatement(*i);
      ROSE_ASSERT(fs);
      SgBasicBlock* lbody = isSgBasicBlock(fs->get_loop_body());
      ROSE_ASSERT(lbody);
      SageInterface::replaceStatement(lbody, loopbb, true);
      loopbb->append_statement(lbody);
      loopToComputeBody[fs] = lbody;
    }
  //wei: insert max(arr_l) infront of the computation body
    /*for(std::vector<SgNode*>::iterator itr = forLoops.begin(); itr != forLoops.end()){
      SgNode* lbody = itr->second;
      Rose_STL_Container<SgNode*> varRefs = 
      	NodeQuery::querySubTree(lbody, V_SgVarRefExp);
	std::set<std::string> arrNames;
      for(Rose_STL_Container<SgNode*> :: iterator k = varRefs.begin(); k != varRefs.end(); ++k){
      	SgVarRefExp* varRef = isSgVarRefExp(*k);
      	if(varRef && isSgArrayType(varRef->get_symbol()->get_type())){
      	  //std::cout << "the variables \n" << (*k)->unparseToCompleteString() << std::endl; 
	  std::string name = varRef->get_symbol()->get_name() + "_l_cycle";
	  arrNames.insert(name);
	}
      }
      std::set<std::string>::iterator k = arrNames.begin();
      std::string maxStr = (*k++);
      for(; k!= arrNames.end(); ++k){
      	maxStr = "std::max(" + maxStr + ", " + (*k) + ")";
      }
      maxStr = "wait(" + maxStr + ", SC_NS);\n";
      SageInterface::attachArbitraryText(isSgStatement(lbody), maxStr, PreprocessingInfo::inside);
    }*/

  std::vector<SgNode*> decl_vec;
  // Map from loops to scanned data space, for annotation with the
  // loop trip count.
  std::map<SgNode*, isl_set*> loopTCmap;

  // Iterate on all arrays.
  scoplib_scop_p scop = input->scop;
  int nparam = scop->nb_parameters;
  int c;
  int array_dim;
  for (c = 0; c < scop->nb_arrays; ++c)
    {
      std::cout << "[LMP] Processing array ";
      std::cout << std::string(((SgVariableSymbol*)scop->arrays[c])->get_name());
      std::cout << std::endl;
      SgVariableSymbol* global_array_sym = (SgVariableSymbol*)scop->arrays[c];

      const char* strArrName = global_array_sym->get_name().getString().c_str();
      // Skip scalar as arrays.
      if (strlen(strArrName) > 13 &&
	  ! strncmp(strArrName, "__local_scal_", 13))
	{
	  std::cout << "[LMP] Skip array " << strArrName << std::endl;
	  continue;
	}

      int array_id = c + 1;
      // Solution set.
      std::map<SgNode*, std::pair<isl_set*, isl_set*> > sol_set;
      std::map<SgNode*, std::pair<isl_set*, isl_set*> > sol_set_s;
      std::map<SgNode*, std::vector<Polynomial> > buffer_size;
      std::map<SgNode*, isl_map*> buffer_desc;
      std::map<SgNode*, isl_map*> writeout_set;

      // ISL space for the array.
      isl_space* isl_space_desc = NULL;
      // Compute the computation data space.
      isl_map* full_dspace =
	compute_data_space (root, scop, array_id, 0, false, false,
			    &isl_space_desc);

      // Iterate on all loops.
      if (debug_level > 0)
	std::cout << "[LMP] (1) Compute solution set" << std::endl;
      for (std::vector<SgNode*>::iterator i = forLoops.begin();
	   i != forLoops.end(); ++i)
	{
	  ScopForAnnotation* annot =
	    (ScopForAnnotation*)(*i)->getAttribute("ScopFor");
	  if (debug_level > 2)
	    {
	      std::cout << "[LMP] Computing solution for loop: ";
	      std::cout << std::string(annot->iterator->get_name());
	      std::cout << std::endl;
	    }

	  SgForStatement* fs = isSgForStatement(*i);
	  ROSE_ASSERT(fs);
	  // Use a space local to each loop: parameters change for
	  // each loop as we treat surrounding iterators as
	  // parameters.
	  isl_space* dim = NULL;

	  // Compute the communication and preload sets, for read references.
	  // 1- Compute data space of array *j at iteration i.
	  isl_map* dspace = compute_data_space (fs, scop, array_id,
						0, false, true, &dim);
	  // If the array is never referenced in the loop, skip the loop!
	  if (dspace == NULL)
	    continue;
	  // 2- Compute data space of array *j at iteration i-1.
	  isl_map* dspacem1 = compute_data_space (fs, scop, array_id,
						  -1, false, true, &dim);
	  // 3- Compute the per-iteration communication set/code.
	  isl_map* per_iter_comm = isl_map_subtract
	    (isl_map_copy(dspace), isl_map_copy(dspacem1));
	  isl_set* per_iter_comm_set =
	    isl_map_range(isl_map_copy(per_iter_comm));

	  // 4- Compute the communication pre-load.
	  isl_map* pre_load_comm = isl_map_intersect
	    (isl_map_copy(dspace), isl_map_copy(dspacem1));
	  isl_set* pre_load_comm_set =
	    isl_map_range(isl_map_copy(pre_load_comm));
	  // Debug.
	  if (debug_level > 4)
	    {
	      std::cout << "[LMP] SETS: " << std::endl;


	      // std::cout << "[LMP] XXXXXXXXXXXXXXXX 1 (map): " << std::endl;
	      // isl_printer_print_map(pr, (isl_map_copy(dspace)));
	      // printf ("\n");
	      // std::cout << "[LMP] XXXXXXXXXXXXXXXX 2 (range): " << std::endl;
	      // isl_printer_print_set(pr, isl_map_range(isl_map_copy(dspace)));
	      // printf ("\n");
	      // std::cout << "[LMP] XXXXXXXXXXXXXXXX 3 (coalesce): " << std::endl;
	      // isl_printer_print_set(pr, isl_set_coalesce(isl_map_range(isl_map_copy(dspace))));
	      // printf ("\n");

	      std::cout << "[LMP] ds: " << std::endl;
	      isl_printer_print_set(pr, isl_set_coalesce
				    (isl_map_range(isl_map_copy(dspace))));
	      printf ("\n");
	      std::cout << "[LMP] dsm1: " << std::endl;
	      isl_printer_print_set(pr, isl_set_coalesce
				    (isl_map_range(isl_map_copy(dspacem1))));
	      printf ("\n");
	      std::cout << "[LMP] Preload: " << std::endl;
	      isl_printer_print_set(pr, isl_set_coalesce
				    (isl_set_copy(pre_load_comm_set)));
	      printf ("\n");
	      std::cout << "[LMP] Comm: " << std::endl;
	      isl_printer_print_set(pr, isl_set_coalesce
				    (isl_set_copy(per_iter_comm_set)));
	      printf ("\n");
	    }

	  // 5- Compute the write-out data.
	  isl_map* write_out = compute_data_space (fs, scop, array_id,
						   0, true, false, &dim);
	  // Store the solutions.
	  sol_set[*i] = std::pair<isl_set*, isl_set*>(per_iter_comm_set,
						      pre_load_comm_set);
	  sol_set_s[*i] = std::pair<isl_set*, isl_set*>
	    (isl_map_range(isl_map_coalesce(isl_map_copy(per_iter_comm))),
	     isl_map_range(isl_map_coalesce(isl_map_copy(pre_load_comm))));
	  writeout_set[*i] = write_out;
	  // Compute the buffer size, along each dimension.
	  array_dim = isl_space_dim(dim, isl_dim_out);
	  // Compute now the comm/preload space considering all references,
	  // including writes.
	  isl_map* dspacef = compute_data_space (fs, scop, array_id,
						 0, false, false, &dim);
	  isl_map* dspacefm1 = compute_data_space (fs, scop, array_id,
						   -1, false, false, &dim);
	  isl_map* per_iter_comm_f = isl_map_subtract
	    (isl_map_copy(dspacef), isl_map_copy(dspacefm1));
	  isl_map* pre_load_comm_f = isl_map_intersect
	    (isl_map_copy(dspacef), isl_map_copy(dspacefm1));
	  isl_map_free(dspacef);
	  isl_map_free(dspacefm1);
	  isl_map* buffer_map = isl_map_union(isl_map_copy(per_iter_comm_f),
					      isl_map_copy(pre_load_comm_f));
	  isl_map_free(per_iter_comm_f);
	  isl_map_free(pre_load_comm_f);
	  if (!isl_map_is_empty(buffer_map))
	    buffer_size[*i] = compute_buffer_dims(buffer_map, array_dim, nparam);
	  // Store the buffer description.
	  buffer_desc[*i] = buffer_map;

	  // Be clean.
	  isl_map_free (per_iter_comm);
	  isl_map_free (pre_load_comm);
	  isl_map_free (dspace);
	  isl_map_free (dspacem1);
	}

      // // Nothing to bufferize...
      // if (sol_set.size() == 0)
      // 	continue;

      // Compute the best loops for this array.
      if (debug_level > 0)
	std::cout << "[LMP] (2) Find optimal option solution" << std::endl;
      std::vector<SgNode*> bestLoops =
	computeBestSolution(sol_set_s, full_dspace,
			    options->buffsize_limit,
			    buffer_desc, scop, root,
			    options->commsched_mode);
      /*
      for(std::vector<SgNode*>::iterator r = bestLoops.begin(); r!= bestLoops.end(); ++r){
      	using namespace std;
      	cout << "\n\n\n best loop is \n\n\n" << (*r)->unparseToCompleteString() << endl;
      	      bestLoopsCopyAcc.insert(std::pair<SgNode*, bool>(*r, false));
      	      bestLoopsCopy.insert(*r);
      }*/

      if (debug_level > 0)
	std::cout << "[LMP] (3) Implement the solution" << std::endl;
      // Make the hull of the various buffers needed.
      std::vector<SgNode*> local_array_dims;
      std::vector<Polynomial> local_array_dims_poly;

      for (std::vector<SgNode*>::iterator r = bestLoops.begin();
      	   r != bestLoops.end(); ++r)
      	{
	  int cnt = 1;
	  for (std::vector<Polynomial>::iterator
		 p = buffer_size[*r].begin();
	       p != buffer_size[*r].end(); ++p, ++cnt)
	    {
	      // std::cout << "value of p:" << std::endl;
	      // p->print();
	      ROSE_ASSERT(p->isConstant());
	      if (local_array_dims_poly.size() < cnt)
		local_array_dims_poly.push_back(*p);
	      else
		local_array_dims_poly[cnt - 1].maxOf(*p);
	    }
	}
      // Create the Sage sub-tree for the dimension expressions.
      if (debug_level > 1)
	std::cout << "[LMP] Buffer size description: [";
      for (std::vector<Polynomial>::iterator r = local_array_dims_poly.begin();
	   r != local_array_dims_poly.end(); ++r)
	{
	  // Use only power-of-2 for the buffer sizes.
	  int count = 0;
	  int p2 = 0;
	  /// LNP: Commented out. Not needed anymore with new addressing.
	  // while (p2 < (*r).max)
	  //   p2 = pow(2,count++);

	  p2 = (*r).max;

	  (*r).max = (*r).min = (*r).avg = (*r).coef[0] = p2;
	  if (debug_level > 1)
	    {
	      if (r != local_array_dims_poly.begin())
		std::cout << ", ";
	      std::cout << (*r).max;
	    }
	  local_array_dims.push_back(SageBuilder::buildIntVal((*r).max));
	}
      if (debug_level > 1)
	std::cout << "]" << std::endl;

      input->bufferized_symbols.insert(global_array_sym);

      // Declare and insert the buffer.
      SgTreeCopy treeCopy;
      bool array_is_scalar = true;
      // 1- Create the new declaration.
      SgScopeStatement* scope = isSgScopeStatement(root);
      SgBasicBlock* bb = isSgBasicBlock(root);
      ROSE_ASSERT(scope);
      ROSE_ASSERT(bb);
      std::string local_array_name =
	std::string(global_array_sym->get_name().getString() + "_l");
      SgType* global_array_type = isSgType(global_array_sym->get_type());
      SgType* local_array_type =
	isSgType(SageInterface::deepCopy(global_array_type));
      SgArrayType* arr = isSgArrayType(local_array_type);

      SgArrayType* loctype;
      if (arr && local_array_dims.size())
	{
	  SgType* tmp = arr;
	  while (tmp && isSgArrayType(tmp))
	    tmp = isSgArrayType(tmp)->get_base_type();
	  SgType* base_type = tmp;
	  int pos1 = array_dim - 1;
	  SgNode* e = SageInterface::deepCopy(local_array_dims[pos1]);
	  arr = isSgArrayType(arr->get_base_type());
	  loctype = SageBuilder::buildArrayType(base_type,
						isSgExpression(e));
	  while (arr)
	    {
	      pos1--;
	      SgNode* e = SageInterface::deepCopy(local_array_dims[pos1]);
	      arr = isSgArrayType(arr->get_base_type());
	      loctype = SageBuilder::buildArrayType(loctype, isSgExpression(e));
	    }
	  local_array_type = loctype;
	  array_is_scalar = false;
	}
      SgVariableDeclaration* decl_local =
	SageBuilder::buildVariableDeclaration
	(local_array_name, local_array_type, NULL, scope);
      SageAPDeclarationInfo* annot = new SageAPDeclarationInfo();
      decl_local->setAttribute("SageAPDeclarationInfo", annot);

      // 2- Insert the declaration.
      bb->prepend_statement(decl_local);
      // std::cout << decl_local->unparseToCompleteString() << std::endl;

      // Iterate on all solution loops, and bufferize.
      for (std::vector<SgNode*>::iterator r = bestLoops.begin();
      	   r != bestLoops.end(); ++r)
      	{

	  // std::cout << (*r)->unparseToCompleteString() << std::endl;
	  ScopForAnnotation* annot =
	    (ScopForAnnotation*)(*r)->getAttribute("ScopFor");
	  ROSE_ASSERT(annot);
	  if (debug_level > 1) {
	    std::cout << "[LMP] Bufferize along loop: ";
	    std::cout << std::string(annot->iterator->get_name());
		std::cout << std::endl;
      }
	  // std::cout << "loop considered: " << annot->iterator->get_name()
	  // 	    << std::endl;

      	  SgForStatement* bestLoop = isSgForStatement(*r);


	  // Get the comm/preload sets.
	  std::pair<isl_set*, isl_set*> final = sol_set[bestLoop];
	  isl_set* preload_set = isl_set_coalesce(isl_set_copy(final.second));
	  isl_set* comm_set = isl_set_coalesce(isl_set_copy(final.first));
	  // Get the copy-out set.
	  isl_set* copyout_set = isl_set_coalesce
	    (isl_map_range((isl_map_copy(writeout_set[bestLoop]))));

	  if (use_simple_hull)
	    {
	      if (debug_level > 2)
		{
		  std::cout << "[LMP] Compute simple hull of the communication sets"
			    << std::endl;
		}
	      preload_set = isl_set_from_basic_set
		(isl_set_unshifted_simple_hull(isl_set_copy(preload_set)));
	      comm_set = isl_set_from_basic_set
		(isl_set_unshifted_simple_hull(isl_set_copy(comm_set)));
	      // Don't hullify the copy-out, otherwise correctness 
	      // is not guaranteed.
	      // copyout_set = isl_set_from_basic_set
	      // 	(isl_set_simple_hull(isl_set_copy(copyout_set)));
	    }

	  // isl_printer_print_map (pr, isl_map_coalesce(buffer_desc[*r]));
	  // printf ("\n");
	  if (debug_level > 2)
	    {
	      if (preload_set)
		{
		  std::cout << "[LMP] Preload set: " << std::endl;
		  isl_printer_print_set(pr, preload_set);
		  printf ("\n");
		}
	      else
		std::cout << "[LMP] Preload set is null" << std::endl;
	      if (comm_set)
		{
		  std::cout << "[LMP] Comm set: " << std::endl;
		  isl_printer_print_set(pr, comm_set);
		  printf ("\n");
		}
	      else
		std::cout << "[LMP] Comm set is null" << std::endl;
	      if (copyout_set)
		{
		  std::cout << "[LMP] Copyout set: " << std::endl;
		  isl_printer_print_set(pr, copyout_set);
		  printf ("\n");
		}
	      else
		std::cout << "[LMP] Copyout set is null" << std::endl;
	    }

	  SgNode* cpstm = NULL;
	  SgNode* cpostm = NULL;
	  SgNode* preloadRoot = NULL;
	  SgNode* commRoot = NULL;
	  SgNode* copyoutRoot = NULL;
	  SgNode* commRootPr = NULL;
	  SgNode* commRootPrN = NULL;

	  // Prepare a fake scop for the copy statements.
	  scoplib_scop_p fake_scop = scoplib_scop_malloc();
	  scoplib_statement_p copy_stm = scoplib_statement_malloc();
	  fake_scop->statement = copy_stm;
	  copy_stm->nb_iterators = array_dim;
	  copy_stm->iterators =
	    (char**) malloc((array_dim + 1) * sizeof(SgVariableSymbol*));
	  std::vector<SgVariableSymbol*> fk_iters;
	  int it = 0;
	  Rose_STL_Container<SgNode*> forNodes =
	    NodeQuery::querySubTree(root, V_SgForStatement);
	  Rose_STL_Container<SgNode*>::iterator vit;
	  std::set<SgVariableSymbol*> dummyits;
	  for (vit = forNodes.begin(); vit != forNodes.end(); ++vit)
	    {
	      ScopForAnnotation* dannot =
	  	(ScopForAnnotation*)(*vit)->getAttribute("ScopFor");
	      if (dannot)
	  	dummyits.insert(dannot->iterator);
	    }
	  std::set<SgVariableSymbol*>::iterator dits = dummyits.begin();
	  for (it = 0; it < array_dim; ++it)
	    {
	      SgVariableSymbol* iterS = new SgVariableSymbol();
	      fk_iters.push_back(iterS);
	      copy_stm->iterators[it] = (char*)iterS;
	      ++dits;
	    }
	  copy_stm->iterators[it] = NULL;
	  SgVariableSymbol* local_array_sym =
	    isSgVariableSymbol(decl_local->get_decl_item(local_array_name)->
	  		       get_symbol_from_symbol_table());
	  cpstm =
	    createCopyStatement((SgVariableSymbol*)scop->arrays[c],
	  			local_array_sym, fk_iters, true,
	  			local_array_dims);
	  copy_stm->body = (char*)cpstm;

	  // Loop pre-load.
	  if (debug_level > 1)
	    std::cout << "[LMP] PRELOAD stage" << std::endl;
	  if (! isl_set_is_empty(preload_set))
	    {
	      // std::cout << "create scanning code" << std::endl;
	      isl_set* cpre = isl_set_coalesce(isl_set_copy(preload_set));
	      s_past_node_t* preload =
	  	create_scanning_code(isl_set_copy(cpre), scopSuperScope, scop);
	      // std::cout << "convert past 2 sage" << std::endl;
	      BGPastToSage conv1(scopSuperScope, preload, fake_scop);
	      preloadRoot = conv1.getBasicBlock();
	      // std::cout << "PRELOAD CODE (Sage): " << std::endl;
	      // if (preloadRoot)
	      // 	std::cout << preloadRoot->unparseToCompleteString()
	      // 		  << std::endl;
	      // Insert the loop lower bounds for the iterators used
	      // in the pre-load.
	      // std::cout << "update iterators" << std::endl;
	      addIteratorLb(preloadRoot, bestLoop);

	      SageAPCopyBlockInfo* annot = new SageAPCopyBlockInfo();
	      annot->type = 0;
	      annot->orig_sym = global_array_sym;
	      annot->local_sym = local_array_sym;
	      annot->dim = array_is_scalar ? 0 : array_dim;
	      preloadRoot->setAttribute("SageAPCopyBlockInfo", annot);

	      // Backup the set associated to the loops, for future
	      // annotation with the trip count.
	      Rose_STL_Container<SgNode*> loops =
	  	NodeQuery::querySubTree(preloadRoot, V_SgForStatement);
	      for (Rose_STL_Container<SgNode*>::iterator q = loops.begin();
	  	   q != loops.end(); ++q)
	  	loopTCmap[*q] = isl_set_copy(cpre);
	    }

	  // Per-iteration communication.
	  if (debug_level > 1)
	    std::cout << "[LMP] COMM stage" << std::endl;
	  if (! isl_set_is_empty(comm_set))
	    {
	      // Communication prefetch.
	      if (use_prefetch && ! array_is_scalar)
		{
		  // Per-iteration communication prefetch..
		  isl_set* comm_set_cp_1 = isl_set_copy(comm_set);
		  isl_set* comm_set_cp_2 = isl_set_copy(comm_set);
		  isl_set* ccomm = isl_set_coalesce(comm_set_cp_1);
		  s_past_node_t* comm =
		    create_scanning_code(isl_set_copy(ccomm),
		  			 scopSuperScope, scop);
		  BGPastToSage conv2(scopSuperScope, comm, fake_scop);
		  commRootPr = conv2.getBasicBlock();
		  addIteratorLb(commRootPr, bestLoop);
		  SageAPCopyBlockInfo* annot = new SageAPCopyBlockInfo();
		  annot->type = 3;
		  annot->orig_sym = global_array_sym;
		  annot->local_sym = local_array_sym;
		  annot->dim = array_is_scalar ? 0 : array_dim;
		  std::cout << "array dim is " << array_dim<< std::endl;
		  commRootPr->setAttribute("SageAPCopyBlockInfo", annot);

		  // Backup the set associated to the loops, for future
		  // annotation with the trip count.
		  Rose_STL_Container<SgNode*> loops =
		    NodeQuery::querySubTree(commRootPr, V_SgForStatement);
		  for (Rose_STL_Container<SgNode*>::iterator q = loops.begin();
		       q != loops.end(); ++q)
		    loopTCmap[*q] = isl_set_copy(ccomm);

		  // Next per-iteration communication prefetch..
		  isl_set* ccomm2 = isl_set_coalesce(comm_set_cp_2);
		  s_past_node_t* comm2 =
		    create_scanning_code(ccomm2,
					 scopSuperScope, scop);
		  BGPastToSage conv3(scopSuperScope, comm2, fake_scop);
		  commRootPrN = conv3.getBasicBlock();
		  annot = new SageAPCopyBlockInfo();
		  annot->type = 4;
		  annot->orig_sym = global_array_sym;
		  annot->local_sym = local_array_sym;
		  annot->dim = array_is_scalar ? 0 : array_dim;
		  commRootPrN = addIteratorNextVal(commRootPrN, bestLoop);
		  commRootPrN->setAttribute("SageAPCopyBlockInfo", annot);

		  // Backup the set associated to the loops, for future
		  // annotation with the trip count.
		  loops =
		    NodeQuery::querySubTree(commRootPrN, V_SgForStatement);
		  for (Rose_STL_Container<SgNode*>::iterator q = loops.begin();
		       q != loops.end(); ++q)
		    loopTCmap[*q] = isl_set_copy(ccomm2);
		}

	      // Per-iteration communication.
	      isl_set* ccomm = isl_set_coalesce(isl_set_copy(comm_set));
	      s_past_node_t* comm =
	  	create_scanning_code(isl_set_copy(ccomm),
	  			     scopSuperScope, scop);
	      BGPastToSage conv2(scopSuperScope, comm, fake_scop);
	      commRoot = conv2.getBasicBlock();
	      //wei
	      // std::cout << "COMM CODE (Sage): " << std::endl;
	      // std::cout << commRoot->unparseToCompleteString() << std::endl;

	      SageAPCopyBlockInfo* annot = new SageAPCopyBlockInfo();
	      annot->type = 1;
	      annot->orig_sym = global_array_sym;
	      annot->local_sym = local_array_sym;
	      annot->dim = array_is_scalar ? 0 : array_dim;
	      commRoot->setAttribute("SageAPCopyBlockInfo", annot);

	      // Backup the set associated to the loops, for future
	      // annotation with the trip count.
	      Rose_STL_Container<SgNode*> loops =
	  	NodeQuery::querySubTree(commRoot, V_SgForStatement);
	      for (Rose_STL_Container<SgNode*>::iterator q = loops.begin();
	  	   q != loops.end(); ++q)
	  	loopTCmap[*q] = isl_set_copy(ccomm);
	    }

	  // Loop copy-out.
	  if (debug_level > 1)
	    std::cout << "[LMP] COPYOUT stage" << std::endl;
	  if (! isl_set_is_empty(copyout_set))
	    {
	      isl_set* ccout = isl_set_coalesce(isl_set_copy(copyout_set));
	      s_past_node_t* copyout =
	  	create_scanning_code(isl_set_copy(ccout), scopSuperScope, scop);
	      cpostm =
	  	createCopyStatement((SgVariableSymbol*)scop->arrays[c],
	  			    local_array_sym, fk_iters, false,
	  			    local_array_dims);
	      copy_stm->body = (char*)cpostm;
	      BGPastToSage conv3(scopSuperScope, copyout, fake_scop);
	      copyoutRoot = conv3.getBasicBlock();
	      // std::cout << "COPY OUT CODE (Sage): " << std::endl;
	      // std::cout << copyoutRoot->unparseToCompleteString() << std::endl;

	      SageAPCopyBlockInfo* annot = new SageAPCopyBlockInfo();
	      annot->type = 2;
	      annot->orig_sym = global_array_sym;
	      annot->local_sym = local_array_sym;
	      annot->dim = array_is_scalar ? 0 : array_dim;
	      copyoutRoot->setAttribute("SageAPCopyBlockInfo", annot);

	      // Backup the set associated to the loops, for future
	      // annotation with the trip count.
	      Rose_STL_Container<SgNode*> loops =
	  	NodeQuery::querySubTree(copyoutRoot, V_SgForStatement);
	      for (Rose_STL_Container<SgNode*>::iterator q = loops.begin();
	  	   q != loops.end(); ++q)
	  	loopTCmap[*q] = isl_set_copy(ccout);
	    }

	  // Replace all references in the loop to local references.
	  Rose_STL_Container<SgNode*> varRefs =
	    NodeQuery::querySubTree(bestLoop, V_SgVarRefExp);
	  for (Rose_STL_Container<SgNode *>::iterator k = varRefs.begin();
	       k != varRefs.end(); k++)
	    {
	      SgVarRefExp* vRef = isSgVarRefExp(*k);
	      std::map<SgVariableSymbol*,SgVariableDeclaration*>::iterator it;
	      if (vRef->get_symbol() == (SgVariableSymbol*)scop->arrays[c])
	  	{
	  	  SgPntrArrRefExp* arex = isSgPntrArrRefExp(vRef->get_parent());
	  	  int pos = 0;
	  	  while (arex)
	  	    {
	  	      SgExpression* modexp;
	  	      SgIntVal* iv = isSgIntVal(local_array_dims[pos]);
	  	      if ((iv && iv->get_value() != 1) || !iv)
	  		{
	  		  modexp = isSgExpression
	  		    (local_array_dims[pos]->copy(treeCopy));
	  		  modexp = SageBuilder::buildBinaryExpression<SgModOp>
	  		    (arex->get_rhs_operand(), modexp);
	  		}
	  	      else
	  		modexp = SageBuilder::buildIntVal(0);
	  	      pos++;
	  	      arex->set_rhs_operand(modexp);
	  	      arex = isSgPntrArrRefExp(arex->get_parent());
	  	    }
	  	  SgVariableSymbol* sym =
	  	    SageInterface::getFirstVarSym(decl_local);
	  	  SgVarRefExp* newRef = SageBuilder::buildVarRefExp(sym);
	  	  SageInterface::replaceExpression(vRef, newRef);
	  	}
	    }

	  // Plug it in around the loop.
	  if (preloadRoot)
	    {
	      int cnt = insertMemoryCycle(preloadRoot, loopTCmap, scop, arrayDimMap);
	      //insertForEachBlock(preloadRoot, acc_num, 2, cnt);
	      insertForEachBlock(preloadRoot, acc_num, 2, arrayDimMap, cnt);
	      std::string comment("/* loop data preload (blocking) */");
	      SageInterface::attachArbitraryText(isSgStatement(preloadRoot),
	  					 comment,
	  					 PreprocessingInfo::before);
	      SageInterface::insertStatementBefore(isSgStatement(bestLoop),
	  					   isSgStatement(preloadRoot));
	    }
	  if (commRoot)
	    {
	      if (commRootPr)
		{
		  std::string
		    comment("/* prefetch per-iteration comm (non-blocking) */");
		  SageInterface::attachArbitraryText(isSgStatement(commRootPr),
						     comment,
						     PreprocessingInfo::before);
		  SageInterface::insertStatementBefore
		    (isSgStatement(bestLoop), isSgStatement(commRootPr));

		}
	      //Wei: Get the memory access time
	      int cnt = insertMemoryCycle(commRoot, loopTCmap, scop, arrayDimMap);
	      //insertForEachBlock(commRoot, cnt);
	      //insertForEachBlock(commRoot, acc_num, 2, cnt);
	      insertForEachBlock(commRoot, acc_num, 2, arrayDimMap, cnt);
	      //wei end

	      std::string comment("/* per-iteration communication (blocking) */");
	      SageInterface::attachArbitraryText(isSgStatement(commRoot),
	  					 comment,
	  					 PreprocessingInfo::before);
	      SgBasicBlock* lbb =
	  	isSgBasicBlock(isSgForStatement(bestLoop)->get_loop_body());
	      ROSE_ASSERT(lbb);
	      lbb->prepend_statement(isSgStatement(commRoot));
	      if (commRootPrN)
		{
		  std::string comment
		    ("/* prefetch next per-iteration comm (non-blocking) */");
		  SageInterface::attachArbitraryText(isSgStatement(commRootPrN),
						     comment,
						     PreprocessingInfo::before);
		  SgBasicBlock* lbb =
		    isSgBasicBlock(isSgForStatement(bestLoop)->get_loop_body());
		  ROSE_ASSERT(lbb);
		  lbb->prepend_statement(isSgStatement(commRootPrN));
		}
	    }
	  if (copyoutRoot)
	    {
	      int cnt = insertMemoryCycle(copyoutRoot, loopTCmap, scop, arrayDimMap);
	      insertForEachBlock(copyoutRoot, acc_num, 1, arrayDimMap, cnt);
	      std::string comment("/* per-iteration copy-out */");
	      SageInterface::attachArbitraryText(isSgStatement(copyoutRoot),
	  					 comment,
	  					 PreprocessingInfo::before);
	      SgBasicBlock* lbb =
	  	isSgBasicBlock(isSgForStatement(bestLoop)->get_loop_body());
	      ROSE_ASSERT(lbb);
	      lbb->append_statement(isSgStatement(copyoutRoot));
	      // SageInterface::insertStatementAfter(isSgStatement(bestLoop),
	      // 				      isSgStatement(copyoutRoot));
	    }

	  // Annotate the compute loop body for future outlining.
	  SgNode* loopComputeBB = loopToComputeBody[bestLoop];
	  //std::cout << "compute loop is \n" << loopComputeBB->unparseToCompleteString() << std::endl;
	  SageAPComputeBlockInfo* annotc = (SageAPComputeBlockInfo*)
	    loopComputeBB->getAttribute("SageAPComputeBlockInfo");
	  if (! annotc)
	    {
	      annotc = new SageAPComputeBlockInfo();
	      loopComputeBB->setAttribute("SageAPComputeBlockInfo", annotc);
	    }

	  // Clean the temporary ROSE AST nodes created.
	  for (it = 0; it < array_dim; ++it)
	    delete fk_iters[it];
	  if (cpstm)
	    delete cpstm;
	  if (cpostm)
	    delete cpostm;
	  //SageInterface::deleteAST(cpstm);


	  // scoplib_statement_free (copy_stm);
	  // fake_scop->statement = NULL;
	  // scoplib_scop_free(fake_scop);
	}

    }

  /*
  std::set<SgNode*> bestLoopsCopy2 = bestLoopsCopy;
  for(std::set<SgNode*>::iterator r = bestLoopsCopy.begin(); r!=bestLoopsCopy.end(); ++r){
  	  SgForStatement* tmpFor = isSgForStatement(*r);
  	  ROSE_ASSERT(tmpFor);
  	  SgNode* tmpForParent = tmpFor->get_parent();
  	  while(isSgBasicBlock(tmpForParent) || isSgForStatement(tmpForParent)){
  	  	  tmpForParent = tmpForParent->get_parent();
  	  	  if(isSgForStatement(tmpForParent)){
			  std::set<SgNode*>::iterator it = std::find(bestLoopsCopy2.begin(), bestLoopsCopy2.end(), tmpForParent);
			  if(it != bestLoopsCopy2.end()) bestLoopsCopy2.erase(it);
  	  	  }
  	  }
  }
*/
  //WeiWei: collect all tiled compute loops

  std::vector<SgNode*> forLoopsForComputeLoops = NodeQuery::querySubTree(root, V_SgForStatement);
  std::set<SgNode*> computeForLoops;

  for(std::vector<SgNode*>:: iterator itr = forLoopsForComputeLoops.begin(); itr != forLoopsForComputeLoops.end(); ++itr){
    //cout << (*itr)->unparseToString() << endl;
    Rose_STL_Container<SgNode*> varRefs = NodeQuery::querySubTree((*itr), V_SgVarRefExp);
    Rose_STL_Container<SgNode*> :: iterator k = varRefs.begin();
    for(; k != varRefs.end(); ++k){
      SgVarRefExp* varRef = isSgVarRefExp(*k);
      if(varRef && isSgArrayType(varRef->get_symbol()->get_type())){ 
      	std::string name = varRef->get_symbol()->get_name();
      	if(name.size() < 2 || name.substr(name.size() - 2) != "_l") break;
      }
    }
    if(k != varRefs.end()) continue;
    //this loop does not contain global arrays, push this loop to another container;
    computeForLoops.insert(*itr);
  }

  std::set<std::string> tLoops;
  std::string loop;
  std::string line;
  std::ifstream myfile(".tiles");
  if(!myfile.is_open()) std::cout << "file .tiles is not found. \n";
  assert(myfile.is_open());
  while(getline(myfile, line)){
    std::string subline = line.substr(0, line.find(" "));
    tLoops.insert(subline);
  }
  myfile.close();

  std::set<std::string> tiled_Loops; //the iteration corresponding to tiles
  std::ifstream myfile1(".tiled_loops");
  if(!myfile1.is_open()) std::cout << "file .tiled_loops is not found. \n";
  assert(myfile1.is_open());
  while(getline(myfile1, line)){
    std::string subline = line.substr(0, line.find(" "));
    tiled_Loops.insert(subline);
  }
  myfile1.close();

  std::set<SgNode*> tiledComputeLoops ;
  for(std::set<SgNode*>::iterator l=computeForLoops.begin(); l != computeForLoops.end(); ++l){
    if(tiledLoop(isSgForStatement(*l), tLoops)){
      continue;
    }
    tiledComputeLoops.insert(*l);
  }
  
  //only need to top tiled computation loops
  std::set<SgNode*> topTiledComputeLoops =tiledComputeLoops;
  for(std::set<SgNode*>::iterator l = tiledComputeLoops.begin(); l!= tiledComputeLoops.end(); ++l ){
    std::vector<SgNode*> subForLoops = NodeQuery::querySubTree(isSgForStatement(*l)->get_loop_body(), V_SgForStatement);
    for(std::vector<SgNode*>::iterator ita = subForLoops.begin(); ita != subForLoops.end(); ++ita){
      topTiledComputeLoops.erase(*ita);
    }
  }
  //Encapsulate the top tiled loops with a basic block
  std::set<SgNode*> topTiledComputeLoopsBBs;
  for(std::set<SgNode*>::iterator l = topTiledComputeLoops.begin(); l != topTiledComputeLoops.end(); ++l){
    SgBasicBlock* loopbb = SageBuilder::buildBasicBlock();
    SgForStatement* fs = isSgForStatement(*l);
    ROSE_ASSERT(fs);
    SageInterface::replaceStatement(fs, loopbb, true);
    loopbb->append_statement(fs);
    topTiledComputeLoopsBBs.insert(loopbb);
  }

  annotateLoopTripCount(root, scop, loopTCmap);

  //we can extend to support II, but need to be given as an input
  //acc_latency + II * iter
  for(std::set<SgNode*>::iterator bbit = topTiledComputeLoopsBBs.begin(); bbit != topTiledComputeLoopsBBs.end(); ++bbit){
	  using namespace std;
	  //collect cycle information
	  //annotateLoopTripCount(*bbit, scop, loopTCmap);
	  std::vector<SgNode*> forLoops1 = NodeQuery::querySubTree(*bbit, V_SgForStatement);
	  int tripCountAvg = 1;
	  for(std::vector<SgNode*>::iterator i = forLoops1.begin(); i!=forLoops1.end(); ++i){
	    SgForStatement* fs = isSgForStatement(*i);
	    ROSE_ASSERT(fs);
	    SgExpression* incr_exp = fs->get_increment();
	    assert(isSgUnaryOp(incr_exp)); //currently only suport itr++ for incresement.
	    string incr_idx = isSgUnaryOp(incr_exp)->get_operand()->unparseToCompleteString();
	    SageAPForInfo* annot = (SageAPForInfo*)fs ->getAttribute("SageAPForInfo");
	    assert(annot !=NULL);
	    if(tiled_Loops.find(incr_idx) != tiled_Loops.end()){ //the trip count should only reflect tile size.
	      tripCountAvg *= annot->avgTripCount;
	    }
	  }
	  
	  //cout << (*bbit)->unparseToCompleteString() << endl << endl;
	  std::ostringstream stm_tmp;
	  stm_tmp << "acc" << acc_num;
	  std::string accString(stm_tmp.str());
	  AstTextAttribute* accNumS = new AstTextAttribute(accString);
	  SgForStatement* rootLoop = isSgForStatement(*(isSgBasicBlock(*bbit)->get_statements().begin()));
	  ROSE_ASSERT(rootLoop); 
	  //innermost loop
	  std::vector<SgNode*> forLoops = NodeQuery::querySubTree(rootLoop->get_loop_body(), V_SgForStatement);
	  forLoops.push_back(rootLoop);
	  for(std::vector<SgNode*>::iterator i = forLoops.begin(); i != forLoops.end(); ++i){
	    SgForStatement* fs = isSgForStatement(*i);
	    ROSE_ASSERT(fs);
	    std::vector<SgNode*> query = NodeQuery::querySubTree(fs->get_loop_body(), V_SgForStatement);
	    if(query.size() == 0){
	      isSgNode(fs)->setAttribute(std::string("accNum"), accNumS);
	    }
	    break;
	  }

	  Rose_STL_Container<SgNode*> varRefs = NodeQuery::querySubTree((*bbit), V_SgVarRefExp);
	  std::set<std::string> arrNames;
	  for(Rose_STL_Container<SgNode*> :: iterator k = varRefs.begin(); k != varRefs.end(); ++k){
	    SgVarRefExp* varRef = isSgVarRefExp(*k);
	    if(varRef && isSgArrayType(varRef->get_symbol()->get_type())){
	      std::string name = varRef->get_symbol()->get_name() + "_cycle";
	      arrNames.insert(name);
	    }
	  }
	  std::set<std::string>::iterator k = arrNames.begin();

	  std::string maxStr = (*k++);
	  for(; k!= arrNames.end(); ++k){
	    maxStr = "std::max(" + maxStr + ", " + (*k) + ")";
	  }
	  //maxStr = "wait(" + maxStr + "*(thread_id+1)*WRITE_LATENCY, SC_NS)";
	  maxStr = "wait(" + maxStr + "*WRITE_LATENCY, SC_NS)";
	  //SageInterface::attachArbitraryText(isSgStatement(*bbit), maxStr, PreprocessingInfo::after);
	  isSgBasicBlock(*bbit)->append_statement(SageBuilder::buildExprStatement(SageBuilder::buildVarRefExp(maxStr)));
	  //maxStr = "wait(" + accString + "_LATENCY, SC_NS)";
	  ostringstream tmp;
	  tmp << (tripCountAvg-1);
	  maxStr = "wait(("+accString + "_LATENCY + "  + accString + "_II * " +tmp.str()+"), SC_NS)"; 
	  isSgBasicBlock(*bbit)->append_statement(SageBuilder::buildExprStatement(SageBuilder::buildVarRefExp(maxStr)));

	  //reset them to 0
	  for(k = arrNames.begin(); k!=arrNames.end(); ++k){
	    std::string rst = (*k) + "=0";
	    //SageInterface::attachArbitraryText(isSgForStatement(*bbit), rst, PreprocessingInfo::after);
	    isSgBasicBlock(*bbit)->append_statement(SageBuilder::buildExprStatement(SageBuilder::buildVarRefExp(rst)));
	  }
	  insertForEachBlock((*bbit), acc_num++, 3, arrayDimMap, tripCountAvg);
  }


  /*for(std::set<SgNode*>::iterator it = bestLoopsCopy2.begin(); it != bestLoopsCopy2.end(); ++it){
	  using namespace std;
  	  if(bestLoopsCopyAcc.at((*it)) == false){
  	  	  Rose_STL_Container<SgNode*> bbNodes = NodeQuery::querySubTree((*it), V_SgBasicBlock);
  	  	  Rose_STL_Container<SgNode*>::iterator bbit;
  	  	  for(bbit = bbNodes.begin(); bbit != bbNodes.end(); ++bbit){
  	  	  	  if(((*bbit)->get_parent() == isSgForStatement(*it)->get_loop_body()) && (isSgForStatement(*(isSgBasicBlock(*bbit)->get_statements().begin())))){
				  std::ostringstream stm_tmp;
				  stm_tmp << "acc" << acc_num;
				  std::string accString(stm_tmp.str());
				  AstTextAttribute* accNumS = new AstTextAttribute(accString);
				  SgForStatement* rootLoop = isSgForStatement(*(isSgBasicBlock(*bbit)->get_statements().begin()));
				  ROSE_ASSERT(rootLoop);

				  //innermost loop
				  std::vector<SgNode*> forLoops = NodeQuery::querySubTree(rootLoop->get_loop_body(), V_SgForStatement);
				  forLoops.push_back(rootLoop);
				  for(std::vector<SgNode*>::iterator i = forLoops.begin(); i != forLoops.end(); ++i){
				  	  SgForStatement* fs = isSgForStatement(*i);
				  	  ROSE_ASSERT(fs);
					  std::vector<SgNode*> query = NodeQuery::querySubTree(fs->get_loop_body(), V_SgForStatement);
					  if(query.size() == 0){
					  	  isSgNode(fs)->setAttribute(std::string("accNum"), accNumS);
					  }
					  break;
				  }

				  Rose_STL_Container<SgNode*> varRefs = NodeQuery::querySubTree((*bbit), V_SgVarRefExp);
				  std::set<std::string> arrNames;
				  for(Rose_STL_Container<SgNode*> :: iterator k = varRefs.begin(); k != varRefs.end(); ++k){
				    SgVarRefExp* varRef = isSgVarRefExp(*k);
				    if(varRef && isSgArrayType(varRef->get_symbol()->get_type())){
				      std::string name = varRef->get_symbol()->get_name() + "_cycle";
				      arrNames.insert(name);
				    }
				  }
				  std::set<std::string>::iterator k = arrNames.begin();

				  std::string maxStr = (*k++);
				  for(; k!= arrNames.end(); ++k){
				    maxStr = "std::max(" + maxStr + ", " + (*k) + ")";
				  }
				  maxStr = "wait(" + maxStr + "*(thread_id+1), SC_NS)";
				  //SageInterface::attachArbitraryText(isSgStatement(*bbit), maxStr, PreprocessingInfo::after);
				  isSgBasicBlock(*bbit)->append_statement(SageBuilder::buildExprStatement(SageBuilder::buildVarRefExp(maxStr)));
				  maxStr = "wait(" + accString + "_LATENCY, SC_NS)";
				  isSgBasicBlock(*bbit)->append_statement(SageBuilder::buildExprStatement(SageBuilder::buildVarRefExp(maxStr)));

				  //reset them to 0
				  for(k = arrNames.begin(); k!=arrNames.end(); ++k){
				    std::string rst = (*k) + "=0";
				    //SageInterface::attachArbitraryText(isSgForStatement(*bbit), rst, PreprocessingInfo::after);
				    isSgBasicBlock(*bbit)->append_statement(SageBuilder::buildExprStatement(SageBuilder::buildVarRefExp(rst)));
				  }
				  //FIXME
				  insertForEachBlock((*bbit), acc_num++, 3, 100);
				  break;
  	  	  	  }
  	  	  }
  	  	  bestLoopsCopyAcc.at(*it) = true;
  	  }

  }*/


  removeEmptyBasicBlocks(root);

  if (debug_level > 3)
    {
      std::cout << "[LMP] Final code: " << std::endl;
      std::cout << root->unparseToCompleteString() << std::endl;
    }

  // std::cout << "Run consistency tests (1): " << std::endl;
  // AstTests::runAllTests(SageInterface::getProject());


  std::cout << "[LMP] Local Memory Promotion: all done" << std::endl;
}


//return the trip counts for this loop
int insertMemoryCycle(SgNode* commRoot, std::map<SgNode*, isl_set*>& loopTCmap, scoplib_scop_p scop, std::map<std::string, int> &ArrayDimMap){
  
//  std::cout <<"\n\n\n bla \n\n\n";
	      annotateLoopTripCount(commRoot, scop, loopTCmap);
	      Rose_STL_Container<SgNode*> query_comm =
	      	NodeQuery::querySubTree(commRoot, V_SgForStatement);
	      int tripCountAvg = 1;
	      for (std::vector<SgNode*>::iterator j = query_comm.begin(); j != query_comm.end(); ++j){
	      	//std::cout << (*j)->unparseToCompleteString() << std::endl;
	      	SgForStatement* fs = isSgForStatement((*j));
	      	SageAPForInfo* annot = (SageAPForInfo*)fs ->getAttribute("SageAPForInfo");
	      	assert(annot !=NULL);
	      	tripCountAvg *= annot->avgTripCount;
	      	//printf("average trip count : %d, \n", avg);
	      }

	      SageAPCopyBlockInfo* annot = (SageAPCopyBlockInfo*)commRoot->getAttribute("SageAPCopyBlockInfo");
	      SgVariableSymbol* local_array = annot->local_sym;
	      int dim = annot->dim ;

	      if(dim ){
		const std::string locArrCycle = local_array->get_name().getString() + "_cycle";
		//std::cout << "local array name is " << locArrName << std::endl;
		//SgVariableDeclaration* var = SageBuilder::buildVariableDeclaration (locArrCycle, SageBuilder::buildIntType(), SageBuilder::buildAssignInitializer(SageBuilder::buildIntVal(tripCountAvg)) ,isSgScopeStatement(isSgStatement(commRoot)));
		//SgVariableDeclaration* var = SageBuilder::buildVariableDeclaration(locArrCycle, SageBuilder::buildIntType(), SageBuilder::buildAssignInitializer(SageBuilder::buildIntVal(tripCountAvg)), isSgScopeStatement(commRoot));
		//SgExpression* assign = isSgExpression(SageBuilder::buildBinaryExpression<SgAssignOp>(SageBuilder::buildVarRefExp(var), SageBuilder::buildIntVal(tripCountAvg)));
		SgExprStatement* assign = SageBuilder::buildAssignStatement(SageBuilder::buildVarRefExp(locArrCycle, isSgScopeStatement(commRoot)), SageBuilder::buildIntVal(tripCountAvg));
		isSgBasicBlock(commRoot)->append_statement(assign);
		//std::cout << "assign stmt is " << std::endl << std::endl << assign->unparseToCompleteString() << std::endl << std::endl;
		//SageInterface::attachArbitraryText(isSgStatement(commRoot),  assign->unparseToCompleteString() + ";\n", PreprocessingInfo::after);
	      }
	      ArrayDimMap[local_array->get_name().getString()] = tripCountAvg;
	      //std::cout << "\n\narray name " << local_array->get_name().getString() << ", inserted tripCount is " << tripCountAvg << std::endl;
	      return tripCountAvg;

}

//cnt is the number of iterations for this loop block
void insertForEachBlock(SgNode* Root, int acc_Num, int inputBlockType, std::map<std::string, int> &ArrayDimMap, int cnt){
//void insertForEachBlock(SgNode* Root, int cnt){

  using namespace std;
	int index = 0;
	int cntForAcc = cnt;
        //build hamming function for each tile iteration
        //defining the function name hamming and the return type
        SgName funcName ("hamming");
        SgTypeUnsignedInt* retType = SageBuilder::buildUnsignedIntType();
        
        //declare power
	SgVariableDeclaration* power = SageBuilder::buildVariableDeclaration("power", SageBuilder::buildDoubleType(), SageBuilder::buildAssignInitializer(SageBuilder::buildDoubleVal(0)), isSgScopeStatement(Root));
	isSgBasicBlock(Root)->prepend_statement(power); 

	string	latency;
	std::ostringstream stm;
	//accNumString
	stm << acc_Num;
	std::string accNumString(stm.str());

	if(inputBlockType == 1){
	  std::ostringstream tmp;
	  tmp << "wait(" << cnt << "*READ_LATENCY, SC_NS)";
	  //string maxStr = "wait(" + string(cnt) + "*(thread_id+1)*READ_LATENCY, SC_NS)";
	  string maxStr = tmp.str();
	  //SageInterface::attachArbitraryText(isSgStatement(*bbit), maxStr, PreprocessingInfo::after);
	  isSgBasicBlock(Root)->append_statement(SageBuilder::buildExprStatement(SageBuilder::buildVarRefExp(maxStr)));
	}
	

	//get the innermost loop
	std::vector<SgNode*> s= NodeQuery::querySubTree(Root, V_SgForStatement);
	for(std::vector<SgNode*>::iterator i = s.begin(); i != s.end(); ++i){
		SgForStatement* fs = isSgForStatement(*i);
		ROSE_ASSERT(fs);
		std::vector<SgNode*> query = NodeQuery::querySubTree(fs->get_loop_body(), V_SgForStatement);
		if(query.size() != 0) continue;
    
    		//found the innermost loop
    		SgBasicBlock* fbb = isSgBasicBlock(fs->get_loop_body());
    		ROSE_ASSERT(fbb);
    		std::vector<SgNode*> readRefs;
    		std::vector<SgNode*> writeRefs;
    		ROSE_ASSERT(SageTools::collectReadWriteRefs(isSgStatement(fbb), readRefs, writeRefs, true));
    		//we can only control the input ,which are the readRefs.
    		std::vector<SgNode*> :: iterator itr = readRefs.begin();
    		bool containArray = false;
    		for(; itr != readRefs.end();++itr){ 
    		        //cout << "read ref is " << (*itr)->unparseToCompleteString() << endl << endl;
    			Rose_STL_Container<SgNode*> varRefs = NodeQuery::querySubTree((*itr), V_SgVarRefExp);
    			bool isArray= false;
    			//check whether this is an array read ref, otherwise, skip
    			for(Rose_STL_Container<SgNode*>::iterator iitr = varRefs.begin(); iitr != varRefs.end(); ++iitr){
    				if(isSgArrayType(isSgVarRefExp(*iitr)->get_symbol()->get_type())) {
    					isArray = true;
    					containArray = true;
				} else {
					varRefs.erase(iitr--);
				} 
			}
			if(!isArray) continue;
    			
    			assert(varRefs.size() == 1);
    			SgVarRefExp* readRef = isSgVarRefExp(*varRefs.begin());
			SgType* readRefType = readRef->get_symbol()->get_type();
			while(isSgArrayType(readRefType)) readRefType = isSgArrayType(readRefType)->get_base_type();
			//if(!isSgArrayType(readRefType)); //FIXME, do I need to constrain to array type? Yes otherwise it become the indices
			std::string readRefName = readRef->get_symbol() ->get_name();
			if(inputBlockType == 3){
			  cnt = ArrayDimMap[readRefName];
			  //cout << "readRef Name " << readRefName  << ", cnt = " << cnt << endl;
			}
			//cout << "read ref name " << readRefName << endl << endl;
			ostringstream tmp;
			tmp << index;
    			std::string preEntry("pre_entry_" + readRefName+tmp.str());
			SgVariableDeclaration* preEntryVarDec = SageBuilder::buildVariableDeclaration(preEntry, readRefType, SageBuilder::buildAssignInitializer(SageBuilder::buildIntVal(0)), isSgScopeStatement(Root));
			//build dis
			std::string dis("dis"+tmp.str());
			SgVariableDeclaration* disVarDec = SageBuilder::buildVariableDeclaration(dis, SageBuilder::buildUnsignedIntType(), SageBuilder::buildAssignInitializer(SageBuilder::buildUnsignedIntVal(0)), isSgScopeStatement(Root));
			isSgBasicBlock(Root)->prepend_statement(disVarDec);

			//call hamming function
	      		isSgBasicBlock(Root)->prepend_statement(preEntryVarDec);
    			SgVarRefExp* preEntryVar = SageBuilder::buildVarRefExp(preEntry);
    			SgExprListExp* parameters = SageBuilder::buildExprListExp(preEntryVar, isSgExpression(*itr));
    			SgFunctionCallExp* func =SageBuilder::buildFunctionCallExp(funcName, retType, parameters, isSgScopeStatement(Root));
    			SgVarRefExp* disVar = SageBuilder::buildVarRefExp(dis);
    			SgExprStatement* funcAssign = SageBuilder::buildAssignStatement(disVar, SageBuilder::buildBinaryExpression<SgAddOp>(disVar, func));
    			//pre_entry = x_l[ 
    			SgExprStatement* preEntryAssign = SageBuilder::buildAssignStatement(preEntryVar, isSgExpression(*itr));
    			fbb->prepend_statement(preEntryAssign);
    			fbb->prepend_statement(isSgStatement(funcAssign)); 
    			//build sw
    			std::string sw("sw"+tmp.str());
    			SgVariableDeclaration* swVarDec = SageBuilder::buildVariableDeclaration(sw, SageBuilder::buildDoubleType(), SageBuilder::buildAssignInitializer(SageBuilder::buildDoubleVal(0)), isSgScopeStatement(Root));
    			isSgBasicBlock(Root)->prepend_statement(swVarDec);

			//sw =((double)dis/(double)(8*sizeof(DATA_TYPE)))/(double)(cnt-1)

			//SgVarRefExp* disVar = SageBuilder::buildVarRefExp(dis);
			SgCastExp* doubleDis = SageBuilder::buildCastExp(disVar, SageBuilder::buildDoubleType());
			SgCastExp* doubleMul = SageBuilder::buildCastExp(SageBuilder::buildBinaryExpression<SgMultiplyOp>(SageBuilder::buildIntVal(8), SageBuilder::buildSizeOfOp(SageBuilder::buildVarRefExp("DATA_TYPE"))), SageBuilder::buildDoubleType()); 
			SgDoubleVal* doubleCnt = SageBuilder::buildDoubleVal((double)cnt/20);
			//SgCastExp* doubleCnt = SageBuilder::buildCastExp(
			  //SageBuilder::buildBinaryExpression<SgSubtractOp>(SageBuilder::buildVarRefExp(counter), SageBuilder::buildIntVal(1)),
			//  SageBuilder::buildIntVal(cnt-1),
			//  SageBuilder::buildDoubleType()
			//  );
			SgDivideOp* div1 = SageBuilder::buildBinaryExpression<SgDivideOp>(doubleDis, doubleMul);
			SgDivideOp* div2 = SageBuilder::buildBinaryExpression<SgDivideOp>(div1, doubleCnt);
			SgAddOp* add1 = SageBuilder::buildBinaryExpression<SgAddOp>(div2, SageBuilder::buildDoubleVal(0.5));
			//SgExprStatement* swAssign = SageBuilder::buildAssignStatement(SageBuilder::buildVarRefExp(sw), div2);
			SgExprStatement* swAssign = SageBuilder::buildAssignStatement(SageBuilder::buildVarRefExp(sw),add1);
			isSgBasicBlock(Root)->append_statement(swAssign);


			//power
			//FIXME: use real number of accNum and local_size
			//int inputBlockType = 1;

			std::string dyn_power;
			if(inputBlockType == 1 or inputBlockType == 3){ //read
				dyn_power = "m_dyn_read";
		//		latency = "READ_LATENCY";
			}
			else{ //write
				dyn_power = "m_dyn_write";
		//		latency = "WRITE_LATENCY";
			}
			//else{
				//dyn_power = "acc" + accNumString + "_pwr";
				//latency = "acc" + accNumString +"_LATENCY";
			//}


			int local_size_final = roundUp(cnt);
			SgPntrArrRefExp* dynArr = SageBuilder::buildBinaryExpression<SgPntrArrRefExp>(SageBuilder::buildVarRefExp(dyn_power), SageBuilder::buildIntVal(local_size_final));
			SgCastExp* castSw = SageBuilder::buildCastExp(SageBuilder::buildVarRefExp(sw), SageBuilder::buildUnsignedIntType());
			SgPntrArrRefExp* dynArr1;
			//if(inputBlockType == 1 || inputBlockType == 2)
				dynArr1 = SageBuilder::buildBinaryExpression<SgPntrArrRefExp>(dynArr, castSw);
			//else
			//	dynArr1 = SageBuilder::buildBinaryExpression<SgPntrArrRefExp>(SageBuilder::buildVarRefExp(dyn_power), castSw);

			//power = power + dynArray;
			SgExprStatement* assignPower = SageBuilder::buildAssignStatement(
			  SageBuilder::buildVarRefExp(power), 
			  SageBuilder::buildBinaryExpression<SgAddOp>
			  (SageBuilder::buildVarRefExp(power), dynArr1));
    			isSgBasicBlock(Root)->append_statement(assignPower);

		
			index++;
		}

		if(!containArray) return;
		//we need to extraly consider the write to memory power and the accelerator power
		if(inputBlockType == 3){

		  std::string sw_lhs("(sw0");
		  for(int i = 1; i < index; i++){
		    ostringstream tmp;
		    tmp << i;
		    sw_lhs = sw_lhs + "+sw"+tmp.str();
		  }
		  sw_lhs += ")";
		  SgVariableDeclaration* swVarDec = SageBuilder::buildVariableDeclaration("sw", SageBuilder::buildDoubleType(), SageBuilder::buildAssignInitializer(
		      SageBuilder::buildBinaryExpression<SgDivideOp>(SageBuilder::buildVarRefExp(sw_lhs), SageBuilder::buildDoubleVal(index))),
		       isSgScopeStatement(Root));

		  isSgBasicBlock(Root)->append_statement(swVarDec);

		  std::string dyn_power = "acc" + accNumString + "_pwr";
		  //latency = "acc"+accNumString + "_LATENCY" " + acc" + accNumString + "_II * " +(cntForAcc-1); 

		  SgCastExp* castSw = SageBuilder::buildCastExp(SageBuilder::buildVarRefExp("sw"), SageBuilder::buildUnsignedIntType());
		  SgPntrArrRefExp* dynArr1 = SageBuilder::buildBinaryExpression<SgPntrArrRefExp>(SageBuilder::buildVarRefExp(dyn_power), castSw);

		  //power = power + dynArray;
		  SgExprStatement* assignPower = SageBuilder::buildAssignStatement(
		    SageBuilder::buildVarRefExp(power), 
		    SageBuilder::buildBinaryExpression<SgAddOp>
		    (SageBuilder::buildVarRefExp(power), dynArr1));
		  isSgBasicBlock(Root)->append_statement(assignPower);


		}
	}
	//energy
	//SgVariableDeclaration* energy = SageBuilder::buildVariableDeclaration("energy", SageBuilder::buildDoubleType(), SageBuilder::buildAssignInitializer(SageBuilder::buildDoubleVal(0)), isSgScopeStatement(Root));
	//isSgBasicBlock(Root)->prepend_statement(energy);

	if(inputBlockType == 1){ //read
		latency = "READ_LATENCY";
	}
	else if(inputBlockType == 2){ //write
		latency = "WRITE_LATENCY";
	}
	else{
		//latency = "acc" + accNumString +"_LATENCY";
		ostringstream tmp;
		tmp << (cntForAcc-1);
		latency = "(acc"+accNumString + "_LATENCY" " + acc" + accNumString + "_II * " +tmp.str()+")"; 
		cnt = cntForAcc;
	}

	//energy = energy + power * latency
	SgAddOp* energyPlusPower ;
	if(inputBlockType ==1 || inputBlockType == 2)
	  energyPlusPower= SageBuilder::buildBinaryExpression<SgAddOp>(SageBuilder::buildVarRefExp("energy"),
	  SageBuilder::buildBinaryExpression<SgMultiplyOp>(SageBuilder::buildVarRefExp(latency), 
	 SageBuilder::buildBinaryExpression<SgMultiplyOp>(SageBuilder::buildVarRefExp(power),
		 SageBuilder::buildIntVal(cnt))
	 ));
	else
	  energyPlusPower = SageBuilder::buildBinaryExpression<SgAddOp>(SageBuilder::buildVarRefExp("energy"), 
	    SageBuilder::buildBinaryExpression<SgMultiplyOp>(SageBuilder::buildVarRefExp(latency), SageBuilder::buildVarRefExp(power))
	    );
	SgExprStatement* energyAssign = SageBuilder::buildAssignStatement(SageBuilder::buildVarRefExp("energy"), energyPlusPower);
	//SgExprStatement* energyAssign = SageBuilder::buildAssignStatement(SageBuilder::buildVarRefExp(energy), SageBuilder::buildDoubleVal(0));
	isSgBasicBlock(Root)->append_statement(energyAssign);
}

int roundUp(int x) { 
  int power = 1;
  while(power < x)
    power*=2;
  return power;
}

bool tiledLoop(SgForStatement* forLoop, std::set<std::string> tLoops){

  SgExpression* tmp =  forLoop -> get_increment();
  Rose_STL_Container<SgNode*> varRefs = NodeQuery::querySubTree(tmp, V_SgVarRefExp);
  for(Rose_STL_Container<SgNode*> :: iterator k = varRefs.begin(); k != varRefs.end(); ++k){
    SgVarRefExp* varRef = isSgVarRefExp(*k);
    if(varRef && isSgArrayType(varRef->get_symbol()->get_type())) continue;
    else if(varRef){
      std::string name = varRef->get_symbol()->get_name();
      if (tLoops.find(name) != tLoops.end()){//found tile loop
      	return true;
      }

    }
  }
  return false;
}

