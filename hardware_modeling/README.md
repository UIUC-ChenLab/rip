### Publication
 A Polyhedral-based SystemC Modeling and Generation Framework for Effective Low-power Design Space Exploration. Wei Zuo, Warren Kemmerer, Jong Bin Lim, Louis-Noël Pouchet, Andrey Ayupov, Taemin Kim, Kyungtae Han, and Deming Chen. (ICCAD '15). [link](http://dl.acm.org/citation.cfm?id=2840870) 

### Prerequisit tool
1. [PolyOpt-0.3.0](http://web.cs.ucla.edu/~pouchet/software/polyopthls/download/polyopt-0.3.0.tar.gz)
    Just download, do not install yet.

    It includes the polyhedral transformation tool targeting HLS and hardware generation. PolyOpt requires the installation of ROSE and BOOST. A simpler way to install these two tools is to install [CDSC Mapper](http://cadlab.cs.ucla.edu/mapper/).


### Installation the hardware modeling tool

After dowloading (Not installing) PolyOpt, replace the source files in polyopt folder with provided file, and recompile it.
    
        cd <polyopt-0.3.0 dir>
        rm -r polyopt
        cp -r polyopt_replace/ ./polyopt
        cd ../
        ./install.sh

### Run a benchmark
cd example (When run another benchmark, all the scripts need to copy the benchmark folder)

1. FIll in the power.h. This file stores the power characterizaiton data. 
There are three global variables.
	m_dyn_read: memory read power
	m_dyn_write: memory write power
	acci_pwr: the power of the ith accelerator in your design

   	m_dyn_read and m_dyn_write are map data structures, using the memory size as the key, and an array of nine elements as the value. Where each element in the array represents a power value of the corresponding switching activity. For example, the first element is the power when switching activity is one. 
	
	acc_pwr is one dimension array of nine elements, where each element is corresponding to the switching activity.
	
2. Fill in the latencies.h. This is the file which stores the latency characterization data.

	* acci_LATENCY : the latency of one iteration of the i-th accelerator.
	* acci_II: the pipeline initialization interval of the i-th accelerator.
	* READ_LATECY: the memory read latency
	* WRITE_LATENCY: the memory write latency
	
3. Generate input sample points:
    python ./generate_input_sample_space.py [options][value]
    
    This file generates the input sample points for SystemC simulation, write it to a input_points.csv
    
    Options:

        --iterNum: the number of the largest loop iteration in your design. 
        --iterBoundary: a list of the max number of each iterator. The length of the list should equal to iterNum. For example:
        
        for(int i = 0; i < N; i++)
				for(int j=0; j<N; j++)
					stmt1;

		then iterNum = 2, iterBoundary=[N, N];
		
	--maxTileSizePerLoop: the max tile size the user would like to explore for each iteration. This is also a list.
	
		If maxTileSizePerLoop = 128, then the script won’t generate tile size bigger then 128.
		
	--minTileSizePerLoop: the min tile size the user would like to explore for each iteration
	
	--exponent_tile: the exponent of tile size increase for each iteration level
	
		If exponent_tile =2. Then if the the current tile size is n, then next tile size generated would be n^2.
		
	--exponent_unroll: The exponent of unroll factor increase for each iteration level
	
	--functionName: the name of the function the user is exploring.

4. Generate SystemC:

    (1) One run (with one tile size and one unrolling factor)
        
        (a) Fill in the file tile.sizes: which stores the tile size for each iteration (refer to PolyOpt manual)
        
        (b) Fill in the file unroll_factor: stores the copy of replications for each loop level.
        
        (c): Run the following command:

	       PolyRose   [options] [values] //comments (should be removed when run the command)
	
	   --polyopt-pluto-tile   				//refer to PolyOpt manual
           --polyopt-pluto-fuse-nofuse 			//refer to PolyOpt manual
           --polyopt-HLS 				//refer to PolyOpt manual
           --systemc-target-func=functionName 	//the top-level module in your design
	   --systemc-depth=N 				//the depth from top you want to explore parallelsim. If N = 0, then no parallelism is explored. 
	   --systemc-preprocess 				//to indicate this is a preprocess pass, it will generate some information for later runs. Only need to run once for one design.
	   --systemc-HLS loop1.c			//to generate the HLS version of the systemC code. (Currently this flag is still under development).
	       
	       InputFile.c	

    This generates the output file rose_InputFile.c
    
         (d): Compile the c code.
        
      ```
      g++ -O3 -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux64 -lsystemc -lm -fno-deduce-init-list rose_InputFile.c  -std=c++0x -o rose_InputFile.out
      ```
	 (e): run the executable: ./rose_InputFile.out.
	   

    (2) The script to run multiple runs. The following scripts read the input data from input_data.csv and generate the result data in data_points.csv.
    
	python run.py [options][values]
	
		--iterNum: The number of max iteration levels of the loops. (Similar to the same option in generate_input_sample_space.py )
		--startLineNum : The line number in input_data.csv the user wants to start running.
		--endLineNum: The line number in input_data.csv the user wants to end running.
		--functionName: The name of the target function (similar to the same option in generate_input_sample_space.py)
		
 5. Run matlab script to generate the design space and Pareto points.
    
        This script does two things:
            1. Extrapolate the entire design space using triangulation. Implemented by the matlab function "griddatan". The stride of the space is controlled by spacing vector
    	2. Generate the pareto point considering power and latency

    To run the script correctly, it requires the other matlab files in the same folder, so add the entire folder to the matlab working path. 
    
    The following are the detailed steps.
    
        (1) python ./generate_theory_sample_space.py [options][values]. This generates the points of the entire design space. 
        
                --iterNum: The number of max iteration levels of the loops. (Similar to the same option in generate_input_sample_space.py )
                --iterBoundary: a list of the max number of each iterator. The length of the list should equal to iterNum. For example:
	        --maxTileSizePerLoop: the max tile size the user would like to explore for each iteration. This is also a list.	
	        --minTileSizePerLoop: the min tile size the user would like to explore for each iteration
		        
		(2) customize training.m. The only parameter need to tune is the "degenerate_level" (refer to the comment in the script).
		
		(3) run the matlab scripts. ./training.m.
		
		  It generates the thickened pareto points and write it to thicked_points.csv. Which will be used for the second round SystemC simulation.
		  It also generates the "thicked_points_full.csv" which contains the modeled latency and power value, it is used to compare the accuracy of the estimated model.
		  
  6. Run the SystemC on the modeled pareto points to get the power/latency annotation.
    This step is similar to step 4, except the input file is "thicked_points.csv". To use the script to run simulation of different points, the following command :
   python run.py[options][values]
   
        --iterNum: The number of max iteration levels of the loops. (Similar to the same option in generate_input_sample_space.py )
        --startLineNum : The line number in input_data.csv the user wants to start running.
        --endLineNum: The line number in input_data.csv the user wants to end running.
        --functionName: The name of the target function (similar to the same option in generate_input_sample_space.py)
        --inputIsParetoCurve=1 : Indicate the input is modeled Pareto curve.
		  
		
		        
