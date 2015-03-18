#include "RomanNumber.h"
#include <iostream>
#include <cstdio>;
using namespace std;
int main(){
	string s;
	cin>> s;
	RomanNumber n(s);
	int res=n.toArabicNumber();
	//printf("arabic=%d\n",res);
	cout<<"back to Roman= "<<n.toRomanNumber(res)<<endl;
	return 0;
}
