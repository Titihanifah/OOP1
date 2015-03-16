#include "Stack.h"
#include <string>
#include <iostream>
using namespace std;
int main(){
	Stack <int> S(2);
	int e;
	printf("isEmpty(S)=%d\n",S.isEmpty());
	printf("isFull(S)=%d\n",S.isFull());
	S.push(5);
	S.push(3);
	printf("isEmpty(S)=%d\n",S.isEmpty());
	printf("isFull(S)=%d\n",S.isFull());
	Stack<int> S2=S;
	S.pop(e);
	printf("e=%d\n",e);
	int f;
	S2.pop(f);
	printf("f=%d\n",f);
	Stack<string> S3;
	S3.push("halo\n");
	string x;
	S3.pop(x);
	cout<<x;
	return 0;
}
