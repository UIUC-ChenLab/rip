#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <math.h>
#include <pthread.h>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

#define SEED 0
#define SAVE 1
#define ARGS 13
#define PARAMETER_BUFF_SIZE 256

using namespace std;

struct ROI_datapoint {
	int ROI_number;
	bool value_set;
	double data_value_latency;
	double data_value_power;
	long instruction_start;
	long instruction_length;
	int warmup_iter;
	int start_iter;
	int stop_iter;
	int speculative_pid;
	int next_set;
	int prev_set;
	bool next_dep_met;
	bool prev_dep_met;
};

struct ROI_tuple {
	int set_number;
	int sub_setnumber;
};

vector<int> core_assignment_list;
vector<int> convergence_list;

int * previous_last_values;

vector<vector<string> > ROI_table;
vector<vector<ROI_datapoint> > resulting_datapoints;
string my_current_directory;
string my_benchmark;
string my_McPAT_directory;
string warmup_instruction_count;
double LATENCY_TOLERANCE;
double POWER_TOLERANCE;
string McPAT_template_file;
char *gem5_parameters;
int number_gem5_parameters;
string simulation_suffix;

char **execution_parameters;

std::vector<std::vector<int> > ROI_dependency_queues;

//McPat is NOT thread safe, but we need to call it from within pthreads
pthread_mutex_t mcpat_protection;
pthread_mutex_t core_assignment_mutex;
pthread_mutex_t convergence_list_mutex;
pthread_mutex_t * division_assignment_mutex_list;
pthread_mutex_t * ROI_queue_mutex_list;
pthread_cond_t * ROI_queue_condition_list;

void extract_gem5_parameters_from_string(string gem5_executable, string gem5_config, string gem5_executable_parameters){
	//string gem5_executable_parameters = gem5_executable_parameters_with_quotes.substr(1, gem5_executable_parameters_with_quotes.size() - 1);
	istringstream my_string_stream( gem5_executable_parameters );
	vector <string> record;
	while (my_string_stream)
	{
		string s;
		if (!getline( my_string_stream, s, ' ' )) break;
		if(!s.empty()){record.push_back( s );}
	}
	int num_parameters = record.size() + 10;
	execution_parameters = new char*[num_parameters];
	for(int index = 0; index < num_parameters - 1; index++){
		execution_parameters[index] = new char[PARAMETER_BUFF_SIZE];
	}
	strncpy(execution_parameters[0], gem5_executable.c_str(), PARAMETER_BUFF_SIZE);
	strncpy(execution_parameters[1], "-d", PARAMETER_BUFF_SIZE);
	//parameter 2 is the directory of the ROI execution, known only at execution
	strncpy(execution_parameters[3], gem5_config.c_str(), PARAMETER_BUFF_SIZE);
	strncpy(execution_parameters[4], "-c", PARAMETER_BUFF_SIZE);	
	strncpy(execution_parameters[5], (my_current_directory + "/pin_profile/" + my_benchmark + ".out").c_str(), PARAMETER_BUFF_SIZE);

	for(int index = 0; index < record.size(); index++){
		strncpy(execution_parameters[6+index], record[index].c_str(), PARAMETER_BUFF_SIZE);
	}
	
	execution_parameters[num_parameters - 1] = NULL;
	number_gem5_parameters = num_parameters;
} 

void free_execution_parameters(void){
	for(int index = 0; index < number_gem5_parameters - 1; index++){
		free(execution_parameters[index]);
	}
	free(execution_parameters);
}

vector<vector<string> > readCsvFileContent(const string my_filename)
{
	vector<vector<string> > data;
	        ifstream configFile;
        configFile.exceptions(ifstream::badbit);
        try
        {
            configFile.open( my_filename.c_str(),ifstream::in);
            if(configFile.is_open())
            {
                string line;                
                while (getline(configFile,line))
                {
			istringstream my_string_stream( line );
			vector <string> record;

			while (my_string_stream)
			{
				string s;
				if (!getline( my_string_stream, s, ',' )) break;
				if(!s.empty()){record.push_back( s );}
			}

			data.push_back( record );
		}
            }
	    configFile.close();        
        }
        catch (ifstream::failure e){            
            throw e;
        }
	return data;
}
void write_performance_datafile(void)
{
	ofstream results_file;
        results_file.exceptions(ofstream::badbit);
        try
        {
	    results_file.open( (my_current_directory + "/predicted_points.csv").c_str(),ofstream::out);
	    int index1, index2;
	    int index1_max = resulting_datapoints.size();
	    results_file.precision(12);
	    for(index1 = 0; index1 < index1_max; index1++){
		int index2_max = resulting_datapoints[index1].size();
		for(index2 = 0; index2 < index2_max; index2++){
			results_file << index1 << "," << index2 << "," << resulting_datapoints[index1][index2].data_value_latency << "," << resulting_datapoints[index1][index2].data_value_power << endl;
		}
	    }
	    results_file.close(); 
        }
        catch (ofstream::failure e){            
            throw e;
        }
}

