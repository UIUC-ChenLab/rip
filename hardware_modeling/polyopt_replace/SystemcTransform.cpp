#include <rose.h>
#include <Cxx_Grammar.h>
#include <AstTraversal.h>
#include "string.h"
#include <iostream>
#include <polyopt/SystemcTransform.hpp>

#include <candl/candl.h>
#include <pocc/options.h>
#include <pocc/exec.h>
#include <pocc-utils/options.h>

#include <past/past.h>

#include <polyopt/ScopExtractor.hpp>
#include <polyopt/ClastToSage.hpp>
#include <polyopt/PastToSage.hpp>
#include <polyopt/PoCCOptimize.hpp>
#include <polyopt/PolyRoseOptions.hpp>
#include <polyopt/SageNodeAnnotation.hpp>


using namespace std;
using namespace SageBuilder;
using namespace SageInterface;

std::set<string> tLoops;
std::set<string> canUnrollLoops;

void writeCanUnrollLoops(){
	ofstream myfile(".canunrollLoops");
	if(!myfile.is_open()) cout << "file .canunrollLoops cannot be opened.\n";
	assert(myfile.is_open());
	for(std::set<string>::iterator itr = canUnrollLoops.begin(); itr != canUnrollLoops.end(); ++itr){
		myfile<< (*itr) << endl;
	}
	myfile.close();
}
void setTLoops(){
	string loop;
	string line;
	ifstream myfile(".tiles");
	if(!myfile.is_open()) cout << "file .tiles is not found. \n";
	assert(myfile.is_open());
	while(getline(myfile, line)){
		string subline = line.substr(0, line.find(" "));
		tLoops.insert(subline);
	}
	myfile.close();
}

//using namespace ExtendedNameSpace;

int getIterationBasedTripCount(SgForStatement* fs){
	ROSE_ASSERT(isSgForStatement(fs));
	SageAPForInfo* annot = (SageAPForInfo*)fs -> getAttribute("SageAPForInfo");
	assert(annot != NULL);
	int avg = annot->avgTripCount;
	//printf("average trip count : %d, \n", avg);
	return avg;
}

SgFunctionDeclaration* findFunctionWithName(SgNode* root, string name)
{
	SgFunctionDeclaration* retval;
	std::vector<SgNode*> functions = NodeQuery::querySubTree(root, V_SgFunctionDeclaration);
	for(vector<SgNode*>::iterator it=functions.begin(); it != functions.end(); ++it)
	{
		retval = isSgFunctionDeclaration(*it);
		if(retval && retval->get_name().str()==name)
		{
			if(retval->get_definition())
				return retval;
		}
	}
	return 0;
}

//return (1) a vector of array indices of SgArray (2) the base type of this array
std::pair<std::vector<SgExpression*>, SgType*> getSgArrayDim(SgArrayType* arrtype){
	std::vector<SgExpression*> indices;
	SgType* basetype;
	while(arrtype){
		SgExpression *index = arrtype -> get_index();
		if(index)
			indices.push_back(index);
		else
			cout << "Warning: the index is not a number\n";
		basetype = arrtype -> get_base_type();
		arrtype = isSgArrayType(basetype);
	}
	return std::pair<std::vector<SgExpression*>, SgType*>(indices, basetype);
}

string intToString(int Number){
	string Result;
	ostringstream convert;
	convert << Number;
	Result = convert.str();
	return Result;
}

//The first string is the begining of for loop, the second string is the tabs.
std::pair<string, string>  beginingOfForLoopAndTab(std::vector<SgExpression*> indices, string tab){
	string replaceText ="";
	int idx = 0;
	std::vector<SgExpression*>::iterator itr = indices.begin();
	string tabs = tab;
	for(; itr != indices.end(); ++itr){
		for(int curIt = 0; curIt < idx; curIt ++){
			tabs += tab;
		}
		string idx_str = "it" + intToString(idx);
		string itr_str = (*itr)->unparseToString();
		replaceText = replaceText + tabs + "for(int " + idx_str + "=0; " 
		  + idx_str + "< " + itr_str + "; "
		  + idx_str + "++){\n";
		idx ++;
	}
	return std::pair<string, string>(replaceText, tabs);
}

//get the strings in the format of [i][j]... given the indices.
std::pair<string, int> getTheIndicesStr(std::vector<SgExpression*> indices){
	string indices_str = "";
	int idx =  0;
	std::vector<SgExpression*>::iterator itr = indices.begin();
	for(; itr != indices.end(); ++itr){
		indices_str = indices_str+ "["+"it" +intToString(idx) + "]";
		//indices_str  = indices_str + "["+(*itr)->unparseToString()+"]";
		idx ++;
	}
	return std::pair<string, int> (indices_str, idx);
}

//get the strings of the dimention of the indices, e.g, an array of size MxN, returns [M][N]
string getTheDimStr(std::vector<SgExpression*> indices){
	std::vector<SgExpression*>::iterator itr = indices.begin();
	string replaceText ="";
	for(; itr != indices.end(); ++itr){
		replaceText = replaceText + "[";
		string itr_str = (*itr)->unparseToString();
		replaceText = replaceText + itr_str + "]";
	}
	return replaceText;
}

string EndOfForLoop(int idx, string tab){
	string replaceText = "";
	for(; idx > 0; idx --){
		for(int curIt = idx; curIt > 0; curIt --){
			replaceText =replaceText+ tab;
		}
		replaceText = replaceText +  "}\n";
	}
	return replaceText;
}

// used to convert scalar types to a string that can be used to manually insert
// SystemC constructs such as sc_in<T>, sc_out<> sc_signal<>, etc.
// when AST support is added for these template types, typetostring will not be necessary.
string typeToString(SgType* type)
{
	string ret = "";
	if(type->isUnsignedType())
		ret = "unsigned";
	else if(type->isIntegerType())
		ret = "int";
	else if(type->isFloatType())
		ret = "float";

	return ret;
}

//
// Add arbitrary text next to a node, then remove that node
//
void replaceWithText(SgStatement* stmt, string text, bool before)
{
	SgBasicBlock* bblock = SageBuilder::buildBasicBlock();
	SageInterface::addTextForUnparser(bblock, text, AstUnparseAttribute::e_inside);
	SageInterface::insertStatement(stmt, bblock, before);
	//SageInterface::insertStatement(stmt, bblock);
	SageInterface::removeStatement(stmt);
}



bool isTopLevelInScope(SgForStatement* forLoop, SgScopeStatement* scope)
{
	//yes if this is a top level loop in the provided scope
	SgNode* parent_node = forLoop->get_parent();
	// ignore parent until it's not a basic block
	//printf("ancestors: ");
	while(isSgBasicBlock(parent_node)||(isSgIfStmt(parent_node)))
	{
		//printf("%s, ", parent_node->sage_class_name());
		parent_node = parent_node->get_parent();
	}
	//printf("%s\n", parent_node ? parent_node->sage_class_name() : "0");
	return parent_node == scope;
}

// used in processing a module function to see if its children loops can be unrolled
bool canUnroll(SgForStatement* forLoop)
{

	SageForInfo* annot = (SageForInfo*) forLoop->getAttribute(SageForInfo::name());
	if(annot)
	{
		//there should be at most one ddv because we ran hullify
		if(annot->ddvs.size()>0)
		{
			PolyDDV myddv = annot->ddvs[0];
			//cout << "Print ddvs for next loop:\n";
			//cout << myddv << "\n";
			//cout.flush();
			int ddv_size = myddv.getSize();
			if(ddv_size>0 && !myddv.isEq(ddv_size-1))
				return false;
		}
		else
		{
			cout << "No ddvs for this loop.\n";
		}
	}
	else
	{
		return false;
	}
	return true;
}

