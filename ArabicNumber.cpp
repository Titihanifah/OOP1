#include "ArabicNumber.h"
#include <iostream>
ArabicNumber::ArabicNumber() {
	StrValue = " ";
}
ArabicNumber::ArabicNumber(string s) {
	StrValue = s;
}
ArabicNumber::ArabicNumber(const ArabicNumber& a) {
	StrValue = a.StrValue;
}
ArabicNumber::~ArabicNumber() {
}

string ArabicNumber::getStrValue() {
	return StrValue;
}

int ArabicNumber::convertNumber(char c) {
	switch (c) {
		case '0' : return 0;
				   break;
		case '1' : return 1;
				   break;
		case '2' : return 2;
				   break;
		case '3' : return 3;
				   break;
		case '4' : return 4;
				   break;
		case '5' : return 5;
				   break;
		case '6' : return 6;
				   break;
		case '7' : return 7;
				   break;
		case '8' : return 8;
				   break;
		case '9' : return 9;
				   break;
	}
}

long long ArabicNumber::toArabicNumber() {
	long long sum;
	int num;
	long long value = 0;
	for(int i = 0; i < StrValue.length(); i++){
		num = convertNumber(StrValue[i]);
		long double pangkat = 1;
		// hitung hasil pangkat
		for (int j = 1; j <= StrValue.length()- (i+1); j++) {
			pangkat = pangkat * 10;
		}
		sum = num * pangkat;
		value += sum;
	} 
	return value;
}
