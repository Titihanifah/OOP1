/*!
 *  \author  Elvan Owen
 *  \date    2015
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

//!  Class OperandConverter
/*!
	A class to change the types of Operands in a given expression string.
	Numbers in an expression is converted into Arabic Number ( primitive integer ) for easy calculation later on
	
	I.S "VII + I - X"
	
	F.S "7 + 1 - 10"

	I.S "true & (false & ! true)"
	
	F.S "1 & ( 0 & ! 1)"
*/
class OperandConverter
{
private:
	//! A string containing expression that will be operand - converted
	string expression;
	//! A function returning true if a character is an operator
	int isOperator(char in);
	//! A variable pointing to Calculator Object which contains this Object
	Calculator* calculator;
	
public:
	//! OperandConverter constructor.
    /*!
		A Constructor taking Calculator Object which contains this Object
    */
	OperandConverter(Calculator* calculator);
	
	//! A function returning changed expression into an Arabic Number expression
	string toArabicExpression();
	
	/*!
	A function that set the expression this object is holding

	I.S expression = old expression
	
	F.S expression = new expression
	*/
	void setExpression(string);
};

#endif