//to test whether this loop is tiled loop (contain loop tiles), if it is, then we can try to further unroll, otherwise, stop here. We dont want to unroll a loop tile, that should be the finest granularity.
//
//WEI: FIXME, 
bool tiledLoop(SgForStatement* forLoop, string& ref){
	SgExpression* tmp =  forLoop -> get_increment();
	Rose_STL_Container<SgNode*> varRefs = NodeQuery::querySubTree(tmp, V_SgVarRefExp);
	for(Rose_STL_Container<SgNode*> :: iterator k = varRefs.begin(); k != varRefs.end(); ++k){
		SgVarRefExp* varRef = isSgVarRefExp(*k);
		if(varRef && isSgArrayType(varRef->get_symbol()->get_type())) continue;
		else if(varRef){
			std::string name = varRef->get_symbol()->get_name();
			if (tLoops.find(name) != tLoops.end()){//found tile loop
				ref = name;
				return true;
			}

		}
	}
	return false;
}
//
// Determine the initialization value for the iterator in a for loop.
// this translator currently assumes a very strict loop header format of "for(<varref> = <int>; <varref> <[=] <int>; <varref>++)"
// any other format may cause assertions to fail, or cause incorrect translation
// TODO: support more for loop formats
//
string getForInit(SgForStatement* forLoop)
{
	//int retval = 0;
	//find assignment expression
	SgStatementPtrList statementlist = forLoop->get_init_stmt();
	SgAssignOp* init_expr=0;
	for(SgStatementPtrList::iterator it=statementlist.begin(); it!=statementlist.end(); ++it)
	{
		SgExprStatement* init_expstmt = isSgExprStatement(*it);
		if(init_expstmt)
		{
			init_expr = isSgAssignOp(init_expstmt->get_expression());
			if(init_expr)
				break;
		}
	}
	assert(init_expr);

	// extract value of rhs of assignment
	SgExpression* rhs = init_expr->get_rhs_operand();
	return rhs->unparseToString();
	//assert(isSgIntVal(rhs) || isSgLongIntVal(rhs) || isSgUnsignedIntVal(rhs) || isSgUnsignedLongVal(rhs));

/*	if(isSgIntVal(rhs))
	{
		SgIntVal* intval = isSgIntVal(rhs);
		assert(intval);
		retval = intval->get_value();
	}
	else if(isSgLongIntVal(rhs))
	{
		SgLongIntVal* intval = isSgLongIntVal(rhs);
		assert(intval);
		retval = intval->get_value();
	}
	else if(isSgUnsignedIntVal(rhs))
	{
		SgUnsignedIntVal* intval = isSgUnsignedIntVal(rhs);
		assert(intval);
		retval = intval->get_value();
	}
	else if(isSgUnsignedLongVal(rhs))
	{
		SgUnsignedLongVal* intval = isSgUnsignedLongVal(rhs);
		assert(intval);
		retval = intval->get_value();
	}*/

	//printf("init start is %d\n", retval);
	//return retval;
}

//
// Determine the limit value for the iterator in a for loop.
// this translator currently assumes a very strict loop header format of "for(<varref> = <int>; <varref> <[=] <int>; <varref>++)"
// any other format may cause assertions to fail, or cause incorrect translation
// TODO: support more for loop formats
//
int getForLimit(SgForStatement* forLoop)
{
	// get comparison expression
	int retval=0;
	SgExprStatement* test_stmt = isSgExprStatement(forLoop->get_test());
	assert(test_stmt);
	SgExpression* test_expr = test_stmt->get_expression();

	SgBinaryOp* binop = isSgBinaryOp(test_expr);
	assert(binop && (isSgLessThanOp(binop) || isSgLessOrEqualOp(binop)));

	SgExpression* rhs = binop->get_rhs_operand();
	//cout << "name = " << (*(isSgVarRefExp(rhs))).get_symbol()->get_name() << endl;
	//cout<<(*isSgNode(rhs)).unparseToString();
	bool isInt = (*(*rhs).get_type()).isIntegerType(); 
	bool isUnsigned = (*(*rhs).get_type()).isUnsignedType(); 
//	assert(isSgIntVal(rhs) || isSgLongIntVal(rhs) || isSgUnsignedIntVal(rhs) || isSgUnsignedLongVal(rhs));
	assert(isInt || isUnsigned);

	// extract value of rhs of comparison
	if(isSgIntVal(rhs))
	{
		SgIntVal* intval = isSgIntVal(rhs);
		assert(intval);
		retval = intval->get_value();
	}
	else if(isSgLongIntVal(rhs))
	{
		SgLongIntVal* intval = isSgLongIntVal(rhs);
		assert(intval);
		retval = intval->get_value();
	}
	else if(isSgUnsignedIntVal(rhs))
	{
		SgUnsignedIntVal* intval = isSgUnsignedIntVal(rhs);
		assert(intval);
		retval = intval->get_value();
	}
	else if(isSgUnsignedLongVal(rhs))
	{
		SgUnsignedLongVal* intval = isSgUnsignedLongVal(rhs);
		assert(intval);
		retval = intval->get_value();
	}
	//cout << "retval " << retval << endl;

	if(isSgLessOrEqualOp(binop))
		retval++;

	//printf("test limit is %d\n", retval);
	return retval;
}

//
// Determine the increment value for the iterator in a for loop.
// this translator currently assumes a very strict loop header format of "for(<varref> = <int>; <varref> <[=] <int>; <varref>++)"
// any other format may cause assertions to fail, or cause incorrect translation
// TODO: support more for loop formats
//
int getForIncrement(SgForStatement* forLoop)
{
	return 1;
}

//
// Determine the name of the iterator in a for loop.
// this translator currently assumes a very strict loop header format of "for(<varref> = <int>; <varref> <[=] <int>; <varref>++)"
// any other format may cause assertions to fail, or cause incorrect translation
// TODO: support more for loop formats
//
string getForIterator(SgForStatement* forLoop)
{
	// find assignment expression
	SgStatementPtrList statementlist = forLoop->get_init_stmt();
	SgAssignOp* init_expr=0;
	for(SgStatementPtrList::iterator it=statementlist.begin(); it!=statementlist.end(); ++it)
	{
		SgExprStatement* init_expstmt = isSgExprStatement(*it);
		if(init_expstmt)
		{
			init_expr = isSgAssignOp(init_expstmt->get_expression());
			if(init_expr)
				break;
		}
	}
	assert(init_expr);

	// extract value of lhs of assignment
	SgVarRefExp* varref = isSgVarRefExp(init_expr->get_lhs_operand());
	assert(varref);
	//printf("iterator name is %s\n", string(varref->get_symbol()->get_name()).c_str());
	return varref->get_symbol()->get_name();
}

