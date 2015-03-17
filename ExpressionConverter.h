#include <string>
using namespace std;

#ifndef EXPRESSIONCONVERTER_H
#define EXPRESSIONCONVERTER_H

class ExpressionConverter {
  public :
	const static int POSTFIKS_OPERATOR = 1;
	const static int INFIKS_OPERATOR = 2;
	const static int PREFIKS_OPERATOR = 3;
	string toPostfix(string);
	void setExpType(int);
  private :	
	int isOperator(char in);
	int OperatorPrecedence(char op);
	int exp_type;
};

#endif