#ifndef __COMMAND_HISTORY__
#define __COMMAND_HISTORY__

#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include "Stack.h"
#include "Calculator.h"
using namespace std;

class CommandHistory
{
	Stack<string> undoStack;
	Stack<string> redoStack;
	Calculator* calculator;
	
public:
	CommandHistory(Calculator* calculator);
	
	void putCommand(string in);
	
	void undo(int);
	void undo();
	
	void redo(int);
	void redo();
	
	void showMem(int);
	
	void showAll();
	
	void save(string);
};

#endif