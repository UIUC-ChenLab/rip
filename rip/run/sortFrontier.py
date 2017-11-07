from optparse import OptionParser

#Untility functions
def foo_callback(option, opt, value, parser):
    setattr(parser.values, option.dest, value.split(','))

options = OptionParser();
options.add_option("--fileNames", action = "callback", type="string", callback=foo_callback, dest="fileNameList");

(opts, args) = options.parse_args();

for fname in opts.fileNameList:
        #fname = "frontier_1.txt";
        f = open(fname);
        lines = f.readlines();
        f.close()
        linesList=[];
        for l in lines:
                ll = l.rstrip('\n').split(',')
                print ll[5]
                ll = map(float, ll)
                #ll[4] = ll[4] / 2 
                ll[5] = ll[5] 
                #print ll
                linesList.append(ll);

        linesList = sorted(linesList,key=lambda x: x[5])
        #wfname = "frontier_1.txt";
        wfname = fname;
        wf = open(wfname, 'w');
        for ll in linesList:
                str1 = ",".join(str(v) for v in ll);
                wf.write(str1+'\n');

        wf.close();
