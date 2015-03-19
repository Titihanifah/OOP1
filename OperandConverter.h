/*!
 *  \author  Elvan Owen
 *  \date    1990-2011
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

//!  OperandConverter class
/*!
	A class to change types of Operands
	Numbers in an expression is converted into Arabic Number ( primitive integer )
*/
class OperandConverter
{
private:
	string expression;
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
	
	/*!
	A function that set the expression this object is holding

	I.S expression = old expression
	
	F.S expression = new expression
	*/
	void setExpression(string);
};

#endif
