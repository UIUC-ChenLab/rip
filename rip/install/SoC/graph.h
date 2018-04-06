#include "llvm/Transforms/Utils/UnrollLoop.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/Analysis/MemoryDependenceAnalysis.h"
#include "llvm/IR/Dominators.h"
#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Analysis/LoopPass.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/Analysis/LoopAccessAnalysis.h"
#include "llvm/Analysis/BranchProbabilityInfo.h"
#include "llvm/Analysis/BlockFrequencyInfoImpl.h"
#include "llvm/Analysis/BlockFrequencyInfo.h"
#include <queue>
#include <set>

typedef enum{
	NOT_VISITED,
	VISITED
} STATUS;


/* node in the graph, the fields are :
 * latencyHw_: associated latency if it is mapped to hardware
 * latencySw_: associated latency if it is mapped to software
 * powerHw_:  associated power if it is mapped to hardware
 * powerSw_:  associated power if it is mapped to software
 * freq_:   associated branch freq_ number
 * effLatHw_:  expectation of latencyHw_
 * effLatSw_:  expectation of latencySw_
 * critical_ ???
 * BasicBlock*:   the entry BB of current node
 * area_: associated area number
 * status_: visited or not
 * successors:  the successors of the current node
 * predecessors: the predecessors of the current node
 */

class Vertex{
	llvm::BasicBlock* BB_;	//the corresponding basic block of the current node
	double effLatHw_;	//the expectation of latencyHw_ (latencyHw_ * block frequency)
	double effLatSw_;       //the expectation of latencySw_ (latencySw_ * block frequency)
	double powerHw_;	//power if it is mapped to hardware
	double powerSw_;	//power if it is mapped to software

	int BRAM_;		//number of BRAM of current node
	int DSP_;		//number of DSPs of this node
	int FF_;		//number of FFs of this node
	int LUT_;		//number of LUTs of this node
	int InLineNum_;		//inLine group number, the vertices within the same inline group, might be sharing resource. If inLineNum == 0, means it is not in any resource reuse group
	STATUS status_;		//the visiting status of the current node
	unsigned ID_;		//The node ID, each one has a unique ID
	bool isSink_;		//Whether the current node is sink
	bool hasShadow_;	//Whether it is the orignial node and it has shadow
	bool isShadow_;		//Whether it is the duplicated node 
	Vertex* DupNode_;	//If it it is hasShadow or isShadow, what is the duplicated node
	bool critical_;		//Whether this node is marked as critical node
	std::set<Vertex*> successors;//All the successors of the current node
	std::set<Vertex*> predecessors;//All the predecessors of the current node
	double stamp_;		//The time stamp of the current node (starting time)
public: 
	Vertex(
	  llvm::BasicBlock* BB,
	  const double eff_latencyHw,
	  const double eff_latencySw,
	  const double powerHw,
	  const double powerSw,
	  const int BRAM,
	  const int DSP,
	  const int FF,
	  const int LUT,
	  const int InLineNum,
	  unsigned ID,
	  bool isSink,
	  bool hasShadow,
	  bool isShadow,
	  Vertex* DupNode,
	  bool critical = false): 
	  	BB_(BB), 
	  	effLatHw_(eff_latencyHw),
	  	effLatSw_(eff_latencySw),
	  	powerHw_(powerHw),
	  	powerSw_(powerSw),
	  	BRAM_(BRAM),
	  	DSP_(DSP),
	  	FF_(FF),
	  	LUT_(LUT),
	  	InLineNum_(InLineNum),
	  	status_(NOT_VISITED),
	  	ID_(ID),
	  	isSink_(isSink),
	  	hasShadow_(hasShadow),
	  	isShadow_(isShadow),
	  	DupNode_(DupNode),
	  	critical_(critical) { 
	  		stamp_ = 0; 
	  	};

