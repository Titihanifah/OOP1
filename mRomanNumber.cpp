#include "RomanNumber.h"
#include <iostream>
using namespace std;
int main(){
	string s;
	cin>> s;
	RomanNumber n(s);
	printf("arabic=%d",n.toArabicNumber());
	return 0;
}
