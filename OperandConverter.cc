#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include "OperandConverter.h"

using namespace std;

class OperandConverter
{
private:
	string romawiExpression;
	
public:
	OperandConverter::OperandConverter(string in)
	{
		romawiExpression = in;
	}
	
private:
	int OperandConverter::romawiToInteger(char* romawi)
	{
		int fre[256];
		int val[256];
		int res = 0;
	
		for (int i=0;i<256;i++) {fre[i] = 0;val[i] = 0;}
	
		val['I'] = 1;val['i'] = 1;
		val['V'] = 5;val['v'] = 5;
		val['X'] = 10;val['x'] = 10;
		val['L'] = 50;val['l'] = 50;
		val['C'] = 100;val['c'] = 100;
		val['D'] = 500;val['d'] = 500;
		val['M'] = 1000;val['m'] = 1000;
	
		for (int i=0;i<strlen(romawi);i++)
		{
			fre[romawi[i]]++;
			if (fre[romawi[i]] > 3) return -1;
		}
	
		if (fre['V'] + fre['v'] == 2) return -1;
		if (fre['L'] + fre['l'] == 2) return -1;
		if (fre['D'] + fre['d'] == 2) return -1;
	
		int i = 0;
		while (i<strlen(romawi)-1)	
		{
			if (val[romawi[i]] < val[romawi[i+1]])
			{
				res+= val[romawi[i+1]] - val[romawi[i]];
				i+=2;
			}else
			{
				res+= val[romawi[i]];
				i++;
			}
		}
	
		if (i == strlen(romawi)-1) res+=val[romawi[strlen(romawi)-1]];
		return res;
	}
	
	int OperandConverter::isOperator(char in)
	{
		if (in == '+') return 1;
		if (in == '-') return 1;
		if (in == '/') return 1;
		if (in == '*') return 1;
		if (in == '%') return 1;
		return 0;
	}
	
public:
	string OperandConverter::toArabicExpression()
	{
		string res="";
		string temp="";
		
		for (int i=0;i<romawiExpression.length();i++)
		{
			if (isOperator(romawiExpression[i]))
			{
				//printf("temp : %s\n",temp.c_str());
				int xx = romawiToInteger((char*)temp.c_str());
				ostringstream convert;
				convert << xx;
				res.append(convert.str());
				//printf("op : %s\n",string(1,romawiExpression[i]).c_str());
				res.append(string(1,romawiExpression[i]));
				temp = "";
			}else
			{
				temp.append(string(1,romawiExpression[i]));
			}
		}
		if (temp!="")
		{
			//printf("temp : %s\n",temp.c_str());
			int xx = romawiToInteger((char*)temp.c_str());
			ostringstream convert;
			convert << xx;
			res.append(convert.str());
		}
		return res;
	}
};