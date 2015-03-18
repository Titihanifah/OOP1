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
	public :
		ArabicNumber();
		ArabicNumber(string);
		ArabicNumber(const ArabicNumber&);
		~ArabicNumber();
		string getStrValue(); // fungsi untuk mengambil StrValue
};
#endif
	