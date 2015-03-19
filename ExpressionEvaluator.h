/*!
 *  \author  Elvan Owen
 *  \date    2015
 */

#ifndef __EXPRESSION_EVALUATOR__
#define __EXPRESSION_EVALUATOR__
#include <string>
#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include "Stack.h"
using namespace std;

//!  Class ExpressionEvaluator
/*!
	A class that return calculated values from a postfix-expression string
	
	I.S "3 4 +"
	
	F.S "7"
*/
class ExpressionEvaluator{
	//! A stack holding values to calculate the value of an expression
	Stack<int> st;
	//! A string used to hold temporary current values while parsing expression
	string temp;
	//! A string containing the expression which will be calculated
	string expression;
	//! A variable that tells if previous character is an operator or an operand
	int opFlag;
	/**
	* A function returning true if input character is an arithmetic operator ( + , - , * , % , / )
	*/
	int isOperatorArith(char);
	
	/**
	* A function returning true if input character is a logical / relational operator ( & , ! , | , ^ , > , < , = )
	*/
	int isOperatorLogic(char);
public:	
	//! A Default Constructor 
	ExpressionEvaluator();
	
	//! A Constructor taking a string as input parameter, representing the expression this object will calculates
	ExpressionEvaluator(string);
	
	//! A function returning calculated values of a postfix arithmetic - expression
	int calculateArith();
	
	//! A function returning calculated values of a postfix logical - expression
	int calculateLogic();
	
	//! A function that sets current's expression to new expression
	void setExpression(string);
};
#endif
