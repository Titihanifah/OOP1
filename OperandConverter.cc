#include "OperandConverter.h"
using namespace std;

OperandConverter::OperandConverter()
{}

void OperandConverter::setExpression(string in)
{
	romawiExpression = in;
}

// return 1 for arithmetic expression and return 2 for logic expression
int OperandConverter::isOperator(char in)
{
	if (in == '+') return 1;
	if (in == '-') return 1;
	if (in == '/') return 1;
	if (in == '*') return 1;
	if (in == '%') return 1;
	if (in == '&') return 2;
	if (in == '|') return 2;
	if (in == '!') return 2;
	if (in == '^') return 2;
	return 0;
}
	
string OperandConverter::toArabicExpression()
{
	string res = "";
	string temp = "";
	string spc = " ";
	int flag, space = 0;
	
	for (int i=0;i<romawiExpression.length();i++)
	{
		if (isOperator(romawiExpression[i]) == 1) // arithmetic
		{
			if (flag != 1 || flag != 2) flag = 1;
			RomanNumber n(temp);
			int xx = n.toArabicNumber();
			//printf("xx : %d\n",xx);
			ostringstream convert;
			convert << xx;
			res.append(convert.str());
			if (space == 1)
			{
				space = 0;
				res.append(spc);
			}
			res.append(string(1,romawiExpression[i]));
			temp = "";
		}else if (isOperator(romawiExpression[i]) == 2) // logic
		{
			if (flag != 1 || flag != 2) flag = 2;
			if (temp.compare("") == 0)
			{
				if (space == 1) {space = 0;res.append(spc);}
				res.append(string(1,romawiExpression[i]));
				continue;
			}
			LogicNumber n(temp);
			int xx = n.toArabicNumber();
			ostringstream convert;
			convert << xx;
			res.append(convert.str());
			if (space == 1)
			{
				space = 0;
				res.append(spc);
			}
			res.append(string(1,romawiExpression[i]));
			temp = "";
		}
		else if (romawiExpression[i] == ' ')
		{
			space = 1;
		}
		else
		{
			if (space == 1) {space = 0;res.append(spc);}
			temp.append(string(1,romawiExpression[i]));
		}
	}
	//printf("flag : %d\n",flag);
	if (flag == 1 && temp!="")
	{
		//printf("temp : %s\n",temp.c_str());
		RomanNumber n(temp);
		int xx = n.toArabicNumber();
		//int xx = romawiToInteger((char*)temp.c_str());
		ostringstream convert;
		convert << xx;
		res.append(convert.str());
	}
	else if (flag == 2 && temp!="")
	{
		//printf("temp : %s\n",temp.c_str());
		LogicNumber n(temp);
		//printf("temp : %s\n",temp.c_str());
		int xx = n.toArabicNumber();
		//printf("xx : %d\n",xx);
		//int xx = romawiToInteger((char*)temp.c_str());
		ostringstream convert;
		convert << xx;
		res.append(convert.str());
	}
	return res;
}