	void set_stamp(const double stamp){ stamp_ = stamp; }
	double get_stamp(){ return stamp_; }
	void set_status(const STATUS s){ status_ = s; }
	STATUS get_status() const { return status_;}
	llvm::BasicBlock* getBB() {return BB_;}
	double get_effLatHw() {return effLatHw_;}
	double get_effLatSw() {return effLatSw_;}
	unsigned getID() {return ID_;}
	void set_critical(bool critical){critical_ = critical;}
	bool get_critical(){return critical_;}
	bool getSink(){return isSink_;}
	void setDupNode(Vertex* DupNode){DupNode_ = DupNode;}
	Vertex* getDupNode(){return DupNode_;}
	bool getIsShadow(){return isShadow_;}
	bool getHasShadow(){return hasShadow_;}
	int getInlineNum(){return InLineNum_;}
	void set_isShadow(bool isShadow){isShadow_ = isShadow;}
	void set_hasShadow(bool hasShadow){hasShadow_ = hasShadow;}
	void set_InLineNum(int InLineNum){InLineNum_ = InLineNum;}
	void set_effLatHw(double effLat){effLatHw_ = effLat;}
	void set_effLatSw(double effLat){effLatSw_ = effLat;}
	void acc_effLatHw(double effLat){effLatHw_ += effLat;}
	void acc_effLatSw(double effLat){effLatSw_ += effLat;}
	//void acc_area(double area){area_ += area;}
	void acc_area(int BRAM, int DSP, int FF, int LUT){
		BRAM_ += BRAM;
		DSP_ += DSP;
		FF_ += FF;
		LUT_ += LUT;
	}
	void acc_powerHw(double powerHw){powerHw_ += powerHw;}
	void acc_powerSw(double powerSw){powerSw_ += powerSw;}
	void add_succ(Vertex *V){successors.insert(V);}
	void add_pred(Vertex *V){predecessors.insert(V);}
	std::set<Vertex*> *get_succs(){return &(successors);}
	std::set<Vertex*> get_succ_copies(){ return successors;} //the deep copy version of the successors.
	std::set<Vertex*> *get_preds(){return &(predecessors);}
	std::set<Vertex*> get_preds_copies(){return predecessors;}
	double getPowerHw(){return powerHw_;}
	double getPowerSw(){return powerSw_;}
	//double getArea(){return area_;}
	void getArea(int *BRAM, int *DSP, int *FF, int *LUT){
		*BRAM = BRAM_;
		*DSP = DSP_;
		*FF = FF_;
		*LUT = LUT_;
	}
};

class taskGraph{
	typedef std::set<Vertex*> Vertices;
	typedef std::set<Vertex*>::iterator VerticesItr;
	typedef std::set<Vertex*>::const_iterator VerticesItrConst;
	typedef typename std::map<llvm::BasicBlock*, Vertex*> BBVertexTable; //The table using the BasicBlock as key, to look-up the corresponding Vertex

	int total_BRAM_;
	int total_DSP_;
	int total_FF_;
	int total_LUT_;
	double totalEnergy_;
	double totalLat_;
	
	BBVertexTable bbVerTab;
	Vertex* root_;
	Vertex* sink_;
	llvm::LoopInfo* LI_;
	std::map<llvm::Loop*, Vertex*> loopMergedNodeTab; //indicate the loop is mapped to which node;

	std::set<Vertex*> Leaves;
	unsigned curNodeId; //this is going to be assgined when a new node is allocated;

	std::map<Vertex*, bool > mergeableTable;
public:
	Vertices vertices_;
	double base_freq;
	void Hoisting(llvm::Loop* L, llvm::BasicBlock* hoistToB);
	Vertex* getMergeNode(llvm::Loop *L){return loopMergedNodeTab.at(L);}
	void setMergeNode(llvm::Loop* L, Vertex* V){loopMergedNodeTab[L] = V;}
	BBVertexTable* getbbVerTab(){return &bbVerTab;}
	taskGraph(llvm::Function &F, llvm::LoopInfo *LI);

	Vertex* allocateVertex(llvm::Function &, llvm::BasicBlock* BB);
	Vertex* deepCopyVertex(Vertex* V);

	void addEdge(Vertex* fromNode, Vertex* toNode);
	bool vertices_contain(Vertex *V){
		VerticesItrConst itr = vertices_.find(V);
		if(itr == vertices_.end()) return false;
		return true;
	}
	void mergeTwoNodes(Vertex* frmoNode, Vertex* toNode);
	void MergeEdgesToNode(Vertex* ParentNode, Vertices* ConnnectedNode, bool isSucc);
	void removeEdge(Vertex *masterNode, Vertex* slaveNode);
	void removeEdge(llvm::BasicBlock *masterBB, llvm::BasicBlock *slaveBB);
	Vertex* getRoot(){return root_;}
	void setRoot(Vertex* v){root_ = v;}
	void clear_status();
	llvm::BasicBlock* getBBforNode(Vertex*);
	void printEdges(llvm::BasicBlock *BB);
	void printNodes();
	void printSuccessors(Vertex* V);
	bool simplifyTaskGraph(Vertex* V);
	bool bbExist(llvm::BasicBlock* BB){return (bbVerTab.find(BB) != bbVerTab.end());}
	bool vertexExist(Vertex* V){return (vertices_.find(V) != vertices_.end());}
	void getAttrfromBB(llvm::BasicBlock * BB, double *latencyHw, double *latencySw, double *powerHw, double *powerSw, int *BRAM, int *DSP, int *FF, int *LUT, int *inLineNum);
	void addDummySink();
	Vertex* getSink(){return sink_;}
	void rev_dfs(Vertex* V, std::ofstream &f, std::ofstream &f1);
	void dfsToFindLeaves(Vertex* V);
	void generateILP();
	void calCriticalLength();
	bool predContainCritical(Vertex *V);
	int numberofNodes();
	~taskGraph(){
		//printf("distructor\n");
		for(VerticesItr is = vertices_.begin(), ie = vertices_.end(); is!=ie; ++is){
			delete(*is);
		}
	}
};
