#include "OperandConverter.h"
#include "Calculator.h"
using namespace std;

/**
* a Constructor taking Calculator Object which contains this Object
* @param calculator a Calculator Object argument.
*/
OperandConverter::OperandConverter(Calculator* calculator){
	this->calculator = calculator;
}

/**
* a function that set the expression this object is holding
* @param in a string argument.
*/
void OperandConverter::setExpression(string in){
	romawiExpression = in;
}

/**
* a function returning true if a character is an operator
* @param in a character argument.
*/
int OperandConverter::isOperator(char in)
{
	if (in == '+') return 1;
	if (in == '>') return 1;
	if (in == '<') return 1;
	if (in == '=') return 1;
	if (in == '-') return 1;
	if (in == '/') return 1;
	if (in == '*') return 1;
	if (in == '%') return 1;
	if (in == '&') return 1;
	if (in == '|') return 1;
	if (in == '!') return 1;
	if (in == '^') return 1;
	if (in == '(') return 1;
	if (in == ')') return 1;
	//! if not an operator
	return 0;
}

/**
* a function returning the string expression it holds into an Expression containing Arabic Number ( primitive integer )
*/
string OperandConverter::toArabicExpression(){
	string res = ""; /*!< string holding final value */
	string temp = ""; /*!< string holding temporary number while parsing string */
	string spc = " "; /*!< string representing a space */
	int mode = 1; /*!< 1 : previous operator , 2 : previous operand */
	Number* num; /*!< Number Object to store temporary operand while parsing */
	
	for (int i=0;i<romawiExpression.length();i++)
	{
		if (isOperator(romawiExpression[i]))
		{
			//! set mode to 1
			mode = 1;
			//! merely append the current character if it is an operator
			res.append(string(1,romawiExpression[i]));
		}
		else if (romawiExpression[i] == ' ')
		{
			/**
		    * mode = 1 : if previous character is an operator
		    */
			if (mode == 1) res.append(spc);
			else //! mode = 2 : if previous character is an operand
			{
				/**
				* check the calculator's, which holds this object, number type settings
				*/
				if (calculator->getNumberType() == Calculator::ARABIC_NUMBER) {num = new ArabicNumber(temp);}
				else if (calculator->getNumberType() == Calculator::ROMAWI_NUMBER) {num = new RomanNumber(temp);}
				else if (calculator->getNumberType() == Calculator::LOGIC_NUMBER) {num = new LogicNumber(temp);}
			
				long long xx = num->toArabicNumber();
				ostringstream convert;convert << xx;
			
				res.append(convert.str()); // append operand
				res.append(spc); // append space
				temp = "";
			}
		}
		else //! if current character is part of an operand
		{
			//! set mode to 2 : which means previous character is an operand
			mode = 2;
			//! buffering current operand
			temp.append(string(1,romawiExpression[i]));
		}
	}
	
	//! reach end of line and there is still operand left
	if (temp!=""){
		/**
		* check the calculator's, which holds this object, number type settings
		*/
		if (calculator->getNumberType() == Calculator::ARABIC_NUMBER) {num = new ArabicNumber(temp);}
		else if (calculator->getNumberType() == Calculator::ROMAWI_NUMBER) {num = new RomanNumber(temp);}
		else if (calculator->getNumberType() == Calculator::LOGIC_NUMBER) {num = new LogicNumber(temp);}
		
		int xx = num->toArabicNumber();
		ostringstream convert;convert << xx;
		
		res.append(convert.str());
	}
	//! returning final string representing expression containing Arabic Numbers
	return res;
}