//
// Returns true if the specified variable reference exists in a scope
// at a higher level than the specified scope. This is used to determine
// whether a variable used in a for loop that is becoming a function needs to be
// a function parameter
bool existsInHigherScope(SgVarRefExp* varRef, SgStatement* scope)
{
	SgNode* checknode = scope->get_parent();
	while(checknode)
	{
		SgScopeStatement* checkscope = isSgScopeStatement(checknode);
		if(checkscope && checkscope->symbol_exists(varRef->get_symbol()))
		{
			return true;
		}
		else if(SgFunctionDeclaration* funcdef = isSgFunctionDeclaration(checknode))
		{
			//SgFunctionParameterList* paramlist = funcdef->get_parameterList();
			 SgInitializedNamePtrList params = funcdef->get_parameterList()->get_args();
			 for(int i=0; i< params.size(); ++i)
			 {
				 SgSymbol* symbol = params[i]->get_symbol_from_symbol_table();
				 assert(symbol);
				 if(symbol->get_name() == varRef->get_symbol()->get_name())
					 return true;
			 }
		}
		checknode=checknode->get_parent();
	}

	return false;
}

//
// Copy the contents of a for loop into a new function
// If any variables are used in the loop that are not defined in the loop,
// make them parameters of the function
SgFunctionDeclaration* forToFunction(SgForStatement* forLoop, string funcname, SgScopeStatement* scope)
{
	SgFunctionParameterList* parameterList = buildFunctionParameterList();
	std::set<string> existingRefs;
	SgStatement* forBody = forLoop->get_loop_body();
	std::vector<SgNode*> varRefs = NodeQuery::querySubTree(forBody, V_SgVarRefExp);
	for(vector<SgNode*>::iterator it=varRefs.begin(); it != varRefs.end(); ++it)
	{
		SgVarRefExp* varRef = isSgVarRefExp(*it);
		//test if this variable was declared outside this loop body by checking whether it exists in a higher scope.
		//if the scope of the variable extends beyond this loop, add it as a parameter to the generated function
		if(varRef && (typeToString(varRef->get_symbol()->get_type())!="" || isSgArrayType(varRef->get_symbol()->get_type()))&& existsInHigherScope(varRef, forLoop->get_loop_body()) )
		{
			//make sure we only add it once
			string refName = varRef->get_symbol()->get_name();
			if(existingRefs.count(refName)==0)
			{
				existingRefs.insert(refName);
				SgInitializedName *param = SageBuilder::buildInitializedName(varRef->get_symbol()->get_name(), varRef->get_symbol()->get_type());
				SageInterface::appendArg(parameterList, param);
			}
		}
	}
	//printf("found %d of %d parameters for %s\n", parameterList->get_args().size(), varRefs.size(), funcname.c_str());

	SgFunctionDeclaration* moduleFunc = SageBuilder::buildDefiningFunctionDeclaration(funcname, SageBuilder::buildVoidType(), parameterList, scope);
	//need to temporarily place it in global scope so it doesn't complain when we call remove later
	SageInterface::appendStatement(moduleFunc, scope);

	SageInterface::appendStatement(forBody, moduleFunc->get_definition());
	//moduleFunc->get_definition()->set_body(SageBuilder::buildBasicBlock(forBody));

	return moduleFunc;
}

SC_FunctionModule::SC_FunctionModule(SgFunctionDeclaration* func, SgScopeStatement* scope, int depth, int looplevel, bool isroot)
: modulefunc(func)
 ,parentscope(scope)
 ,moduleclass(0)
 ,latencyVar("")
 ,depth_below_me(depth)
 ,loop_level(looplevel)
 ,is_root(isroot)
{
}

