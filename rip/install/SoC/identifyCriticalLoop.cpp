#include "llvm/Analysis/AliasAnalysis.h"
#include "llvm/Analysis/AliasSetTracker.h"
#include "llvm/Analysis/BasicAliasAnalysis.h"
#include "llvm/Transforms/Utils/UnrollLoop.h"
#include "llvm/ADT/SetVector.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Pass.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/Statistic.h"
#include "llvm/IR/DebugInfo.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/IR/Dominators.h"
#include "llvm/Analysis/LoopAccessAnalysis.h"
#include "llvm/Analysis/LoopPass.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/Analysis/MemoryDependenceAnalysis.h"
#include "llvm/IR/Dominators.h"
#include "llvm/ADT/SetVector.h"
#include "llvm/IR/CallSite.h"
#include "llvm/Transforms/Utils/LoopUtils.h"
#include "llvm/IR/InstIterator.h"
#include <fstream>
#include <iostream>
#include <map>

#include "llvm/Analysis/BranchProbabilityInfo.h"
#include "llvm/Analysis/BlockFrequencyInfoImpl.h"
#include "llvm/Analysis/BlockFrequencyInfo.h"

#include "graph.h"

#define DEBUG_TYPE "identifyCriticalLoop"

using namespace llvm;

namespace{
	struct IdentifyCriticalLoop : public FunctionPass{
		static char ID;
		IdentifyCriticalLoop(): FunctionPass(ID){}
		bool runOnFunction(Function &F) override;
		void getAnalysisUsage(AnalysisUsage &AU) const override {
			AU.addRequiredID(LoopSimplifyID);
			AU.addRequired<DominatorTreeWrapperPass>();
			AU.addRequired<LoopInfoWrapperPass>();
			AU.addRequired<MemoryDependenceWrapperPass>();
			AU.addRequired<AAResultsWrapperPass>();
		}
		enum DepType {
			Clobber = 0,
			Def,
			NonFuncLocal,
			Unknown
		};

		typedef std::set<Vertex*> Vertices;
		typedef std::set<Vertex*>::iterator VerticesItr;
		typedef std::set<Vertex*>::const_iterator VerticesItrConst;
		typedef typename std::map<llvm::BasicBlock*, Vertex*> BBVertexTable;
		typedef PointerIntPair<const Instruction *, 2, DepType> InstTypePair;
		typedef std::pair<InstTypePair, const BasicBlock *> Dep;
		typedef SmallSetVector<Dep, 4> DepSet;
		typedef DenseMap<const Instruction *, DepSet> DepSetMap;
		DepSetMap Deps;
	private:

		static InstTypePair getInstTypePair(MemDepResult dep) {
			if (dep.isClobber())
				return InstTypePair(dep.getInst(), Clobber);
			if (dep.isDef())
				return InstTypePair(dep.getInst(), Def);
			if (dep.isNonFuncLocal())
				return InstTypePair(dep.getInst(), NonFuncLocal);
			assert(dep.isUnknown() && "unexpected dependence type");
			return InstTypePair(dep.getInst(), Unknown);
		}
		LoopInfo *LI;
		DominatorTree *DT;
		AliasAnalysis *AA; //current AliasAnalysis information

		AliasSetTracker * CurAST; //AliasSet information for the current Loop

		SmallVector<Loop*, 32> criticalLoopSet;
		SmallVector<Loop*, 32> pureNonCriticalLoopSet;
		SmallVector<Loop*, 32> halfNonCriticalLoopSet;
		bool IsCriticalPragma(const Loop *L);
		bool getCriticalSet();
		BasicBlock* findHoist(BasicBlock* curBB, std::set<BasicBlock*>* VisitedBB);
		void findDomBBForLoopScalarVariable(Loop *L);
		void findDomBBForLoopMemVariable(Loop *L);
		void findDomBBForLoopAlias(Loop *L);
		Instruction* InstructionForSplitingBB(BasicBlock* PreHeader);
		bool dfs_load_store(User* ValueInst, BasicBlock* parentBB);
		std::set<BasicBlock*> BBset; //dependence block set
		//now starte to build task graph
		std::map< llvm::Loop*, llvm::BasicBlock* > LoopHoistTable;
		bool buildTaskGraph(Function &F);
		void removeBackEdge(Loop* L, taskGraph *TG);
		void mergeNonCriticalNodes(taskGraph *TG);
	};
}

char IdentifyCriticalLoop::ID = 0;
static RegisterPass<IdentifyCriticalLoop> X("identifyCriticalLoop", "Identify critical loop pass", false, false);

bool IdentifyCriticalLoop::getCriticalSet(){
	SmallVector<Loop*, 32> nonCriticalLoopSet;
	//first, use dfs to get the critical loop sets.
	for(Loop *TopLevelLoop : *LI) {
		for(Loop *L: depth_first(TopLevelLoop)){
			//if there is no loop preheader, stay out of trouble
			if(! L->isLoopSimplifyForm()) {
				errs() << "Loop " << L->getName() << "has no loop header" << '\n';
				return false;
			}
			if(IsCriticalPragma(L)) criticalLoopSet.push_back(L);
		}
	}
	//for all loops, if it is not contained in critical loop, it is a noncritical loop
	if(criticalLoopSet.empty())return false;
	for(Loop *TopLevelLoop : *LI){
		for(Loop* L: depth_first(TopLevelLoop)){
			bool skip = false;
			for(Loop* CL : criticalLoopSet){
				if(CL->contains(L) | (CL == L)) {skip = true;break;}
			}
			if(!skip)
				nonCriticalLoopSet.push_back(L);
		}
	}
	//for all non critical loops, if it does not contain critical loop, it is a pure non-critical loop
	for(Loop *NCL : nonCriticalLoopSet){
		bool pure = true;
		for(Loop *CL : criticalLoopSet){
			if(NCL->contains(CL)){pure = false; break;} 
		}
		if(pure) pureNonCriticalLoopSet.push_back(NCL);
		else halfNonCriticalLoopSet.push_back(NCL);
	}
	return true;
}

//identify whether this loop is has metadata "llvm.loop.critical"
bool IdentifyCriticalLoop:: IsCriticalPragma(const Loop *L){
  if(MDNode *LoopID = L->getLoopID())
    if(GetUnrollMetadata(LoopID, "llvm.loop.critical")) return true;
  return false;
}


