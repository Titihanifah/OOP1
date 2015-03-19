#include <string>
using namespace std;

#ifndef EXPRESSIONCONVERTER_H
#define EXPRESSIONCONVERTER_H

//!  Class ExpressionConverter
/*!
	A class that converts string of any expression to a postfix-expression string
	
	I.S "3 + 4"
	
	F.S "3 4 +"
*/
class ExpressionConverter {
  public :
	const static int POSTFIKS_OPERATOR = 2;
	//! konstanta untuk operator postfiks
	const static int INFIKS_OPERATOR = 1;
	//! konstanta untuk operator infiks
	const static int PREFIKS_OPERATOR = 3;
	//! konstanta untuk operator prefiks
	string toPostfix(string);
	//! Return postfix representation of the input string
	void setExpType(int);
	/*! Set exp_type with an integer taken from input
	
	I.S. exp_type terdefinisi
	
	F.S. exp_type diset dengan suatu nilai baru
	*/
  private :	
	int isOperator(char in);
	//! Menghasilkan true jika karakter in adalah operator
	//! @return 0 jika in bukan operator dan 1 jika in adalah operator
	int OperatorPrecedence(char op);
	//! Menghasilkan tingkat prioritas(precedence) suatu operator op
	//! @return tingkat prioritas(precedence) operator op, makin tinggi tingkatnya maka makin diprioritaskan 
	int exp_type;
	//! variabel tipe mode
};

#endif