void SC_FunctionModule::process(std::vector<int> globalUnrollFactor, bool no_pretile)
{
	// sc_module base class for function module inheritances
	static SgClassDeclaration* sc_base_declaration = new SgClassDeclaration(SOURCE_POSITION,
																"sc_module",SgClassDeclaration::e_class,
																NULL,NULL);
	static SgBaseClass* sc_module_base = new SgBaseClass(sc_base_declaration);

	static SgClassDeclaration* pw_base_declaration = new SgClassDeclaration(SOURCE_POSITION,
																"pw_module",SgClassDeclaration::e_class,
																NULL,NULL);
	static SgBaseClass* pw_module_base = new SgBaseClass(pw_base_declaration);

	// extend sc_module with <function name>_module
	string classname = this->modulefunc->get_name()+string("_module");
	moduleclass = SageBuilder::buildClassDeclaration(classname, parentscope);

	moduleclass->get_definition()->append_inheritance(sc_module_base);
	// may need to add back later
	//moduleclass->get_definition()->append_inheritance(pw_module_base);

	// collect parameter and return type information (these will be ports in the sc_module)
	SgInitializedNamePtrList parameters = this->modulefunc->get_args();
	for(SgInitializedNamePtrList::iterator paramIt=parameters.begin(); paramIt!=parameters.end(); paramIt++)
	{
		SgSymbol* member_sym= (*paramIt)->get_symbol_from_symbol_table();
		//cout << "member name is  " << member_sym->get_name();
		//cout << ", member type is  " << member_sym->get_type()->unparseToString() << endl;
		member_names.push_back(member_sym->get_name());
		member_types.push_back(member_sym->get_type());
	}
	//member_names.push_back("thread_id");
	//member_types.push_back(SageBuilder::buildIntType());

	return_type = this->modulefunc->get_orig_return_type();

	if(depth_below_me > 0)
	{
		//find top level parallel loops, clone their contents into new functions, set parameters as all variables used in this function but declared outside (esp iterator),
		// replace function with for loop for setting "start" variables, create SC_FunctionModule with new function, process it
		//std::vector<SgNode*> forLoops_org = NodeQuery::querySubTree(this->modulefunc, V_SgForStatement);
		//   cout << "Contain " << forLoops_org.size() << " for statements" << endl;
		//std::vector<SgNode*> ifLoops = NodeQuery::querySubTree(this->modulefunc, V_SgIfStmt);
		//std::vector<SgNode*> forLoops;
		/*if(ifLoops.size()){
		   cout << "Contain " << ifLoops.size() << " if statements" << endl;
		std::vector<SgNode*> forifLoops = NodeQuery::querySubTree(ifLoops[0], V_SgForStatement);
		forLoops.reserve(forLoops_org.size()+forifLoops.size());
		forLoops.insert(forLoops.end(), forLoops_org.begin(), forLoops_org.end());
		forLoops.insert(forLoops.end(), forifLoops.begin(), forifLoops.end());
                }
                else forLoops = forLoops_org;*/
		std::vector<SgNode*> forLoops = NodeQuery::querySubTree(this->modulefunc, V_SgForStatement);
		std::vector<SgForStatement*> topForLoops;
		int index=0;
		for(vector<SgNode*>::iterator it=forLoops.begin(); it != forLoops.end(); ++it)
		{
			SgForStatement* forLoop = isSgForStatement(*it);
			bool toplevel = isTopLevelInScope(forLoop, this->modulefunc->get_definition());
			bool canunroll =  canUnroll(forLoop);
			string ref;
			bool isTiledLoop = tiledLoop(forLoop, ref);
			//cout << endl << endl<< "is tiled loop ??? " << isTiledLoop << endl << endl;
			//cout << forLoop->unparseToString() << endl;
			if(forLoop && toplevel&& canunroll && isTiledLoop)//isTopLevelInScope(forLoop, this->modulefunc->get_definition()) && canUnroll(forLoop))
			{
				topForLoops.push_back(forLoop);
				//printf("Loop %s can be unrolled\n", ref.substr(1).c_str());
				canUnrollLoops.insert(ref.substr(1));
			}
			else
				;//printf("Loop %d toplevel: %d, canunroll: %d\n", index, toplevel, canunroll);
				//printf("Loop %s can NOT be unrolled\n", ref.c_str());
			index++;
		}

		//printf("has %d top level loops inside\n", topForLoops.size());
		for(int i=0; i<topForLoops.size(); ++i)//vector<SgForStatement*>::iterator it=topForLoops.begin(); it != topForLoops.end(); ++it)
		{
			stringstream ss;
			string parentName = this->modulefunc->get_name();
			ss << parentName << "_loop" << i;
			string funcname = ss.str();

			//int unrollFactor = atoi(globalUnrollFactor[depth_below_me-1].c_str());
			//int unrollFactor =atoi(globalUnrollFactor[loop_level].c_str());
			int unrollFactor = globalUnrollFactor[loop_level];
			//int it_start = getForInit(topForLoops[i]);
			//int it_stop = getForLimit(topForLoops[i]);
			int it_inc = getForIncrement(topForLoops[i]);
			//int iterations_unit = (it_stop - it_start) / it_inc;
			string it_start = getForInit(topForLoops[i]);
			//int iterations_unit = getIterationBasedTripCount(topForLoops[i]);
			//int tile_size = ((iterations_unit-1)/unrollFactor+1);
			//int iterations = unrollFactor;


			//cout << "\n\n " << isSgBinaryOp(test_exp)->get_rhs_operand()->unparseToString() << endl;
			SgExpression* test_exp = topForLoops[i]->get_test_expr();
			string iterationBoundary = isSgBinaryOp(test_exp)->get_rhs_operand()->unparseToString();

			string iterator = getForIterator(topForLoops[i]);

			int iterations = unrollFactor;
			string iterations_str= "("+intToString(unrollFactor)+"<("+iterationBoundary+"+1-"+iterator+")?"+intToString(unrollFactor) + ":(" +iterationBoundary+"+1-"+iterator+"))";
			//cout << "\n\n " << iterations_str << endl;
			//int iterations = unrollFactor;

			SgFunctionDeclaration* moduleFunc = forToFunction(topForLoops[i], ss.str(), this->parentscope);
			SC_FunctionModule* childModule = new SC_FunctionModule(moduleFunc, this->parentscope, depth_below_me-1, loop_level+1, false);
			stringstream sslat;
			sslat << this->latencyVar << "_LOOP" << i;
			childModule->latencyVar = sslat.str();
			printf("Processing loop %s...\n", funcname.c_str());
			childModule->process(globalUnrollFactor, no_pretile);
			printf("Finished processing loop %s\n", funcname.c_str());

			this->children_functions.push_back(childModule);
			this->children_iterations.push_back(iterations);
			this->children_iterations_str.push_back(iterations_str);

			string tab = "   ";
			stringstream replaceText;


			replaceText << endl << "// send signal for loop" << i << "modules to start\n"
						<< "for(int loopi=0; loopi<" << iterations_str <<" ; ++loopi)\n"
						<< "{\n";
			for(int j=0; j<childModule->member_names.size(); j++)
			{ 
				if(childModule->member_names[j]==iterator)
				{
					replaceText << tab <<  gen_prefix << "tiles" << i << "_" << childModule->member_names[j] << "[loopi]=(" << it_start <<"+" <<iterator  << "+(loopi*" << it_inc << "));\n";
				}
				//else if(childModule->member_names[j] =="thread_id"){
				//	replaceText << tab << gen_prefix << "tiles" << i << "_" << childModule->member_names[j] << "[loopi]=(loopi) + thread_id * " << unrollFactor << ";\n";
				//}
				else if(isSgArrayType(childModule->member_types[j])){
					/*
					string name = childModule->member_names[j];
					if(name.size() < 2 || name.substr(name.size() - 2) != "_l") continue;
					//1. get the dimension of the array.
					SgArrayType* arrtype = isSgArrayType(childModule->member_types[j]);
					std::vector<SgExpression*> indices = getSgArrayDim(arrtype).first;
					assert(indices.size() > 0);
					// build for loops to assign the value of arrays.
					// 1. the begining of for loops
					string tab = "   ";
					std::pair<string, string> tmp = beginingOfForLoopAndTab(indices, tab);
					string forBeginStmt  = tmp.first;
					string tabs = tmp.second;
					replaceText << forBeginStmt;
					//2. the statment
					std::pair<string, int> tmp2 = getTheIndicesStr(indices);
					string indices_str = tmp2.first;
					int idx = tmp2.second;
					string stmt = string(gen_prefix) + "tiles" + intToString(i) + "_"
					  + childModule->member_names[j] + "[loopi]";

					stmt = stmt +indices_str + " = " + childModule->member_names[j] + indices_str +";";
					replaceText << tabs << tab << stmt << "\n";
					//3. the end of the for loop
					string endFor = EndOfForLoop(idx, tab);
					replaceText << endFor;
					*/
				}
				else
				{
					replaceText << tab <<  gen_prefix << "tiles" << i << "_" << childModule->member_names[j] << "[loopi]=" << childModule->member_names[j] << ";\n";
				}
			}
			replaceText << tab << gen_prefix << "tiles" << i << "_start[loopi]=true;//start the tile's thread\n";
			replaceText << "}\n"
			  << "wait(1, SC_NS);\n"
						<< "for(int loopi=0; loopi<" << iterations_str << "; loopi++)\n"
						<< "{\n"
						<< tab << gen_prefix << "tiles" << i << "_start[loopi]=false;\n"
						<< "}\n";

			replaceText << "bool all_done = false;\n";

			//replaceText		<< "while(!(";
			replaceText <<  "while(!all_done){\n";
			replaceText << tab << "wait();\n";
			replaceText << tab << "bool tmp = true;\n";
			replaceText << tab << "for(int loopi=0; loopi<" << iterations_str << "; loopi++){\n"
			  << tab << tab << "tmp &= " << gen_prefix << "tiles" << i << "_done[loopi];\n" 
			  << tab << "}\n";
			replaceText << tab << "all_done = tmp;\n";
			replaceText << "}";

			SgBasicBlock* bblock_in = SageBuilder::buildBasicBlock();
			SgBasicBlock* bblock = SageBuilder::buildBasicBlock(bblock_in);
			topForLoops[i]-> set_loop_body(bblock);
			SgExpression* incr_exp = topForLoops[i]->get_increment();
			//cout << "loop" << i << " , has " << children_iterations[i] << " iterations" << endl;
			//for(int j=0; j<children_iterations[i]; ++j)
			//{
			//	replaceText << " " << gen_prefix << "tiles" << i << "_done" << "[" << j << "]" << (j==children_iterations[i]-1 ? " " : " &&");
			//}
			//replaceText << "))\n"
			//			<< "{\n"
		//				<< tab << "wait();"
		//				<< "}\n";

			//replaceWithText(topForLoops[i], replaceText.str());
			//cout << incr_exp->unparseToString() << endl;
			//cout << isSgUnaryOp(incr_exp)->get_operand()->unparseToString()<< endl;
			assert(isSgUnaryOp(incr_exp)); //currently only suport itr++ for incresement.
			SgExpression* new_incr_exp = isSgExpression(SageBuilder::buildPlusAssignOp(isSgUnaryOp(incr_exp)->get_operand(), SageBuilder::buildIntVal(unrollFactor)));
			//cout << new_incr_exp->unparseToString()<< endl;
			//SageInterface::setOperand(topForLoops[i]->get_increment(), SageBuilder::buildIntVal(tile_size));
			//SageInterface::replaceExpression(incr_exp, new_incr_exp);
			topForLoops[i]->set_increment(new_incr_exp);
			//cout << topForLoops[i]->get_increment()->unparseToString() << endl;
			SageInterface::addTextForUnparser(bblock_in, replaceText.str(), AstUnparseAttribute::e_inside);
			//replaceWithText(topForLoops[i], replaceText.str());
		}
	}


	SageInterface::removeStatement(this->modulefunc);//remove from previous location
	SageInterface::appendStatement(this->modulefunc, moduleclass->get_definition());
	SgFunctionParameterList* parameterList = buildFunctionParameterList();
	this->modulefunc->set_parameterList(parameterList);

	stringstream member_text, constructor_text;
	string tab = "   ";
	member_text << endl  << "public:\n"
				<<  tab << "sc_in<bool> " << gen_prefix << "start;\n"
				<<  tab << "sc_signal<bool> " << gen_prefix << "running;\n";
	if(!this->is_root)
		member_text	<< tab << "sc_out<bool> " << gen_prefix << "done;\n\n";

	for(int i=0; i<member_names.size(); ++i)
	{
		if(isSgArrayType(this->member_types[i])){
			/*
			string name = this->member_names[i];
			if(name.size() < 2 || name.substr(name.size() - 2) != "_l") continue;
			//get the dimension of the array
			SgArrayType* arrtype = isSgArrayType(this->member_types[i]);
		        std::pair<std::vector<SgExpression*>, SgType*> tmp = getSgArrayDim(arrtype);
			std::vector<SgExpression*> indices = tmp.first;
			assert(indices.size() > 0);
			
			//declare those arrays;
			//get the indices string 
			string type = typeToString(tmp.second);
			string dim_str = getTheDimStr(indices);
			member_text << tab << "sc_in<" << type << ">" << gen_prefix << name << dim_str << ";\n";
			*/
		}
		else{
			member_text << tab << "sc_in<" << typeToString(member_types[i]) << "> " << gen_prefix << member_names[i] << ";\n";
		}
	}
	if(!isSgTypeVoid(return_type))
	{
		member_text << tab << "sc_out<" << typeToString(return_type) << "> ret_out;\n";
	}

	//if(children_functions.size() == 0){
	//	//cout << this->modulefunc->unparseToString() << endl << endl;
	//	//this is a leaf node, and we want to insert wait(max memory wait), then reset these values to zero;
	//	std::vector<SgNode*> subForLoops = NodeQuery::querySubTree(this->modulefunc, V_SgForStatement);
	//	std::set<SgNode*> computeForLoops ;
	//	for(vector<SgNode*> :: iterator itr = subForLoops.begin(); itr != subForLoops.end(); ++itr){
	//		//cout << (*itr)->unparseToString() << endl;
	//		Rose_STL_Container<SgNode*> varRefs = NodeQuery::querySubTree((*itr), V_SgVarRefExp);
	//		Rose_STL_Container<SgNode*> :: iterator k = varRefs.begin();
	//		for(; k != varRefs.end(); ++k){
	//			SgVarRefExp* varRef = isSgVarRefExp(*k);
	//			if(varRef && isSgArrayType(varRef->get_symbol()->get_type())){ 
	//				std::string name = varRef->get_symbol()->get_name();
	//				if(name.size() < 2 || name.substr(name.size() - 2) != "_l") break;
	//			}
	//		}
	//		if(k != varRefs.end()) continue;
	//		//this loop does not contain global arrays, push this loop to another container;
	//		computeForLoops.insert(*itr);
	//	}
	//	/*
	//	//I don't want to mess with the original vector, so the loop can finish correctly
	//	std::set<SgNode*> computeForLoopCopy = computeForLoops;
	//	//find all the top loop levels in computation loops, and those are in the computeForLoopCopy
	//	std::set<SgNode*>::iterator l = computeForLoops.begin();
	//	for(; l != computeForLoops.end();){
	//		bool changed = false;
	//		std::vector<SgNode*> subsubForLoops = NodeQuery::querySubTree(isSgForStatement((*l))->get_loop_body(), V_SgForStatement);
	//		std::vector<SgNode*>::iterator itA = subsubForLoops.begin();
	//		for(; itA != subsubForLoops.end(); ++itA) { 
	//			int tmp = computeForLoopCopy.erase(*itA);
	//			if(tmp) changed = true;
	//		}
	//		if(changed){ 
	//			computeForLoops = computeForLoopCopy;
	//			l = computeForLoops.begin();
	//		} else ++l;
	//	}
	//	l = computeForLoopCopy.begin();
	//	//for each, I need to add the wait(), and reset the values
	//	for(; l != computeForLoopCopy.end(); ++l){
	//		Rose_STL_Container<SgNode*> varRefs = NodeQuery::querySubTree((*l), V_SgVarRefExp);
	//		std::set<std::string> arrNames;
	//		for(Rose_STL_Container<SgNode*> :: iterator k = varRefs.begin(); k != varRefs.end(); ++k){
	//			SgVarRefExp* varRef = isSgVarRefExp(*k);
	//			if(varRef && isSgArrayType(varRef->get_symbol()->get_type())){
	//				//std::cout << "the variables \n" << (*k)->unparseToCompleteString() << std::endl; 
	//				std::string name = varRef->get_symbol()->get_name() + "_cycle";
	//				arrNames.insert(name);
	//			}
	//		}
	//		std::set<std::string>::iterator k = arrNames.begin();

	//		std::string maxStr = (*k++);
	//		for(; k!= arrNames.end(); ++k){
	//			maxStr = "std::max(" + maxStr + ", " + (*k) + ")";
	//		}
	//		maxStr = "wait(" + maxStr + "*(thread_id+1), SC_NS);\n";
	//		SageInterface::attachArbitraryText(isSgStatement(*l), maxStr, PreprocessingInfo::after);

	//		//reset them to 0
	//		for(k = arrNames.begin(); k!= arrNames.end(); ++k){
	//			string rst = (*k) + "=0;\n"; 
	//			//cout << "string is " <<rst << endl;
	//			SageInterface::attachArbitraryText(isSgStatement(*l), rst, PreprocessingInfo::after);
	//		}

	//	}
	//	*/
	//	//for each computation loop, I want to see whether that is tiled loop, if so, I add latency information, otherwise, go deeper
	//	//if it does contain tile loops, remove
	//	/*
	//	std::set<SgNode*> computeForLoopCopy2 = computeForLoops; //this is for finding loop tiles
	//	set<SgNode*> computeForLoopCopyForTiles = computeForLoopCopy2;
	//	std::set<SgNode*>::iterator l = computeForLoops.begin();
	//	for(l=computeForLoopCopy2.begin(); l != computeForLoopCopy2.end(); ){
	//		bool changed = false;
	//		if(tiledLoop(isSgForStatement(*l))){
	//			int tmp = computeForLoopCopyForTiles.erase(*l);
	//			if(tmp) changed = true;
	//		}
	//		if(changed){
	//			computeForLoopCopy2 = computeForLoopCopyForTiles;
	//			l = computeForLoopCopy2.begin();
	//		} else ++l;
	//	}
	//	*/

	//	/*for(l=computeForLoopCopy2.begin(); l != computeForLoopCopy2.end(); ){
	//		Rose_STL_Container<SgNode*> varRefs = NodeQuery::querySubTree((*l), V_SgVarRefExp);
	//		bool changed = false;
	//		for(Rose_STL_Container<SgNode*> :: iterator k = varRefs.begin(); k != varRefs.end(); ++k){
	//			SgVarRefExp* varRef = isSgVarRefExp(*k);
	//			if(varRef && isSgArrayType(varRef->get_symbol()->get_type())) continue;
	//			else if(varRef){
	//				std::string name = varRef->get_symbol()->get_name();
	//				if (tLoops.find(name) != tLoops.end()){//found tile loop
	//					int tmp = computeForLoopCopyForTiles.erase(*l);
	//					if(tmp) changed = true;
	//					break;
	//				}

	//			}
	//		}
	//		if(changed){
	//			computeForLoopCopy2 = computeForLoopCopyForTiles;
	//			l = computeForLoopCopy2.begin();
	//		} else ++l;

	//	}

	//	for(l = computeForLoopCopyForTiles.begin(); l!= computeForLoopCopyForTiles.end(); ++l){
	//		cout << "compute loop body \n" << (*l)->unparseToCompleteString() << endl<<endl;
	//	}*/

	//	//rest, find the top level of the loop tiles, that weher
	//	/*
	//	set<SgNode*> tileTopLoops = computeForLoopCopyForTiles;
	//	l = computeForLoopCopyForTiles.begin();
	//	for(; l != computeForLoopCopyForTiles.end(); ){
	//		bool changed = false;
	//		std::vector<SgNode*> subsubForLoops = NodeQuery::querySubTree(isSgForStatement((*l))->get_loop_body(), V_SgForStatement);
	//		std::vector<SgNode*>::iterator itA = subsubForLoops.begin();
	//		for(; itA != subsubForLoops.end(); ++itA) { 
	//			int tmp = tileTopLoops.erase(*itA);
	//			if(tmp) changed = true;
	//		}
	//		if(changed){ 
	//			computeForLoopCopyForTiles = tileTopLoops;
	//			l = computeForLoopCopyForTiles.begin();
	//		} else ++l;
	//	}*/
	//	//for each top tile loop, insert the latency information
	//	//cout << "the tile top loop size is " << tileTopLoops.size() << endl;
	//	
	//	/*
	//	for(l = tileTopLoops.begin(); l != tileTopLoops.end(); ++l){
	//		cout << (*l)->unparseToString() << endl << endl;
	//	}*/
/*	//	
	//	assert(tileTopLoops.size() == 1);
	//	std::vector<SgNode*> subTileLoops = NodeQuery::querySubTree(isSgForStatement(*(tileTopLoops.begin())), V_SgForStatement);
	//	string latencyVar1;
	//	std::vector<SgNode*>::iterator it = subTileLoops.begin();
	//	for(it = subTileLoops.begin(); it!= subTileLoops.end(); ++ it){
	//		SgForStatement* fs = isSgForStatement(*it);
	//		assert(fs);
	//		std::vector<SgNode*> query = NodeQuery::querySubTree(fs->get_loop_body(), V_SgForStatement);
	//		if(query.size() != 0) continue;
	//		latencyVar1 = isSgNode(fs)->getAttribute(std::string("accNum"))->toString();
	//		break;
	//	}
	//	string latText = tab + tab+ "wait(" + latencyVar1 + ", SC_NS);\n";

	//	SageInterface::addTextForUnparser((*tileTopLoops.begin()), latText, AstUnparseAttribute::e_before);
	//	*/
	//}

	for(int i=0; i<children_functions.size(); ++i)
	{
		SC_FunctionModule* child = children_functions[i];
		member_text << tab << string(child->moduleclass->get_name()) << "* " << gen_prefix << "tiles" << i << "[" << children_iterations[i] << "];\n";
		member_text << tab << "sc_signal<bool> " << gen_prefix << "tiles" << i << "_start[" << children_iterations[i] << "];\n";
		member_text << tab << "sc_signal<bool> " << gen_prefix << "tiles" << i << "_done[" << children_iterations[i] << "];\n";
		for(int j=0; j<child->member_names.size(); ++j)
		{
			if(isSgArrayType(child->member_types[j])){ 
				//cout << "is array : " << child->member_names[j] << endl;
				/*
				string name = child->member_names[j];
				if(name.size() < 2 || name.substr(name.size() - 2) != "_l") continue;
				//get the dimension of the array
				SgArrayType* arrtype = isSgArrayType(child->member_types[j]);
				std::pair<std::vector<SgExpression*>, SgType*> tmp = getSgArrayDim(arrtype);
				std::vector<SgExpression*> indices = tmp.first;
				assert(indices.size() > 0);
				//declare those arrays;
				//get the indices string 
				string type = typeToString(tmp.second);
				string dim_str = getTheDimStr(indices);

				member_text << tab << "sc_signal<" << type << ">" << gen_prefix << "tiles" << i << "_" << name << "[" << children_iterations[i] << "]" << dim_str << ";\n"; 
*/
			}
			else
			{
				//cout << "is Not array: " <<child->member_names[j] << endl;
				member_text << tab << "sc_signal<" << typeToString(child->member_types[j]) << "> " << gen_prefix << "tiles" << i << "_" << child->member_names[j] << "[" << children_iterations[i] << "];\n";
			}
		}
	}

	SageInterface::addTextForUnparser(this->modulefunc, member_text.str(), AstUnparseAttribute::e_before);

	// add SC_CTOR, SC_THREADs
	string threadname = this->modulefunc->get_symbol_from_symbol_table()->get_name();
	//constructor_text << "\n" <<  tab << "SC_CTOR(" << string(this->moduleclass->get_name()) << ")\n"
	constructor_text << "\n" << tab << "SC_HAS_PROCESS(" <<  string(this->moduleclass->get_name()) << ");\n"
			<<  tab << string(this->moduleclass->get_name()) << "(const sc_module_name& p_name) :\n"
			<< tab << "  sc_module(p_name)\n"
			<< tab << "{\n"
			<< tab << tab << "SC_THREAD(" << threadname << ");\n"
			<< tab << tab << "sensitive << " << gen_prefix << "start;\n";
	for(int i=0; i<children_functions.size(); ++i)
	{
		constructor_text << tab << "for(int loopi=0; loopi<" << children_iterations[i] <<"; loopi++)\n"
						<< tab << "{\n"
						<< tab << tab << "sensitive << " << gen_prefix << "tiles" << i << "_done[loopi];\n";
		constructor_text << tab << "}\n";
	}

	for(int i=0; i<children_functions.size(); ++i)
	{
		SC_FunctionModule* child = children_functions[i];

	      // loop 0
		if(this->is_root){
		}

		constructor_text << tab << "for(int loopi=0; loopi<" << children_iterations[i] <<"; loopi++)\n"
						<< tab << "{\n"
						<< tab << tab << "//creat tile module\n"
						<< tab << tab << "std::stringstream ss;\n"
						<< tab << tab << "ss << \"tile" << i << "_\" << loopi;\n"
						<< tab << tab << gen_prefix << "tiles" << i << "[loopi] = new " << string(child->moduleclass->get_name()) << "((ss.str().c_str()));\n\n"
						<< tab << tab << "//bind ports\n"
						<< tab << tab << gen_prefix << "tiles" << i << "[loopi]->" << gen_prefix << "start(" << gen_prefix << "tiles" << i << "_start[loopi]);\n"
						<< tab << tab << gen_prefix << "tiles" << i << "[loopi]->" << gen_prefix << "done(" << gen_prefix << "tiles" << i << "_done[loopi]);\n";
		for(int j=0; j<child->member_names.size(); ++j)
		{
			if(isSgArrayType(child->member_types[j])){
				/*
				string name = child->member_names[j];
				if(name.size() < 2 || name.substr(name.size() - 2) != "_l") continue;
				//1. get the dimension of the array.
				SgArrayType* arrtype = isSgArrayType(child->member_types[j]);
				std::vector<SgExpression*> indices = getSgArrayDim(arrtype).first;
				assert(indices.size() > 0);
				//build for loops for binding ports
				//1 the beging of for loops
				string tab = "      ";
				std::pair<string, string> tmp = beginingOfForLoopAndTab(indices, tab);
				string forBeginStmt  = tmp.first;
				string tabs = tmp.second;
				constructor_text << forBeginStmt;
				//2 the statment
				std::pair<string, int> tmp2 = getTheIndicesStr(indices);
				string indices_str = tmp2.first;
				int idx = tmp2.second;
				constructor_text << tab << tabs << gen_prefix << "tiles" << i <<"[loopi]->"<< gen_prefix << child->member_names[j] 
				  << indices_str << "(" << gen_prefix << "tiles" << i << "_" 
				  << child->member_names[j] << "[loopi]" << indices_str << ");"<< "\n";
				//3 the end of for statement
				string endFor = EndOfForLoop(idx, tab);
				constructor_text << endFor;
				*/
			}
			else{
				constructor_text << tab << tab << gen_prefix << "tiles" << i << "[loopi]->" << gen_prefix << child->member_names[j] << "(" << gen_prefix << "tiles" << i << "_" << child->member_names[j] << "[loopi]);\n";
			}
		}
		constructor_text << tab << "}\n";
	}
	constructor_text << endl << tab << "}\n";


	SageInterface::addTextForUnparser(this->modulefunc, constructor_text.str(), AstUnparseAttribute::e_after);


	// add while(true){while(!start)wait(1NS)...done=true; loop at top of function
	SgBasicBlock* funcBody = modulefunc->get_definition()->get_body();
	SageInterface::removeStatement(funcBody);

	// while true
	SgExprStatement* trueStatement = SageBuilder::buildExprStatement(SageBuilder::buildBoolValExp(true));
	SgWhileStmt* whileTrue = buildWhileStmt(trueStatement, funcBody);
	SgBasicBlock* newBB = SageBuilder::buildBasicBlock(whileTrue);

	modulefunc->get_definition()->set_body(newBB);

	//insert while(!start)... done=true
	stringstream beforeBody;
	stringstream afterBody;
	beforeBody << endl <<tab << "while(!" << gen_prefix << "start) wait();\n";
	if(no_pretile){ 
		beforeBody << tab << "wait(ACC_LATENCY, SC_NS);\n"; 
	}
	//beforeBody << tab << gen_prefix << "running = true;\n";
	if(!this->is_root)
		beforeBody << tab << gen_prefix << "done = false;\n";

	//if this is a leaf module, add latency
	/* Wei, may need to add in
	beforeBody << tab <<  "#ifdef " << latencyVar << "_SIM_LATENCY)*10, SC_NS);\n"
				   << tab << "wait((" << latencyVar << "_SIM_LATENCY)*10, SC_NS);\n"
		   	   	   << "#endif\n";
		   	   	   */

	// initialize variables;
	for(int i=0; i<this->member_names.size(); ++i)
	{
		if(isSgArrayType(this->member_types[i])){
			string name = this->member_names[i];
			if(name.size() < 2 || name.substr(name.size() - 2) != "_l") continue;
			//get the dimension of the array
			SgArrayType* arrtype = isSgArrayType(this->member_types[i]);
		        std::pair<std::vector<SgExpression*>, SgType*> tmp = getSgArrayDim(arrtype);
			std::vector<SgExpression*> indices = tmp.first;
			assert(indices.size() > 0);

			//declare those arrays;
			//get the indices string 
			string type = typeToString(tmp.second);
			string dim_str = getTheDimStr(indices);
			beforeBody << tab << type << " " << name << dim_str << ";\n";
			beforeBody << tab << "int " << name+"_cycle = 0;\n"; 
			// build for loops to assign the value of arrays.
			// 1. the begining of for loops
			/*
			string tab = "   ";
			std::pair<string, string> tmp3 = beginingOfForLoopAndTab(indices, tab);
			string forBeginStmt  = tmp3.first;
			string tabs = tmp3.second;
			beforeBody << forBeginStmt;
			//2. the statment
			std::pair<string, int> tmp2 = getTheIndicesStr(indices);
			string indices_str = tmp2.first;
			int idx = tmp2.second;
			string stmt = name + indices_str + " = " + gen_prefix + name + indices_str;
			beforeBody << tabs << tab << stmt << ";\n";
			//3 the end of the for loop
			string endFor = EndOfForLoop(idx, tab);
			beforeBody << endFor;
			*/
		}
		else{
			string name = this->member_names[i];
			string type = typeToString(this->member_types[i]);
			beforeBody << tab << type << " " << name << "=" << gen_prefix << name << ";\n";
		}
	}

	//notify we're done at the end
	afterBody << endl << tab << gen_prefix << "running = false;\n";
	if(this->is_root)
		afterBody << tab << "sc_stop();\n";
	else
		afterBody << tab << gen_prefix << "done = true;\n";
	SageInterface::addTextForUnparser(funcBody->get_statements().front(), "", AstUnparseAttribute::e_before);
	SageInterface::addTextForUnparser(funcBody->get_statements().front(), beforeBody.str(), AstUnparseAttribute::e_before);
	SageInterface::addTextForUnparser(funcBody->get_statements().back(), "", AstUnparseAttribute::e_after);
	SageInterface::addTextForUnparser(funcBody->get_statements().back(), afterBody.str(), AstUnparseAttribute::e_after);
}

