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

//! forward reference
class Calculator;

class CommandHistory
{	
	Stack<string> undoStack; /*!< stack holding user's SET commands that enables them to undo */
	Stack<string> redoStack; /*!< stack holding user's SET which has been undone so that they can redo what they had undone */
	Stack<string> tempStack; /*!< stack for holding temporary value while iterating through every elements inside another stack */
	Stack<string> saveStack; /*!< stack holding every user's commands ( Expression and Set and Others ) that is used to be saved or displayed */
	Calculator* calculator; /*!< Calculator Object which contains this Object */
	/**
	* a function returning true if input string is an expression
	* @param in a string argument.
	*/
	int isExpression(string in);
	
public:
	/**
	* a Constructor which takes Calculator Object as argument
	* @param in a string argument.
	* save Calculator Object which holds this Object so that this Object can change the Calculator's Settings
	*/
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
	
	//! undo(n) will undo n user's last SET commands
	void undo(int);
	
	//! redo(n) will redo n user's undone SET commands
	void redo(int);
};
#endif