//find the latest basic block the scalar variable in this loop depends on.
void IdentifyCriticalLoop::findDomBBForLoopScalarVariable(Loop *L){
	//for each instruction in all basic blocks in the loop, try to get the value(def) for the use variables. if this value is outside of loop, and it properly dominates the preheader, it is a hoist candidate.
	for(auto *BB : L->blocks()){
		for(auto &I : BB->getInstList()){
			for(Use &U : I.operands()){
				Value *V = U.get();
				//If it is a constant, pass, if it is instruction, get the parent BB, if it is a BB, return itself.
				//FIXME: here I assume the value can only be one of three types: Instruction, BasicBlock or Constant. May need to extend to more
				Instruction* II = dyn_cast<Instruction>(V);
				BasicBlock* BB = dyn_cast<BasicBlock>(V);
				Constant* CC = dyn_cast<Constant>(V);
				assert((II ||  BB || CC) && "the use has not value(def), something is wrong");
				BasicBlock *defBB = BB;
				if(II) defBB = II->getParent();
				//if this is the def BB and it is properly dominates L, it is candidate 
				if(DT->properlyDominates(defBB, L->getLoopPreheader())){
					BBset.insert(defBB);
				}
			}
		}
	}
}

//for each critical loop, for each instruction in that loop, if it is an array instruction
//find the aliasset,
//for each instruction in that set, if it is in the same loop, then ignore
//else push the basic block to the BBset?
//
void IdentifyCriticalLoop::findDomBBForLoopAlias(Loop *L){
	for(auto *BB : L->blocks()){
		for(auto &I : BB->getInstList()){
			uint64_t Size = 0;
			if (I.getType()->isSized())
				Size = I.getModule()->getDataLayout().getTypeStoreSize(I.getType()); 
			AAMDNodes AAInfo;
			I.getAAMetadata(AAInfo);
			if(isa<GetElementPtrInst>(I)){
				AliasSet* AS = CurAST->getAliasSetForPointerIfExists (dyn_cast<Value>(&I), Size, AAInfo);
				AliasSet::iterator I = AS->begin();
				AliasSet::iterator E = AS->end();
				for(; I != E; ++I){
					BasicBlock* BB = dyn_cast<Instruction>(I.getPointer())->getParent(); 
					if(L->contains(BB)) continue;
					//errs() << "does not contain\n" ;
					BBset.insert(BB);
				}
			}
		}
	}
}


void IdentifyCriticalLoop::findDomBBForLoopMemVariable(Loop *L){
	MemoryDependenceResults &MDA = getAnalysis<MemoryDependenceWrapperPass>().getMemDep();
	for(auto *BB : L->blocks()){
		for(auto &I : BB->getInstList()){
			Instruction *Inst = &I;
			//if the instruction is not a read/write inst, or it is local(within the block), then continue
			if(!Inst->mayReadFromMemory() && !Inst->mayWriteToMemory())
				continue;
			if(isa<StoreInst>(Inst)) continue;
			MemDepResult Res = MDA.getDependency(Inst);
			//FIXME: currently, only consider RAW 
			if(!Res.isNonLocal()) continue;
			if(auto CS= CallSite(Inst)){
				const MemoryDependenceResults::NonLocalDepInfo &NLDI = MDA.getNonLocalCallDependency(CS);
				DepSet &InstDeps = Deps[Inst];
				bool changed = false; //if it is a dict item only with the key, then remove it later.
				for (MemoryDependenceResults::NonLocalDepInfo::const_iterator
				  I = NLDI.begin(), E = NLDI.end(); I != E; ++I) {
				  	if(L->contains(I->getBB())) continue; //if the dependence is in the L, then ignore
				  	const MemDepResult &Res = I->getResult();
				  	if(isa<LoadInst>(Res.getInst())) continue; //ignore RAR
				  	InstDeps.insert(std::make_pair(getInstTypePair(Res), I->getBB()));
				  	BBset.insert(I->getBB());
				  	changed = true;
				}
				if(!changed) Deps.erase(Inst);
			} else {
				SmallVector<NonLocalDepResult, 4> NLDI;
				assert( (isa<LoadInst>(Inst) || isa<StoreInst>(Inst) ||
					  isa<VAArgInst>(Inst)) && "Unknown memory instruction!"); 
				MDA.getNonLocalPointerDependency(Inst, NLDI);

				DepSet &InstDeps = Deps[Inst];
				bool changed = false;
				for (SmallVectorImpl<NonLocalDepResult>::const_iterator
				  I = NLDI.begin(), E = NLDI.end(); I != E; ++I) {
				  	if(L->contains(I->getBB())) continue; //if the dependence is in the L, then ignore
				  	const MemDepResult &Res = I->getResult();
				  	if(isa<LoadInst>(Res.getInst())) continue; //ignore RAR
				  	InstDeps.insert(std::make_pair(getInstTypePair(Res), I->getBB()));
				  	BBset.insert(I->getBB());
				  	changed = true;
				}
				if(!changed) Deps.erase(Inst);
			}
			DepSetMap::const_iterator DSMI = Deps.find(Inst);
			if(DSMI == Deps.end()) continue;
		}
	}
}

/*
 * Find the earliest hoistable module given the current basic block;
 * if curBB is in the dependent set, then it is a true dependency, return curBB;
 * else if curBB has unique predecessor, the recursively call the function on the predecessor
 * else if curBB has multiple predecessors, for each predecessor, call the function, if the hoist BB are different, means more than one branch L is depended on, so we can not hoist. Otherwise, recursively call the function on the common predecessor.
 * Be careful about loops, you dont want to be in inf loop, and you need to identify backedge
 */

