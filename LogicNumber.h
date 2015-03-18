#include <string>
#include <cstdlib>
#include "Number.h"
#ifndef LOGICNUMBER_H
#define LOGICNUMBER_H
using namespace std;
/**@brief Kelas turunan dari Number
* Kelas LogicNumber digunakan untuk merepresentasikan
* operand yang bertipe logika (true, false, 0, 1);
*/
class LogicNumber: public Number{
	private:
	//data member
	/**
	* data member
	*/
	string StrValue;
	
	public:
	/**
	* Constructor
	*/
	LogicNumber();
	/**
	* Constructor with parameter
	*/
	LogicNumber(string);
	/**
	* Copy constructor
	*/
	LogicNumber(const LogicNumber&);
	/**
	* Destructor
	*/
	~LogicNumber();
	/**
	* mengambil data member StrValue
	*/
	string getStrValue();
	/**
	* mengubah operand logika ke arabic number (1 / 0)
	*/
	long long toArabicNumber();
	/**
	* mengubah suatu arabic number ke logic number
	*/
	string toLogicNumber(int);
};
#endif
