#ifndef __EXPRESSION_EVALUATOR__
#define __EXPRESSION_EVALUATOR__

class ExpressionEvaluator{
private:
	stack<int> st;
	string temp;
	string expression;
	int opFlag;
	int isOperator(char in);
	
public:	
	ExpressionEvaluator(string input);
	int calculate();
};

#endif