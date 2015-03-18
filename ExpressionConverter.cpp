#include "ExpressionConverter.h"
#include <string>
#include "Stack.h"
#include <iostream>
using namespace std;

int ExpressionConverter::isOperator(char in)
{
	if (in == '+') return 1;
	if (in == '-') return 1;
	if (in == '/') return 1;
	if (in == '*') return 1;
	if (in == '%') return 1;
	if (in == '(') return 1;
	if (in == ')') return 1;
	if(in == '&') return 1;
	if(in == '|') return 1;
	if(in == '!') return 1;
	if(in == '^') return 1;
	if(in == '>') return 1;
	if(in == '<') return 1;
	if(in == '=') return 1;
	return 0;
}

int ExpressionConverter::OperatorPrecedence(char op) {
	if (op == '!')
		return 3;
	else if ((op == '*') || (op == '/') || (op == '%') || (op == '&') || (op == '>') || (op == '<'))
		return 2;
	else if ((op == '+') || (op == '-') || (op == '|') || (op == '='))
		return 1;
	return 0;
}

string ExpressionConverter::toPostfix(string expression) {
	if (exp_type == POSTFIKS_OPERATOR)
	{
		return expression;
	}
	string postfix = "";
	if (exp_type == PREFIKS_OPERATOR) 
	{
		Stack<string> S;
		string oprnd = "";
		for (int i = expression.length() - 1; i >= 0; i--)
		{
			if (isOperator(expression[i]))
			{
				string op1 = "";
				string op2 = "";
				S.pop(op1);
				if (expression[i] != '!')
					S.pop(op2);
				op1 = op1 + op2 + expression[i];
				if (i != 0)
				{
					op1 += " ";
				}
				S.push(op1);
			}
			else if (expression[i] == ' ')
			{
				if (oprnd != "")
				{
					oprnd += " ";
					S.push(oprnd);
					oprnd = "";
				}
			}
			else 
			{
				oprnd = expression[i] + oprnd;
			}
		}
		S.pop(postfix);
	}
	else if (exp_type == INFIKS_OPERATOR) /* 1 berarti infix */
	{
		Stack<char> S;
		string stemp = "";
		for (int i = 0; i < expression.length(); i++)
		{
			if (isOperator(expression[i]))
			{
				if (stemp != "") 
				{
					if (postfix != "")
						postfix += " ";
					postfix += stemp;
					stemp = "";
				}
				if ((expression[i] == '(') || (S.isEmpty()))
				{
					S.push(expression[i]);
				}
				else if (expression[i] == ')')
				{
					char op;
					S.pop(op);
					while (op != '(')
					{
						postfix += " ";
						postfix.append(1, op);
						S.pop(op);
					}
				}
				else 
				{
					char op = S.getTop();
					if (op == '(')
					{
						S.push(expression[i]);
					}
					else 
					{
						if (OperatorPrecedence(op) >= OperatorPrecedence(expression[i]))
						{
							S.pop(op);
							postfix += " ";
							postfix.append(1, op);
							S.push(expression[i]);
						}
						else
							S.push(expression[i]);
					}
				}
			}
			else if (expression[i] != ' ')
			{
				stemp += expression[i];
			}
		}
		if (stemp != "")
			postfix += " " + stemp;
		while (!S.isEmpty())
		{
			char op;
			S.pop(op);
			postfix += " ";
			postfix.append(1, op);
		}
	}
	return postfix;
}

void ExpressionConverter::setExpType(int e_type) {
	exp_type = e_type;
}