BasicBlock* IdentifyCriticalLoop::findHoist(BasicBlock* curBB, std::set<BasicBlock*> *VisitedBB){
	//VisitedBB is a set keeps the blocks we have seen before, so, if a block is in the set, it should be in the loop. 
	//More importantly, the curBB is NOT depended on the loop, so we can jump to the preheader, this prevents infinite loop in our algo
	if(VisitedBB->find(curBB) != VisitedBB->end()) {
		Loop* L = LI->getLoopFor(curBB);
		assert(L && "block should be in a loop?!");
		BasicBlock* preH = L->getLoopPreheader();
		VisitedBB->insert(curBB);
		return findHoist(preH, VisitedBB);
	}
	//Everytime when we really return a curBB, we want to clear the VisitBB set, because we dont want to count in the visiting the same BB from different forwarding branches, this is only for the loop
	//If the curBB is in the dependent set, then return itself, there is no further hoisting.
	if(BBset.find(curBB) != BBset.end()){ VisitedBB->clear(); 
		//errs() << "hositing\n";
		//curBB->dump();
		return curBB;
	}
	//if curBB is not in the dependent set, and it has unique predecessor, recursively call findHoist() on the predecessor
	if(curBB->getUniquePredecessor()) {VisitedBB->insert(curBB); return findHoist(curBB->getUniquePredecessor(), VisitedBB);}
	//otherwise, curBB is not in the dependent set, and it has multiple predecessors, two situations:
	//(1) if one predecesor is in the back edges (the curBB is dominating the predecessor), if that is the only other edge, then we can safely go to the other predecessor,which should be the preheader, and recursively call findHoist()
	pred_iterator PI = pred_begin(curBB), E = pred_end(curBB);
	for(; PI != E; PI++){
		//(2) else, it is a forwarding branch and some branches is depended by curBB, so we stop hoisting and return curBB;
		return findHoist(*PI, VisitedBB);
	}
	//otherwise, both predecessors are not depended by curBB, for each of the predecessor, we recursively call findHoist. Two situations:
	//(1) if in one path there is a dependent BB, we return curBB;
	//(2) if all path finally merge to a common ancestor, then recursively call findHoist() on the ancesstor.
	PI = pred_begin(curBB);
	VisitedBB->insert(*PI);
	BasicBlock* curFound = findHoist(*PI, VisitedBB);
	PI++;
	for(; PI !=E; PI++){
		VisitedBB->insert(*PI);
		BasicBlock* curFound2 = findHoist(*PI, VisitedBB);
		if (curFound != curFound2) {VisitedBB->clear(); return curBB;}
	}
	VisitedBB->insert(curFound);
	return findHoist(curFound, VisitedBB);
}

/*
 * build task graph
 */

//add all the edges to one node, this is used when we want to merge two nodes.
void taskGraph::MergeEdgesToNode(Vertex* ParentNode, Vertices* ConnnectedNode, bool isSucc){
	VerticesItr itrs = ConnnectedNode->begin();
	VerticesItr itre = ConnnectedNode->end();
	//errs() << (*itrs)->getBB()->getName() <<'\n';
	//errs() << ConnnectedNode->size() << '\n';
	for(; itrs != itre; ++itrs){
		if((*itrs) != ParentNode){
			if(isSucc){
				ParentNode->add_succ(*itrs);
			} else {
				ParentNode->add_pred(*itrs);
			}
		} 
	}
}

/*
 * Merge two nodes into one, put all edges from fromNode to toNode
 */
void taskGraph::mergeTwoNodes(Vertex* fromNode, Vertex* toNode){

	//errs() << "fromNode " << fromNode->getBB()->getName() << " address is " << fromNode << '\n';
	//errs() << "toNode " << toNode->getBB()->getName() << " address is " << toNode << '\n';

	toNode -> acc_effLatHw(fromNode->get_effLatHw());
	toNode -> acc_effLatSw(fromNode->get_effLatSw());
	toNode -> setDupNode(fromNode->getDupNode());
	int BRAM = 0;
	int DSP = 0;
	int LUT = 0;
	int FF = 0;
	fromNode->getArea(&BRAM, &DSP, &FF, &LUT);
	toNode -> acc_area(BRAM, DSP, FF, LUT);
	toNode -> acc_powerHw(fromNode->getPowerHw());
	toNode -> acc_powerSw(fromNode->getPowerSw());
	if(fromNode->getInlineNum() != 0)
		toNode -> set_InLineNum(fromNode->getInlineNum());
	Vertices *succs = fromNode->get_succs();
	Vertices *preds = fromNode->get_preds();
	//for all the predecessors of fromNode, delete fromNode in the successor list, and add the toNode to the successor list, if it is not there
	VerticesItr pitrs = preds->begin();
	VerticesItr pitre = preds->end();
	for(; pitrs != pitre; ++pitrs){
		(*pitrs)->get_succs()->erase(fromNode);
		if((*pitrs) != toNode)
			(*pitrs)->get_succs()->insert(toNode);
	}
	//for all the successors of the fromNode, delete fromNode in the predecessor lilst, and add toNode to the predecessor list if it is not there
	VerticesItr sitrs = succs->begin();
	VerticesItr sitre = succs->end();
	for(; sitrs != sitre; ++sitrs){
		(*sitrs)->get_preds()->erase(fromNode);
		if((*sitrs) != toNode)
			(*sitrs)->get_preds()->insert(toNode);
	}
	//add the successors and predecessors of the fromNode to the toNode
	MergeEdgesToNode(toNode, succs, true);
	MergeEdgesToNode(toNode, preds, false);

	vertices_.erase(fromNode);
	bbVerTab.erase(fromNode->getBB());
	if(Leaves.erase(fromNode)) {
		Leaves.insert(toNode);
	}
	if(getRoot() == fromNode){
	  setRoot(toNode);
	}
	//errs() << "fromNode " << fromNode->getBB()->getName() << "address is " << fromNode << '\n';
	//errs() << "toNode " << toNode->getBB()->getName() << "address is " << toNode << '\n';
	delete fromNode;
	//errs() << "about to exit mergeTwoNodes\n";
	//errs() << "after nullify fromNode " << fromNode << '\n';
}

