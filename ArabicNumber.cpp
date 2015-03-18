#include "ArabicNumber.h"
#include <iostream>

ArabicNumber::ArabicNumber() {
	StrValue = "";
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

int ArabicNumber::numberConverter(char c) {
	switch(c) {
		case '0' : return 0;
		case '1' : return 1;
		case '2' : return 2;
		case '3' : return 3;
		case '4' : return 4;
		case '5' : return 5;
		case '6' : return 6;
		case '7' : return 7;
		case '8' : return 8;
		case '9' : return 9;
	}
}

long long ArabicNumber::toArabicNumber() {
	long long sum = 0, hasil = 1;
	int num;
	for (int i = StrValue.length() - 1 ; i >= 0; i--) {
		num = numberConverter(StrValue[i]);
		cout<<num<<endl;
		sum += num * hasil;
		hasil = hasil * 10;
	}
	return sum;
}
