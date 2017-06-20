/*BEGIN_LEGAL 
Intel Open Source License 

Copyright (c) 2002-2015 Intel Corporation. All rights reserved.
 
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are
met:

Redistributions of source code must retain the above copyright notice,
this list of conditions and the following disclaimer.  Redistributions
in binary form must reproduce the above copyright notice, this list of
conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.  Neither the name of
the Intel Corporation nor the names of its contributors may be used to
endorse or promote products derived from this software without
specific prior written permission.
 
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE INTEL OR
ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
END_LEGAL */
/*
 *  This file contains a Pintool for sampling the IPs of instruction executed.
 *  It serves as an example of a more efficient way to write analysis routines
 *  that include conditional tests.
 *  Currently, it works on IA-32 and Intel(R) 64 architectures.
 */

#include <stdio.h>
#include <stdlib.h>
#include "pin.H"
#include "roi_addresses.h"
#include <vector>

FILE * trace;

long icount = 0;
int prev_index = -1;

vector< vector<long> > roi_instruction_counts(INSTRUCTION_ARRAY_SIZE,vector<long>());
vector<int> index_expired(INSTRUCTION_ARRAY_SIZE,0);


/*
 *  IP-sampling could be done in a single analysis routine like:
 *
 *        VOID IpSample(VOID *ip)
 *        {
 *            --icount;
 *            if (icount == 0)
 *            {
 *               fprintf(trace, "%p\n", ip);
 *               icount = N + rand() % M;
 *            }
 *        }
 *
 *  However, we break IpSample() into two analysis routines,
 *  CountDown() and PrintIp(), to facilitate Pin inlining CountDown()
 *  (which is the much more frequently executed one than PrintIp()).
 */

VOID CountInstructions(VOID *ip)
{
    ++icount;
    int index;
    for(index = 0; index < INSTRUCTION_ARRAY_SIZE; index++){
	if(my_instruction_array[index] == ip){
		if(index_expired[index] == 0){
			if(prev_index != -1){
				index_expired[prev_index] = 2;
			}
			prev_index = index;
			index_expired[index] = 1;
		}
		if(prev_index == index && index_expired[index] == 1){
			roi_instruction_counts[index].push_back(icount);
		}
		else{
			index_expired[prev_index] = 2;
			prev_index = index;
		}
		return;
	}
    }
    return;
}


// The IP of the current instruction will be printed and
// the icount will be reset to a random number between N and N+M.
VOID PrintIp(VOID *ip)
{
    fprintf(trace, "%ld, ", icount);
}


// Pin calls this function every time a new instruction is encountered
VOID Instruction(INS ins, VOID *v)
{
    // CountDown() is called for every instruction executed
    INS_InsertCall(ins, IPOINT_BEFORE, (AFUNPTR)CountInstructions, IARG_INST_PTR, IARG_END);
    
}

// This function is called when the application exits
VOID Fini(INT32 code, VOID *v)
{
    trace = fopen("roi_sampling.pm", "w");
    fprintf(trace, "package generate_roi_structure;\n\n");
    fprintf(trace, "my @profiled_instruction_counts = (");
    int index = 0;
    for(index = 0; index < INSTRUCTION_ARRAY_SIZE; index++){
	int vector_index = 0;
	int my_vector_size = roi_instruction_counts[index].size();
	if(my_vector_size > 0){
		if(index>0){
			fprintf(trace, ", ");
		}
		for(vector_index = 0; vector_index < my_vector_size - 1; vector_index++){
			fprintf(trace, "%ld, ", roi_instruction_counts[index].at(vector_index));
		}
		fprintf(trace, "%ld", roi_instruction_counts[index].at(my_vector_size-1));
	}
    }
    fprintf(trace, ");\n");
    fprintf(trace, "my @roi_block_starts = (");
    int block_count = 0;
    for(index = 0; index < INSTRUCTION_ARRAY_SIZE; index++){
	if(index>0){
		fprintf(trace, ", ");
	}
	fprintf(trace, "%d", block_count);
	block_count += roi_instruction_counts[index].size();
    }
    fprintf(trace, ");\n");
    fprintf(trace, "my @roi_block_stops = (");
    block_count = 0;
    for(index = 0; index < INSTRUCTION_ARRAY_SIZE; index++){
	if(index>0){
		fprintf(trace, ", ");
	}
	block_count += roi_instruction_counts[index].size();
	fprintf(trace, "%d", block_count-1);
    }
    fprintf(trace, ");\n");

    fclose(trace);
}

/* ===================================================================== */
/* Print Help Message                                                    */
/* ===================================================================== */

INT32 Usage()
{
    PIN_ERROR( "This Pintool samples the IPs of instruction executed\n"
                + KNOB_BASE::StringKnobSummary() + "\n");
    return -1;
}

/* ===================================================================== */
/* Main                                                                  */
/* ===================================================================== */

int main(int argc, char * argv[])
{
    //std::fill(roi_instruction_counts.begin(), roi_instruction_counts.end(), std::vector<long>)
//trace = fopen("roi_sampling.pm", "w");
    // Initialize pin
    if (PIN_Init(argc, argv)) return Usage();

    // Register Instruction to be called to instrument instructions
    INS_AddInstrumentFunction(Instruction, 0);

    // Register Fini to be called when the application exits
    PIN_AddFiniFunction(Fini, 0);
    
    // Start the program, never returns
    PIN_StartProgram();
    
    return 0;
}
