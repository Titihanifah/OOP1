#include "number.h"
class RomanNumber: public Number{
	private:
	string StrValue;
	public:
	string getStrValue(); //mengambil data member StrValue
	int toArabicNumber(); // menngubah data member ke arabic number
};