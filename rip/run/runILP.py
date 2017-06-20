from optparse import OptionParser
import sys
import os
import commands
import matlab.engine
from ILP_builder import ILP_builder

options = OptionParser();
options.add_option("--sampleNum", action="store", type="int", dest="sampleNum")
options.add_option("--PowerBudget", action="store", type = "float", dest="Pbug")
options.add_option("--LUTBudget", action="store", type="int", dest="LUTbug");
options.add_option("--BRAMBudget", action="store", type="int", dest="BRAMbug");
options.add_option("--FFBudget", action="store", type="int", dest="FFbug");
options.add_option("--DSPBudget", action="store", type="int", dest="DSPbug");

options.add_option("--benchmarkName", action="store", type="string", dest="benchmarkName");
options.add_option("--loopIndexes", action="store", type="string", dest="loopIndexes");
options.add_option("--cpp", action="store", type="int", dest="cpp");
options.add_option("--power", action="store", type="int", dest="power");

(opts, args) = options.parse_args();
sampleNumber= opts.sampleNum;
benchmarkName = opts.benchmarkName;
loopIndexes = opts.loopIndexes;
LoopLists = loopIndexes.split(',');
cpp = opts.cpp;
power = opts.power;

P   = 10
LUT = opts.LUTbug
BRAMbug = opts.BRAMbug
FFBudget = opts.FFbug
DSPBug = opts.DSPbug

loopS = {};

#matlab engine
eng = matlab.engine.start_matlab()
print "after launcth mt"

def read_nextIteration(loopIndex, dec):
        fileName = "forNextIteration"+loopIndex+".txt";
        if int(dec) == 5: dec = 4;
        with open(fileName) as f:
                lines = f.readlines();
                line = lines[int(dec)]
                key, value= line.split(':');
                start = value.split()[0];
                end = value.split()[-1];
                length = len(value.split());
        return length, start, end

for it in LoopLists:
        cmd = 'wc -l frontier_' + it + '.txt';
        #print cmd
        cmd_out = commands.getstatusoutput(cmd)[1].split()[0]
        #print cmd_out
        loopS[it] = (0, int(cmd_out)-1);

converged = False
while not converged:
#create sampled table.txt
        for it in LoopLists:
                sampleStart = loopS[it][0];
                sampleEnd = loopS[it][1];
                if it is LoopLists[0]:
                        writeMode = 'w';
                else:
                        writeMode = 'a';
                #print "aa",sampleStart, sampleEnd;
                #sample file
                sampleFile = 'frontier_'+it+'.txt';
                cmd = 'python sample.py --sampleFile '+ sampleFile+' --sampleNumber '+str(sampleNumber)+' --sampleStart '+str(sampleStart)+' --sampleEnd '+str(sampleEnd)+' --loopNumber '+str(it)+' --writeMode '+writeMode + " --power " + str(power)
                print cmd
                os.system(cmd);
                cmd = 'python geneMyfiles.py --sampleNum '+str(sampleNumber)+' --benchmarkName '+benchmarkName + " --cpp " + str(cpp);
                print cmd
        #os.system(cmd);
        #cmd = 'python test.py --sampleNum '+str(sampleNumber)
        os.system(cmd); 
        sol = ILP_builder(sampleNumber, P, LUT, BRAMbug, FFBudget, DSPBug)
        sol.buildGraph('myfile0.txt')
        sol.getNodesCnodes('nodeInfo0.txt')
        sol.readAllmyFiles();
        sol.readAllNodeInfoFiles();
        sol.zConstraints()
        sol.setVarNum()
        sol.latencyConstraints()
        sol.xConstraints()
        sol.x_zConstratints()
        sol.yConstraints()
        sol.powerConstraints()
        sol.areaConstraints() 

        sol.writeAs("outputA.txt", sol.A)
        sol.writeAs("outputAeq.txt", sol.Aeq)
        sol.writeBs("outputB.txt", sol.b)
        sol.writeBs("outputBeq.txt", sol.beq)
        sol.writeOutputf();
        x,latency, Power, decisions, bram, dsp, lut, ff = eng.ILP(sol.powerStart, sol.powerEnd, len(sol.nodes),len(sol.cNodes),sampleNumber,len(sol.Zs), sol.mayShareNodes, nargout=8);
#get the next iteration
        convergency = 0;
        for it, dec in zip(LoopLists, decisions):
                if dec != 'inf':
                        length, start, end =  read_nextIteration(it,dec[0]);
                loopS[it] = (start, end);
                if(length < 5):
                        loopS[it] = (int(start), int(start)+4);
                        convergency = convergency + 1;
#test the convergency
        #print loopS;
        converged = True if convergency == len(loopS) else False;

print "Constraints P, LUT, BRAMbug, FF, DSPBug ", P, LUT,  BRAMbug, FFBudget, DSPBug;
print decisions, latency, Power, bram, dsp, lut, ff;
