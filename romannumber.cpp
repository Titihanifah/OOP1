#include "RomanNumber.h"

RomanNumber::RomanNumber(){
	StrValue="";
}
RomanNumber::RomanNumber(string s){
	StrValue=s;
}
RomanNumber::RomanNumber(const RomanNumber& n){
	StrValue=n.StrValue;
}
RomanNumber::~RomanNumber(){}

string RomanNumber::getStrValue(){
	return StrValue;
}
int RomanNumber:: toArabicNumber(){
	int sum=0; int prev=0;
	for(int i=(StrValue.length()-1); i>=0; i--){
		//printf("prev=%d\n",prev);
		if(digitConvert(StrValue[i])<prev){
			sum -= digitConvert(StrValue[i]);
					prev = digitConvert(StrValue[i]);
		}
		else{
				sum += digitConvert(StrValue[i]);
				prev = digitConvert(StrValue[i]);
		}
	}
	return sum;
}
int RomanNumber:: digitConvert(char c){
	switch(c){
		case 'I':return 1;
		case 'V':return 5;
		case 'X':return 10;
		case 'L':return 50;
		case 'C':return 100;
		case 'D':return 500;
		case 'M':return 1000;
    }
}

