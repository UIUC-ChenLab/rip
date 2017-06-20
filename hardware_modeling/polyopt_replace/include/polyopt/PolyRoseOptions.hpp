/*
 * PolyRoseOptions.hpp: This file is part of the PolyOpt project.
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
 * @file: PolyRoseOptions.hpp
 * @author: Louis-Noel Pouchet <pouchet@cse.ohio-state.edu>
 */


#ifndef POLYOPT_POLYOPTOPTIONS_HPP
# define POLYOPT_POLYOPTOPTIONS_HPP

# include <pocc/options.h>


class PolyRoseOptions
{
public:
  PolyRoseOptions();
  PolyRoseOptions(int argc, char** argv);
  void parse(int argc, char** argv);
  s_pocc_options_t* buildPoccOptions();


  // Accessors.
  bool getCodegenUsePAST();
  bool isVerbose();
  int getScVerboseLevel();
  bool getScUnsafeExtractor();
  bool getScStrictExtractor();
  bool getScApproximateExtractor();
  bool getScF2CExtractor();
  bool getScGenericExtractor();
  bool getAnnotateOnly();
  bool getAnnotateInnerLoops();
  void setAnnotateInnerLoops(bool val);
  bool getGeneratePragmas();
  void setGeneratePragmas(bool val);
  bool getComputeDDV();
  void setComputeDDV(bool val);
  bool getHullifyDDV();
  void setHullifyDDV(bool val);
  bool getAllowMathFunc();
  void setAllowMathFunc(bool val);
  bool getCodegenUsePtile();
  void setCodegenUsePtile(bool val);
  bool getInsertPtileAPI();
  void setInsertPtileAPI(bool val);
  bool getQuiet();
  void setQuiet(bool val);
  bool getOptimize();
  void setOptimize(bool val);
  void setPluto(bool val);
  bool getPluto();
  void setPlutoTile(bool val);
  void setPlutoParralel(bool val);
  void setPlutoPrevector(bool val);

  void setScalarPrivatization(bool val);
  bool getScalarPrivatization();

  //for SystemC transformation
  bool getScHLS();
  std::string getSCTargetFunc();
  std::string getSCTestbenchFunc();
  std::string getSCDepth();
  bool getSCPreprocess();
  bool getSCPretile();
  //std::string getSCUnrollFile();


  void setHLS(bool val);
  bool getHLS();
  bool getHLSautopilot();
  bool getHLSautopilotMembus();
  bool getHLSautopilotFifo();
  bool getHLSautopilotFifoSimu();
  bool getHLSLotha();
  bool getHLSBuffergen();
  bool getHLSLMP();
  long int getHLSMaxBuffSizePerArray();
  bool getHLSModuloSimplification();
  bool getHLSLoopBoundSimplification();
  bool getHLSAPPragmaDepFalse();
  bool getHLSAPPragmaTripcount();
  bool getHLSLoopInvariantRefHoisting();
  bool getHLSRefGVN();
  bool getHLSPrefetchFun();
  bool getHLSCostFunctionBSL();
  bool getHLSUsefloat2();
  bool getASTConsistencyCheck();
  void setASTConsistencyCheck(bool val);

  /**
   * Static attributes for verbosity.
   *
   */
  static const int VERBOSE_NONE = 0;
  static const int VERBOSE_BASIC = 1;
  static const int VERBOSE_COMPREHENSIVE = 2;
  static const int VERBOSE_SHOWINVALID = 3;
  static const int VERBOSE_FULL = 4;
  static const int VERBOSE_DEBUG = 5;

  //private:
private:
  void initialize();
  // PolyRose Options
  bool		pr_verbose;
  bool		polyopt_quiet;
  bool		sc_generic_scop_extractor;
  int			sc_scop_extractor_verbose_level;
  bool		sc_strict_scop_extractor;
  bool		sc_unsafe_scop_extractor;
  bool		sc_approximate_scop_extractor;
  bool		sc_f2c_scop_extractor;
  bool	        sc_allow_math_func;

  // Sanity check.
  bool		polyopt_ast_consistency_check;

  // Dependence analysis.
  bool		polyopt_scalar_privatization;

