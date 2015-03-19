#include "OperandConverter.h"
#include "Calculator.h"
using namespace std;

OperandConverter::OperandConverter(Calculator* calculator){
	this->calculator = calculator;
}

void OperandConverter::setExpression(string in){
	romawiExpression = in;
}

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
	// if not an operator
	return 0;
}

string OperandConverter::toArabicExpression(){
	string res = ""; // string holding final value
	string temp = ""; // string holding temporary number while parsing string
	string spc = " "; // string representing a space
	int mode = 2; // 1 : previous char is operand , 2 : previous char is operator or space
	Number* num; // Number Object to store temporary operand while parsing
	
	for (int i=0;i<romawiExpression.length();i++)
	{
		if ((isOperator(romawiExpression[i])) || (romawiExpression[i] == ' '))
		{
			if (mode == 1)
			{
				//check the calculator's, which holds this object, number type settings
				if (calculator->getNumberType() == Calculator::ARABIC_NUMBER) {num = new ArabicNumber(temp);}
				else if (calculator->getNumberType() == Calculator::ROMAWI_NUMBER) {num = new RomanNumber(temp);}
				else if (calculator->getNumberType() == Calculator::LOGIC_NUMBER) {num = new LogicNumber(temp);}
			
				long long xx = num->toArabicNumber();
				ostringstream convert;convert << xx;
				
				res.append(convert.str()); // append operand
				temp = "";
			}		
			// set mode to 2
			mode = 2;
			// merely append the current character if it is an operator or space
			res.append(string(1,romawiExpression[i]));
		}
		else 
		{
			mode = 1;
			temp.append(1, romawiExpression[i]);
		}
	}
	
	// reach end of line and there is still operand left
	if (mode == 1){
		//check the calculator's, which holds this object, number type settings
		if (calculator->getNumberType() == Calculator::ARABIC_NUMBER) {num = new ArabicNumber(temp);}
		else if (calculator->getNumberType() == Calculator::ROMAWI_NUMBER) {num = new RomanNumber(temp);}
		else if (calculator->getNumberType() == Calculator::LOGIC_NUMBER) {num = new LogicNumber(temp);}
			
		long long xx = num->toArabicNumber();
		ostringstream convert;convert << xx;
				
		res.append(convert.str()); // append operand
	}
	// returning final string representing expression containing Arabic Numbers
	return res;
}
