#ifndef __EXPRESSION_EVALUATOR__
#define __EXPRESSION_EVALUATOR__

class ExpressionEvaluator{
private:
	Stack<int> st;
	string temp;
	string expression;
	int opFlag;
	int isOperator(char in);
	
public:	
	ExpressionEvaluator();
	int calculate();
};

#endif