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
	}else if(in == "arabic" || in == "roman" || in == "logicn")
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
		printf(" - %s\n",temp.c_str());
		n--;
	}
	printf("\n");
	
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
		printf(" -    %s\n",temp.c_str());
	}
	printf("\n");
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
	string filename;
	printf("  Filename : ");
	char temp[256];
	scanf("%s",temp);
	filename = temp;
	//cin>>filename;
	FILE* fp = fopen(filename.c_str(),"w");
	
	time_t t = time(0);   // get time now
	struct tm * now = localtime( & t );
	fprintf(fp,"%d - %d - %d , %d:%d:%d\n\n",(now->tm_year + 1900),(now->tm_mon + 1),now->tm_mday,now->tm_hour,now->tm_min,now->tm_sec);
	
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
		printf("\nBack to default Settings\n");
		calculator->setOperatorType(Calculator::ARITMATIKA_OPERATOR);
		calculator->setNumberType(Calculator::ARABIC_NUMBER);
		calculator->setExpressionType(Calculator::INFIKS_OPERATOR);
		return;
	}
	if (redoStack.isEmpty()) {n++;}
	int i;
	for (i=0;i<n && !undoStack.isEmpty();i++)
	{
		string temp; // string holding original string of user's input Set commands
		undoStack.pop(temp);
		redoStack.push(temp);
		char* ttemp =(char*) temp.c_str(); // temporary value to hold last user's Set commands
		char tttemp[256],ttttemp[256],tttttemp[256];
		
		// extract the first, second and third word in user's Set commands
		sscanf(ttemp,"%s %s %s",tttemp, ttttemp, tttttemp);
		if (strcmp(tttemp,"SET") == 0)
		{
			// if user's command Set operator mode
			if (strcmp(ttttemp,"opr") == 0)
			{
				// if user's command Set operator arithmetic mode ( + , - , / , * , % )
				if (strcmp(tttttemp,"arith") == 0) {calculator->setOperatorType(Calculator::ARITMATIKA_OPERATOR);}
				// if user's command Set operator logic mode ( & , | , ^ , ! , < , > , = )
				if (strcmp(tttttemp,"logic") == 0) {calculator->setOperatorType(Calculator::LOGIKA_OPERATOR);}
			}
			// if user's command Set number mode
			else if (strcmp(ttttemp,"num") == 0)
			{
				// if user's command Set number mode to Arabic
				if (strcmp(tttttemp,"arabic") == 0) {calculator->setNumberType(Calculator::ARABIC_NUMBER);}
				// if user's command Set number mode to Romawi
				if (strcmp(tttttemp,"roman") == 0) {calculator->setNumberType(Calculator::ROMAWI_NUMBER);}
				// if user's command Set number mode to Logic ( true , false )
				if (strcmp(tttttemp,"logicn") == 0) {calculator->setNumberType(Calculator::LOGIC_NUMBER);}
			}
			// if user's command Set expression mode
			else if (strcmp(ttttemp,"exp") == 0)
			{
				// if user's command Set expression mode to postfix
				if (strcmp(tttttemp,"post") == 0) {calculator->setExpressionType(Calculator::POSTFIKS_OPERATOR);}
				// if user's command Set expression mode to infix
				if (strcmp(tttttemp,"in") == 0) {calculator->setExpressionType(Calculator::INFIKS_OPERATOR);}
				// if user's command Set expression mode to prefix
				if (strcmp(tttttemp,"pref") == 0) {calculator->setExpressionType(Calculator::PREFIKS_OPERATOR);}
			}
		}
	}
	if ((i>=n && undoStack.isEmpty()) || undoStack.isEmpty())
	{
		printf("\nBack to default Settings\n");
		calculator->setOperatorType(Calculator::ARITMATIKA_OPERATOR);
		calculator->setNumberType(Calculator::ARABIC_NUMBER);
		calculator->setExpressionType(Calculator::INFIKS_OPERATOR);
	}
}

void CommandHistory::redo(int n)
{
	// if user has never undo anything, then s/he cannot redo
	if (redoStack.isEmpty())
	{
		//printf("Redo has reached the end\n");
		return;
	}
	for (int i=0;i<n && !redoStack.isEmpty();i++)
	{
		string temp; // string holding original string of user's input Set commands
		redoStack.pop(temp);
		undoStack.push(temp);
		char* ttemp =(char*) temp.c_str(); // temporary value to hold last user's Set commands
		char tttemp[256],ttttemp[256],tttttemp[256];
		
		// extract the first, second and third word in user's Set commands
		sscanf(ttemp,"%s %s %s",tttemp, ttttemp, tttttemp);
		if (strcmp(tttemp,"SET") == 0)
		{
			// if user's command Set operator mode
			if (strcmp(ttttemp,"opr") == 0)
			{	
				// if user's command Set operator arithmetic mode ( + , - , / , * , % )
				if (strcmp(tttttemp,"arith") == 0) {calculator->setOperatorType(Calculator::ARITMATIKA_OPERATOR);}
				// if user's command Set operator logic mode ( & , | , ^ , ! , < , > , = )
				if (strcmp(tttttemp,"logic") == 0) {calculator->setOperatorType(Calculator::LOGIKA_OPERATOR);}
			}
			else if (strcmp(ttttemp,"num") == 0)
			{
				// if user's command Set number mode to Arabic ( 1 , 30 , 1000 )
				if (strcmp(tttttemp,"arabic") == 0) {calculator->setNumberType(Calculator::ARABIC_NUMBER);}
				// if user's command Set number mode to Romawi ( I , XXX , M )
				if (strcmp(tttttemp,"roman") == 0) {calculator->setNumberType(Calculator::ROMAWI_NUMBER);}
				// if user's command Set number mode to Logic ( true , false )
				if (strcmp(tttttemp,"logicn") == 0) {calculator->setNumberType(Calculator::LOGIC_NUMBER);}
			}
			else if (strcmp(ttttemp,"exp") == 0)
			{
				// if user's command Set expression mode to postfix
				if (strcmp(tttttemp,"post") == 0) {calculator->setExpressionType(Calculator::POSTFIKS_OPERATOR);}
				// if user's command Set expression mode to infix
				if (strcmp(tttttemp,"in") == 0) {calculator->setExpressionType(Calculator::INFIKS_OPERATOR);}
				// if user's command Set expression mode to prefix
				if (strcmp(tttttemp,"pref") == 0) {calculator->setExpressionType(Calculator::PREFIKS_OPERATOR);}
			}
		}	
	}
}