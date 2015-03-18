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

long long RomanNumber:: toArabicNumber(){
	printf("masuk\n");
	long long sum=0, prev=0;
	for(int i=(StrValue.length()-1); i>=0; i--){
		//printf("prev=%d\n",prev);
		if(digitToArabic(StrValue[i])<prev){
			sum -= digitToArabic(StrValue[i]);
					prev = digitToArabic(StrValue[i]);
		}
		else{
				sum += digitToArabic(StrValue[i]);
				prev = digitToArabic(StrValue[i]);
		}
	}
	printf("sum : %d\n",sum);
	return sum;
}
int RomanNumber:: digitToArabic(char c){
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
string RomanNumber::toRomanNumber(int R){
	int temp_num=R, kurangi=0;
	string hasil,temp_hasil;
	if(temp_num>=1 && temp_num<=3999){
		while(temp_num>0){
			digitToRoman(temp_num,temp_hasil, kurangi);
			temp_num-=kurangi;
			hasil.append(temp_hasil);
		}
	}
	return hasil;
}

void RomanNumber:: digitToRoman(int n, string &hasil, int &kurangi){
		if(n>=1000){ 
			hasil="M";
			kurangi=1000;
		}
		else if(n>=900){
			hasil="CM";
			kurangi=900;
		}
		else if(n>=500){
			hasil="D";
			kurangi=500;
		}
		else if(n>=400){
			hasil="CD";
			kurangi=400;
		}
		else if(n>=100){
			hasil="C";
			kurangi=100;
		}
		else if(n>=90){
			hasil="XC";
			kurangi=90;
		}
		else if(n>=50){
			hasil="L";
			kurangi=50;
		}
		else if(n>=40){
			hasil="XL";
			kurangi=40;
		}
		else if(n>=10){
			hasil="X";
			kurangi=10;
		}
		else if(n>=9){
			hasil="IX";
			kurangi=9;
		}
		else if(n>=5){
			hasil="V";
			kurangi=5;
		}
		else if(n>=4){
			hasil="IV";
			kurangi=4;
		}
		else if(n>=1){
			hasil="I";
			kurangi=1;
		}
}
