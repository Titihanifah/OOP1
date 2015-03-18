/*!
 *  \author  Elvan Owen
 *  \date    1990-2011
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

//!  ExpressionEvaluator class
/*!
	A class to return values from a postfix-expression string
*/
class ExpressionEvaluator{
	Stack<int> st; /*!< stack holding values to calculate the value of an expression */
	string temp;
	string expression;
	int opFlag;
	/**
	* a function returning true if input character is an arithmetic operator ( + , - , * , % , / )
	* @param in a character argument.
	*/
	int isOperatorArith(char in);
	
	/**
	* a function returning true if input character is a logical / relational operator ( & , ! , | , ^ , > , < , = )
	* @param in a character argument.
	*/
	int isOperatorLogic(char in);
	
public:	
	
	//!a Default Constructor 
	ExpressionEvaluator();
	
	//! a Constructor taking string input as a parameter representing the expression this object will holds
	ExpressionEvaluator(string);
	
	//! a function returning values of a postfix arithmetic - expression string this object is holding
	int calculateArith();
	
	//! a function returning values of a postfix logical - expression string this object is holding
	int calculateLogic();
	
	//! a function that set the expression this object is holding
	void setExpression(string);
};
#endif