void IdentifyCriticalLoop::mergeNonCriticalNodes(taskGraph *TG){
	Vertex *root = TG->getRoot();
	//everything in the que is a non criticl vertex which needs to process
	std::queue<Vertex*> que;
	que.push(root);
	while(!que.empty()){
		  Vertex* curNode = que.front();
		  Vertices *succs = curNode->get_succs();
		  //if only one successor and not critical, merge
		  if(succs->size() == 0) {que.pop(); continue;}
		  if(succs->size() == 1) {
			  Vertex* succNode = *(succs->begin());
			  if(!succNode->get_critical()) {
				  TG->mergeTwoNodes(succNode, curNode);
				  succs = curNode->get_succs(); //update after merging
			  }
			  else{
				  //if the succNode is critical, pop the curNode, and add in the successors of the critical node to the que, if they are non-critical
				  que.pop();
				  succs = succNode->get_succs();
				  VerticesItr itrs = succs->begin();
				  VerticesItr itre = succs->end();
				  for(; itrs != itre; ++itrs){
					  if((*itrs) ->get_critical()) continue;
					  que.push((*itrs));
				  }
			  }
			  continue;
		  }
		  //if more than one successors, if none of them are critical, merge, else leave the node.
		  bool containCritical = false;
		  VerticesItr sitrs = succs->begin();
		  VerticesItr sitre = succs->end();
		  for(; sitrs != sitre; ++sitrs){
			  Vertex* succNode = *sitrs;
			  if(succNode->get_critical()){
				  containCritical = true;
				  break;
			  }
		  }
		  if(containCritical){
			  sitrs = succs->begin();
			  que.pop();
			  for(; sitrs != sitre; ++sitrs){
				  Vertex* succNode = *sitrs;
				  if(succNode ->get_critical())
					  continue;
				  else que.push(succNode);
			  }
		  } else {
		  	  Vertices tmpSuccs = *succs; //store the successors in tmp, so when merging two nodes, the list of successors are not modified
		  	  VerticesItr tmpsitrs = tmpSuccs.begin();
		  	  VerticesItr tmpsitre = tmpSuccs.end();
		  	  for(; tmpsitrs != tmpsitre; ++tmpsitrs){
		  	  	  Vertex* succNode = *tmpsitrs;
		  	  	  TG->mergeTwoNodes(succNode, curNode);
			  }
		  }
	  }
}

void taskGraph::removeEdge(Vertex *masterNode, Vertex* slaveNode){
	masterNode->get_succs()->erase(slaveNode);
	slaveNode->get_preds()->erase(masterNode);
}

void taskGraph::removeEdge(BasicBlock *masterBB, BasicBlock* slaveBB){
  Vertex *masterNode = bbVerTab.at(masterBB);
  Vertex *slaveNode = bbVerTab.at(slaveBB);
  removeEdge(masterNode, slaveNode);
}

void IdentifyCriticalLoop::removeBackEdge(Loop *L, taskGraph *TG){
	BasicBlock* HeadBB = L->getHeader();
	//errs() << "removeBackEdge, loop header is : " << HeadBB->getName() << '\n';
	assert(L && "The L does not exist in LoopHoistTable. Function removeBackEdge()");
	Vertex* HeadV = TG->getbbVerTab()->at(HeadBB);
	Vertices *HeadPreds = HeadV->get_preds();
	Vertices tmpHeadPreds = *HeadPreds;
	VerticesItr itrs = tmpHeadPreds.begin();
	VerticesItr itre = tmpHeadPreds.end();
	for(; itrs != itre; ++itrs){
		BasicBlock* BB = (*itrs)->getBB();
		if(L->contains(BB)){ //backedge
			TG->removeEdge(BB, HeadBB);
		}
	}
}

bool IdentifyCriticalLoop::buildTaskGraph(Function &F){
	//generate the original task graph, this is identical to the CFG
	//errs() << "starting buildTaskGraph\n";
	taskGraph TG(F, LI);
	errs() << "1 : there are " << TG.numberofNodes() << "\n";
	//errs() << "finishing initialize buildTaskGraph\n";
	//for each of the critical loop L in the criticalLoopSet, merge nodes in task graph
	for(Loop *L: criticalLoopSet){
		//errs() << "current loop :\n";
		//L->dump();
		BasicBlock* toBB = L->getHeader();
		Vertex* toNode = TG.getbbVerTab()->at(toBB);
		for(BasicBlock* BB : L->getBlocks()){
			if(BB == toBB) {//errs() << "equal\n"; 
				continue;
			}
			Vertex* fromNode = TG.getbbVerTab()->at(BB);
			TG.mergeTwoNodes(fromNode, toNode);
		}
		toNode->set_critical(true);
		TG.setMergeNode(L, toNode);
	}
	errs() << "2: there are " << TG.numberofNodes() << "\n";
	//errs() << "finishing merging critical loops \n";
	//then remove all the back edges.
	//for each of the pure Non critical loop, merge nodes in task graph.
	for(Loop *L: pureNonCriticalLoopSet){
		BasicBlock* toBB = L->getHeader();
		if(!TG.bbExist(toBB)){ // the loops is gone
			continue;
		}
		Vertex* toNode = TG.getbbVerTab()->at(toBB);
		for(BasicBlock* BB : L->getBlocks()){
			if(BB == toBB) {//errs() << "equal\n"; 
				continue;
          		}
          		Vertex* fromNode = TG.getbbVerTab()->at(BB);
          		TG.mergeTwoNodes(fromNode, toNode);
          	}
          	toNode->set_critical(false);
          	TG.setMergeNode(L, toNode);
        }
	errs() << "3: there are " << TG.numberofNodes() << "\n";
	//errs() << "finishing merging non loops \n";
        //for each of the half non critical loop, rewind the for.cond -> for end to for.inc->for end. Then remove the back edge.
        for(Loop *L: halfNonCriticalLoopSet){
        	BasicBlock* condBB = L->getExitingBlock();
        	if(condBB == NULL){
        		removeBackEdge(L, &TG);
        		continue;
        	}
        	Vertex* condNode = TG.getbbVerTab()->at(condBB);
        	BasicBlock* exitBB = L->getExitBlock();
        	assert(exitBB && "there is no end block?");
        	Vertex* endNode = TG.getbbVerTab()->at(exitBB);
        	BasicBlock* latchBB = L->getLoopLatch() ;
        	assert(latchBB && "there is no latch block?");
        	Vertex* incNode = TG.getbbVerTab()->at(latchBB);
        	TG.removeEdge(condNode, endNode);
        	TG.addEdge(incNode, endNode);
        	removeBackEdge(L, &TG);
	}
	errs() << "4: there are " << TG.numberofNodes() << "\n";
	//errs() << "finishing merging remove back edges \n";
	//hoist
	std::map<Loop*, BasicBlock*>::iterator hitr = LoopHoistTable.begin();
	std::map<Loop*, BasicBlock*>::iterator hitre = LoopHoistTable.end();
	for(; hitr != hitre; ++hitr){
		Loop* L = hitr->first;
		BasicBlock* BB = hitr->second;
		//L->getLoopPreheader()->dump();
		//BB->dump();
		if(L->getLoopPreheader() != BB){
			TG.Hoisting(L, BB);
		}
	}
	errs() << "5: there are " << TG.numberofNodes() << "\n";
	//errs() << "finishing hoisting \n";
	TG.clear_status();
	TG.simplifyTaskGraph(TG.getRoot());
	TG.clear_status();
	errs() << "6: there are " << TG.numberofNodes() << "\n";
	TG.addDummySink();
	TG.clear_status();
	TG.generateILP();
	errs() << "7: there are " << TG.numberofNodes() << "\n";
	TG.calCriticalLength();
	errs() << "finishing simplifying \n";
	return true;
}


