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
	//! A stack holding user's Set commands that will be used to undo
	Stack<string> undoStack;
	//! A stack holding user's Set commands that has been undone, so it can be redo
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
	
	/**
	* A function that pushes argument into stack
	* 
	* I.S top Stack = previous Argument
	*
	* F.S top Stack = argument
	*/
	void putCommand(string);
	
	/**
	* A function that will print n last user's inputs into screen
	* 
	* I.S Screen blank
	*
	* F.S top Stack = argument
	*/
	void showMem(int);
	
	//! A function that will print all user's inputs into screen
	void showAll();
	
	//! A function that will request filename and save all histories into filename
	void save();
	
	//! A function that will undo n user's last Set commands
	void undo(int);
	
	//! A function that will redo n user's undone Set commands
	void redo(int);
};
#endif