void write_backannotation(void)
{
	ofstream results_file;
        results_file.exceptions(ofstream::badbit);
        try
        {
	    results_file.open( (my_current_directory + "/target_files/back_annotation_" + simulation_suffix + ".h").c_str(),ofstream::out);
	    results_file << "#ifndef BACK_ANNOTATION_H\n#define BACK_ANNOTATION_H\n\n";
            results_file << "#include \"ROI_INDEX_VALUES_" + simulation_suffix + ".h\"\n\n";
	    results_file.precision(12);

	    int index1, index2;
	    int index1_max = resulting_datapoints.size();
	    for(index1 = 0; index1 < index1_max; index1++){
			int index2_max = resulting_datapoints[index1].size();
			results_file << "static double latency_roi_" << index1 << "[" << index2_max << "] = {";
			for(index2 = 0; index2 < index2_max; index2++){
				if(index2 == index2_max - 1){
					results_file << resulting_datapoints[index1][index2].data_value_latency << "};\n\n";
				}
				else{
					results_file << resulting_datapoints[index1][index2].data_value_latency << ", ";
				}
			}
	    }

		for(index1 = 0; index1 < index1_max; index1++){
			int index2_max = resulting_datapoints[index1].size();
			results_file << "static double energy_roi_" << index1 << "[" << index2_max << "] = {";
			for(index2 = 0; index2 < index2_max; index2++){
				if(index2 == index2_max - 1){
					results_file << resulting_datapoints[index1][index2].data_value_power*resulting_datapoints[index1][index2].data_value_latency << "};\n\n";
				}
				else{
					results_file << resulting_datapoints[index1][index2].data_value_power*resulting_datapoints[index1][index2].data_value_latency << ", ";
				}
			}
	    }
	    results_file << "static double * my_latency[" << index1_max << "] = {";
	    for(index1 = 0; index1 < index1_max; index1++){
		if(index1 == index1_max - 1){
			results_file << "&latency_roi_" << index1 << "[0]};\n\n";
		}
		else{
			results_file << "&latency_roi_" << index1 << "[0], ";
		}
	    }

	    results_file << "static double * my_energy[" << index1_max << "] = {";
	    for(index1 = 0; index1 < index1_max; index1++){
		if(index1 == index1_max - 1){
			results_file << "&energy_roi_" << index1 << "[0]};\n\n";
		}
		else{
			results_file << "&energy_roi_" << index1 << "[0], ";
		}
	    }

	    results_file << "static int ROI_iteration_counts[" << index1_max << "] = {";
	    for(index1 = 0; index1 < index1_max; index1++){
		if(index1 == index1_max - 1){
			results_file << "0};\n";
		}
		else{
			results_file << "0, ";
		}
	    }
	    results_file << "static int ROI_iteration_current_idexes[" << index1_max << "] = {";
	    for(index1 = 0; index1 < index1_max; index1++){
		if(index1 == index1_max - 1){
			results_file << "0};\n";
		}
		else{
			results_file << "0, ";
		}
	    }

		results_file << "static double global_energy_value = 0;\nstatic double global_latency_value = 0;\n\ninline void update_performance(int roi_num){\n\tint current_iteration_number = ROI_iteration_counts[roi_num];\n\tint current_index = ROI_iteration_current_idexes[roi_num];\n\tif(my_index_arrays[roi_num][current_index] == current_iteration_number){\n\t\tglobal_energy_value += my_energy[roi_num][current_index];\n\t\tglobal_latency_value += my_latency[roi_num][current_index];\n\t\tif(my_index_array_sizes[roi_num] - 1 > current_index){\n\t\t\tROI_iteration_current_idexes[roi_num] += 1;\n\t\t}\n\t}\n\tROI_iteration_counts[roi_num] += 1;\n}\n\ninline double get_global_latency(void){\n\treturn global_latency_value;\n}\n\ninline double get_global_energy(void){\n\treturn global_energy_value;\n}\n\ninline void set_global_latency(double input_latency){\n\tglobal_latency_value = input_latency;\n}\n\ninline void set_global_energy(double input_energy){\n\tglobal_latency_value = global_energy_value;\n}\n\ninline void add_to_latency(double input_latency){\n\tglobal_latency_value += input_latency;\n}\n\ninline void add_to_energy(double input_energy){\n\tglobal_latency_value += global_energy_value;\n}\n";

		results_file << "#endif";
	    results_file.close(); 
        }
        catch (ofstream::failure e){            
            throw e;
        }
}

