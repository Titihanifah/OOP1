#ifndef __EXPRESSION_EVALUATOR__
#define __EXPRESSION_EVALUATOR__
#include <string>
using namespace std;

#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include "Stack.h"
using namespace std;
class ExpressionEvaluator{
private:
	Stack<int> st;
	string temp;
	string expression;
	int opFlag;
	int isOperatorArith(char in);
	int isOperatorLogic(char in);
	
public:	
	ExpressionEvaluator();
	int calculateArith();
	int calculateLogic();
	void setExpression(string);
};

#endif