  // Main Optimization options.
  bool		polyopt_fixed_tiling;
  bool		polyopt_parametric_tiling;
  bool		polyopt_parallel_only;

  // Main driver control.
  bool		polyopt_annotate_only;
  bool		polyopt_annotate_inner_loops;
  bool		polyopt_generate_pragmas;
  bool		polyopt_compute_ddv;
  bool		polyopt_hullify_ddv;
  bool		polyopt_optimize;

  // Codegen options.
  bool		polyopt_codegen_use_past;
  bool		polyopt_codegen_use_ptile;
  bool		polyopt_insert_ptile_api;

  // HLS options.
  bool		polyopt_HLS;
  bool		polyopt_HLS_default;
  long int		polyopt_HLS_max_buff_size_per_array;
  bool		polyopt_HLS_autopilot;
  bool		polyopt_HLS_autopilot_membus;
  bool		polyopt_HLS_autopilot_fifo;
  bool		polyopt_HLS_autopilot_fifo_simu;
  bool		polyopt_HLS_Lotha;
  bool		polyopt_HLS_Buffergen;
  bool		polyopt_HLS_LMP;
  bool		polyopt_HLS_create_ap_pragma_tripcount;
  bool		polyopt_HLS_create_ap_pragma_dep_false;
  bool		polyopt_HLS_loop_bound_hoisting;
  bool		polyopt_HLS_loop_invariant_ref_hoisting;
  bool		polyopt_HLS_ref_inner_GVN;
  bool		polyopt_HLS_modulo_simpl;
  bool		polyopt_HLS_gen_prefetch_fun;
  bool		polyopt_HLS_cost_function_is_bsl;
  bool		polyopt_HLS_use_float2;


  // PoCC Options.
  // In/Out file information
  FILE*		pocc_input_file;
  char*		pocc_input_file_name;
  FILE*		pocc_output_file;
  char*		pocc_output_file_name;

  // Verbose.
  bool		pocc_verbose;
  bool		pocc_quiet;

  // Trash.
  bool		pocc_trash;

  // Parser options.
  bool		pocc_clan_bounded_context;
  bool		pocc_inscop_fakepoccarray;

  // Compile command.
  char*		pocc_compile_command;
  char*		pocc_execute_command_args;

  // LetSee Options.
  bool		pocc_letsee; // Run LetSee (default: no)
  int		pocc_letsee_space;
  int		pocc_letsee_traversal;
  bool		pocc_letsee_normspace;
  int*		pocc_letsee_scheme_m1;
  bool		pocc_letsee_prune_precut;
  bool		pocc_letsee_backtrack_multi;
  int		pocc_letsee_rtries;
  int		pocc_letsee_ilb;
  int		pocc_letsee_iUb;
  int		pocc_letsee_plb;
  int		pocc_letsee_pUb;
  int		pocc_letsee_clb;
  int		pocc_letsee_cUb;

  // PLuTo Options.
  bool		pocc_pluto; // Run PLuTo (default: no)
  bool		pocc_pluto_unroll;
  bool		pocc_pluto_parallel;
  bool		pocc_pluto_tile;
  bool		pocc_pluto_rar;
  int		pocc_pluto_fuse;
  bool		pocc_pluto_polyunroll;
  bool		pocc_pluto_bee;
  bool		pocc_pluto_prevector;
  int		pocc_pluto_ufactor;
  bool		pocc_pluto_quiet;
  bool		pocc_pluto_context;
  int		pocc_pluto_ft;
  int		pocc_pluto_lt;
  bool		pocc_pluto_multipipe;
  bool		pocc_pluto_l2tile;
  bool		pocc_pluto_lastwriter;
  bool		pocc_pluto_scalpriv;

  // Vectorization.
  bool		pocc_vectorizer;
  // Storage compaction.
  bool		pocc_storage_compaction;

  // SystemC transform options
  std::string 	systemc_target_func;
  std::string 	systemc_testbench_func;
  bool 		systemc_pretile;
  bool		systemc_preprocess;
  bool		systemc_HLS;
  std::string	systemc_depth;
};


#endif