//to add a dummy node as sink, this is used for computing the shortest critical path.
void taskGraph::addDummySink(){
	//errs() << "number of leaves is " << Leaves.size() << "\n";
	Leaves.clear();
	dfsToFindLeaves(root_);
	VerticesItr itrs = Leaves.begin();
	VerticesItr itre = Leaves.end();
	std::cout << "leave size " << Leaves.size() << '\n';
	Vertex* sink = new Vertex(nullptr, 0, 0, 0, 0, 0, 0, 0, 0, 0,curNodeId++, true, false, false, nullptr);
	vertices_.insert(sink);
	for(; itrs != itre; ++itrs){
		addEdge(*itrs, sink);
	}
	sink_ = sink;
}

void taskGraph::dfsToFindLeaves(Vertex* V){
  if(V->get_status() == VISITED) return;
  V->set_status(VISITED);
  auto succs = V->get_succs();
  if(succs->empty()){
    Leaves.insert(V);
  }
  VerticesItr sitrs = succs->begin();
  for(; sitrs != succs->end(); ++sitrs){
    dfsToFindLeaves(*sitrs);
  }
}


//Traverse the graph using reverse order from leaves to root, assign the stamps.
//(1) for each of the predecessor, if it is not a critical node, 
//(2) if the predecessor is a critical node
void taskGraph::generateILP(){
	clear_status();
	std::ofstream f;
	std::ofstream f1;
	//first, generate the sv
	f.open ("myfile.txt");
	f1.open("nodeInfo.txt");
	if(f == NULL) {perror("Error opening file"); return;}
	if(f1 == NULL) {perror("Error opening file"); return;}
	rev_dfs(sink_, f, f1);
	clear_status();
	f.close();
	f1.close();
}

//reverse dfs from leave to the root.
void taskGraph::rev_dfs(Vertex* V, std::ofstream &f, std::ofstream &f1){
	//mark v as explored
	V->set_status(VISITED);

	int LUT, BRAM, DSP, FF;
	V->getArea(&BRAM, &DSP, &FF, &LUT);
	//1. print out the information for generating area and energy constraints
	f1 << V->getID() << "\t";
	f1 << V->get_critical() << "\t";
	f1 << V->getHasShadow() << "\t";
	f1 << V->getIsShadow() << "\t";
	f1 << V->get_effLatSw() << "\t";
	f1 << V->get_effLatHw() << "\t";
	f1 << V->getPowerSw() << "\t";
	f1 << V->getPowerHw() << "\t";
	f1<< BRAM << "\t" << DSP << "\t" << FF << "\t" << LUT << "\t";
	f1 << V->getInlineNum() << "\t";
	if(V->getIsShadow())
		f1 << V->getDupNode()->getID();
	else f1 << 0;
	f1 << '\n';

	//2. print out the informatino for generating sv constraints.
	VerticesItr itrs = V-> get_preds()->begin();
	VerticesItr itre = V-> get_preds()->end();
	for(; itrs != itre; ++itrs){
		Vertex* pred = *itrs;
		bool isCritical = pred->get_critical(); 
		bool isShadow = pred->getIsShadow();
		bool hasShadow = pred->getHasShadow();
		f << V->getID() << "\t";
		f << pred->getID() << '\t';
		f << isCritical << '\t';
		f << hasShadow << '\t';
		f << isShadow << '\t';
		f << "1\t";
		f << pred->get_effLatSw() << '\t';
		f << pred->get_effLatHw() << '\t';
		if(pred->getIsShadow())
			f << pred->getDupNode()->getID();
		else f << 0;
		f << '\n';

		if(pred->get_status() == VISITED) continue;
		rev_dfs(pred, f, f1);
	}
}

bool taskGraph::predContainCritical(Vertex *V){
	//Vertices　*preds = V->get_preds();
	//VerticesItr itrs = preds->begin();
	//VerticesItr itre = preds->end();
	Vertices *preds = V->get_preds();
	VerticesItr itrs = preds->begin();
	VerticesItr itre = preds->end();
	for(; itrs != itre; ++itrs){
		if((*itrs)->get_critical()){
			return true;
		}
	}
	return false;
}
//simplify the task graph in post order.
/*
bool taskGraph::simplifyTaskGraph(Vertex* V){
	if(V->get_status() == VISITED) return mergeableTable[V];
	V->set_status(VISITED);
	//errs() << "enter simplifyTaskGraph\n";
	//if current node is critical, 
	if(!vertices_contain(V)) {
		//errs() << "does not contain!, true\n";
		mergeableTable[V] = true;
		return true;
	}
	//errs() << "current node is " << V->getBB()->getName() << '\n';
	Vertices succs = V->get_succ_copies();
	if(succs.empty()){
		//errs() << "leaves!\n";
		Leaves.insert(V);
		if(V->get_critical()) {
		  //errs() << "critical " << V->getBB() ->getName() << " the current node is " << V->getBB()->getName() <<  " exit simplifyTaskGraph\n, False";
		  mergeableTable[V] = false;
		  return false;
		}
		if(predContainCritical(V)) {
			//errs() << "pred contain Critical , false\n"; 
			mergeableTable[V] = false;
			return false;}
		//errs() << V->getBB()->getName()<< "exit simplifyTaskGraph, true\n";
		mergeableTable[V] = true;
		return true;
	}
	if(V->get_critical()){
		//errs() << "critical " << V->getBB() ->getName() << " exit simplifyTaskGraph\n";
		Vertices succs = V->get_succ_copies();
		VerticesItr sitrs = succs.begin();
		VerticesItr sitre = succs.end();
		for(; sitrs != sitre; ++sitrs){
			//errs() << "the successor " << (*sitrs)->getBB()->getName() << '\n';
			simplifyTaskGraph(*sitrs);
		}
		//errs() << V->getBB()->getName()<< "exit simplifyTaskGraph, false \n";
		mergeableTable[V] = false;
		return false;
	}
	//if current node has one or more successors
	//errs() << "has successors!\n";
	bool mergable = true;
	succs = V->get_succ_copies();
	VerticesItr sitrs = succs.begin();
	VerticesItr sitre = succs.end();
	for(; sitrs != sitre; ++sitrs){
		//errs() << "the successor " << (*sitrs)->getBB()->getName() << '\n';
		mergable = simplifyTaskGraph(*sitrs) & mergable;
	} 
	//errs() << "mergable " << mergable << '\n';
	if(mergable){
		Vertices succs = V->get_succ_copies();
		VerticesItr sitrs = succs.begin();
		VerticesItr sitre = succs.end();
		sitrs = succs.begin();
		for(; sitrs != sitre; ++sitrs){
			mergable &= mergeableTable[(*sitrs)];
		}
	}
	if(mergable){
		Vertices succs = V->get_succ_copies();
		VerticesItr sitrs = succs.begin();
		VerticesItr sitre = succs.end();
		sitrs = succs.begin();
		for(; sitrs != sitre; ++sitrs){
			mergeTwoNodes(*sitrs, V);
		}
	}
	//errs() << V->getBB()->getName()<< "exit simplifyTaskGraph\n";
	if(predContainCritical(V)) {
		//errs() << "contain, false \n";
		mergeableTable[V] = false;
		return false;}
	//errs() << "does not contain, true\n";
	mergeableTable[V] = true;
	return true;
}
*/

