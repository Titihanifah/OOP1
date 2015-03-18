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
	else{ // arabic number biasa, untuk ekspresi relasional
		int val=0, i=0;
		while(StrValue[i]!='\0'){
			val=val*10+(StrValue[i]-'0');
			i++;
		}
		return val;
	}
}

string LogicNumber::toLogicNumber(int L){
	if(L>0)
		return "true";
	else
		return "false";
}