vector<vector<string> > processCsvList(vector<string> csvList)
{
    #define SINGER_CONFIG_COUNT 3 //number of comma separated data suppose to be in one line.
    #define DELIMITED_CHAR ","
    #define EMPTY_STRING ""

    vector<vector<string> > tempList;
    string configCell ="";
    for(vector<string>::iterator it = csvList.begin(); it != csvList.end(); ++it)
    {
        if(*it == EMPTY_STRING)
        {
            continue;
        }
        stringstream  configLine(*it);
        vector<string> tempDevice;
        for(int i=0; i<SINGER_CONFIG_COUNT; i++)
        {
            if(getline(configLine,configCell))
            {               
                tempDevice.push_back(configCell);
            }else
            {
            tempDevice.push_back(EMPTY_STRING);
            }
        }
        tempList.push_back(tempDevice);
    }
    return tempList;
}

void initialize_datapoints(){
	//Get power and latency for point
	string roi_instruction_breakdown_filename = my_current_directory + "/Roi_divisions.csv";
	vector<vector<string> > roi_instruction_division = readCsvFileContent(roi_instruction_breakdown_filename);

	int index1, index2;
	int index1_max, index2_max;
	int line_read_counter = 0;
	long inst_start, inst_length;
	index1_max = ROI_table.size();
	for(index1 = 0; index1<index1_max; index1++){
		index2_max = ROI_table[index1].size();
		vector<ROI_datapoint> temp_ROI;
		for(index2 = 0; index2<index2_max; index2++){
			stringstream my_ss_roi_inst_start, my_ss_roi_inst_length;
			ROI_datapoint temp_point;
			temp_point.ROI_number = index2;
			temp_point.value_set = false;
			temp_point.data_value_latency = -1;
			temp_point.data_value_power = -1;
			temp_point.next_set = -1;
			temp_point.prev_set = -1;
			my_ss_roi_inst_start << roi_instruction_division[line_read_counter][2];
			my_ss_roi_inst_start >> inst_start;
			my_ss_roi_inst_length << roi_instruction_division[line_read_counter][3];
			my_ss_roi_inst_length >> inst_length;
			temp_point.instruction_start = inst_start;
			temp_point.instruction_length = inst_length;
			temp_point.speculative_pid = 0;
			temp_point.prev_dep_met = false;
			temp_point.next_dep_met = false;
			temp_ROI.push_back(temp_point);
			line_read_counter++;
		}
		resulting_datapoints.push_back(temp_ROI);
	}
}

//This assignes an idle thread to work on a target ROI block
int get_block_assignment(int my_Rank, int current_assignment){
	pthread_mutex_lock(&core_assignment_mutex);
	pthread_mutex_lock(&convergence_list_mutex);
	int index;

	//assignment length should be equal to the number of ROI blocks
	size_t assignment_length = core_assignment_list.size();
	
	//must remove from list if I
	if(current_assignment >= 0){
		core_assignment_list[current_assignment]--;
		if(core_assignment_list[current_assignment] <0){printf("ERROR core %d assignment negative!!\n",current_assignment);}
	}

	bool core_assigned = false;

	//sanity check: ensure an unconverged ROI exists
	bool ROI_unconverged = false;
	for(index = 0; index<assignment_length; index++){
		if(convergence_list[index] == 0){
			ROI_unconverged = true;
		}
	}
	//return -1 if all ROI have already converged
	if(!ROI_unconverged){
		pthread_mutex_unlock(&convergence_list_mutex);
		pthread_mutex_unlock(&core_assignment_mutex);
		return -1;
	}
	
	//Otherwise assign thread to ROI
	//First if empty ROI block exists, assign thread to it
	for(index = 0; index<assignment_length; index++){
		//if the ROI is not converged and no other core as been assigned to ROI
		if(convergence_list[index] == 0 && core_assignment_list[index] < 1){
			core_assignment_list[index] += 1;
			pthread_mutex_unlock(&convergence_list_mutex);
			pthread_mutex_unlock(&core_assignment_mutex);
			return index;
		}
	}
	
	//If we have reached this point then all ROI are assigned at least 1 thread
	//Instead find ROI with min assigned cores
	
	int min_ROI = 0;
	//This may have converged, find first instance of non_converged
	while(convergence_list[min_ROI] != 0 && min_ROI<assignment_length){
		min_ROI +=1;
	}

	//this should never happen since the variable is locked, but incase all converged, don't continue, assign -1
	if(min_ROI >= assignment_length){
		pthread_mutex_unlock(&convergence_list_mutex);
		pthread_mutex_unlock(&core_assignment_mutex);
		return -1;
	}

	int min_cores = core_assignment_list[min_ROI];
	
	//Search for the min ROI and assign thread to it
	for(index=min_ROI; index<assignment_length; index++){
		if(core_assignment_list[index] < min_cores && convergence_list[index] == 0){
			min_ROI = index;
			min_cores = core_assignment_list[index];
		}
	}
	

	core_assignment_list[min_ROI] += 1;
	pthread_mutex_unlock(&convergence_list_mutex);
	pthread_mutex_unlock(&core_assignment_mutex);
	return min_ROI;
}

