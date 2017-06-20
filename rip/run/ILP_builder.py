import networkx as nx
import itertools
class ILP_builder():
        def __init__(self, SAMPLE, P, LUT, BRAM, FF, DSP):
                self.inLine = {};
                self.ShadowNodes = {}                       #the dictionary stores all the shadowNodes, and the value are the orignial nodes which creates that shadow
                self.HasShadowNodes =[]
                self.linesList =[]                          #the lineslist which contains all the info from ALL myfile.txt
                self.linesList2 = []                        #the lineslist which contains all the info from ALL nodeInfo.txt
                self.Zs = [];
                self.varNum = 0;                            #number of variables in the final ILP 
                self.G = nx.DiGraph()
                self.nodes=set()
                self.cNodes=set()
                self.mayShareNodes = 0;                     #nodes that may be shared, this is for computing the variable length
                self.YsIndex = {}

                self.SAMPLE = SAMPLE
                self.PowerBudget = P
                self.LUTBudget = LUT
                self.BRAMBudget = BRAM
                self.FFBudget = FF
                self.DSPBudget = DSP

                self.A=[]
                self.b=[]
                self.Aeq = []
                self.beq = [] 
#######################################
## Utility functions
#######################################

        #read in myfile.txt, build the graph, G will be used in power constraints, anti-chain
        def buildGraph(self, fileName):
                with open (fileName) as f:
                        for line in f:
                                if line != '\n':
                                        lineList = line.split()
                                        nodeId = lineList[0]
                                        predId = lineList[1]
                                        self.G.add_edge(predId, nodeId);

        # read in nodeInfo.txt, record all the nodes and critical nodes, ordered
        def getNodesCnodes(self, fileName):
                with open(fileName) as f:
                        for line in f:
                                if line != "\n":
                                        lineList = line.split()
                                        nodeId = lineList[0]
                                        self.nodes.add(nodeId)

                                        preIsCritical = lineList[1]
                                        if preIsCritical == '1':
                                                self.cNodes.add(nodeId);
                                        if(lineList[3] == '1'):
                                                self.ShadowNodes[nodeId] = lineList[-1];
                                                self.HasShadowNodes.append(lineList[-1]);
                                        inLineNum = lineList[-2];
                                        if (inLineNum != '0'):
                                                self.mayShareNodes += 1
                                                if(self.inLine.has_key(inLineNum)):
                                                        self.inLine[inLineNum].append(nodeId);
                                                else:
                                                        self.inLine[inLineNum] = [nodeId];
                        self.nodes = list(self.nodes)
                        self.nodes = map(int, self.nodes)
                        self.nodes.sort()

                        self.cNodes = list(self.cNodes)
                        self.cNodes = map(int, self.cNodes)
                        self.cNodes.sort()

#read all files in
        def readAllmyFiles(self):
                for i in range(self.SAMPLE):
                        fileName = "myfile" + str(i) + ".txt"
                        f = open(fileName)
                        lines = f.readlines()
                        self.linesList.append(lines)
                        f.close()

        def readAllNodeInfoFiles(self):
                for i in range(self.SAMPLE):
                        fileName = "nodeInfo"+str(i)+".txt"
                        f = open(fileName)
                        lines = f.readlines()
                        self.linesList2.append(lines);
                        f.close()


#whether node n1 and n2 are a shawdow pair, original node and shadow node
        def isShadowPair(self, n1, n2):
                if(n1 in self.ShadowNodes):
                        return self.ShadowNodes[n1] == n2;
                elif(n2 in self.ShadowNodes):
                        return self.ShadowNodes[n2] == n1;
                else:
                        return False

#set the number of varNum
        def setVarNum(self):
                SAMPLE = self.SAMPLE
                self.varNum = len(self.nodes)+len(self.cNodes)*(SAMPLE+1)+len(self.Zs) + self.mayShareNodes * (SAMPLE);
                
#where i is the ith element in self.Zs
        def getZIndex(self,i):
                return len(self.nodes) + len(self.cNodes)*(self.SAMPLE+1) + i

        def getZIndexNode(self, v1, v2):
                if v1 < v2:
                        zIndex = self.Zs.index((v1, v2));
                else:
                        zIndex = self.Zs.index((v2, v1));
                return len(self.nodes) + len(self.cNodes)*(self.SAMPLE+1) + zIndex

        #get the index of the critical node in the variable length
        def getCriticalIndex(self, n):
                return self.cNodes.index(int(n))*(self.SAMPLE+1) + len(self.nodes);

        #get the starting index of Y in variable length
        def getYIndex(self, v):
                return self.YsIndex[v];

        #finde linenumber of a particular node in one linesList
        def findLineNum(self, linesList, n):
                for i, line in enumerate(linesList[0]):
                        if(line == '\n'):
                                continue;
                        lineList = line.split()
                        if int(lineList[0]) == int(n):
                                return  i;
