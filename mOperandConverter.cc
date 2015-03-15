#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include "OperandConverter.h"
using namespace std;

int main()
{
	
	string in("XL+IX/C");
	operandConverter op(in);
	string out = op.toArabicExpression();
	printf("%s\n",out.c_str());
	
	return 0;
}