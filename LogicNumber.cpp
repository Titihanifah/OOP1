#include "LogicNumber.h"

LogicNumber::LogicNumber(){
	StrValue="";
}

LogicNumber::LogicNumber(string s){
	StrValue=s;
}

LogicNumber::LogicNumber(const LogicNumber& n){
	StrValue= n.StrValue;
}

LogicNumber::~LogicNumber(){}

string LogicNumber:: getStrValue(){
	return StrValue;
}

int LogicNumber:: toArabicNumber(){
	if(StrValue.compare("1")==0 || StrValue.compare("true")==0)
		return 1;
	else if(StrValue.compare("0")==0 || StrValue.compare("false")==0)
		return 0;
}