#allocate a new Y index
        def allocateYIndex(self):
                self.varNumBeforeY += self.SAMPLE
                return (self.varNumBeforeY-self.SAMPLE);

        def setVarNumBeforeY(self):
                SAMPLE = self.SAMPLE
                self.varNumBeforeY = len(self.nodes)+len(self.cNodes)*(SAMPLE+1)+len(self.Zs);

###################################################
# Constraints functions, please refer to the paper for detail
###################################################

#latency constraints
        def latencyConstraints(self):
                print "latencyConstraints"
                i = 0;
                SAMPLE = self.SAMPLE
                for line0 in self.linesList[0]:
                        varList = [0] * self.varNum;
                        if(line0 != '\n'):
                                lineList = line0.split();
                                curId = int(lineList[0])
                                predId = int(lineList[1])
                                curIndex = self.nodes.index(curId);
                                predIndex = self.nodes.index(predId);
                                varList[curIndex] = -1;
                                varList[predIndex] = 1;
                                predIsCritical = lineList[2];
                                predLsw = float(lineList[6]);
                                if(predIsCritical != '1'):
                                        self.A.append(varList)
                                        self.b.append(-predLsw)
                                        i = i+1;
                                        continue
                                pHasShadow = lineList[3]
                                xpredIndex = self.getCriticalIndex(predId)
                                for j in range(SAMPLE):
                                        varList[xpredIndex + j] = float(self.linesList[j][i].split()[7])
                                varList[xpredIndex+SAMPLE] = predLsw
                                self.A.append(varList)
                                self.b.append(0)
                        i = i+1;

#sum_j(x_ij + y_ij) = 1
        def xConstraints(self):
                print "xConstraints"
                SAMPLE = self.SAMPLE
                for i in self.cNodes:
                                varList = [0] * self.varNum
                                curNode = i
                                #if curNode is a ShadowNode (1) the sum of the original node and the shadow node hardware version should be 1 
                                if(curNode in self.ShadowNodes):
                                       orgNode = ShadowNodes[curNode];
                                       startAdd = getCriticalIndex(i);
                                       startAdd1 = getCriticalIndex(orgNode);
                                       for j in range(SAMPLE):
                                               varList[startAdd+j] = 1
                                               varList[startAdd1 + SAMPLE] = 1;
                                       varList[startAdd1+SAMPLE] = 1
                                       self.Aeq.append(varList)
                                       self.beq.append(1)

                                       #(2) the software version of the shadowNode should be 0
                                       varList = [0] * self.varNum
                                       varList[startAdd + SAMPLE] = 1
                                       self.Aeq.append(varList)
                                       self.beq.append(0)
                                       continue;
                                #since the hasShadow case is considered in IsShadow case, we dont do anything here
                                if (curNode in self.HasShadowNodes):
                                        continue;
                                startAdd = self.getCriticalIndex(i);
                                for j in range(SAMPLE+1):
                                        varList[startAdd+j] = 1
                                self.Aeq.append(varList)
                                self.beq.append(1)


#we don't explicitly have z constraints, but we put it in to a list, since it constrains y constraints. For all pairs in the same inline group, we add an z constraint.
        def zConstraints(self):
                print "zConstraint"
                assert(self.varNum == 0, "you should set zConstraint before doing any other thing")
                for values in self.inLine.values():
                        for iter in itertools.combinations(values, 2):
                                n1 = iter[0];
                                n2 = iter[1];
                                if self.isShadowPair(n1, n2):
                                        continue;
                                if n1 < n2:
                                        self.Zs.append((n1, n2));
                                else:
                                        self.Zs.append((n2, n1));
                self.Zs.sort()

