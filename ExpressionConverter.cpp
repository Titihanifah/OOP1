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
	switch (op) 
	{
		case '!' : return 8;
				   break;
		case '*' : case '/' : case '%' : return 7;
										 break;
		case '+' : case '-' : return 6;
							  break;
		case '<' : case '>' : return 5;
										 break;
		case '=' : return 4;
				   break;
		case '&' : return 3;
				   break;
		case '^' : return 2;
				   break;
		case '|' : return 1;
				   break;
		default : return 0;
	};
}

string ExpressionConverter::toPostfix(string expression) {
	string postfix = "";
	if (exp_type == POSTFIKS_OPERATOR)
	{
		string oprnd = "";
		int mode = 1; // 1 : previous char is space , 0 : previous char is not space
		int nonspc = expression.length() - 1;
		while (expression[nonspc] == ' ')
		{
			nonspc--;
		}
		for (int i = 0; i < expression.length(); i++)
		{
			if (expression[i] != ' ')
			{
				if (oprnd != "")
				{
					oprnd += " ";
					postfix += oprnd;
					oprnd = "";
				}
				if (isOperator(expression[i]))
				{
					postfix.append(1, expression[i]);
					if (i != nonspc)
					{
						postfix.append(1, ' ');
					}
				}
				else
				{
					oprnd = expression[i] + oprnd;
				}
			}
		}
		return postfix;
	}
	if (exp_type == PREFIKS_OPERATOR) 
	{
		Stack<string> S;
		string oprnd = "";
		int mode = 0; // 1 : previous char is operand , 2 : previous char is operator or space
		int nonspc = 0; 
		while (expression[nonspc] == ' ')
			nonspc++;
		for (int i = expression.length() - 1; i >= 0; i--)
		{
			if (expression[i] != ' ')
			{
				if (oprnd != "")
				{
					oprnd += " ";
					S.push(oprnd);
					oprnd = "";
				}
				if (isOperator(expression[i]))
				{
					string op1 = "";
					string op2 = "";
					S.pop(op1);
					if (expression[i] != '!')
						S.pop(op2);
					op1 = op1 + op2 + expression[i];
					if (i != nonspc)
					{
						op1 += " ";
					}
					S.push(op1);
				}
				else
				{
					oprnd = expression[i] + oprnd;
				}
			}
		}
		S.pop(postfix);
	}
	else if (exp_type == INFIKS_OPERATOR) 
	{
		Stack<char> S;
		string stemp = "";
		int mode = 0; // 1 : previous char is operand 
		              //2 : previous char is operator that has caused at least one operator has been popped from stack
		for (int i = 0; i < expression.length(); i++)
		{
			if (isOperator(expression[i]))
			{
				if ((mode == 1) && (stemp != ""))
				{
					postfix += stemp;
					postfix.append(1, ' ');
					stemp = "";
				}
				if (expression[i] == '(')
				{
					S.push(expression[i]);
				}
				else if (expression[i] == ')')
				{
					char op;
					S.pop(op);
					while (op != '(')
					{
						if (mode != 1)
							postfix.append(1, ' ');
						postfix.append(1, op);
						mode = 2;
						S.pop(op);
					}
					//printf("pp %s\n",postfix.c_str());
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
							if (mode != 1)
								postfix.append(1, ' ');
							postfix.append(1, op);
							S.push(expression[i]);
							mode = 2;
						}
						else
						{
							S.push(expression[i]);
						}
					}
				}
			}
			else if (expression[i] != ' ')
			{
				if (mode == 2)
					postfix.append(1, ' ');
				mode = 1;
				stemp.append(1, expression[i]);
			}
		}
		if ((mode == 1) && (stemp != ""))
		{
			postfix +=stemp;
			postfix.append(1, ' ');
		}
		while (!S.isEmpty())
		{
			char op;
			S.pop(op);
			if (mode != 1)
				postfix.append(1, ' ');
			postfix.append(1, op);
		}
	}
	return postfix;
}

void ExpressionConverter::setExpType(int e_type) {
	exp_type = e_type;
}