//if two nodes only have 1 predecessor and 1 successor, then merge
bool taskGraph::simplifyTaskGraph(Vertex* V){
	if(V->get_status() == VISITED) return false;
	V->set_status(VISITED);
	Vertices succs = V->get_succ_copies();
	if(succs.empty()){
		Leaves.insert(V);
		return false;
	}
	if(V->get_critical()){
		VerticesItr sitrs = succs.begin();
		VerticesItr sitre = succs.end();
		for(; sitrs != sitre; ++sitrs){
			//errs() << "the successor " << (*sitrs)->getBB()->getName() << '\n';
			simplifyTaskGraph(*sitrs);
		}
		return false;
	}
	if(succs.size() == 1){
		Vertex* succNode = *(succs.begin());
		Vertices preds = succNode->get_preds_copies();
		if(preds.size() == 1 && (*preds.begin())->get_critical() == false && (succNode->get_critical()==false)){
			std::cout << "eff_lat_sw of from Node " << V->get_effLatSw() << " eff_latSw from to Node " << succNode->get_effLatSw() << '\n';
			mergeTwoNodes(V, succNode);
			std::cout << "after merging, eff_latSw from to Node " << succNode->get_effLatSw() << '\n';
		}
		simplifyTaskGraph(succNode);
		return false;
	}
	else{
		VerticesItr sitrs = succs.begin();
		VerticesItr sitre = succs.end();
		for(; sitrs != sitre; ++sitrs){
			//errs() << "the successor " << (*sitrs)->getBB()->getName() << '\n';
			simplifyTaskGraph(*sitrs);
		}
		return false;
	}
}



//for each critical Loop which needs to be hoisted, hoist it to the correspoinding node, for all the predecessors of the original loop merged node, we copy a new node from it, and for the new node, we set its predecessor as the hoistToB, and the successors are the successors of the original loop merged node.
void taskGraph::Hoisting(Loop* L, BasicBlock* hoistToB){
	//hoistToB->dump();
	Vertex* hoistToV = bbVerTab.at(hoistToB);
	Vertex* HeaderV = getMergeNode(L);
	Vertex* shadowV = deepCopyVertex(HeaderV);
	shadowV -> set_isShadow(true);
	shadowV -> set_hasShadow(true);
	shadowV -> setDupNode(HeaderV);
	HeaderV->set_hasShadow(true);
	HeaderV->set_isShadow(false);
	HeaderV->setDupNode(shadowV);
	addEdge(hoistToV, shadowV);
	Vertices *succs = HeaderV->get_succs();
	VerticesItr itrs = succs->begin();
	VerticesItr itre = succs->end();
	for(; itrs != itre; ++itrs){
		addEdge(shadowV, *itrs);
	}
}


bool IdentifyCriticalLoop::runOnFunction(Function &F){
	if(F.isDeclaration()) return false;
	LI = &getAnalysis<LoopInfoWrapperPass>().getLoopInfo();
	AA = &getAnalysis<AAResultsWrapperPass>().getAAResults();
	DT = &getAnalysis<DominatorTreeWrapperPass>().getDomTree();

	criticalLoopSet.clear();
	pureNonCriticalLoopSet.clear();
	halfNonCriticalLoopSet.clear(); 
	//1. identify criticalLoops, push them to criticalLoopSet
	if(!getCriticalSet()) {
		//errs() << "this function has no critical loops. \n";
		return false;
	} 
	errs() << "Processing function: " << F.getName() << '\n';
	errs() << "There are(is) " << criticalLoopSet.size() << " critical loops \n";
	CurAST = new AliasSetTracker(*AA);
	for(inst_iterator I = inst_begin(F), E = inst_end(F); I != E; ++I){
		CurAST->add(&*I);
	}
	//errs() << "before build the graph" << '\n';
	for(Loop * L : criticalLoopSet){
		BBset.clear();

		findDomBBForLoopScalarVariable(L);
		findDomBBForLoopAlias(L);
		findDomBBForLoopMemVariable(L);
		std::set<BasicBlock*> VisitedBB;
		BasicBlock *HBB =findHoist(L->getLoopPreheader(), &VisitedBB);
		Loop* tmpL = LI->getLoopFor(HBB);
		//if the found HBB is in the another critical loop, move the hoist bb to the exit block of that critical loop.
		if(tmpL){
			bool skip = false;
			for( Loop *LL : criticalLoopSet){
				if(LL == L ) continue;
				if(LL->contains(tmpL)){ 
					SmallVector< BasicBlock* , 16 > ExitBlocks;
					//errs() << "blabla\n";
					LL->getExitBlocks(ExitBlocks); 
					//for(BasicBlock* BB : ExitBlocks){
					//	BB->dump();
					//}
					HBB = ExitBlocks[0];
					skip = true;
					break;
				}
			}
			//else if HBB is does not contain L either, then it is a pure non critical loop, it is going to be merged, so put the HBB to the exit block of the non critical loop
			if(!skip && !tmpL->contains(L)) {
				//errs() << "blablaa\n";
				HBB = tmpL->getExitBlock();
			}
			//if the HBB is the loop preheader of the current loop, no need to hoist.
			if(HBB == L->getLoopPreheader()) continue;
		}
		LoopHoistTable[L] = HBB;
	}
	//errs() << "right before build the graph" << '\n';
	buildTaskGraph(F);
	//errs() << "after build the graph" << '\n';
	delete CurAST ;

	return false;
}

