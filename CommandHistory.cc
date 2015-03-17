#include "CommandHistory.h"
#include "Calculator.h"

CommandHistory::CommandHistory()
{}

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

void CommandHistory::save()
{
	string filename;
	printf("Filename : ");cin >> filename;
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