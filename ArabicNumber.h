#include "Number.h"
#include <string>
using namespace std;
#ifndef ARABICNUMBER_H
#define ARABICNUMBER_H
//kelas untuk angka arab
class ArabicNumber : public Number {
	private :
		//data member
		string StrValue; 
		int numberConverter(char);
	public :
		ArabicNumber();
		/* ctor untuk kelas Arabic Number */
		/*Insialisasi StrValue dengan " " */
		ArabicNumber(string);
		/* ctor berparameter untuk kelas Arabic Number */
		/* Insialisasi StrValue dengan string s */
		ArabicNumber(const ArabicNumber&);
		/*cctor pada kelas Arabic Number */
		~ArabicNumber();
		/*dtor pada kelas Arabic Number */
		string getStrValue(); 
		/* fungsi untuk mengambil StrValue */
		long long toArabicNumber(); 
		/* fungsi untuk mengubah string ke integer */
};
#endif
	