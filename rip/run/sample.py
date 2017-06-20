from optparse import OptionParser
import sys

options = OptionParser();

options.add_option("--sampleFile", action="store", type="string", dest="sampleFile");
options.add_option("--sampleNumber", action="store", type="int", dest="sampleNumber");
options.add_option("--sampleStart", action="store", type="int", dest="sampleStart");
options.add_option("--sampleEnd", action="store", type = "int", dest="sampleEnd");
options.add_option("--loopNumber", action="store", type = "string", dest="loopNumber");
options.add_option("--writeMode", action="store", type="string", dest="writeMode");
options.add_option("--power", action="store", type="int", dest="power");

(opts, args) = options.parse_args();

sampleFile = opts.sampleFile;
sampleNumber = opts.sampleNumber;
sampleStart = opts.sampleStart;
sampleEnd = opts.sampleEnd;
loopNumber = opts.loopNumber;
writeMode = opts.writeMode;
power   = opts.power;

def split_seq(seq, size):
        newseq = []
        splitsize = 1.0/size*len(seq)
        for i in range(size):
                newseq.append(seq[int(round(i*splitsize)):int(round((i+1)*splitsize))])
        return newseq


sampleSets = split_seq(range(sampleStart, sampleEnd+1), sampleNumber);
latencyList = []
powerList = []
bramList = []
dspList = []
FFList = []
LUTList = []

print sampleSets
with open(sampleFile) as f:
    lines = f.readlines();
    for i in range(sampleNumber):
        sampleLength = len(sampleSets[i]);
        sampleIndex = sampleSets[i][int(sampleLength/2 + sampleLength%2)-1];
        samplePointList = lines[sampleIndex].split(',');
        latencyList.append(float(samplePointList[5]));
        if(power == 0):
            powerList.append(float(samplePointList[4])/float(samplePointList[5]));
        else:
            powerList.append(float(samplePointList[4]));
        bramList.append(samplePointList[6]);
        dspList.append(samplePointList[7]);
        FFList.append(samplePointList[8]);
        LUTList.append(samplePointList[9].rstrip());

print bramList;
print dspList;
print FFList;
print LUTList;

bramStr = ''.join(str(e)+'  ' for e in bramList)
dspStr = ''.join(str(e)+'  ' for e in dspList)
FFStr = ''.join(str(e)+'  ' for e in FFList)
LUTStr = ''.join(str(e)+'  ' for e in LUTList)
latencyStr = ''.join(str(e)+'  ' for e in latencyList)
powerStr = ''.join(str(e)+'  ' for e in powerList)

with open("table.txt", writeMode) as fw:
    fw.write("LAT_HW_"+loopNumber+" "+latencyStr+'\n');
    fw.write("POW_HW_"+loopNumber+" "+powerStr+'\n');
    fw.write("BRAM_HW_"+loopNumber+" "+bramStr+'\n');
    fw.write("DSP_HW_"+loopNumber+" "+dspStr+'\n');
    fw.write("FF_HW_"+loopNumber+" "+FFStr+'\n');
    fw.write("LUT_HW_"+loopNumber+" "+LUTStr+'\n');
    fw.write('\n');

fileName = "forNextIteration"+loopNumber+".txt"
with open(fileName, 'w') as fw:
    for i in range(sampleNumber):
        fw.write(str(i)+": "+ ''.join(str(e)+' ' for e in sampleSets[i]));
        fw.write('\n');

