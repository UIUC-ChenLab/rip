from optparse import OptionParser
import os
import os.path
import copy
import csv

#clear states

if(os.path.exists('./sampled_space.csv')):
    print "remove ./sampled_space.csv"
    cmd = 'rm ./sampled_space.csv'
    os.system(cmd);
#Untility functions
def foo_callback(option, opt, value, parser):
    setattr(parser.values, option.dest, value.split(','))

options = OptionParser();

options.add_option("--iterNum", action = "store", type = "int", dest = "loopNum"); 
options.add_option("--maxTileSizePerLoop", action = "callback", type = "string", callback = foo_callback, dest = "maxTileSizePerLoopList"); #number of minimum tile size for all iterations
options.add_option("--iterBoundary", action = "callback", type = "string", callback = foo_callback, dest = "iterBoundaryList"); #number of minimum tile size for all iterations
options.add_option("--minTileSizePerLoop", action = "callback", type = "string", callback = foo_callback, dest = "minTileSizePerLoopList"); #number of maximum tile size for all iterations

#parse the input flags
(opts, args) = options.parse_args();
loopNum = opts.loopNum;
maxTileSizePerLoopList = map(int, opts.maxTileSizePerLoopList);
minTileSizePerLoopList = map(int, opts.minTileSizePerLoopList);
iterBoundaryList = map(int, opts.iterBoundaryList);

with open(".canunrollLoops", 'r') as f:
    canUnrollLoopList = f.read().splitlines();

canUnrollLoopList = map(int, canUnrollLoopList);

#collect the tile size DSE space
tileSizeVector = [minTileSizePerLoopList[:]];
tileSizeVectorNew = [x[:] for x in tileSizeVector];

spacing = 8;

for i in range(loopNum):
    for ts in tileSizeVector:
        max_ts = maxTileSizePerLoopList[i];
        while(ts[i] < max_ts):
            if(ts[i] + spacing < max_ts):
                ts[i] = ts[i] + spacing;
                tileSizeVectorNew.append(ts[:]);
            else:
                ts[i] = max_ts;
                tileSizeVectorNew.append(ts[:]);
    tileSizeVector = [x[:] for x in tileSizeVectorNew];

for tileLine in tileSizeVector:
    unrollVector = [[1] * loopNum];
    unrollVectorNew = [x[:] for x in unrollVector];
    for i, ts in enumerate(tileLine):
        iterBoundary = iterBoundaryList[i];
        if((i+1) in canUnrollLoopList):
            for us in unrollVector:
                while(us[i] *2 < iterBoundary/ts):
                    us[i] = us[i] *2 ;
                    unrollVectorNew.append(us[:]);
                us[i] = iterBoundary/ts;
                unrollVectorNew.append(us[:]);
            unrollVector = [x[:] for x in unrollVectorNew];

    for uv in unrollVector:
        sampleVector = tileLine + uv;
        if(os.path.exists('./sampled_space.csv')):
            mode = 'a';
        else:
            mode = 'w';
        with open('sampled_space.csv', mode) as f:
            wr = csv.writer(f, dialect='excel')
            wr.writerow(sampleVector);
