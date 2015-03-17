//!  A class to change types of Operands
/*!
	Numbers in an expression is converted into Arabic Number which is
	a normal primitive integer
*/

#ifndef __OPERAND_CONVERTER__
#define __OPERAND_CONVERTER__

#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include "RomanNumber.h"

class OperandConverter
{
private:
	string romawiExpression;
	int isOperator(char in);
	
public:
	//! OperandConverter constructor.
    /*!
		Takes in expression in string which is NOT an Arabic Expression ( Expression containing primitive integer )
    */
	OperandConverter();
	
	//! A function which returns string containing expression in Arabic ( primitive integer )
	string toArabicExpression();
	
	void setExpression(string in);
};

#endif