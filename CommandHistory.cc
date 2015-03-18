#include "CommandHistory.h"
#include "Calculator.h"

CommandHistory::CommandHistory(Calculator* calculator)
{
	this->calculator = calculator;
}

void CommandHistory::putCommand(string in)
{
	if (in == "arith" || in == "logic" || in == "rel")
	{
		string temp = "SET opr "; // temporary string holding the value of user's input
		temp.append(string(in));
		// since this is a SET commands, it is pushed into undo Stack
		undoStack.push(temp);
		// every user's valid input is pushed into save Stack
		saveStack.push(temp);
	}else if(in == "arabic" || in == "roman")
	{
		string temp = "SET num "; // temporary string holding the value of user's input
		temp.append(string(in));
		// since this is a SET commands, it is pushed into undo Stack
		undoStack.push(temp);
		// every user's valid input is pushed into save Stack
		saveStack.push(temp);
	}else if(in == "post" || in == "in" || in == "pref")
	{
		string temp = "SET exp "; // temporary string holding the value of user's input
		temp.append(string(in));
		// since this is a SET commands, it is pushed into undo Stack
		undoStack.push(temp);
		// every user's valid input is pushed into save Stack
		saveStack.push(temp);
	}
	else
	{
		// every user's valid input is pushed into save Stack
		saveStack.push(in);
	}

}

int CommandHistory::isExpression(string in)
{
	const char* temp = in.c_str();
	char* firstArgument;
	sscanf(temp,"%s",firstArgument);
	
	// Comparing first word in user's input and check whether it is one of the available input which is not an expression
	if (strcmp(firstArgument,"Set") == 0) return 0;
	if (strcmp(firstArgument,"ShowMem") == 0) return 0;
	if (strcmp(firstArgument,"ShowAll") == 0) return 0;
	if (strcmp(firstArgument,"Undo") == 0) return 0;
	if (strcmp(firstArgument,"Redo") == 0) return 0;
	if (strcmp(firstArgument,"Save") == 0) return 0;
	
	// input is an expression
	return 1;
}

void CommandHistory::showMem(int n)
{
	printf("\nLast %d histories:\n\n",n);
	
	// popping last n histories for printing to screen from save Stack
	while(!saveStack.isEmpty() && n > 0)
	{
		string temp;
		saveStack.pop(temp);
		tempStack.push(temp);
		printf("%s\n",temp.c_str());
		n--;
	}
	
	// popping back last n histories back into save Stack
	while(!tempStack.isEmpty())
	{
		string temp;
		tempStack.pop(temp);
		saveStack.push(temp);
	}
}

void CommandHistory::showAll()
{
	printf("\nAll Histories:\n\n");
	
	// popping every last histories for printing to screen from save Stack
	while(!saveStack.isEmpty())
	{
		string temp;
		saveStack.pop(temp);
		tempStack.push(temp);
		printf("%s\n",temp.c_str());
	}
	
	// popping back all histories back into save Stack
	while(!tempStack.isEmpty())
	{
		string temp;
		tempStack.pop(temp);
		saveStack.push(temp);
	}
}

void CommandHistory::save()
{
	// requesting filename for user's output file
	printf("Filename : ");
	char temp[100];
	scanf("%s",temp);
	string filename = temp;
	FILE* fp = fopen(filename.c_str(),"w");
	
	// popping every last histories for saving to file from save Stack
	while(!saveStack.isEmpty())
	{
		string temp;
		saveStack.pop(temp);
		tempStack.push(temp);
		fprintf(fp,"%s\n",temp.c_str());
	}
	
	// popping back all histories back into save Stack
	while(!tempStack.isEmpty())
	{
		string temp;
		tempStack.pop(temp);
		saveStack.push(temp);
	}
	
	fclose(fp);
}

