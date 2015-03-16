/* Calculator.h */
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <iostream>
#include <string>
using namespace std;

class Calculator {
	private :
		int OprType;
		int NumType;
		int ExpType;
		int Mode;
		CommandHistory cmdHistory;
	public :
		Calculator();
		Calculator(const Calculator&);
		~Calculator();
		const static int POSTFIKS_OPERATOR = 1;
		const static int INFIKS_OPERATOR = 2;
		const static int PREFIKS_OPERATOR = 3;
		const static int ARITMATIKA_OPERATOR = 1;
		const static int LOGIKA_OPERATOR = 2;
		const static int RELATIONAL_OPERATOR = 3;
		const static int ARABIC_NUMBER = 1;
		const static int ROMAWI_NUMBER = 2;
		const static int MODE_HITUNG = 1;
		const static int MODE_SETTING = 2;
		
		void setOperatorType(int);
		void setNumberType(int);
		void setExpressionType(int);
		int getOperatorType();
		int getNumberType();
		int getExpressionType();
		void executeCommand(string);
		void setMode(int);
		int getMode();
};
#endif