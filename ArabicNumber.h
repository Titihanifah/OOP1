#include "Number.h"
#include <string>
using namespace std;
#ifndef ARABICNUMBER_H
#define ARABICNUMBER_H
//! Class ArabicNumber.
/*! 
	Class ArabicNumber untuk mengubah string dalam bentuk angka arab ke dalam bentuk integer
*/
class ArabicNumber : public Number {
	private :
		//! data member class.
		/*! 
			StrValue merupakan bentuk string
		*/
		string StrValue; 
		//! data member class (fungsi).
		/*! 
			numberConverter merupakan fungsi untuk mengubah string ke dalam bentuk integer
		*/
		int numberConverter(char);
	public :
		//! ArabicNumber constructor.
		ArabicNumber();
		//! ctor berparameter untuk kelas Arabic Number.
		/*! 
			Insialisasi StrValue dengan string s .
		*/
		ArabicNumber(string);
		//! cctor pada kelas Arabic Number.
		ArabicNumber(const ArabicNumber&);
		//!dtor pada kelas Arabic Number.
		~ArabicNumber();
		//! fungsi untuk mengambil StrValue
		string getStrValue(); 
		//! fungsi yang mengembalikan nilai long long, untuk mengubah string ke dalam bentuk angaka arab.
		long long toArabicNumber(); 
};
#endif
	