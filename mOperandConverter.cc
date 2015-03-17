#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include "OperandConverter.h"
using namespace std;

int main()
{
	//string in("X + II / V");
	string in("true & true ^ false | false");
	OperandConverter op;
	op.setExpression(in);
	string out = op.toArabicExpression();
	printf("%s\n",out.c_str());
	
	return 0;
}