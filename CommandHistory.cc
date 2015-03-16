#include "CommandHistory.h"

CommandHistory::CommandHistory(Calculator* calculator)
{
	this->calculator = calculator;
}

void CommandHistory::putCommand(string in)
{
	if (in == "arith" || in == "logic" || in == "rel")
	{
		string temp = "SET opr";
		undoStack.push(temp.append(string("in")));
	}else if(in == "arabic" || in == "roman")
	{
		string temp = "SET num";
		undoStack.push(temp.append(string("in")));
	}else if(in == "post" || in == "in" || in == "pref")
	{
		string temp = "SET exp";
		undoStack.push(temp.append(string("in")));
	}
	undoStack.push(in);
}

void CommandHistory::undo()
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
			if (strcmp(ttemp,"rel") == 0) calculator->setOperatorType(Calculator::RELATIONAL_OPERATOR);
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

void CommandHistory::undo(int n)
{
	for (int i=0;i<n;i++) undo();
}

void CommandHistory::redo()
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
			if (strcmp(ttemp,"rel") == 0) calculator->setOperatorType(Calculator::RELATIONAL_OPERATOR);
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

void CommandHistory::redo(int n)
{
	for (int i=0;i<n;i++) redo();	
}

void CommandHistory::showMem(int n)
{
	printf("Histories:\n\n");
	int m = n;
	while(!undoStack.isEmpty() && m>0)
	{
		string temp;
		undoStack.pop(temp);
		redoStack.push(temp);
		printf("\t%s\n",temp.c_str());m--;
	}
	while(!redoStack.isEmpty())
	{
		string temp;
		redoStack.pop(temp);
		undoStack.push(temp);
	}
}

void CommandHistory::showAll()
{
	printf("Histories:\n\n");
	while(!undoStack.isEmpty())
	{
		string temp;
		undoStack.pop(temp);
		redoStack.push(temp);
		printf("\t%s\n",temp.c_str());
	}
	while(!redoStack.isEmpty())
	{
		string temp;
		redoStack.pop(temp);
		undoStack.push(temp);
	}
}

void CommandHistory::save(string filename)
{
	FILE* fp = fopen(filename.c_str(),"w");
	
	while(!undoStack.isEmpty())
	{
		string temp;
		undoStack.pop(temp);
		redoStack.push(temp);
		fprintf(fp,"%s\n",temp.c_str());
	}
	while(!redoStack.isEmpty())
	{
		string temp;
		redoStack.pop(temp);
		undoStack.push(temp);
	}
	
	fclose(fp);
}