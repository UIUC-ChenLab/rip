use Time::HiRes qw( gettimeofday );
use File::chdir;

require 'parse_code_for_asm_insert.pl';
require 'parse_code_for_back_annotation.pl';
require 'pin_profile/profile_code.pl';
require 'parse_predicted_points.pl';

#BEGIN_CHANGE_ME
#Benchmark Specific Parameters:  These parameters will need to be changed for each benchmark.
#  Each is related to paths or file names that are unique to each benchmark

#  These variables include: 
#  -The absolute path associated with the top level directory
#  -The prefix name of the benchmark (used for generating and identifying the generated <name>.out file)
#  -The source file containing the main() function, for now we expect that this file also contains the ROI directives
#  -Additional source files (typically non-header) that will also need to be compiled before runtime
#  -Benchmark arguments that are to be passed into executable benchmark at runtime

my $current_directory = "<You DIR>/benchmarks/generic_benchmark";
my $benchmark = "lu";
my $main_source_file = "lu.c";
my $additional_dependencies = "polybench.c";
my $benchmark_arguments = "";

#General Parameters:  These parameters are related to paths and runtime environment and will likely remain consistent between benchmarks
my $pintool_directory = "<PIN install dir>/source/tools";
my $mcpat_directory = "<MACPAT install dir>";
my $gem5_directory = "<gem5 install dir>";
my $gem5_executable = $gem5_directory . "/build/X86/gem5.perf";
my $gem5_config = $gem5_directory . "/configs/example/se.py";

#Target CPU Parameters: Please look at gem5 manual for a list of command parameters, as these allow you to modify the target CPU
#not all CPU parameters can be modified in command line, you may need to generate a new CPU model or config file, in which case
#those parameters would need to be modified instead.  However, you should be able to configure by command line things such as 
#core frequency, parallelism, and cache structure here. Note that these only effect the gem5 simulation and does not effect the 
#McPAT execution.  Unfortunately the only way to modify the McPAT simulation is to generate a new template xml file
my $gem5_executable_parameters = "\"--cpu-type=kvm --standard-switch=1 --cpu-clock=3.4GHz --caches --l2cache --fast-forward=1 --maxinsts=1\"";
my $McPAT_template_file = "my_xeon_template.xml";

#Simulation Parameters:  These parameters allow you to modify the simulation parameters 
my $warmup_instructions = 3000000;
my $host_parallelism = 6;
my $latency_tolerance = 0.001;
my $power_tolerance = 0.005;
#boolean to indicate whether guided ROI should be used, if it is set to 1, then in the Start_ROI_loop(Iteration number) you put in source file, the Iteration number will be ignored
my $guided = 1;
#2D Array to indicate ROI divisions, inner dimension represents different ROI blocks in benchmark and needs to be sized accordingly, outer dimension indicates different runs
#note that this variable is ignored if guided is set to 1
my @ROI_array = (['4000','4000','4000'], ['20','20','20']);
#boolean to indicate whether to run PIN TOOL profiling of code. This only needs to be run once per benchmark (unless benchmark has new input arguments).
#after initial run, this should be changed to 0;  Otherwise this will result in unnecessarily long runtime.
my $run_PIN = 1;

#END_CHANGE_ME

my $command = "";
my $array_index = 0;
my $simulation_suffix = "";

#copy source files to target location to ensure that all modifications overwrite working source file structure
$command = "cp -R $current_directory/source_files/* $current_directory/target_files/";
system($command);

if ($run_PIN == 1){
	#copy source files in preparation for PIN execution run
	$command = "cp -R $current_directory/source_files/* $current_directory/pin_profile/";
	system($command);
	
	#generate source code with assembly directives, to overwrite main_source_file
	partition_asm_insert($current_directory, $benchmark, $main_source_file);

	#profile code using PIN tool
	$CWD = $current_directory . "/pin_profile";
	run_pin_profile($benchmark, $main_source_file, $additional_dependencies, $benchmark_arguments, $current_directory . "/pin_profile", $pintool_directory);
	$CWD = $current_directory;
}

if($guided == 1){
	$simulation_suffix = "guided_" . $warmup_instructions;

	#parse the source file into multiple ROI according to guided algorithm
	#this require must go here...otherwise perl libraries updated by pin run will not be reflected
	require 'parse_code_guided.pl';
	partition_guided($current_directory, $benchmark, $main_source_file, $simulation_suffix);
	
	#generate directory file to map ROI structure for batch controller
	$command = "perl generate_directory_file.pl $current_directory";
	system($command);
	
	#Simulate the ROI using convergence modelling as controlled through async batch control
	$command = "./batch_control.out " . $host_parallelism . " " . $current_directory . " " . $mcpat_directory . " " . $benchmark . " " . $warmup_instructions . " " . $latency_tolerance . " " . $power_tolerance . " " . $gem5_executable ." " . $gem5_config . " " . $gem5_executable_parameters . " " . $McPAT_template_file . " " . $simulation_suffix ." > log_" . $simulation_suffix . ".txt";
	system($command);

	#Combine simulation results into a single file
	$command = "perl combine_results.pl " . $current_directory;
	system($command);

	#generate output source code that can interface with back annotated data
	partition_back_annotation($current_directory, $benchmark, $main_source_file, $simulation_suffix);
	
	#Rename output of batch_control to reflect specific input parameters (allowing multiple runs without overwriting data)
	#predicted points reflects the entire model while global performance results contains only points sampled during simulation
	$command = "mv predicted_points.csv predicted_points_" . $simulation_suffix . ".csv";
	system($command);
	$command = "mv global_performance_results.csv global_performance_results_" . $simulation_suffix . ".csv";
	system($command);
	
}
else{
	#this require must go here...otherwise perl libraries updated by pin run will not be reflected
	require 'parse_code_standard.pl';
	foreach $ROI_setting (@ROI_array) {
		$simulation_suffix = $ROI_array[$array_index][0] . "_" . $warmup_instructions;
		#parse the source file into multiple ROI according to array values
		partition_standard($current_directory, $benchmark, $main_source_file, \@ROI_array, $array_index, $simulation_suffix);

		#generate directory file to map ROI structure for batch controller
		$command = "perl generate_directory_file.pl $current_directory";
		system($command);

		#Simulate the ROI using convergence modelling as controlled through async batch control
		$command = "./batch_control.out " . $host_parallelism . " " . $current_directory . " " . $mcpat_directory . " " . $benchmark . " " . $warmup_instructions . " " . $latency_tolerance . " " . $power_tolerance . " " . $gem5_executable ." " . $gem5_config . " " . $gem5_executable_parameters . " " . $McPAT_template_file . " " . $simulation_suffix ." > log_" . $simulation_suffix . ".txt";
		system($command);

		#Combine simulation results into a single file
		$command = "perl combine_results.pl " . $current_directory;
		system($command);

		#generate output source code that can interface with back annotated data
		partition_back_annotation($current_directory, $benchmark, $main_source_file, $simulation_suffix);
		
		#Rename output of batch_control to reflect specific input parameters (allowing multiple runs without overwriting data)
		#predicted points reflects the entire model while global performance results contains only points sampled during simulation
		$command = "mv predicted_points.csv predicted_points_" . $simulation_suffix . ".csv";
		system($command);
		$command = "mv global_performance_results.csv global_performance_results_" . $simulation_suffix . ".csv";
		system($command);
		
		$array_index += 1;
	}
}

#combine results to calculate total energy and latency for each region.  Results for all tests are entered into a single file for quick viewing
parse_predicted_points($current_directory);
