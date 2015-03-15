#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
#include "Stack.h"
#include "ExpresseionEvaluator.h"

using namespace std;

int main()
{
	ExpressionEvaluator ee("53+");
	int res = ee.calculate();
	printf("%d\n",res);
	return 0;
}