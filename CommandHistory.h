/*!
 *  \author  Elvan Owen
 *  \date    1990-2011
 */

#ifndef __COMMAND_HISTORY__
#define __COMMAND_HISTORY__

#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include "Stack.h"
using namespace std;

//! forward reference
class Calculator;

//!  Class CommandHistory
/*!
	Class which has its own stack to remember user's past command.
	Class is able to perform a number of methods related to user's past command
*/
class CommandHistory
{	
	//! A stack holding user's SET commands that will be used to undo
	Stack<string> undoStack;
	//! A stack holding user's SET commands that has been undone, so it can be redo
	Stack<string> redoStack;
	//! A stack holding temporary value for iterating and keeping old elements
	Stack<string> tempStack;
	//! A stack holding every user's commands ( Expression and Set and Others ) , used to be saved or displayed
	Stack<string> saveStack;
	//! A pointer to Calculator Object that contains this Object
	Calculator* calculator;
	//! A function returning true if input string is an expression
	int isExpression(string);
	
public:
	/**
	* a Constructor which takes Calculator Object as argument
	* save Calculator Object which holds this Object so that this Object can change the Calculator's Settings
	*/
	CommandHistory(Calculator*);
	
	//! putCommand pushes argument into stack
	void putCommand(string);
	
	//! showMem(n) will print n user's histories into screen
	void showMem(int);
	
	//! showAll will print all user's histories into screen
	void showAll();
	
	//! save will request filename and save all commands in memory to filename
	void save();
	
	//! undo(n) will undo n user's last SET commands
	void undo(int);
	
	//! redo(n) will redo n user's undone SET commands
	void redo(int);
};
#endif