void add_to_ROI_queue(int ROI_number, int division_number){
	pthread_mutex_lock(&ROI_queue_mutex_list[ROI_number]);
	ROI_dependency_queues[ROI_number].push_back(division_number);
	pthread_mutex_unlock(&ROI_queue_mutex_list[ROI_number]);
}

int get_division_assignment(int assigned_ROI){
	
	//return -1 if ROI already converged before enterance
	pthread_mutex_lock(&convergence_list_mutex);
	if(convergence_list[assigned_ROI]==1){
		pthread_mutex_unlock(&convergence_list_mutex);
		return -1;
	};
	pthread_mutex_unlock(&convergence_list_mutex);

	//Only one thread can search for an assignment on a given ROI at a time
	pthread_mutex_lock(&division_assignment_mutex_list[assigned_ROI]);

	pthread_mutex_lock(&convergence_list_mutex);
	//return -1 if ROI converged while waiting
	if(convergence_list[assigned_ROI]==1){
		pthread_mutex_unlock(&convergence_list_mutex);
		pthread_mutex_unlock(&division_assignment_mutex_list[assigned_ROI]);
		return -1;
	};
	pthread_mutex_unlock(&convergence_list_mutex);

	int index2 = previous_last_values[assigned_ROI];
	int index2_max = resulting_datapoints[assigned_ROI].size();
	int first_value = -1;
	int last_value = index2_max;
	bool gap_found = false;
	int index_search_count = 0;

	//Searching for a gap in the ROI so we can take the midpoint
	while(index_search_count<=index2_max && last_value==index2_max){
		bool temp_set = resulting_datapoints[assigned_ROI][index2].value_set;
		//printf("index: %d,%d found = %d\n", assigned_ROI,index2,temp_set);
		if(temp_set && !gap_found){
			first_value = index2;
		}
		else if(!temp_set && first_value>=0){
			gap_found = true;
		}
		else if(temp_set && gap_found && first_value != index2){
			last_value = index2;
			previous_last_values[assigned_ROI] = index2;
		}
		index2++;
		index_search_count++;
		if(index2>=index2_max){
			index2 = 0;
			if(index_search_count<index2_max && last_value == index2_max){
				gap_found = false;
			}
		}
	}
	//special case: when index2 0 has not be evaluated
	if(first_value<0){
		//printf("first_value: %d\n",first_value);
		resulting_datapoints[assigned_ROI][0].value_set = true;
		add_to_ROI_queue(assigned_ROI,0);
		pthread_mutex_unlock(&division_assignment_mutex_list[assigned_ROI]);
		return 0;
		
	}

	//special case: when index2 max has not be evaluated
	else if(last_value==index2_max && !resulting_datapoints[assigned_ROI][index2_max-1].value_set){
		//printf("last_value: %d\n",last_value);
		resulting_datapoints[assigned_ROI][index2_max-1].value_set = true;
		resulting_datapoints[assigned_ROI][index2_max-1].prev_set = 0;
		add_to_ROI_queue(assigned_ROI,index2_max-1);
		pthread_mutex_unlock(&division_assignment_mutex_list[assigned_ROI]);
		return index2_max-1;
	}

	//case where a gap has been found
	else if(gap_found){
		int midpoint = (last_value + first_value)/2;
		resulting_datapoints[assigned_ROI][midpoint].value_set = true;
		resulting_datapoints[assigned_ROI][midpoint].prev_set = first_value;
		resulting_datapoints[assigned_ROI][midpoint].next_set = last_value;
		add_to_ROI_queue(assigned_ROI,midpoint);
		pthread_mutex_unlock(&division_assignment_mutex_list[assigned_ROI]);
		return midpoint;
	}

	//If we have reached this point, then table is mismarked.  It should be converged
	printf("Note: %d is now to be marked as converged\n", assigned_ROI);

	pthread_mutex_lock(&convergence_list_mutex);
	convergence_list[assigned_ROI] = 1;
	pthread_mutex_unlock(&convergence_list_mutex);

	pthread_mutex_unlock(&division_assignment_mutex_list[assigned_ROI]);
	return -1;
}
int execute_assignment(int my_ROI_block, int my_division){
	//launch simulation
	int status;
	int my_PID = fork();
	if(my_PID == 0){

		stringstream roi_start, roi_range;
		roi_start << resulting_datapoints[my_ROI_block][my_division].instruction_start;
		roi_range << resulting_datapoints[my_ROI_block][my_division].instruction_length;

		//Since execution is parallel, avoid global modification. Copy pointer array and modify pointers locally
		char **my_local_arguments = new char*[number_gem5_parameters];
		for(int ptr_index = 0; ptr_index < number_gem5_parameters; ptr_index++){
			my_local_arguments[ptr_index] = execution_parameters[ptr_index];
		}
		
		char param_buffer0[PARAMETER_BUFF_SIZE];
		strncpy(param_buffer0, ROI_table[my_ROI_block][my_division].c_str(), PARAMETER_BUFF_SIZE);
		char param_buffer1[PARAMETER_BUFF_SIZE];
		strncpy(param_buffer1, ("--warmup=" + warmup_instruction_count).c_str(), PARAMETER_BUFF_SIZE);
		char param_buffer2[PARAMETER_BUFF_SIZE];
		strncpy(param_buffer2, ("--ROI_start=" + roi_start.str()).c_str(), PARAMETER_BUFF_SIZE);
		char param_buffer3[PARAMETER_BUFF_SIZE];
		strncpy(param_buffer3, ("--ROI_range=" + roi_range.str()).c_str(), PARAMETER_BUFF_SIZE);		
		
		my_local_arguments[2] = param_buffer0;
		my_local_arguments[number_gem5_parameters-4] = param_buffer1;
		my_local_arguments[number_gem5_parameters-3] = param_buffer2;
		my_local_arguments[number_gem5_parameters-2] = param_buffer3;

		execv(my_local_arguments[0], my_local_arguments);
		exit(3);
	}
	else{
		//cout << "Parent Process reporting in with child process " << my_PID << "\n";
		//fflush(stdout);
		resulting_datapoints[my_ROI_block][my_division].speculative_pid = my_PID;
		waitpid(my_PID, &status, 0);
	}
	resulting_datapoints[my_ROI_block][my_division].speculative_pid = 0;
	//cout << "Passed Process reporting in\n";
	//fflush(stdout);
	//Determine if process was killed by external thread due to convergence
	if(WIFSIGNALED(status)){
		return 0;
	}

	//Format gem5 output for input into McPAT
	system(("perl " + my_current_directory + "/remove_nan.pl " + ROI_table[my_ROI_block][my_division] + "/stats.txt").c_str());

	pthread_mutex_lock (&mcpat_protection);
	system(("perl " + my_current_directory + "/GEM5ToMcPAT.py " + ROI_table[my_ROI_block][my_division] + "/stats.txt " + ROI_table[my_ROI_block][my_division] + "/config.json " + my_current_directory + "/" + McPAT_template_file).c_str());
	system(("cp " + my_current_directory + "/mcpat-out.xml " + ROI_table[my_ROI_block][my_division] + "/mcpat-out.xml").c_str());
	pthread_mutex_unlock (&mcpat_protection);

	//Call McPAT - must be serialized -- possibly not with gem5 version
	//pthread_mutex_lock (&mcpat_protection);
	system((my_McPAT_directory + "/mcpat -infile " + ROI_table[my_ROI_block][my_division] + "/mcpat-out.xml > " + ROI_table[my_ROI_block][my_division] + "/power.txt").c_str());
	//pthread_mutex_unlock (&mcpat_protection);

	//parse output files
	system(("perl " + my_current_directory + "/gather_results.pl " + ROI_table[my_ROI_block][my_division]).c_str());
	//Execution successful, return 1
	return 1;
}

