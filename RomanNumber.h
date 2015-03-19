#include <string>
#include <cstdlib>
#include "Number.h"
#include <iostream>
using namespace std;
#ifndef ROMANNUMBER_h
#define ROMANNUMBER_h
/**@brief Kelas turunan dari Number
* Kelas RomanNumber digunakan untuk merepresentasikan
* objek yang bertipe angka romawi
*/
class RomanNumber :public Number{
	private:
	//data member
	/**
	* data member
	*/
	string StrValue; 
	//fungsi antara
	/**
	* fungsi antara dari toArabicNumber()
	*/
	int digitToArabic(char); 
	/**
	* fungsi antara dari toRomanNumber()
	*/
	void digitToRoman(int, string &, int &);
	
	//method
	public:
	/**
	* Constructor
	*/
	RomanNumber();
	/**
	* Constructor with parameter
	*/
	RomanNumber(string);
	/**
	* Copy Constructor
	*/
	RomanNumber(const RomanNumber&);
	/**
	* Destructor
	*/
	~RomanNumber();
	/**
	* Mengambil data member StrValue
	*/
	string getStrValue(); //mengambil data member StrValue
	/**
	* Mengubah data member StrValue ke arabic number
	*/
	long long toArabicNumber(); // menngubah data member ke arabic number
	/**
	* Mengubah suatu arabic number ke roman number
	*/
	string toRomanNumber(int); // mengubah arabic number ke roman number
};
#endif