void CommandHistory::undo(int n)
{
	// if user has never change any Settings, then s/he cannot undo
	if (undoStack.isEmpty())
	{
		printf("No SET command(s), No undo.....\n");
		return;
	}
	// redo is just for the last undo, so we need to pop every elements in redo Stack whenever user start a new undo commands
	while (!redoStack.isEmpty())
	{
		string temp;
		redoStack.pop(temp);
	}
	for (int i=0;i<n && !undoStack.isEmpty();i++)
	{
		string temp; // string holding original string of user's input Set commands
		undoStack.pop(temp);
		redoStack.push(temp);
		char* ttemp =(char*) temp.c_str(); // temporary value to hold last user's Set commands
		char* tttemp;
		// takes the first word in user's Set commands
		sscanf(ttemp,"%s",tttemp);
		if (strcmp(ttemp,"SET") == 0)
		{
			// takes the second word in user's Set commands
			sscanf(ttemp,"%s",tttemp);
			
			// if user's command Set operator mode
			if (strcmp(ttemp,"opr") == 0)
			{
				// takes the third word in user's Set commands
				sscanf(ttemp,"%s",tttemp);
				
				// if user's command Set operator arithmetic mode ( + , - , / , * , % )
				if (strcmp(ttemp,"arith") == 0) calculator->setOperatorType(Calculator::ARITMATIKA_OPERATOR);
				// if user's command Set operator logic mode ( & , | , ^ , ! , < , > , = )
				if (strcmp(ttemp,"logic") == 0) calculator->setOperatorType(Calculator::LOGIKA_OPERATOR);
			}
			// if user's command Set number mode
			else if (strcmp(ttemp,"num") == 0)
			{
				// takes the third word in user's Set commands
				sscanf(ttemp,"%s",tttemp);
				
				// if user's command Set number mode to Arabic
				if (strcmp(ttemp,"arabic") == 0) calculator->setNumberType(Calculator::ARABIC_NUMBER);
				// if user's command Set number mode to Romawi
				if (strcmp(ttemp,"roman") == 0) calculator->setNumberType(Calculator::ROMAWI_NUMBER);
				// if user's command Set number mode to Logic ( true , false )
				if (strcmp(ttemp,"logic") == 0) calculator->setNumberType(Calculator::LOGIC_NUMBER);
			}
			// if user's command Set expression mode
			else if (strcmp(ttemp,"exp") == 0)
			{
				// takes the third word in user's Set commands
				sscanf(ttemp,"%s",tttemp);
				
				// if user's command Set expression mode to postfix
				if (strcmp(ttemp,"post") == 0) calculator->setExpressionType(Calculator::POSTFIKS_OPERATOR);
				// if user's command Set expression mode to infix
				if (strcmp(ttemp,"in") == 0) calculator->setExpressionType(Calculator::INFIKS_OPERATOR);
				// if user's command Set expression mode to prefix
				if (strcmp(ttemp,"pref") == 0) calculator->setExpressionType(Calculator::PREFIKS_OPERATOR);
			}
		}
	}
}

void CommandHistory::redo(int n)
{
	// if user has never undo anything, then s/he cannot redo
	if (redoStack.isEmpty())
	{
		printf("No undo, No redoooo....\n");
		return;
	}
	for (int i=0;i<n && !redoStack.isEmpty();i++)
	{
		string temp; // string holding original string of user's input Set commands
		redoStack.pop(temp);
		undoStack.push(temp);
		char* ttemp =(char*) temp.c_str(); // temporary value to hold last user's Set commands
		char* tttemp;
		sscanf(ttemp,"%s",tttemp);
		// takes the first word in user's Set commands
		if (strcmp(ttemp,"SET") == 0)
		{
			// takes the second word in user's Set commands
			sscanf(ttemp,"%s",tttemp);
			// if user's command Set operator mode
			if (strcmp(ttemp,"opr") == 0)
			{
				// takes the third word in user's Set commands
				sscanf(ttemp,"%s",tttemp);
				
				// if user's command Set operator arithmetic mode ( + , - , / , * , % )
				if (strcmp(ttemp,"arith") == 0) calculator->setOperatorType(Calculator::ARITMATIKA_OPERATOR);
				// if user's command Set operator logic mode ( & , | , ^ , ! , < , > , = )
				if (strcmp(ttemp,"logic") == 0) calculator->setOperatorType(Calculator::LOGIKA_OPERATOR);
			}
			else if (strcmp(ttemp,"num") == 0)
			{
				// takes the third word in user's Set commands
				sscanf(ttemp,"%s",tttemp);
				
				// if user's command Set number mode to Arabic ( 1 , 30 , 1000 )
				if (strcmp(ttemp,"arabic") == 0) calculator->setNumberType(Calculator::ARABIC_NUMBER);
				// if user's command Set number mode to Romawi ( I , XXX , M )
				if (strcmp(ttemp,"roman") == 0) calculator->setNumberType(Calculator::ROMAWI_NUMBER);
				// if user's command Set number mode to Logic ( true , false )
				if (strcmp(ttemp,"logic") == 0) calculator->setNumberType(Calculator::LOGIC_NUMBER);
			}
			else if (strcmp(ttemp,"exp") == 0)
			{
				// takes the third word in user's Set commands
				sscanf(ttemp,"%s",tttemp);
				
				// if user's command Set expression mode to postfix
				if (strcmp(ttemp,"post") == 0) calculator->setExpressionType(Calculator::POSTFIKS_OPERATOR);
				// if user's command Set expression mode to infix
				if (strcmp(ttemp,"in") == 0) calculator->setExpressionType(Calculator::INFIKS_OPERATOR);
				// if user's command Set expression mode to prefix
				if (strcmp(ttemp,"pref") == 0) calculator->setExpressionType(Calculator::PREFIKS_OPERATOR);
			}
		}	
	}
}