void SC_FunctionModule::addToFile()
{
	SageInterface::prependStatement(moduleclass, parentscope);
	for(int i=0; i<children_functions.size(); ++i)
	{
		children_functions[i]->addToFile();
	}
	//cout << moduleclass->unparseToString() << endl;
	//string pw_module_inheritance = "\n#ifdef TIMING_POWER_SIMULATE_ENABLE\n , public pw_module\n#endif\n";
	//SageInterface::addTextForUnparser(moduleclass->get_definition()->get_body(), pw_module_inheritance, AstUnparseAttribute::e_after);
}

string startModuleTrace(SC_FunctionModule* module, string name)
{
	stringstream retStream;
	//retStream << "pw_trace(g_txt_trace_file_pt, *" << name << ", \"" << name << "\");\n";
	//retStream << "sc_trace(wf, " << name << "->" << gen_prefix << "running, \"" << name << "\");\n";
	for(int i=0; i<module->children_functions.size(); ++i)
	{
		for(int j=0; j<module->children_iterations[i]; ++j)
		{
			stringstream nameStream;
			nameStream << name << "->" << gen_prefix << "tiles" << i << "[" << j << "]";
			retStream << startModuleTrace(module->children_functions[i], nameStream.str());
		}
	}
	return retStream.str();
}

