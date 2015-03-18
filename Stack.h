#include <cstdlib>
#include <cassert>
#include <cstdio>

#ifndef STACK_H
#define STACK_H
//deklarasi kelas generik
/**@brief Kelas generik untuk stack
* Stack dapat menampung tipe elemen apapun
*/
template <class T>
class Stack{
	public:
	//ctor, cctor, dtor
	/**
	* Constructor
	*/
	Stack();
	/**
	* Constructor dengan parameter jumlah maksimum elemen
	*/
	Stack(int);
	/**
	* Copy Constructor
	*/
	Stack(const Stack&);
	/**
	* Destructor
	*/
	~Stack();
	
	//methods
	/**
	* memeriksa apakah stack kosong
	*/
	bool isEmpty();
	/**
	* Constructor
	*/
	//* memeriksa apakah stack penuh
	bool isFull();
	
	/**
	* Menambah elemen baru di paling atas
	*/
	void push(T);
	/**
	* Mengambil elemen teratas dari stack
	*/
	void pop(T&);
	/**
	* Mengambil ukuran stack
	*/
	int getSize();
	/**
	* Mengambil elemen teratas
	*/
	T getTop();
	
	private:
	//data member
	/**
	* ukuran default stack;
	*/
	const int defaultSize;
	/**
	* mengembalikan indeks posisi teratas
	*/
	int topStack;
	/**
	* mengembalikan ukuran stack
	*/
	int size;
	/**
	* tabel penampung elemen
	*/
	T *elmt;
};

//implementasi kelas generik
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
template <class T>
bool Stack<T>::isEmpty(){
	return topStack==-1;
}
template <class T>
bool Stack<T>::isFull(){
	return topStack==size-1;
}
template<class T>
void Stack<T>::push(T e){
	assert(!isFull());
	topStack++;
	elmt[topStack]=e;
}
template<class T>
void Stack<T>::pop(T& e){
	assert(!isEmpty());
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
#endif