/*
	check_dependency returns true if all dependencies have been satisfied
	returns false if all dependencies not satisfied
*/
bool check_dependency(int my_ROI_block, int my_division){
	return ROI_dependency_queues[my_ROI_block].front() == my_division || (resulting_datapoints[my_ROI_block][my_division].prev_dep_met == true && resulting_datapoints[my_ROI_block][my_division].next_dep_met == true);
}

void remove_self_from_dependency(int my_ROI_block, int my_division){
	pthread_mutex_lock(&ROI_queue_mutex_list[my_ROI_block]);
	int current_size = ROI_dependency_queues[my_ROI_block].size();
	int index;
	//Update dependency lists
	for(index=0; index<current_size; index++){
		if(resulting_datapoints[my_ROI_block][index].prev_set == my_division){
			resulting_datapoints[my_ROI_block][index].prev_dep_met = true;
		}
		else if(resulting_datapoints[my_ROI_block][index].next_set == my_division){
			resulting_datapoints[my_ROI_block][index].next_dep_met = true;
		}
	}
	for(index=0; index<current_size; index++){
		if(ROI_dependency_queues[my_ROI_block][index] == my_division){
			ROI_dependency_queues[my_ROI_block].erase(ROI_dependency_queues[my_ROI_block].begin()+index);
			pthread_mutex_unlock(&ROI_queue_mutex_list[my_ROI_block]);
			return;
		}
	}
	pthread_mutex_unlock(&ROI_queue_mutex_list[my_ROI_block]);
	return;
}

