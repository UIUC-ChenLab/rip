from optparse import OptionParser
import os
import os.path
import copy
import csv

#clear states

if(os.path.exists('./input_points.csv')):
    print "remove ./input_points.csv"
    cmd = 'rm ./input_points.csv'
    os.system(cmd);


#Untility functions
def foo_callback(option, opt, value, parser):
    setattr(parser.values, option.dest, value.split(','))

options = OptionParser();

options.add_option("--iterNum", action = "store", type = "int", dest = "loopNum"); 
options.add_option("--iterBoundary", action = "callback", type = "string", callback = foo_callback, dest = "iterBoundaryList"); #the maximum iteration number
options.add_option("--maxTileSizePerLoop", action = "callback", type = "string", callback = foo_callback, dest = "maxTileSizePerLoopList"); #number of minimum tile size for all iterations
options.add_option("--minTileSizePerLoop", action = "callback", type = "string", callback = foo_callback, dest = "minTileSizePerLoopList"); #number of maximum tile size for all iterations
options.add_option("--exponent_tile", action = "store", type = "int", dest="exponent_tile");
options.add_option("--exponent_unroll", action = "store", type = "int", dest="exponent_unroll");
options.add_option("--functionName", action = "store", type = "string", dest = "funcName");


#parse the input flags
(opts, args) = options.parse_args();
loopNum = opts.loopNum;
maxTileSizePerLoopList = map(int, opts.maxTileSizePerLoopList);
minTileSizePerLoopList = map(int, opts.minTileSizePerLoopList);
iterBoundaryList = map(int, opts.iterBoundaryList);
exponent_tile = opts.exponent_tile;
exponent_unroll = opts.exponent_unroll;
funcName = opts.funcName;

#preprocess
with open("unroll_factor", 'w') as f1, open("tiling.sizes", 'w') as f2:
    for i in range(loopNum):
        f1.write("1 ");
        f2.write("64 ");

cmd = 'PolyRose --polyopt-fixed-tiling --polyopt-pluto-fuse-nofuse --polyopt-HLS --systemc-target-func=kernel_'+funcName+' --systemc-preprocess --systemc-depth='+str(loopNum)+' '+funcName+'.c'
#print "[PolyWrapper]: ", cmd
os.system(cmd);

with open(".canunrollLoops", 'r') as f:
    canUnrollLoopList = f.read().splitlines();

canUnrollLoopList = map(int, canUnrollLoopList);

#collect the tile size DSE space
tileSizeVector = [minTileSizePerLoopList[:]];
tileSizeVectorNew = [x[:] for x in tileSizeVector];

#spacing = 16;

#generate the tile vector
for i in range(loopNum):
    for ts in tileSizeVector:
        max_ts = maxTileSizePerLoopList[i];
        while(ts[i] < max_ts):
            print "old is ", ts[i];
            print "max ts is ", max_ts;
            if(ts[i] *exponent_tile  <= max_ts):
                ts_old = ts[i];
                ts[i] = ts[i] + ts[i]/2;
                tileSizeVectorNew.append(ts[:]);
                ts[i] = ts_old *exponent_tile;
                tileSizeVectorNew.append(ts[:]);
            else:
                ts[i] = max_ts;
                tileSizeVectorNew.append(ts[:]);
                break;
    tileSizeVector = [x[:] for x in tileSizeVectorNew];

print tileSizeVector;

for tileLine in tileSizeVector:
    unrollVector = [[1] * loopNum];
    unrollVectorNew = [x[:] for x in unrollVector];
    for i, ts in enumerate(tileLine):
        iterBoundary = iterBoundaryList[i];
        if((i+1) in canUnrollLoopList):
            for us in unrollVector:
                while(us[i] * exponent_unroll< iterBoundary/ts):
                    us[i] = us[i] *exponent_unroll;
                    unrollVectorNew.append(us[:]);
                us[i] = iterBoundary/ts;
                unrollVectorNew.append(us[:]);
            unrollVector = [x[:] for x in unrollVectorNew];

    for uv in unrollVector:
        sampleVector = tileLine + uv;
        if(os.path.exists('./input_points.csv')):
            mode = 'a';
        else:
            mode = 'w';
        with open('input_points.csv', mode) as f:
            wr = csv.writer(f, dialect='excel')
            wr.writerow(sampleVector);
