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

