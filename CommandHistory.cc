#include "CommandHistory.h"

CommandHistory::CommandHistory()
{}

void CommandHistory::putCommand(string in)
{
	if (in == "arith" || in == "logic" || in == "rel")
	{
		string temp = "SET opr";
		undoStack.push(temp.append(string(in)));
		saveStack.push(temp.append(string(in)));
	}else if(in == "arabic" || in == "roman")
	{
		string temp = "SET num";
		undoStack.push(temp.append(string(in)));
		saveStack.push(temp.append(string(in)));
	}else if(in == "post" || in == "in" || in == "pref")
	{
		string temp = "SET exp";
		undoStack.push(temp.append(string(in)));
		saveStack.push(temp.append(string(in)));
	}else
	{
		undoStack.push(in);
		saveStack.push(in);
	}
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