void fixTestbenchFunction(SgFunctionDeclaration* tbFunc, string target_func_name, SC_FunctionModule* funcModule, SgScopeStatement* scope, bool no_pretile)
{
	if(!tbFunc)
	{
		printf("Warning: Testbench does not exist.\n");
		return;
	}
	SageInterface::removeStatement(tbFunc);
	SageInterface::appendStatement(tbFunc, scope);
	tbFunc->set_name("sc_main");

	SgFunctionCallExp* targetCall=0;

	//search for function call matching target function
	std::vector<SgNode*> funcCalls = NodeQuery::querySubTree(tbFunc, V_SgFunctionCallExp);
	for(vector<SgNode*>::iterator it=funcCalls.begin(); it != funcCalls.end(); ++it)
	{
		SgFunctionCallExp* call = isSgFunctionCallExp(*it);
		if(call && call->getAssociatedFunctionSymbol()->get_name() == target_func_name)
		{
			targetCall = call;
			break;
		}
	}

	// when the function call is found, replace it with instantiation of target module
	SgStatement* callStmt = isSgStatement(targetCall->get_parent());
	assert(callStmt);

	// manually insert instantiation text
	stringstream moduleDecl;
	moduleDecl << string(funcModule->moduleclass->get_name()) << "* top_module = new " << string(funcModule->moduleclass->get_name()) << "(\"top_module\");\n";

	//now bind all ports, and assign the ports to initial values (the expressions used in the function call)
	SgExpressionPtrList args = targetCall->get_args()->get_expressions();
	int numArgs = args.size();
	//because we added in the therad_id
	//cout  << "numArgs, member_names.size() : " << numArgs << " , " << funcModule->member_names.size() << endl;
	// this is for thread id: 
	// assert(numArgs==funcModule->member_names.size() -1);
	 assert(numArgs==funcModule->member_names.size());
	string tab = "   ";

	stringstream signalDecl;
	signalDecl << endl << tab << "sc_signal<bool> start;\n";
	stringstream signalBind;
	signalBind << endl << tab << "top_module->" << gen_prefix << "start(start);\n";

	SgStatement* first_assign=0;
	//This is also for thread id:for(int i=0; i<numArgs+1; i++)
	for(int i=0; i<numArgs; i++)
	{
		// in sc_main, the module ports will be bound to local variables called <variable name>_main
		string sc_main_varname = string(gen_prefix) + funcModule->member_names[i] + string("_main");

		// signal declaration
		signalDecl << tab << "sc_signal<" << typeToString(funcModule->member_types[i]) << "> " << sc_main_varname << ";\n";

		// port binding
		signalBind << tab << "top_module->" << gen_prefix << funcModule->member_names[i] << "(" << sc_main_varname << ");\n";

		// assign signal: create a variable declaration but don't insert it- assignment will actually be associated with our own sc_signal<> template variable
		// insert assignment after module declaration. declarations and bindings will be inserted before this later
		SgVariableDeclaration* portAttachDecl = buildVariableDeclaration(sc_main_varname, funcModule->member_types[i], NULL, tbFunc->get_definition());
		SgStatement* assign_stmt;
		if(i < numArgs)
			assign_stmt = buildAssignStatement(buildVarRefExp(sc_main_varname), args[i]);
		else
			assign_stmt = buildAssignStatement(buildVarRefExp(sc_main_varname), SageBuilder::buildIntVal(0));
		SageInterface::insertStatement(callStmt, assign_stmt, false);
		first_assign = (!first_assign ? assign_stmt : first_assign);
	}


	stringstream simStart;
	simStart << endl << endl
	  << tab << "// Start simulation\n"
	  << tab << "sc_set_time_resolution(1,SC_NS);\n";
	  //simStart << tab << "wf->set_time_unit(1, SC_NS);\n";
	simStart << tab << "start=true;\n"
	  << tab << "sc_start(1, SC_NS);\n"
	  << tab << "start = false;\n"
	  << tab << "cout << \"start @\" << sc_time_stamp() << endl;\n"//\" start :\" << top_module.start << \", done: \" << top_module.done << endl;\n"
	  << tab << "sc_start(); // start the simulation\n";
	  if(no_pretile){
	  	  simStart << tab << "cout << \"done @\" << sc_time_stamp() << endl;\n";
	  } else {
	  simStart << tab << "cout << \"Energy: \" << energy << endl;\n"
	  << tab << "cout << \"Latency: \" << sc_time_stamp() << endl;\n";
	  }
	  //\" start :\" << top_module.start << \", done: \" << top_module.done << endl;\n";
	  // tab << "#endif\n";

//	SageInterface::addTextForUnparser(callStmt, moduleDecl.str()+signalDecl.str()+signalBind.str()+simStart.str(), AstUnparseAttribute::e_after);
	if(first_assign)
	{
		replaceWithText(callStmt, moduleDecl.str()+signalDecl.str()+signalBind.str());
		SageInterface::addTextForUnparser(first_assign, "", AstUnparseAttribute::e_after);
		SageInterface::addTextForUnparser(first_assign, simStart.str(), AstUnparseAttribute::e_after);
	}
	else
	{
		replaceWithText(callStmt, moduleDecl.str()+signalDecl.str()+signalBind.str()+simStart.str());
	}
}

