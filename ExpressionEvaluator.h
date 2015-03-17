#ifndef __EXPRESSION_EVALUATOR__
#define __EXPRESSION_EVALUATOR__

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
	void setExpression(string input); // setEkspresi
	int calculateArith();
	int calculateLogic();
};

#endif