#for nodes in the same inline group, they should have the same choices of x 
        def x_zConstratints(self):
                print "x_zConstratints"
                for i, (tk1, tk2) in enumerate(self.Zs):
                        n1 = tk1;
                        n1_cIndex = self.getCriticalIndex(n1);
                        n2 = tk2;
                        n2_cIndex = self.getCriticalIndex(n2);
                        z_index = self.getZIndex(i);
                        for k in range(self.SAMPLE+1):
                                varList = [0] * self.varNum
                                varList[n1_cIndex + k] = 1;
                                varList[n2_cIndex + k] = -1;
                                varList[z_index] = 1
                                self.A.append(varList);
                                self.b.append(1)
                                varList[z_index] = -1
                                self.A.append(varList)
                                self.b.append(-1)

        def yConstraints(self):
                print "yConstraints"
                self.setVarNumBeforeY();
                for value in self.inLine.values():
                        Seen = set();
                        for v in value:
                                yIndex = self.allocateYIndex();
                                xIndex = self.getCriticalIndex(v);
                                self.YsIndex[v] = yIndex 
                                #if len(Seen) == 0:
                                #        Seen.add(v);
                                #        varList1=[0]*self.varNum
                                #        varList1[yIndex] = 1;
                                #        self.Aeq.append(varList1)
                                #        self.beq.append(1);
                                #        continue;

                                for j in range(self.SAMPLE):
                                        varList1=[0]*self.varNum
                                        for v1 in Seen:
                                                if self.isShadowPair(v1, v):
                                                        continue;
                                                zIndex = self.getZIndexNode(v1, v)
                                                varList1[zIndex] = -1
                                                varList2=[0] * self.varNum
                                                varList2[zIndex] = 1;
                                                varList2[yIndex+j] = 1;
                                                self.A.append(varList2)
                                                self.b.append(1)

                                        varList1[yIndex+j] = -1
                                        varList1[xIndex+j] = 1
                                        self.A.append(varList1);
                                        self.b.append(0);
                                Seen.add(v);