/*****************************************************
 * * task graph functions
 * ******************************************************/

/*allocate a new vertex in the graph*/
Vertex* taskGraph::allocateVertex(Function &F, BasicBlock *BB){
	BranchProbabilityInfo BPI(F, *LI_);
	BlockFrequencyInfo BFI(F, BPI, *LI_);
	double latencyHw = 0;
	double latencySw = 0;
	double powerHw = 0;
	double powerSw = 0;
	int BRAM = 0;
	int DSP = 0;
	int LUT = 0;
	int FF = 0;
	int inLineNum = 0;
	getAttrfromBB(BB, &latencyHw, &latencySw, &powerHw, &powerSw, &BRAM, &DSP, &FF, &LUT, &inLineNum);
	double bfreq = (double)(BFI.getBlockFreq(BB).getFrequency());
	unsigned loopDepth = LI_->getLoopDepth(BB);
	if(loopDepth == 0) bfreq = bfreq;
	else if(loopDepth == 1) bfreq = base_freq;
	else{
	  BasicBlock* hbb = LI_->getLoopFor(BB)->getHeader();
	  //double bf = (double)(BFI.getBlockFreq(hbb).getFrequency());
	  BasicBlock* hbb2 = LI_->getLoopFor(hbb)->getHeader();
	  bfreq = (double)(BFI.getBlockFreq(hbb2).getFrequency());
	}
	/*if(loopDepth != 0) {
	  errs() << "bfreq of header " << hbb->getName() << " is " <<BFI.getBlockFreq(hbb).getFrequency() << "\n";
	}*/
	//else if(loopDepth == 1) bfreq = 1;
	//else{
	 // l1 = getLoopFor(getLoopFor(BB)->
	//}
	bfreq = bfreq / base_freq;
//	errs() << "bfreq of " << BB->getName() << " is " << bfreq << "\n";
	double eff_latHw = latencyHw * bfreq;
	double eff_latSw = latencySw * bfreq;
	Vertex *node = new Vertex(BB, eff_latHw, eff_latSw, powerHw, powerSw, BRAM, DSP, FF, LUT, inLineNum, curNodeId++, false, false, false, nullptr );
	bbVerTab[BB] = node;
	vertices_.insert(node);
	return node;
}

//check whether there is store lat, power, area information, given a basic block, traverse the instructions 
void taskGraph::getAttrfromBB(BasicBlock * BB, double *latencyHw, double *latencySw, double *powerHw, double *powerSw, int *BRAM, int *DSP, int *FF, int *LUT, int *inLineNum){
	for(Instruction &I : BB->getInstList()){
		//first, whether it is a store instruction
		if(isa<StoreInst>(I)){   
			//second, whether it is a power, latency or area assignment
			StringRef SR = I.getOperand(1)->getName();
			bool IsInLineNum = SR.startswith(StringRef("InLine"));
			bool IsLatHw = SR.startswith(StringRef("lat_hw"));
			bool IsLatSw = SR.startswith(StringRef("lat_sw"));
			bool IsPowHw = SR.startswith(StringRef("power_hw"));
			bool IsPowSw = SR.startswith(StringRef("power_sw"));
			bool IsBRAM = SR.startswith(StringRef("BRAM"));
			bool IsDSP = SR.startswith(StringRef("DSP"));
			bool IsFF = SR.startswith(StringRef("FF"));
			bool IsLUT = SR.startswith(StringRef("LUT"));
			if(IsInLineNum || IsBRAM || IsDSP || IsFF || IsLUT){
				ConstantInt* INTC = dyn_cast<ConstantInt>(I.getOperand(0));
				assert(INTC && "no data assigned to inLineNum");
				int numIntC = INTC->getSExtValue();
				if(IsInLineNum) *inLineNum = numIntC;
				else if(IsBRAM) *BRAM = numIntC;
				else if(IsDSP) *DSP = numIntC;
				else if(IsLUT) *LUT = numIntC;
				else *FF = numIntC;
			}
			if(IsLatHw || IsLatSw || IsPowHw || IsPowSw){
				//if it is, then there should be a double number assigned for this variable
				ConstantFP* FPC = dyn_cast<ConstantFP>(I.getOperand(0));
				assert(FPC && "no data assigned to the latency, power or area");
				double numberFPC = FPC->getValueAPF().convertToDouble();
				if(IsLatHw) *latencyHw = numberFPC;
				else if(IsLatSw) *latencySw = numberFPC;
				else if(IsPowSw) *powerSw = numberFPC;
				else *powerHw = numberFPC;
			}
		}
	}
}

/*
 * add a directed edge from fromNode to to Node
 */ 
void taskGraph::addEdge(Vertex* fromNode, Vertex* toNode){
	fromNode->add_succ(toNode);
	toNode->add_pred(fromNode);
}

/*Constructor: BFS to generate the task graph:
 * the original task graph should be identical to the CFG (later simplification would be applied),
 * following things need to be done
 * starting from the entry basic block of the function, push it to a FIFO (que),  
 * for each BB in the que, allocate a vertex, and push it to the bbVerTable together into the que. Then traverse its successors, if it is not in bbVerTab, which means we haven't created a vertex for it yet, we create the vertex.
 * */


