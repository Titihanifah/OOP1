#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include "Stack.h"
#include "ExpressionEvaluator.h"

using namespace std;
	
int ExpressionEvaluator::isOperatorArith(char in)
{
		if (in == '+') return 1;
		if (in == '-') return 1;
		if (in == '/') return 1;
		if (in == '*') return 1;
		if (in == '%') return 1;
		return 0;
}
	
ExpressionEvaluator::ExpressionEvaluator()
{}

void ExpressionEvaluator::setExpression(string input)
{
	expression = input;
}

int ExpressionEvaluator::isOperatorLogic(char in)
{
	if(in == '&') return 1;
	if(in == '|') return 1;
	if(in == '!') return 1;
	if(in == '&') return 1;
	if(in == '^') return 1;
	return 0;
}	

int ExpressionEvaluator::calculateLogic()
{
	opFlag=0;
	for (int i=0;i<expression.length();i++){
		if(isOperatorLogic(expression[i])){
			opFlag = 1;
			int a,b;
			st.pop(a);
			if(expression[i]!='!')
				st.pop(b);
			switch(expression[i]){
				case '&': st.push(a && b);
				case '|': st.push(a || b);
				case '!': st.push(!a);
				case '^': st.push(a ^ b);
			}
		}
		else if(expression[i]==' '){
			if (opFlag == 0){
				int xx = atoi(temp.c_str());
				st.push(xx);
				temp = "";
			}
		}
		else{
			temp.append(string(1,expression[i]));
			opFlag = 0;
		}
	}
}
 	
int ExpressionEvaluator::calculateArith()
{
	opFlag = 0;
	for (int i=0;i<expression.length();i++)
	{
		if (isOperatorArith(expression[i]))
		{
			printf("1\n");
			opFlag = 1;
			int a,b;
			st.pop(a);
			st.pop(b);
			
			if (expression[i] == '+') st.push(a+b);
			else if (expression[i] == '-') st.push(b-a);
			else if (expression[i] == '/') st.push(b/a);
			else if (expression[i] == '*') st.push(a*b);
			else if (expression[i] == '%') st.push(b%a);
		}else if (expression[i] == ' ')
		{
			if (opFlag == 0){
				int xx = atoi(temp.c_str());
				st.push(xx);
				temp = "";
			}
		}else
		{
			temp.append(string(1,expression[i]));
			opFlag = 0;
		}
	}
	int tt;
	st.pop(tt);
	return tt;
}