#include <string>
using namespace std;

#ifndef EXPRESSIONCONVERTER_H
#define EXPRESSIONCONVERTER_H

class ExpressionConverter {
  public :
	string toPostfix(string);
	void setExpType(int);
  private :	
	int isOperator(char in);
	int OperatorPrecedence(char op);
	int exp_type;
};

#endif