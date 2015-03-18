#include "ExpressionConverter.h"
#include <iostream>
using namespace std;

int main()
{
	ExpressionConverter ec;
	ec.setExpType(3);
	string postfix, exp;
	//exp = "+ 2 - 51 * 7 3";
	//exp = "+ 2 - 1 7";
	exp = "& 2 ! 5";
	postfix = ec.toPostfix(exp);
	cout << postfix << endl;
	
	ec.setExpType(2);
	//exp = "2 + 3";
	//exp = "2 + 3 * 5";
	//exp = "2 * 3 + 5";
	//exp = "(2 + 3)";
	//exp = "((2 + 3) * 5)";
	//exp = "2 * (3 + 5)";	
	//exp = "((28 - 7) % (3 + 4))";
	exp = "-24 > 3 & 4 < -7";
	postfix = ec.toPostfix(exp);
	cout << postfix << endl;
	
	ec.setExpType(1);
	exp = "2 5 +";
	postfix = ec.toPostfix(exp);
	cout << postfix << endl;
	return 0;
}