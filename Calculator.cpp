/* Calculator.cpp */
#include "Calculator.h"
using namespace std;
//ctor
Calculator::Calculator() {
	OprType = 1;
	NumType = 1;
	ExpType = 1;
	Mode = 1;
	CommandHistory cmdHistory;
	OperandConverter oprConverter;
	ExpressionConverter expConverter;
	ExpressionEvaluator expEvaluator;
}
Calculator::Calculator(const Calculator& c) {
	OprType = c.OprType;
	NumType = c.NumType;
	ExpType = c.ExpType;
	Mode = c.Mode;
	CommandHistory cmdHistory;
}	
Calculator::~Calculator() {
}
void Calculator::setOperatorType(int OT) {
	OprType = OT;
}
void Calculator::setNumberType(int NT) {
	NumType = NT;
}
void Calculator::setExpressionType(int ET){
	ExpType = ET;
}
int Calculator::getOperatorType() {
	return OprType;
}
int Calculator::getNumberType() {
	return NumType;
}
int Calculator::getExpressionType() {
	return ExpType;
}

void Calculator::setMode(int M) {
	Mode = M;
}
int Calculator::getMode() {
	return Mode;
}

void Calculator::executeCommand(string Cmd) {
	string ekspresi, postfiks;
	if (getMode() == 2) {
		if (Cmd == "Set") {
			string input;
			cout<<"Ketik 'opr' untuk set operator"<<endl;
			cout<<"Ketik 'num' untuk set number"<<endl;
			cout<<"Ketik 'exp' untuk set expression"<<endl;
			cin>> input;
			if (input == "opr") {
				string inputopr;
				cout<<"Ketik 'arith' untuk set operator menjadi aritmatika"<<endl;
				cout<<"Ketik 'logic' untuk set operator menjadi logika"<<endl;
				cout<<"Ketik 'rel' untuk set operator menjadi relational"<<endl;
				cin>> inputopr;
				cmdHistory.putCommand(inputopr);
				if (inputopr == "arith") {
					setOperatorType(ARITMATIKA_OPERATOR);
				}
				else if (inputopr == "logic") { 
					setOperatorType(LOGIKA_OPERATOR);
				}
				else if (inputopr == "rel") {
					setOperatorType(RELATIONAL_OPERATOR);
				}
			}
			else if (input == "num") {
				string inputnum;
				cout<<"Ketik 'arabic' untuk set number menjadi arabic"<<endl;
				cout<<"Ketik 'roman' untuk set number menjadi romawi"<<endl;
				cin>>inputnum;
				cmdHistory.putCommand(inputnum);
				if (inputnum == "arabic") { 
					setNumberType(ARABIC_NUMBER);
				}
				else if (inputnum == "roman") {
					setNumberType(ROMAWI_NUMBER);
				}
			}
			else if (input == "exp") {
				string inputexp;
				cout<<"Ketik 'post' untuk set number menjadi postfiks"<<endl;
				cout<<"Ketik 'pref' untuk set number menjadi prefiks"<<endl;
				cout<<"Ketik 'in' untuk set number menjadi infiks"<<endl;
				cin>>inputexp;
				cmdHistory.putCommand(inputexp);
				if (inputexp == "post") {
					setExpressionType(POSTFIKS_OPERATOR);
					expConverter.setExpType(POSTFIKS_OPERATOR);
				}
				else if (inputexp == "in") { 
					setExpressionType(INFIKS_OPERATOR);
					expConverter.setExpType(INFIKS_OPERATOR);
				}
				else if (inputexp == "pref") { 
					setExpressionType(PREFIKS_OPERATOR);
					expConverter.setExpType(PREFIKS_OPERATOR);
				}
			}
				
		}
	}
	else if (getMode() == 1) {
		if (Cmd == ekspresi) {
			cmdHistory.putCommand(Cmd);
			cout<<"Masukan ekspresi : "<<endl;
			cin>>ekspresi;
			if (getNumberType() == ROMAWI_NUMBER) {
				// ubah operand ke arabic
				oprConverter.setExpression(ekspresi);
				ekspresi = oprConverter.toArabicExpression();
			}
			// ubah ekspresi ke postfiks
			int exp = getExpressionType();
			expConverter.setExpType(exp);
			postfiks = expConverter.toPostfiks(ekspresi);
			// hitung hasil
			expEvaluator.setExpression(ekspresi);
			int hasil = expEvaluator.calculate();
		}	
	}
	if ((Cmd[0] ==  'S' || Cmd[0] ==  's') && Cmd[1] ==  'h' && Cmd[2] ==  'o' && Cmd[3] ==  'w' && Cmd[4] ==  'm' && Cmd[5] ==  'e' && Cmd[6] ==  'm') {
		cmdHistory.putCommand(Cmd);
		char* s = (char*) Cmd.c_str();
		int n;
		sscanf("%s %d" , s, n);
		cmdHistory.showMem(n);
	}
	else if (Cmd ==  "ShowAll") {
		cmdHistory.putCommand(Cmd);
		cmdHistory.showAll();
	}
	else if ((Cmd[0] ==  'R' || Cmd[0] ==  'r') && Cmd[1] ==  'e' && Cmd[2] ==  'd' && Cmd[3] ==  'o') {
		cmdHistory.putCommand(Cmd);
		char* s = (char*) Cmd.c_str();
		int n;
		sscanf("%s %d" , s, n);
		
		for (int i=0;i<n;i++)
		{
			string temp;
			cmdHistory.redoStack.pop(temp);
			cmdHistory.undoStack.push(temp);
			char* ttemp =(char*) temp.c_str();
			char* tttemp;
			sscanf(ttemp,"%s",tttemp);
			if (strcmp(ttemp,"SET") == 0)
			{
				sscanf(ttemp,"%s",tttemp);
				if (strcmp(ttemp,"opr") == 0)
				{
					sscanf(ttemp,"%s",tttemp);
					if (strcmp(ttemp,"arith") == 0) setOperatorType(ARITMATIKA_OPERATOR);
					if (strcmp(ttemp,"logic") == 0) setOperatorType(LOGIKA_OPERATOR);
					if (strcmp(ttemp,"rel") == 0) setOperatorType(RELATIONAL_OPERATOR);
				}
				else if (strcmp(ttemp,"num") == 0)
				{
					sscanf(ttemp,"%s",tttemp);
					if (strcmp(ttemp,"arabic") == 0) setNumberType(ARABIC_NUMBER);
					if (strcmp(ttemp,"roman") == 0) setNumberType(ROMAWI_NUMBER);
				}
				else if (strcmp(ttemp,"exp") == 0)
				{
					sscanf(ttemp,"%s",tttemp);
					if (strcmp(ttemp,"post") == 0) setExpressionType(POSTFIKS_OPERATOR);
					if (strcmp(ttemp,"in") == 0) setExpressionType(INFIKS_OPERATOR);
					if (strcmp(ttemp,"pref") == 0) setExpressionType(PREFIKS_OPERATOR);
				}
			}	
		}
		
		//cmdHistory.redo(n);
	}
	else if ((Cmd[0] ==  'U' || Cmd[0] ==  'u') && Cmd[1] ==  'n' && Cmd[2] ==  'd' && Cmd[3] ==  'o') {
		cmdHistory.putCommand(Cmd);
		char* s = (char*) Cmd.c_str();
		int n;
		sscanf("%s %d" , s, n);
		
		for (int i=0;i<n;i++)
		{
			string temp;
			cmdHistory.undoStack.pop(temp);
			cmdHistory.redoStack.push(temp);
			char* ttemp =(char*) temp.c_str();
			char* tttemp;
			sscanf(ttemp,"%s",tttemp);
			if (strcmp(ttemp,"SET") == 0)
			{
				sscanf(ttemp,"%s",tttemp);
				if (strcmp(ttemp,"opr") == 0)
				{
					sscanf(ttemp,"%s",tttemp);
					if (strcmp(ttemp,"arith") == 0) setOperatorType(ARITMATIKA_OPERATOR);
					if (strcmp(ttemp,"logic") == 0) setOperatorType(LOGIKA_OPERATOR);
					if (strcmp(ttemp,"rel") == 0) setOperatorType(RELATIONAL_OPERATOR);
				}
				else if (strcmp(ttemp,"num") == 0)
				{
					sscanf(ttemp,"%s",tttemp);
					if (strcmp(ttemp,"arabic") == 0) setNumberType(ARABIC_NUMBER);
					if (strcmp(ttemp,"roman") == 0) setNumberType(ROMAWI_NUMBER);
				}
				else if (strcmp(ttemp,"exp") == 0)
				{
					sscanf(ttemp,"%s",tttemp);
					if (strcmp(ttemp,"post") == 0) setExpressionType(Calculator::POSTFIKS_OPERATOR);
					if (strcmp(ttemp,"in") == 0) setExpressionType(Calculator::INFIKS_OPERATOR);
					if (strcmp(ttemp,"pref") == 0) setExpressionType(Calculator::PREFIKS_OPERATOR);
				}
			}
		}
		//cmdHistory.undo(n);
	}
	else if (Cmd ==  "Save") {
		cmdHistory.putCommand(Cmd);
		cmdHistory.save();
	}
}
