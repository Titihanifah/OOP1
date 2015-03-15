#include "Stack.h"
using namespace std;
template <class T>
Stack<T> :: Stack():defaultSize(50){
	topStack=-1;
	size=defaultSize;
	elmt = new T[size];
}
template <class T>
Stack<T>::Stack(int n):defaultSize(50){
	topStack=-1;
	size=n;
	elmt = new T[size];
}
template <class T>
Stack<T>:: Stack(const Stack& S):defaultSize(50){
	topStack=S.topStack;
	size=S.size;
	elmt=new T[size];
	for(int i=0;i<size;i++)
		elmt[i]=S.elmt[i];
}
template <class T>
Stack<T>::~Stack(){
	delete[] elmt;
}
template<class T>
void Stack<T>::push(T e){
	assert(topStack!=size-1);
	topStack++;
	elmt[topStack]=e;
}
template<class T>
void Stack<T>::pop(T& e){
	assert(topStack!=-1);
	e=elmt[topStack];
	topStack--;
}
template<class T>
int Stack<T>:: getSize(){
	return size;
}	
template<class T>
T Stack<T>::getTop(){
	return elmt[topStack];
}