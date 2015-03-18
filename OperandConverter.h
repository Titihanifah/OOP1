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
#include "Number.h"
#include "RomanNumber.h"
#include "LogicNumber.h"
#include "ArabicNumber.h"

class Calculator;

class OperandConverter
{
private:
	string romawiExpression;
	int isOperator(char in);
	Calculator* calculator;
	
public:
	//! OperandConverter constructor.
    /*!
		Takes in expression in string which is NOT an Arabic Expression ( Expression containing primitive integer )
    */
	OperandConverter(Calculator* calculator);
	
	//! A function which returns string containing expression in Arabic ( primitive integer )
	string toArabicExpression();
	
	void setExpression(string in);
};

#endif
