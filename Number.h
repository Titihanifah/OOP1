#include <string>

#ifndef NUMBER_H
#define NUMBER_H

class Number {
  protected : 
	virtual std::string getStrValue() = 0;
	virtual int toArabicNumber() = 0;
};
#endif
