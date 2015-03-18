#include "ArabicNumber.h"
#include <iostream>
using namespace std;
int main(){
	string s;
	cin>> s;
	ArabicNumber a(s);
	cout<<"Arabic : "<<a.toArabicNumber()<<endl;
	return 0;
}
