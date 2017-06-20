#ifndef SYSTEMC_TRANSFORM_H
#define SYSTEMC_TRANSFORM_H

#include <rose.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

#define SOURCE_POSITION Sg_File_Info::generateDefaultFileInfoForTransformationNode()

static const char* gen_prefix = "scgen__";
static const char* power_config_directory = "power_config";
static const char* thread_id_base = "thread_id_base";

//
// SC_FunctionModule
// this class holds all information relevant to a node
// in our sc_module hierarchy tree. It stores the associated function,
// parameter/member information for the module function, and pointers to children modules,
class SC_FunctionModule
{

public:
	SC_FunctionModule(SgFunctionDeclaration* func, SgScopeStatement* scope, int depth, int looplevel, bool isroot);
	//SC_FunctionModule(SgFunctionDeclaration* func, SgScopeStatement* scope, SgScopeStatement* rootscope, int depth, bool isroot);
	void process(std::vector<int> globalUnrollFactor, bool no_pretile);
	void addToFile();
	SgFunctionDeclaration* modulefunc;
	vector<SgFunctionDeclaration*> modulefuncs;
	SgClassDeclaration* moduleclass;
	vector<string> member_names;
	vector<SgType*> member_types;
	SgType* return_type;
	SgScopeStatement* parentscope;
//	SgScopeStatement* rootscope;

	vector<SC_FunctionModule*> children_functions;
	vector<SgFunctionDeclaration*> children_for_functions;
	vector<int> children_iterations;
	vector<string> children_iterations_str;
	
	vector<SgVarRefExp*>ArrNeedBank;
	vector<SgVarRefExp*>ArrNoNeedBank;
	string latencyVar;
	bool is_root;
	int depth_below_me;
	int loop_level;
	/*
	void ProcessFunctionBody(*SgStatement stmt){
		if(isSgForStatement(stmt)){
			bool needToUnroll = 0;
			SgStatement* loopBody = isSgForStatement(stmt)->get_loop_body();
			SageInterface::addTextForUnparser(loopBody, "wait()", AstUnparseAttribute::e_before);
			vector<SgNode*> children = loopBody->get_traversalSuccessorContainer();
			for(vector<SgNode*>::iterator it1 = children.begin(); it1 != children.end(); it++){
				std::vector<SgNode*> vars = NodeQuery::querySubTree(*it, V_SgVarRefExp);
				for(vector<SgNode*>::iterator it2 = vars.begin(); it2 != vars.end(); it2 ++ ){
					if(find(ArrNeedBank.begin(), ArrNeedBank.end(), isSgVarRefExp(*it2))!=ArrNeedBank.end()){
						needToUnroll = 1;
					}
				}
			}
			if(needToUnroll){
				
			}
			
		}
		if(isSgBasicBlock(*it)){
			
		}
		
	};
	*/
};

SgFunctionDeclaration* findFunctionWithName(SgNode* root, string name);


// used to convert scalar types to a string that can be used to manually insert
// SystemC constructs such as sc_in<T>, sc_out<> sc_signal<>, etc.
// when AST support is added for these template types, typetostring will not be necessary.
string typeToString(SgType* type);


//
// Add arbitrary text next to a node, then remove that node
//
void replaceWithText(SgStatement* stmt, string text, bool before=true);


bool isTopLevelInScope(SgForStatement* forLoop, SgScopeStatement* scope);

// used in processing a module function to see if its children loops can be unrolled
bool canUnroll(SgForStatement* forLoop);

string getForInit(SgForStatement* forLoop);

int getForLimit(SgForStatement* forLoop);

int getForIncrement(SgForStatement* forLoop);

string getForIterator(SgForStatement* forLoop);

bool existsInHigherScope(SgVarRefExp* varRef, SgStatement* scope);

SgFunctionDeclaration* forToFunction(SgForStatement* forLoop, string funcname, SgScopeStatement* scope);

string startModuleTrace(SC_FunctionModule* module, string name);

void fixTestbenchFunction(SgFunctionDeclaration* tbFunc, string target_func_name, SC_FunctionModule* funcModule, SgScopeStatement* scope);

//int TransformToSystemC(SgProject* project, string targetname, string testbenchname, int depth);
int TransformToSystemC(SgProject* project, string targetname, string testbenchname, int depth, std::vector<int> unroll_factors, bool preprocess, bool no_pretile);

bool hasInnerLoop(SgStatement*  stmt){
	if(isSgForStatement(stmt)){
		SgStatement* stmt_for = isSgForStatement(stmt)->get_loop_body();
		if(isSgForStatement(stmt_for)) return true;
		else hasInnerLoop(stmt_for);
	} else if(isSgBasicBlock(stmt)){
		SgStatementPtrList bb = isSgBasicBlock(stmt)->get_statements();
		for(SgStatementPtrList::iterator it = bb.begin(); it != bb.end(); it++){
			if(hasInnerLoop(*it)) return true;
		}
	} else return false;
}

SgStatement* getInnermostLoop(SgStatement* stmt){
	SgStatement* ret_val = stmt;
	if(hasInnerLoop(stmt)){
		if(isSgForStatement(stmt)){
			SgStatement* stmt_for = isSgForStatement(stmt)->get_loop_body(); 
			ret_val = getInnermostLoop(stmt_for);
		}
		else if(isSgBasicBlock(stmt)){
			SgStatementPtrList bb = isSgBasicBlock(stmt)->get_statements();
			for(SgStatementPtrList::iterator it = bb.begin(); it != bb.end(); it++){
				ret_val = getInnermostLoop(*it);
			}
		}

	}
	return  ret_val;
}


#endif
