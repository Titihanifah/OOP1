#ifndef __OPERAND_CONVERTER__
#define __OPERAND_CONVERTER__

/************************************************************

Class OperandConverter (string)

Pre - condition : romawi string

Methods:
- toArabicExpression()  -  return string containing arabic expression

*************************************************************/

class operandConverter
{
private:
	string romawiExpression;
	int romawiToInteger(char* romawi);
	int isOperator(char in);
	
public:
	operandConverter(string in);
	string toArabicExpression();
};

#endif