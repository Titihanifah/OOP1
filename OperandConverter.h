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
	//! A function returning true if a character is an operator
	int isOperator(char in);
	Calculator* calculator;
	
public:
	//! OperandConverter constructor.
    /*!
		A Constructor taking Calculator Object which contains this Object
    */
	OperandConverter(Calculator* calculator);
	
	//! A function returning the string expression it holds into an Expression containing Arabic Number ( primitive integer )
	string toArabicExpression();
	
	//! A function that set the expression this object is holding
	void setExpression(string in);
};

#endif
