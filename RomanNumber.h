#include <string>
#include <cstdlib>
#include "Number.h"
using namespace std;
#ifndef ROMANNUMBER_h
#define ROMANNUMBER_h
class RomanNumber :public Number{
	private:
	//data member
	string StrValue; 
	//fungsi antara
	int digitToArabic(char); 
	void digitToRoman(int, string &, int &);
	
	//method
	public:
	RomanNumber();
	RomanNumber(string);
	RomanNumber(const RomanNumber&);
	~RomanNumber();
	string getStrValue(); //mengambil data member StrValue
	int toArabicNumber(); // menngubah data member ke arabic number
	string toRomanNumber(int); // mengubah arabic number ke roman number
};
#endif