int TransformToSystemC(SgProject* project, string targetname, string testbenchname, int depth, std::vector<int> unroll_factors, bool preprocess, bool no_pretile)
{
	cout << "[SYSTEMC_GENERATION]: Preprocess: " << preprocess << endl;
	cout << "[SYSTEMC_GENERATION]: depth: " << depth<< endl;
	if(!no_pretile)
		assert(depth <= unroll_factors.size());
	setTLoops();
	//lowLevelSCTransform myTraversal(targetname, testbenchname);

	//myTraversal.traverseInputFiles(project, preorder);

	// Access the first file and add a struct with data members specified
	SgSourceFile* file = isSgSourceFile((*project)[0]);
	assert(file != NULL);

	SgFunctionDeclaration* targetFunction = findFunctionWithName(file->get_globalScope(), targetname);
	SgFunctionDeclaration* testbenchFunction = findFunctionWithName(file->get_globalScope(), testbenchname);

	// add include systemc.h directive
	string directives = "#include \"systemc.h\"\n#include <sstream>\n";
	directives += "#include \"latencies.h\"\n";
	if(!no_pretile){
		directives += "#include \"power.h\"\n";
		directives += "#include \"help_function.h\"\n";
		directives += "double energy = 0.0;\n";
	}
	//directives += "#include \"latencies.h\"\n#define TIMING_POWER_SIMULATE_ENABLE\n#ifdef TIMING_POWER_SIMULATE_ENABLE\n#include <tlm_power.h>\n#endif\n";
	SageInterface::addTextForUnparser(file->get_globalScope(), directives, AstUnparseAttribute::e_inside);

	SC_FunctionModule* rootModule = new SC_FunctionModule(targetFunction, file->get_globalScope(), depth, 0, true);
	rootModule->latencyVar = targetname;
	printf("Processing root module...\n");
	rootModule->process(unroll_factors, no_pretile);
	printf("Finished processing root module\n");
	rootModule->addToFile();

	// move testbench function to sc_main at the bottom of file
	fixTestbenchFunction(testbenchFunction, targetname, rootModule, file->get_globalScope(), no_pretile);
	printf("Finished processing root module\n");

	//post processing
	//write the file .canUnrollLoops 
	if(preprocess)
		writeCanUnrollLoops();

	return EXIT_SUCCESS;
}
