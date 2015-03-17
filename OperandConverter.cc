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
	string res="";
	string temp="";
	int flag;
	
	for (int i=0;i<romawiExpression.length();i++)
	{
		if ((flag = isOperator(romawiExpression[i])) == 1) // arithmetic
		{
			//printf("temp : %s\n",temp.c_str());
			RomanNumber n(temp);
			int xx = n.toArabicNumber();
			//int xx = romawiToInteger((char*)temp.c_str());
			ostringstream convert;
			convert << xx;
			res.append(convert.str());
			//printf("op : %s\n",string(1,romawiExpression[i]).c_str());
			res.append(string(1,romawiExpression[i]));
			temp = "";
		}else if ((flag = isOperator(romawiExpression[i])) == 2) // logic
		{
			//printf("temp : %s\n",temp.c_str());
			LogicNumber n(temp);
			int xx = n.toArabicNumber();
			//int xx = romawiToInteger((char*)temp.c_str());
			ostringstream convert;
			convert << xx;
			res.append(convert.str());
			//printf("op : %s\n",string(1,romawiExpression[i]).c_str());
			res.append(string(1,romawiExpression[i]));
			temp = "";
		}
		else
		{
			temp.append(string(1,romawiExpression[i]));
		}
	}
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
		int xx = n.toArabicNumber();
		//int xx = romawiToInteger((char*)temp.c_str());
		ostringstream convert;
		convert << xx;
		res.append(convert.str());
	}
	return res;
}
