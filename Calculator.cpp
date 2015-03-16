/* Calculator.cpp */
#include "Calculator.h"

Calculator::Calculator() {
	OprType = 1;
	NumType = 1;
	ExpType = 1;
	Mode = 1;
}
Calculator::Calculator(const Calculator& c) {
	OprType = c.OprType;
	NumType = c.NumType;
	ExpType = c.ExpType;
	Mode = c.Mode;
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
void Calculator::executeCommand(string Cmd) {
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
			}
			else if (inputexp == "in") { 
				setExpressionType(INFIKS_OPERATOR);
			}
			else if (inputexp == "pref") { 
				setExpressionType(PREFIKS_OPERATOR);
			}
		}
			
	}
	else if (Cmd  == "ShowMem") {
		cmdHistory.putCommand(Cmd);
		cmdHistory.showMem();
	}
	else if (Cmd ==  "ShowAll") {
		cmdHistory.putCommand(Cmd);
		cmdHistory.showAll();
	}
	else if (Cmd ==  "Redo") {
		cmdHistory.putCommand(Cmd);
		cmdHistory.redo();
	}
	else if (Cmd ==  "Undo") {
		cmdHistory.putCommand(Cmd);
		cmdHistory.undo();
	}
	else if (Cmd ==  "Save") {
		cmdHistory.putCommand(Cmd);
		cmdHistory.save();
	}
}
void Calculator::setMode(int M) {
	Mode = M;
}
int Calculator::getMode() {
	return Mode;
}