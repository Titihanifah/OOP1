//!  CommandHistory class.
/*!
	Class which has its own stack to remember user's past command.
	Class is able to perform a number of methods related to user's past command
*/

#ifndef __COMMAND_HISTORY__
#define __COMMAND_HISTORY__

#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include "Stack.h"
using namespace std;

class Calculator;

class CommandHistory
{
	//friend class Calculator;
	
private:
	Stack<string> undoStack;
	Stack<string> redoStack;
	Stack<string> tempStack;
	Stack<string> saveStack;
	Calculator* calculator;
	int isExpression(string in);
	
public:
	//! CommandHistory constructor.
	CommandHistory(Calculator* calculator);
	
	//! putCommand pushes argument into stack
	/*!
	\param in - a string argument.
	*/
	void putCommand(string in);
	
	//! showMem(n) will print n user's histories into screen
	/*!
	\param in - a string argument.
	*/
	void showMem(int);
	
	//! showAll will print all user's histories into screen
	void showAll();
	
	//! save will request filename and save all commands in memory to filename
	void save();
	
	void undo(int);
	void redo(int);
};

#endif