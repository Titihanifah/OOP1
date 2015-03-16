#include <iostream>
#include <cstdio>
#include <string>
#include "Stack.h"
#include "Calculator.h"

class CommandHistory
{
	Stack<string> undoStack;
	Stack<string> redoStack;
	Calculator* calculator;
	
public:
	CommandHistory(Calculator* calculator);
	
	void putCommand(string in);
	
	void undo();
	
	void redo();
	
	void showMem();
	
	void showAll();
	
	void save();
};