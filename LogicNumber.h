#include <string>
#include <cstdlib>
#include "Number.h"
#ifndef LOGICNUMBER_H
#define LOGICNUMBER_H
using namespace std;
class LogicNumber: public Number{
	private:
	//data member
	string StrValue;
	
	public:
	LogicNumber();
	LogicNumber(string);
	LogicNumber(const LogicNumber&);
	~LogicNumber();
	string getStrValue();
	long long toArabicNumber();
	string toLogicNumber(int);
};
#endif
