#include "ExpressionEvaluator.h"

int ExpressionEvaluator::isOperatorArith(char in)
{
	if (in == '+') return 1;
	if (in == '-') return 1;
	if (in == '/') return 1;
	if (in == '*') return 1;
	if (in == '%') return 1;
	// if not an operator
	return 0;
}
	
ExpressionEvaluator::ExpressionEvaluator(){}

ExpressionEvaluator::ExpressionEvaluator(string input)
{
	setExpression(input);
}

void ExpressionEvaluator::setExpression(string input)
{
	expression = input;
}

int ExpressionEvaluator::isOperatorLogic(char in)
{
	if(in == '&') return 1;
	if(in == '|') return 1;
	if(in == '!') return 1;
	if(in == '^') return 1;
	if(in == '>') return 1;
	if(in == '<') return 1;
	if(in == '=') return 1;
	// if not an operator
	return 0;
}	

int ExpressionEvaluator::calculateLogic()
{
	opFlag=0; // 0 : previous string is an operand , 1 : previous character is an operator 
	for (int i=0;i<expression.length();i++){
		if(isOperatorLogic(expression[i])){
			opFlag = 1; // setting to 1 : previous character is an operator 
			int a,b; // temporary variable to hold two operands 
			st.pop(a); // second operand
			if(expression[i]!='!')
				st.pop(b); // first operand
			switch(expression[i]){
				case '&': st.push(a && b); break;
				case '|': st.push(a || b); break;
				case '!': st.push(!a); break;
				case '^': st.push(a ^ b); break;
				case '>': st.push(b > a);break;
				case '<': st.push(b < a);break;
				case '=': st.push(a == b);break;
			}
		}
		else if(expression[i]==' '){
			// if previous string is an operand, it needs to be pushed to stack
			if (opFlag == 0){
				int xx = atoi(temp.c_str());
				st.push(xx);
				temp = "";
			}
		}
		else{
			// buffering current operand
			temp.append(string(1,expression[i]));
			opFlag = 0; // setting to 0 : previous string is an operand 
		}
	}
	
	// reach end of line and there is still operand left
	if (temp != "")
	{
		int xx = atoi(temp.c_str());
		st.push(xx);
		temp = "";
	}
	
	int tt; // temporary variable to hold result values 
	// pop/put the result into the variable
	st.pop(tt);
	// returning values of an expression
	return tt;
}
	
int ExpressionEvaluator::calculateArith()
{
	opFlag = 0; // 0 : previous string is an operand , 1 : previous character is an operator 
	for (int i=0;i<expression.length();i++)
	{
		// if current character is an operator but not a minus in a negative number (ie. -2)
		if (isOperatorArith(expression[i]) && ((expression[i+1] == ' ') || (i+1 == expression.length())))
		{
			opFlag = 1; // setting to 1 : previous character is an operator 
			int a,b; // temporary variable to hold two operands 
			// second operand
			st.pop(a);
			// first operand
			st.pop(b);
			
			if (expression[i] == '+') st.push(a+b);
			else if (expression[i] == '-') st.push(b-a);
			else if (expression[i] == '/') st.push(b/a);
			else if (expression[i] == '*') st.push(a*b);
			else if (expression[i] == '%') st.push(b%a);
		}else if (expression[i] == ' ')
		{
			// if previous string is an operand, it needs to be pushed to stack
			if (opFlag == 0){
				int xx = atoi(temp.c_str());
				st.push(xx);
				temp = "";
			}
		}
		else
		{
			// buffering current operand
			temp.append(string(1,expression[i]));
			opFlag = 0; // setting to 0 : previous string is an operand
		}
	}
	
	// reach end of line and there is still operand left
	if (temp != "")
	{
		int xx = atoi(temp.c_str());
		st.push(xx);
		temp = "";
	}
	
	int tt; // temporary variable to hold result values
	// pop/put the result into the variable
	st.pop(tt);
	// returning values of an expression
	return tt;
}
