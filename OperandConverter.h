#ifndef __OPERAND_CONVERTER__
#define __OPERAND_CONVERTER__

#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include "RomanNumber.h"

/************************************************************

Class OperandConverter (string)

Pre - condition : romawi string

Methods:
- toArabicExpression()  -  return string containing arabic expression

*************************************************************/

class OperandConverter
{
private:
	string romawiExpression;
	int isOperator(char in);
	
public:
	OperandConverter(string in);
	string toArabicExpression();
};

#endif