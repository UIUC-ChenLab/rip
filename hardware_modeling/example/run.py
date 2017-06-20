## this script genereates the sampling points to run polyopt.
## There are following input:
##	1. iterNum: the max number of loop levels in each loop. For example, if there are two loops in the application and one loop contains 3 levels and the other contains 2 levels, then iterNum = 3.
##	2. maxTileSizePerLoop: This is a list, with the dimension of iterNum, which assigns the maximum tile size for each loop level
##	3. minTileSizePerLoop: Similar to maxTileSizePerLoop, assigns the minimum tile size for each loop level
##	4. functionName: the kernel function name

## Given the inputs, there are following parameters in the design space to sample
##	1. tile size: For each loop level, from the minimum tile size to the max tile size, we sample the tile size in the order of 2 manner
##	2. unroll degree: For each tile size, we sample the unroll factor in the order of 2 manner
##	Note that unroll depth is explored implicitly when the unroll degree of that dimension is 1.


from optparse import OptionParser
import os
import os.path
import copy
import csv

options = OptionParser();
options.add_option("--iterNum", action = "store", type = "int", dest = "loopNum"); #number of loop levels
options.add_option("--startLineNum",action = "store", type = "int", dest = "startLineNum"); 
options.add_option("--endLineNum",action = "store", type = "int", dest = "endLineNum"); 
options.add_option("--functionName", action = "store", type = "string", dest = "funcName");
options.add_option("--deleteResultFile", action = "store", type = "int", dest = "deleteResultFile");
options.add_option("--inputIsParetoCurve", action = 'store', type = 'int', dest = "inputIsParetoCurve");

#parsing the input flags
(opts, args) = options.parse_args();
loopNum = opts.loopNum;
startLineNum = opts.startLineNum;
endLineNum = opts.endLineNum;
funcName = opts.funcName;
deleteResultFile = (opts.deleteResultFile == 1); 
inputIsParetoCurve = (opts.inputIsParetoCurve == 1);

if(inputIsParetoCurve):
    resultFile = "./pareto_data_points.csv";
    inputFile = "./thicked_points.csv"
else:
    resultFile = './data_points.csv';
    inputFile = "./input_points.csv";
    
print "Input File is : ", inputFile;
print "Result File is : ", resultFile;
if(deleteResultFile):
    var = raw_input("Are you sure to delete the result file ??: yes/no: ");
    if(var == 'yes'):
        if(os.path.exists(resultFile)):
            cmd = 'rm ' + resultFile;
            print cmd
            os.system(cmd);

with open(inputFile, 'r') as f:
    csvread = csv.reader(f);
    for i, row in enumerate(csvread):
        if i<startLineNum or i>endLineNum:
            continue;
        assert(len(row) == 2*loopNum);
        with open("tile.sizes", 'w') as f1, open("unroll_factor", 'w') as f2:
            for j, item in enumerate(row):
                if(j < loopNum):
                    f1.write("%s " %item);
                else:
                    f2.write("%s " %item);
        uv = map(int, row[loopNum:]);
        uv_copy = [2];
        uv_copy.extend(uv);
        #print "uv_copy is ", uv_copy
        depth = next(x[0] for x in reversed(list(enumerate(uv_copy))) if x[1] > 1); 
        #print depth
        if depth == 0:
            depth = 1;
        cmd= 'PolyRose --polyopt-pluto-tile --polyopt-pluto-fuse-maxfuse --polyopt-HLS --systemc-target-func=kernel_'+funcName+' --systemc-depth='+str(depth)+' --systemc-preprocess --systemc-HLS '+funcName+'.c' 
        #cmd = 'PolyRose --polyopt-fixed-tiling --polyopt-pluto-fuse-nofuse --polyopt-HLS --systemc-target-func=kernel_'+funcName+' --systemc-depth='+str(depth)+' '+funcName+'.c'
        print "\n[PolyWrapper]:\n", cmd
        os.system(cmd);

        cmd = "g++ -O3 -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux64 -lsystemc -lm -fno-deduce-init-list rose_"+funcName + ".c  -std=c++0x -o rose_"+funcName +".out";
        print "\n[PolyWrapper]:\n", cmd
        os.system(cmd);

        cmd = "./rose_"+funcName+".out 2>&1 | tee results.txt"
        print "\n[PolyWrapper]:\n", cmd
        os.system(cmd);

        #process the result
        latency_updated = False;
        energy_updated = False;
        with open("results.txt", 'r') as f:
                lines = f.read().split('\n');
        for line in lines:
                if('Energy' in line):
                        energy = float(line.split()[1]);
                        energy_updated = True;
                elif ('Latency' in line):
                        latency = float(line.split()[1]);
                        latency_unit = line.split()[-1];
                        if(latency_unit == 'us'):
                            latency *= 1000;
                        latency_updated = True;
        print energy_updated;
        print latency_updated;
        assert(energy_updated and latency_updated);
        power = energy / latency;

#!!! Write the generated result into the datapoints.csv, The order of columns is : tile sizes, unroll factors, power, latency!!!
        if(os.path.exists(resultFile)):
                mode = 'a';
        else:
                mode = 'w'
        #print "[PYTHON]: mode is ", mode;
        with open (resultFile, mode) as f:
                for item in row:
                        f.write("%s,\t" %item);
                f.write("%s,\t" %power);
                f.write("%s\n"%latency);
