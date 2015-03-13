#include "romannumber.h"

string RomanNumber::getStrValue(){
	return StrValue;
}
int RomanNumber:: toArabicNumber(){
	int i=0;
	switch(StrValue[i]){
		case 'I':return 1;
		case 'V':return 5;
		case 'X':return 10;
		case 'L':return 50;
		case 'C':return 100;
		case 'D':return 500;
		case 'M':return 1000;
    }
	int sum=0; char prev='%';
	for(int i=(StrValue.length()-1); i>=0; i--){
		if(value(StrValue[i])<sum && (StrValue[i]!=prev)){
			sum -= value(StrValue[i]);
					prev = StrValue[i];
		}
		else{
				sum += value(StrValue[i]);
				prev = StrValue[i];
		}
	}
	return sum;
}
