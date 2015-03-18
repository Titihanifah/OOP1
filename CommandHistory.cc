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
		string temp = "SET opr";
		in = in.append(" ");
		undoStack.push(temp.append(string(in)));
		saveStack.push(temp.append(string(in)));
	}else if(in == "arabic" || in == "roman")
	{
		string temp = "SET num";
		in = in.append(" ");
		undoStack.push(temp.append(string(in)));
		saveStack.push(temp.append(string(in)));
	}else if(in == "post" || in == "in" || in == "pref")
	{
		string temp = "SET exp";
		in = in.append(" ");
		undoStack.push(temp.append(string(in)));
		saveStack.push(temp.append(string(in)));
	}else
	{
		undoStack.push(in);
		saveStack.push(in);
	}
	printf("successfull add\n");
}

int CommandHistory::isExpression(string in)
{
	const char* temp = in.c_str();
	char* firstArgument;
	sscanf(temp,"%s",firstArgument);
	
	if (strcmp(firstArgument,"Set") == 0) return 0;
	if (strcmp(firstArgument,"ShowMem") == 0) return 0;
	if (strcmp(firstArgument,"ShowAll") == 0) return 0;
	if (strcmp(firstArgument,"Undo") == 0) return 0;
	if (strcmp(firstArgument,"Redo") == 0) return 0;
	if (strcmp(firstArgument,"Save") == 0) return 0;
	
	return 1;
}

void CommandHistory::showMem(int n)
{
	printf("\n%d last histories:\n\n",n);
	
	while(!saveStack.isEmpty() && n > 0)
	{
		string temp;
		saveStack.pop(temp);
		tempStack.push(temp);
		printf("%s\n",temp.c_str());
		n--;
	}
	
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
	
	while(!saveStack.isEmpty())
	{
		string temp;
		saveStack.pop(temp);
		tempStack.push(temp);
		printf("%s\n",temp.c_str());
	}
	
	while(!tempStack.isEmpty())
	{
		string temp;
		tempStack.pop(temp);
		saveStack.push(temp);
	}
}

void CommandHistory::save()
{
	string filename;
	printf("Filename : ");cin >> filename;
	FILE* fp = fopen(filename.c_str(),"w");
	
	while(!saveStack.isEmpty())
	{
		string temp;
		saveStack.pop(temp);
		tempStack.push(temp);
		fprintf(fp,"%s\n",temp.c_str());
	}
	
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
	while (!redoStack.isEmpty()) // redo is just for the last undo
	{
		string temp;
		redoStack.pop(temp);
	}
	for (int i=0;i<n;i++)
	{
		string temp;
		undoStack.pop(temp);
		redoStack.push(temp);
		char* ttemp =(char*) temp.c_str();
		char* tttemp;
		sscanf(ttemp,"%s",tttemp);
		if (strcmp(ttemp,"SET") == 0)
		{
			sscanf(ttemp,"%s",tttemp);
			if (strcmp(ttemp,"opr") == 0)
			{
				sscanf(ttemp,"%s",tttemp);
				if (strcmp(ttemp,"arith") == 0) calculator->setOperatorType(Calculator::ARITMATIKA_OPERATOR);
				if (strcmp(ttemp,"logic") == 0) calculator->setOperatorType(Calculator::LOGIKA_OPERATOR);
			}
			else if (strcmp(ttemp,"num") == 0)
			{
				sscanf(ttemp,"%s",tttemp);
				if (strcmp(ttemp,"arabic") == 0) calculator->setNumberType(Calculator::ARABIC_NUMBER);
				if (strcmp(ttemp,"roman") == 0) calculator->setNumberType(Calculator::ROMAWI_NUMBER);
			}
			else if (strcmp(ttemp,"exp") == 0)
			{
				sscanf(ttemp,"%s",tttemp);
				if (strcmp(ttemp,"post") == 0) calculator->setExpressionType(Calculator::POSTFIKS_OPERATOR);
				if (strcmp(ttemp,"in") == 0) calculator->setExpressionType(Calculator::INFIKS_OPERATOR);
				if (strcmp(ttemp,"pref") == 0) calculator->setExpressionType(Calculator::PREFIKS_OPERATOR);
			}
		}
	}
}

void CommandHistory::redo(int n)
{
	for (int i=0;i<n;i++)
	{
		string temp;
		redoStack.pop(temp);
		undoStack.push(temp);
		char* ttemp =(char*) temp.c_str();
		char* tttemp;
		sscanf(ttemp,"%s",tttemp);
		if (strcmp(ttemp,"SET") == 0)
		{
			sscanf(ttemp,"%s",tttemp);
			if (strcmp(ttemp,"opr") == 0)
			{
				sscanf(ttemp,"%s",tttemp);
				if (strcmp(ttemp,"arith") == 0) calculator->setOperatorType(Calculator::ARITMATIKA_OPERATOR);
				if (strcmp(ttemp,"logic") == 0) calculator->setOperatorType(Calculator::LOGIKA_OPERATOR);
			}
			else if (strcmp(ttemp,"num") == 0)
			{
				sscanf(ttemp,"%s",tttemp);
				if (strcmp(ttemp,"arabic") == 0) calculator->setNumberType(Calculator::ARABIC_NUMBER);
				if (strcmp(ttemp,"roman") == 0) calculator->setNumberType(Calculator::ROMAWI_NUMBER);
			}
			else if (strcmp(ttemp,"exp") == 0)
			{
				sscanf(ttemp,"%s",tttemp);
				if (strcmp(ttemp,"post") == 0) calculator->setExpressionType(Calculator::POSTFIKS_OPERATOR);
				if (strcmp(ttemp,"in") == 0) calculator->setExpressionType(Calculator::INFIKS_OPERATOR);
				if (strcmp(ttemp,"pref") == 0) calculator->setExpressionType(Calculator::PREFIKS_OPERATOR);
			}
		}	
	}
}