void check_convergence(int my_ROI_block, int my_division){
	double latency, power;

	//Get power and latency for point
	string my_filename_perforance = ROI_table[my_ROI_block][my_division] + "/performance_results.csv";
	//cout << my_filename_perforance << "\n";
	vector<vector<string> > performance_strings = readCsvFileContent(my_filename_perforance);

	stringstream my_string_stream_latency, my_string_stream_power;
	my_string_stream_latency << performance_strings[0][0];
	my_string_stream_latency >> latency;
	my_string_stream_power << performance_strings[0][1];
	my_string_stream_power >> power;

	//Must wait until thread is head of dependency queue.  Currently busy waiting...in future, make conditional wait.
	while(!check_dependency(my_ROI_block,my_division)){sleep(1);}
	//Now at the head of list, we can check for convergence
	double old_power = resulting_datapoints[my_ROI_block][my_division].data_value_power;
	double old_latency = resulting_datapoints[my_ROI_block][my_division].data_value_latency;
	//cout << "Comparing latencies: " << old_latency <<", " << latency << " at " << my_ROI_block << ", " << my_division;
	//fflush(stdout);
	bool convergence_reached = (abs(power - old_power)/power < POWER_TOLERANCE) && (abs(latency - old_latency)/latency < LATENCY_TOLERANCE);

	//Updating model
	//Must ensure no other thread is getting assignment, as values can be changed
	pthread_mutex_lock(&division_assignment_mutex_list[my_ROI_block]);
	resulting_datapoints[my_ROI_block][my_division].data_value_latency = latency;
	resulting_datapoints[my_ROI_block][my_division].data_value_power = power;
	resulting_datapoints[my_ROI_block][my_division].value_set = true;
	if(convergence_reached){
		//printf("Convergence reached: %d,%d\n",my_ROI_block,my_division);
		//Assume intermediate values are also correct
		//calculate using linear approximation
		int index3;
		int previous_point = resulting_datapoints[my_ROI_block][my_division].prev_set;
		if(previous_point >= 0){
			double slope_power = (power - resulting_datapoints[my_ROI_block][previous_point].data_value_power)/(my_division-previous_point);
			double intercept_power = power - slope_power*my_division;
			double normalize_slope_latency = (latency*1.0/resulting_datapoints[my_ROI_block][my_division].instruction_length - resulting_datapoints[my_ROI_block][previous_point].data_value_latency*1.0/resulting_datapoints[my_ROI_block][previous_point].instruction_length)/(my_division-previous_point);
			double normalize_intercept_latency = latency*1.0/resulting_datapoints[my_ROI_block][my_division].instruction_length - normalize_slope_latency*my_division;
			for(index3 = previous_point + 1; index3 < my_division; index3++){
				if(resulting_datapoints[my_ROI_block][index3].speculative_pid != 0){
					kill(resulting_datapoints[my_ROI_block][index3].speculative_pid, SIGKILL);
					resulting_datapoints[my_ROI_block][index3].speculative_pid = 0;
				}
				resulting_datapoints[my_ROI_block][index3].data_value_power = slope_power*index3 + intercept_power;
				resulting_datapoints[my_ROI_block][index3].data_value_latency = (normalize_slope_latency*index3 + normalize_intercept_latency)*resulting_datapoints[my_ROI_block][index3].instruction_length;
				resulting_datapoints[my_ROI_block][index3].value_set = true;
			}
		}

		int next_point = resulting_datapoints[my_ROI_block][my_division].next_set;
		if(next_point >= 0){
			double slope_power = (power - resulting_datapoints[my_ROI_block][next_point].data_value_power)/(my_division-next_point);
			double intercept_power = power - slope_power*my_division;
			double normalize_slope_latency = (latency*1.0/resulting_datapoints[my_ROI_block][my_division].instruction_length - resulting_datapoints[my_ROI_block][next_point].data_value_latency*1.0/resulting_datapoints[my_ROI_block][next_point].instruction_length)/(my_division-next_point);
			double normalize_intercept_latency = latency*1.0/resulting_datapoints[my_ROI_block][my_division].instruction_length - normalize_slope_latency*my_division;
			for(index3 = my_division + 1; index3 < next_point; index3++){
				if(resulting_datapoints[my_ROI_block][index3].speculative_pid != 0){
					kill(resulting_datapoints[my_ROI_block][index3].speculative_pid, SIGKILL);
					resulting_datapoints[my_ROI_block][index3].speculative_pid = 0;
				}
				resulting_datapoints[my_ROI_block][index3].data_value_power = slope_power*index3 + intercept_power;
				resulting_datapoints[my_ROI_block][index3].data_value_latency = (normalize_slope_latency*index3 + normalize_intercept_latency)*resulting_datapoints[my_ROI_block][index3].instruction_length;
				resulting_datapoints[my_ROI_block][index3].value_set = true;
			}
		}
	}
	else{
		//calculate using linear approximation
		int index3;
		int previous_point = resulting_datapoints[my_ROI_block][my_division].prev_set;
		if(previous_point >= 0){
			double slope_power = (power - resulting_datapoints[my_ROI_block][previous_point].data_value_power)/(my_division-previous_point);
			double intercept_power = power - slope_power*my_division;
			double normalize_slope_latency = (latency*1.0/resulting_datapoints[my_ROI_block][my_division].instruction_length - resulting_datapoints[my_ROI_block][previous_point].data_value_latency*1.0/resulting_datapoints[my_ROI_block][previous_point].instruction_length)/(my_division-previous_point);
			double normalize_intercept_latency = latency*1.0/resulting_datapoints[my_ROI_block][my_division].instruction_length - normalize_slope_latency*my_division;
			for(index3 = previous_point + 1; index3 < my_division; index3++){
				resulting_datapoints[my_ROI_block][index3].data_value_power = slope_power*index3 + intercept_power;
				resulting_datapoints[my_ROI_block][index3].data_value_latency = (normalize_slope_latency*index3 + normalize_intercept_latency)*resulting_datapoints[my_ROI_block][index3].instruction_length;
			}
		}

		int next_point = resulting_datapoints[my_ROI_block][my_division].next_set;
		if(next_point >= 0){
			double slope_power = (power - resulting_datapoints[my_ROI_block][next_point].data_value_power)/(my_division-next_point);
			double intercept_power = power - slope_power*my_division;
			double normalize_slope_latency = (latency*1.0/resulting_datapoints[my_ROI_block][my_division].instruction_length - resulting_datapoints[my_ROI_block][next_point].data_value_latency*1.0/resulting_datapoints[my_ROI_block][next_point].instruction_length)/(my_division-next_point);
			double normalize_intercept_latency = latency*1.0/resulting_datapoints[my_ROI_block][my_division].instruction_length - normalize_slope_latency*my_division;
			for(index3 = my_division + 1; index3 < next_point; index3++){
				resulting_datapoints[my_ROI_block][index3].data_value_power = slope_power*index3 + intercept_power;
				resulting_datapoints[my_ROI_block][index3].data_value_latency = (normalize_slope_latency*index3 + normalize_intercept_latency)*resulting_datapoints[my_ROI_block][index3].instruction_length;
			}
		}
	}

	pthread_mutex_unlock(&division_assignment_mutex_list[my_ROI_block]);

	//Convergence complete, release queue to next dependency
	remove_self_from_dependency(my_ROI_block, my_division);
}