taskGraph::taskGraph(llvm::Function &F, llvm::LoopInfo *LI){
	total_BRAM_ = 0;
	total_LUT_ = 0;
	total_DSP_ = 0;
	total_FF_ = 0;
	totalEnergy_ = 0;
	totalLat_ = 0;
	curNodeId = 0;
	LI_ = LI;
	std::queue<BasicBlock*> que;
	BasicBlock* curBB = &(F.getEntryBlock());
	que.push(curBB);
	BranchProbabilityInfo BPI(F, *LI_);
	BlockFrequencyInfo BFI(F, BPI, *LI_);
	base_freq = (double)(BFI.getBlockFreq(curBB).getFrequency());
	root_ = allocateVertex(F, curBB);
      
	while(!que.empty()){
		curBB = que.front();
		que.pop();
		Vertex* parentNode = bbVerTab.at(curBB);
		//edges, for each successor, we allocated the vertex if needed, and add edges for the successor and predecessor
		succ_iterator SI = succ_begin(curBB), SE = succ_end(curBB);
		for(; SI != SE; ++SI){
			BasicBlock *childBB = *SI;
			BBVertexTable::iterator bitr = bbVerTab.find(childBB);
			Vertex* childNode = NULL;
			if(bitr == bbVerTab.end()){
				que.push(childBB);
				childNode = allocateVertex(F, childBB);
			} else childNode = bitr->second;
			addEdge(parentNode, childNode);
      		}
      	}
}

Vertex* taskGraph::deepCopyVertex(Vertex *V){
	BasicBlock* BB = V->getBB();
	double latencyHw = V->get_effLatHw();
	double latencySw = V->get_effLatHw();
	int BRAM = 0;
	int DSP = 0;
	int LUT = 0;
	int FF = 0;
	V->getArea(&BRAM, &DSP, &FF, &LUT);
	double powerHw = V->getPowerHw();
	double powerSw = V->getPowerSw();
	int inLineNum = V->getInlineNum();
	bool critical = V->get_critical();
	bool isSink = V->getSink();
	bool isShadow = V->getIsShadow();
	bool hasShadow = V->getHasShadow();
	Vertex* dupNode = V->getDupNode();
  Vertex *node = new Vertex(BB, latencyHw, latencySw, powerHw, powerSw, BRAM, DSP, FF, LUT, inLineNum, curNodeId++,isSink, hasShadow, isShadow, dupNode, critical);
  vertices_.insert(node);
  return node;
}

void taskGraph::clear_status(){
  VerticesItr itr = vertices_.begin();
  VerticesItr itre = vertices_.end();
  for(; itr != itre; ++itr){
    (*itr)->set_status(NOT_VISITED);
  }
}

//FIXME: This is WRONG :-(((((
//calculate the critical length and the associated area and power , using BFS
void taskGraph::calCriticalLength(){
	int total_BRAM = 0;
	int total_DSP = 0;
	int total_FF = 0;
	int total_LUT = 0;
	double totalEnergy = 0;
	double totalLat = 0;
	std::queue<Vertex*> que;
	que.push(root_);
	root_->set_status(VISITED);
	root_->set_stamp(0);
	while(!que.empty()){
		Vertex* curNode = que.front();
		que.pop();
		double effLatHw = curNode->get_effLatHw();
		bool maptoSw = (effLatHw == 0) ;
		double power = maptoSw ? curNode->getPowerSw() : curNode->getPowerHw();
		int BRAM = 0;
		int DSP = 0;
		int LUT = 0;
		int FF = 0;
		if(!maptoSw) {
			curNode->getArea(&BRAM, &DSP, &FF, &LUT);
		}
		double lat = maptoSw ? curNode->get_effLatSw() : curNode->get_effLatHw();
		double finishTime = curNode->get_stamp() + lat;
		total_BRAM += BRAM;
		total_DSP += DSP;
		total_FF += FF;
		total_LUT += LUT;
		totalEnergy += power * lat; 
		Vertices *adjNodes = curNode->get_succs();
		VerticesItr itrs = adjNodes->begin();
		VerticesItr itre = adjNodes->end();
		for(; itrs != itre; ++itrs){
			if((*itrs)->get_stamp() <= finishTime){
				(*itrs)->set_stamp(finishTime);
			}
			if((*itrs)->get_status() == VISITED) continue;
			que.push(*itrs);
			(*itrs)->set_status(VISITED);
		}
	}
	totalLat = sink_->get_stamp();
	clear_status();
	total_BRAM_ = total_BRAM;
	total_DSP_ = total_DSP;
	total_FF_ = total_FF;
	total_LUT_ = total_LUT;
	totalEnergy_ = totalEnergy;
	totalLat_ = totalLat;
	std::ofstream f;
	f.open ("criticalPLA.txt");
	f << totalLat_ << "\t" << totalEnergy_ << "\t" << total_BRAM_ << "\t" << total_DSP_ << "\t" << total_FF_ << "\t" << total_LUT_ << "\t" << '\n';
	f.close();
}

//this is for debugging
void taskGraph::printEdges(BasicBlock *BB){
  errs() << "the master node is " << BB->getName() << "\n";
  Vertex* node = bbVerTab.at(BB);
  Vertices *succList = node->get_succs();
  VerticesItr itrs = succList->begin();
  VerticesItr itre = succList->end();
  for(; itrs != itre; itrs++){
    errs() << "the connected node " << (*itrs)->getBB()->getName() << '\t';
  }
}

//this is for debugging, printing all the nodes in the graph, this is BFS
void taskGraph::printNodes(){
  errs() << "\n\nprinting the nodes of the task graph in BFS fashion. \n\n";
  std::queue<Vertex*> que;
  que.push(root_);
  root_->set_status(VISITED);
  while(!que.empty()){
    Vertex* curNode = que.front();
    que.pop();
    if(curNode->getSink()) continue;
    BasicBlock* curBB = getBBforNode(curNode);
    errs() << "current Node is " << curBB->getName()<< " effective hw lat is " << curNode->get_effLatHw()<< " effective sw lat is " << curNode->get_effLatSw() << '\n';
    Vertices *adjNodes = curNode->get_succs();
    VerticesItr itrs = adjNodes->begin();
    VerticesItr itre = adjNodes->end();
    for(; itrs != itre; ++itrs){
      if((*itrs)->get_status() == VISITED) continue;
      que.push(*itrs);
      (*itrs)->set_status(VISITED);
    }
  }
  clear_status();
}

BasicBlock* taskGraph::getBBforNode(Vertex *V){
  return V->getBB();
}

void taskGraph::printSuccessors(Vertex* V){
  BasicBlock *VBB = getBBforNode(V);
  errs() << "printing the successors for " << VBB->getName() << '\n';
  Vertices *succs = V->get_succs();
  VerticesItr sitrs = succs->begin();
  VerticesItr sitre = succs->end();
  for(; sitrs != sitre; ++sitrs){
    BasicBlock* BB = getBBforNode(*sitrs);
    BB->dump();
  }
}

int taskGraph::numberofNodes(){
  return vertices_.size();
}
