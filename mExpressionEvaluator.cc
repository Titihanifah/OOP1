#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include "Stack.h"
#include "ExpressionEvaluator.h"

using namespace std;

int main()
{
	ExpressionEvaluator ee("5 3 32 4 + * /");
	int res = ee.calculate();
	printf("%d\n",res);
	return 0;
}