void* run_simulations (void *Rank){
	int *my_rank_ptr = (int *) Rank;
	int my_rank = *my_rank_ptr;
	int current_ROI_assignment = get_block_assignment(my_rank, -1);
	//printf("thread %d, assigned to ROI: %d\n",my_rank, current_ROI_assignment);
	//While ROI blocks remain that are unconverged
	while(current_ROI_assignment >=0){
		int current_division_assignment = get_division_assignment(current_ROI_assignment);
		//While current ROI block is unconverged
		while(current_division_assignment >=0){
			//execute current assignment, if successful, check convergence
			if(execute_assignment(current_ROI_assignment, current_division_assignment)){
				//Read resulting data and check model for convergence
				check_convergence(current_ROI_assignment, current_division_assignment);
			}
			else{
			//execution was terminated prematurely, but we still need to manage dependency que
				remove_self_from_dependency(current_ROI_assignment, current_division_assignment);
			}
			//Get next division assignment
			current_division_assignment = get_division_assignment(current_ROI_assignment);
		}
		//Get next ROI block assignment
		current_ROI_assignment = get_block_assignment(my_rank, current_ROI_assignment);
	}
	//printf("thread %d, reporting in and signing out\n",my_rank);
}


struct timeval tv;
double get_clock() {
  struct timeval tv; int ok;
  ok = gettimeofday(&tv, NULL);
  if (ok<0) { printf("gettimeofday error");  }
  return (tv.tv_sec * 1.0 + tv.tv_usec * 1.0E-6);
}