#for each node in the inline group, only when zij == 0 and xi == 1, 
# we introduce another variable yij = [zij==0 and xi = 1] for each sample element in node i
# we have 
#   Resource = sum(Ri) + sum_i (sum_j(y_ij*R_ij) )
# where Ri are all the nodes which are not in any inline group
# 
        def areaConstraints(self):
                print "areaConstraints"
                i = 0;
                varListBRAM=[0] * self.varNum;
                varListDSP=[0] * self.varNum;
                varListFF=[0] * self.varNum;
                varListLUT=[0] * self.varNum;
                for line in self.linesList2[0]:
                        if(line == '\n'):
                                i = i + 1;
                                continue;
                        lineList = line.split()
                        isCritical = (lineList[1] == '1')
                        if not isCritical:
                                i = i+1;
                                continue
                        hasShadow = (lineList[2] == '1')
                        isShadow = (lineList[3] == '1')
                        BRAM = []
                        LUT = []
                        FF = []
                        DSP = []
                        inLineNum = lineList[-2];
                        node = int(lineList[0])
                        if(inLineNum == '0'):
                                cNodeIndex = self.getCriticalIndex(node)
                                for j in range(self.SAMPLE):
                                        varListBRAM[cNodeIndex+j] = float(self.linesList2[j][i].split()[8]);
                                        varListDSP[cNodeIndex+j] = float(self.linesList2[j][i].split()[9]);
                                        varListFF[cNodeIndex+j] = float(self.linesList2[j][i].split()[10]);
                                        varListLUT[cNodeIndex+j] = float(self.linesList2[j][i].split()[11]);
                                i = i + 1;
                                continue;

                for n, yIndex in self.YsIndex.items():
                        #print "n, yIndex:", n, yIndex
                        i1 = self.findLineNum(self.linesList2, n);
                        #print i1
                        for j in range(self.SAMPLE):
                                varListBRAM[yIndex + j] = float(self.linesList2[j][i1].split()[8]);
                                varListDSP[yIndex + j] = float(self.linesList2[j][i1].split()[9]);
                                varListFF[yIndex + j] = float(self.linesList2[j][i1].split()[10]);
                                varListLUT[yIndex + j] = float(self.linesList2[j][i1].split()[11]);
                        #print varListBRAM

                self.A.append(varListBRAM);
                self.b.append(self.BRAMBudget);

                self.A.append(varListDSP);
                self.b.append(self.DSPBudget);

                self.A.append(varListLUT);
                self.b.append(self.LUTBudget);

                self.A.append(varListFF);
                self.b.append(self.FFBudget);

        def powerConstraints(self):
                SAMPLE = self.SAMPLE
                PowerNodes= set();
                G_prime = nx.DiGraph()
                with open("nodeInfo0.txt") as f:
                        for line in f:
                                if line != '\n':
                                        lineList = line.split()
                                        nodeId = lineList[0];
                                        powSw = float(lineList[6]);
                                        powHw = float(lineList[7]); 
                                        if((powSw == 0) and (powHw == 0)):
                                                continue;
                                        PowerNodes.add(nodeId); 

                for itr in itertools.combinations(PowerNodes, 2):
                        n1 = itr[0];
                        n2 = itr[1];
                        if(nx.has_path(self.G, n1, n2) or nx.has_path(self.G, n2, n1)):
                                continue;
                        G_prime.add_edge(n1, n2);
                        G_prime.add_edge(n2, n1);

                for it in nx.strongly_connected_components(G_prime):
                        if (not hasattr(self, 'powerStart')):
                                self.powerStart = len(self.A);
                        PowBug = self.PowerBudget
                        varList = [0] * self.varNum
                        for n in it:
                                PowerNodes.remove(n);
                                i = self.findLineNum(self.linesList2, n);
                                powSw = float(self.linesList2[0][i].split()[6]);
                                isCritical = int(n) in self.cNodes;
                                if not isCritical:
                                        PowBug = PowBug - powSw;
                                if isCritical:
                                        nCIndex = self.getCriticalIndex(n);
                                        for j in range(SAMPLE):
                                                varList[nCIndex+j] = float(self.linesList2[j][i].split()[7]); 
                                        varList[nCIndex+SAMPLE] = powSw;
                        self.A.append(varList)
                        self.b.append(PowBug)

                for n in PowerNodes:
                        if (not hasattr(self, 'powerStart')):
                                self.powerStart = len(self.A);
                        PowBug = self.PowerBudget
                        varList = [0] * self.varNum
                        i = self.findLineNum(self.linesList2, n);
                        powSw = float(self.linesList2[0][i].split()[6]);
                        isCritical = int(n) in self.cNodes;
                        if not isCritical:
                                PowBug = PowBug - powSw;
                        if isCritical:
                                nCIndex = self.getCriticalIndex(n);
                                for j in range(SAMPLE):
                                        #print j, i
                                        #print len(self.linesList2)
                                        varList[nCIndex+j] = float(self.linesList2[j][i].split()[7]); 
                                varList[nCIndex+SAMPLE] = powSw;
                                self.A.append(varList)
                                self.b.append(PowBug)
                self.powerEnd = len(self.A)-1;

        #def powerConstraints(self):
        #        print "powerConstraints"
        #        SAMPLE = self.SAMPLE
        #        for iter in nx.antichains(self.G):
        #                print iter
        #                #if len(iter) != 0:
        #                #        PowBug = self.PowerBudget
        #                #        varList = [0] * self.varNum
        #                #        for n in iter:
        #                #                i = self.findLineNum(self.linesList2, n);
        #                #                powSw = float(self.linesList2[0][i].split()[6]);
        #                #                isCritical = int(n) in self.cNodes;
        #                #                if not isCritical:
        #                #                        PowBug = PowBug - powSw;
        #                #                if isCritical:
        #                #                        nCIndex = self.getCriticalIndex(n);
        #                #                        for j in range(SAMPLE):
        #                #                                varList[nCIndex+j] = float(self.linesList2[j][i].split()[7]); 
        #                #                        varList[nCIndex+SAMPLE] = powSw;
        #                #        self.A.append(varList)
        #                #        self.b.append(PowBug)
        
        def writeAs(self, fileName, matrix):
                print "writeAs"
                with open(fileName, 'w') as f:
                        for line in matrix:
                                for element in line:
                                        f.write(str(element));
                                        f.write(' ');
                                f.write('\n')
        def writeBs(self, fileName, matrix):
                print "writeBs"
                with open(fileName, 'w') as f:
                        for line in matrix:
                                f.write(str(line));
                                f.write(' ');
                        f.write('\n')

        def writeOutputf(self):
                print "writeOutputf"
                with open('outputf.txt', 'w') as f:
                        varList = [0] * self.varNum;
                        varList[len(self.nodes)-1] = 1;
                        start = len(self.nodes) + len(self.cNodes)*(self.SAMPLE+1)-1;
                        for i in range(len(self.Zs)):
                                varList[start + i] = -1;
                        for ele in varList:
                                f.write(str(ele))
                                f.write(' ')


