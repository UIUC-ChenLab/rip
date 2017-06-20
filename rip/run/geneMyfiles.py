import os
from optparse import OptionParser

options = OptionParser();
options.add_option("--sampleNum", action="store", type="int", dest="sampleNum");
options.add_option("--benchmarkName", action="store", type="string", dest="benchmarkName");
options.add_option("--cpp", action="store", type="int", dest="cpp");
(opts, args) = options.parse_args();
SAMPLE = opts.sampleNum;
benchmarkName = opts.benchmarkName;
cpp = opts.cpp;

if(cpp == 1):
  benchmark_c = benchmarkName+".cc";
else:
  benchmark_c = benchmarkName+".c";
benchmark_ll = benchmarkName + ".ll";

def reorderFile(fileName):
  with open(fileName, 'r+') as f:
    contents = f.readlines();
    contents.sort()
    f.seek(0)
    for item in contents:
      f.write(item)

#for each sample point, need to go through the whole process
for i in range(SAMPLE):
  #generate the header file
  wfilename = "PLA.h"
  with open("table.txt") as fr, open(wfilename, 'w') as fw:
    fw.write("#ifndef PLA_H\n")
    for line in fr:
      if line != '\n':
        lineList = line.split()
        microName = lineList[0]
        data = lineList[i+1]
        fw.write("\t#define ");
        fw.write(microName +" ");
        fw.write(str(data) + "\n");
    fw.write("#endif\n");
  #run the opt
  cmd_clang ="clang -O0 -emit-llvm "+ benchmark_c +" -S -o " + benchmark_ll
  os.system(cmd_clang)
  cmd_opt = "opt -load ~/software/llvm_3.8.1/build/lib/LLVMIdentifyCriticalLoop.so -identifyCriticalLoop < " + benchmark_ll
  os.system(cmd_opt)
  reorderFile("myfile.txt")
  reorderFile("nodeInfo.txt")
  #rename myfile.txt and nodeInfo.txt
  rename = "myfile"+str(i)+".txt"
  rename1 = "nodeInfo"+str(i)+".txt"
  os.system("mv myfile.txt " + rename)
  os.system("mv nodeInfo.txt " + rename1)