int main(int argc, char *argv[]) {
	int i,j,k,ii,jj,kk;
	double t1,t2;
	int thread_number;
	int pthread_n;
	int *thread_ranks;
	pthread_t *my_thread_handles;
	string directory_filename;
	if (argc != ARGS) {
		fprintf(stderr,"Wrong # of arguments.\nUsage: %s T\n",
					argv[0]);
		return -1;
	}
	pthread_n = atoi(argv[1]);
	my_current_directory = argv[2];
	my_McPAT_directory = argv[3];
	my_benchmark = argv[4];
	warmup_instruction_count = argv[5];
	LATENCY_TOLERANCE = atof(argv[6]);
	POWER_TOLERANCE = atof(argv[7]);
	string gem5_executable = argv[8];
	string gem5_config = argv[9];
	string gem5_executable_parameters = argv[10];
	McPAT_template_file = argv[11];
	simulation_suffix = argv[12];

	extract_gem5_parameters_from_string(gem5_executable, gem5_config, gem5_executable_parameters);
	directory_filename = my_current_directory + "/my_directories.csv";

	thread_ranks = (int *)malloc(pthread_n * sizeof(int));
	ROI_table = readCsvFileContent(directory_filename);
	initialize_datapoints();
	//Initialize all mutex structures required for correct execution
	pthread_mutex_init(&mcpat_protection, NULL);
	pthread_mutex_init(&core_assignment_mutex, NULL);
	pthread_mutex_init(&convergence_list_mutex, NULL);
	int number_of_ROI = ROI_table.size();

	//initialize conditions and mutex
	division_assignment_mutex_list = (pthread_mutex_t*) malloc(number_of_ROI * sizeof(pthread_mutex_t));
	ROI_queue_mutex_list = (pthread_mutex_t*) malloc(number_of_ROI * sizeof(pthread_mutex_t));
	ROI_queue_condition_list = (pthread_cond_t*) malloc(number_of_ROI * sizeof(pthread_cond_t));

	int index;
	for(index = 0; index<number_of_ROI; index++){
		pthread_mutex_init(&division_assignment_mutex_list[index], NULL);
		pthread_mutex_init(&ROI_queue_mutex_list[index], NULL);
		pthread_cond_init(&ROI_queue_condition_list[index], NULL);
	}

	//Initializing core_assignment_list
	for(index = 0; index<number_of_ROI; index++){
		core_assignment_list.push_back(0);
	}

	//Initializing convergence_list
	for(index = 0; index<number_of_ROI; index++){
		convergence_list.push_back(0);
	}

	//Initializing dependency queues
	for(index = 0; index<number_of_ROI; index++){
		std::vector<int> my_temp_list;
		ROI_dependency_queues.push_back(my_temp_list);
	}

	//Initialize array of last values used in upper bound of binary search
	previous_last_values = (int *)malloc(number_of_ROI * sizeof(int));
	for(index = 0; index<number_of_ROI; index++){
		previous_last_values[index]=0;
	}

	//Initialize Thread Vector
	my_thread_handles = (pthread_t*) malloc(pthread_n* sizeof(pthread_t));
	t1 = get_clock();

	//BEGIN MAIN ROUTINE
	for(thread_number=0;thread_number<pthread_n;thread_number++) {
		thread_ranks[thread_number] = thread_number;
		pthread_create(&my_thread_handles[thread_number], NULL, run_simulations, (void *) &thread_ranks[thread_number]);
	}
	for(thread_number=0;thread_number<pthread_n;thread_number++) {
		pthread_join(my_thread_handles[thread_number], NULL);
	}
	// END MAIN ROUTINE


	t2 = get_clock();
	write_performance_datafile();
	write_backannotation();
	printf("Time: %lf\n",(t2-t1));
	fflush(stdout);
	pthread_mutex_destroy(&mcpat_protection);
	pthread_mutex_destroy(&core_assignment_mutex);
	pthread_mutex_destroy(&convergence_list_mutex);
	for(index = 0; index<number_of_ROI; index++){
		pthread_mutex_destroy(&division_assignment_mutex_list[index]);
		pthread_mutex_destroy(&ROI_queue_mutex_list[index]);
	}

	free_execution_parameters();
	free(division_assignment_mutex_list);
	free(ROI_queue_mutex_list);
	free(my_thread_handles);
	return 0;
}
