#include "LogicNumber.h"
#include <iostream>
int main(){
	string s;
	cin>>s;
	LogicNumber L(s);
	int res=L.toArabicNumber();
	printf("toArabic=%d\n",res);
	cout<<"back to Logic= "<<L.toLogicNumber(res)<<endl;
	return 0;
}
