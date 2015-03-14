#include <cstdlib>
#include <cassert>
#include <cstdio>

#ifndef Stack_h
#define Stack_h
template <class T>
class Stack{
	public:
	//ctor, cctor, dtor
	Stack();
	Stack(int);
	Stack(const Stack&);
	~Stack();
	
	//methods
	void push(T);
	void pop(T&);
	int getSize();
	T getTop();
	
	private:
	//data member
	const int defaultSize;
	int topStack;
	int size;
	T *elmt;
};
#include "Stack.cpp" // only for class-template
#endif
