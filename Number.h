#include <string>

#ifndef NUMBER_H
#define NUMBER_H
//! Class Number
/*! Abstract class that provide data type for a number */
class Number {
public:
	virtual std::string getStrValue() = 0;
	//! return string representation of a number 
	//! @return string representation of a number  
	virtual long long toArabicNumber() = 0;
	//! convert any number to arabic number
	//! @return arabic representation of any number
};
#endif
