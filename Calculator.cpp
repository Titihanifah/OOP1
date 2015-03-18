/* Calculator.cpp */
#include "Calculator.h"
using namespace std;
//ctor
Calculator::Calculator():cmdHistory(this) {
	OprType = 1;
	NumType = 1;
	ExpType = 1;
	Mode = 1;
	//CommandHistory cmdHistory;
	OperandConverter oprConverter;
	ExpressionConverter expConverter;
	ExpressionEvaluator expEvaluator;
}
Calculator::Calculator(const Calculator& c) :cmdHistory(this) {
	OprType = c.OprType;
	NumType = c.NumType;
	ExpType = c.ExpType;
	Mode = c.Mode;
	//CommandHistory cmdHistory;
}	
Calculator::~Calculator() {}

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

<<<<<<< HEAD
=======

int Calculator::isExpression(string in) {
	if(in[0] ==  'S'  && in[1] ==  'h' && in[2] ==  'o' && in[3] !=  'w' && in[4] ==  'M' && in[5] !=  'e' && in[6] ==  'm') {
		return 0;
	} else if (in[0] ==  'R' && in[1] ==  'e' && in[2] ==  'd' && in[3] ==  'o') {
		return 0;
	} else if (in[0] ==  'U' && in[1] ==  'n' && in[2] ==  'd' && in[3] ==  'o') {
		return 0;
	} else if (in == "ShowAll") {
		return 0;
	} else if (in == "Save") {
		return 0;
	} else {
		return 1;
}		

void Calculator::executeCommand(string Cmd) {
	string ekspresi, postfiks, romnum;
	int hasil;
	if (getMode() == 2) { // mode settings
		if (Cmd == "Set") {
			string input;
			cout<<"----------------------------------------------------------------------------------------------"<<endl;
			cout<<"1. Ketik 'opr' untuk set operator"<<endl;
			cout<<"2. Ketik 'num' untuk set number"<<endl;
			cout<<"3. Ketik 'exp' untuk set expression"<<endl;
			cout<<"4. Ketik 'Exit' untuk kembali menu utama"<<endl;
			cout<<"----------------------------------------------------------------------------------------------"<<endl;
			cin>> input;
			cout<<"----------------------------------------------------------------------------------------------"<<endl;
				while (input != "Exit") {
					if (input == "opr") {
						string inputopr;
						cout<<"1.1 Ketik 'arith' untuk set operator menjadi aritmatika"<<endl;
						cout<<"1.2 Ketik 'logic' untuk set operator menjadi logika dan relational"<<endl;
						cout<<"----------------------------------------------------------------------------------------------"<<endl;
						cin>> inputopr;
						system("CLS");
						cmdHistory.putCommand(inputopr);
						if (inputopr == "arith") {
							setOperatorType(ARITMATIKA_OPERATOR);
						}
						else if (inputopr == "logic") { 
							setOperatorType(LOGIKA_OPERATOR);
						}
					}
					else if (input == "num") {
						string inputnum;
						cout<<"2.1 Ketik 'arabic' untuk set number menjadi arabic"<<endl;
						cout<<"2.2 Ketik 'roman' untuk set number menjadi romawi"<<endl;
						cout<<"----------------------------------------------------------------------------------------------"<<endl;
						cin>>inputnum;
						system ("CLS");
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
						cout<<"3.1 Ketik 'post' untuk set number menjadi postfiks"<<endl;
						cout<<"3.2 Ketik 'pref' untuk set number menjadi prefiks"<<endl;
						cout<<"3.3 Ketik 'in' untuk set number menjadi infiks"<<endl;
						cout<<"----------------------------------------------------------------------------------------------"<<endl;
						cin>>inputexp;
						system("Cls");
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
					cout<<"----------------------------------------------------------------------------------------------"<<endl;
					cout<<"1. Ketik 'opr' untuk set operator"<<endl;
					cout<<"2. Ketik 'num' untuk set number"<<endl;
					cout<<"3. Ketik 'exp' untuk set expression"<<endl;
					cout<<"4. Ketik 'Exit' untuk kembali menu utama"<<endl;
					cout<<"----------------------------------------------------------------------------------------------"<<endl;
					cin>>input;
				}
		}	
	}
	if (getMode() == 1) {
		if (isExpression(Cmd) == 1) {
			cout<<"----------------------------------------------------------------------------------------------"<<endl;
			if (getNumberType() == ROMAWI_NUMBER) {
				// ubah operand ke arabic
				oprConverter.setExpression(Cmd);
				ekspresi = oprConverter.toArabicExpression();
				//cout<<ekspresi<<endl;
			}
			// ubah ekspresi ke postfiks
			int exp = getExpressionType();
			expConverter.setExpType(exp);
			//cout<<"A"<<endl;
			postfiks = expConverter.toPostfix(Cmd);
			//cout<<postfiks<<endl;
			// hitung hasil
			if (getOperatorType() == 1) { // operator arith
				expEvaluator.setExpression(postfiks);
				//cout<<postfiks<<endl;
				hasil = expEvaluator.calculateArith();
				if (getNumberType() == ROMAWI_NUMBER) {
					RomanNumber rom;
					romnum.append(rom.toRomanNumber(hasil));
					cout<<" Hasil : "<<romnum<<endl;
					string temp = " = "; temp.append(romnum);
					cmdHistory.putCommand(Cmd.append(temp));
				}
				else {
					cout<<" Hasil : "<<hasil<<endl;
					ostringstream convert;
					convert << hasil;
					string temp = " = "; temp.append(convert.str());
					cmdHistory.putCommand(Cmd.append(temp));
				}
				cout<<"----------------------------------------------------------------------------------------------"<<endl;
			}
			else if (getOperatorType() == 2) { // operator logic
				expEvaluator.setExpression(postfiks);
				hasil = expEvaluator.calculateLogic();
				cout<<" Hasil : "<<hasil<<endl;
				ostringstream convert;
				convert << hasil;
				string temp = " = "; temp.append(convert.str());
				cmdHistory.putCommand(Cmd.append(temp));
				cout<<"-----------------------------------------------------------------------------------------------"<<endl;
			}
		}
		else if (isExpression(Cmd) == 0) { // bukan ekspresi
			if ((Cmd[0] ==  'S' || Cmd[0] ==  's') && Cmd[1] ==  'h' && Cmd[2] ==  'o' && Cmd[3] ==  'w' && Cmd[4] ==  'M' && Cmd[5] ==  'e' && Cmd[6] ==  'm') {
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
			}
			else if ((Cmd[0] ==  'U' || Cmd[0] ==  'u') && Cmd[1] ==  'n' && Cmd[2] ==  'd' && Cmd[3] ==  'o') {
				cmdHistory.putCommand(Cmd);
				char* s = (char*) Cmd.c_str();
				int n;
				sscanf("%s %d" , s, n);
			}
			else if (Cmd ==  "Save") {
				cmdHistory.putCommand(Cmd);
				cmdHistory.save();
			}
		}
	}
	if (Cmd[0] ==  'S' && Cmd[1] ==  'h' && Cmd[2] ==  'o' && Cmd[3] ==  'w' && Cmd[4] ==  'M' && Cmd[5] ==  'e' && Cmd[6] ==  'm') {
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
	else if (Cmd[0] ==  'R' && Cmd[1] ==  'e' && Cmd[2] ==  'd' && Cmd[3] ==  'o') {
		cmdHistory.putCommand(Cmd);
		char* s = (char*) Cmd.c_str();
		int n;
		sscanf("%s %d" , s, n);
		
		cmdHistory.redo(n);
	}
	else if (Cmd[0] ==  'U' && Cmd[1] ==  'n' && Cmd[2] ==  'd' && Cmd[3] ==  'o') {
		cmdHistory.putCommand(Cmd);
		char* s = (char*) Cmd.c_str();
		int n;
		sscanf("%s %d" , s, n);
		
		cmdHistory.undo(n);
	}
	else if (Cmd ==  "Save") {
		cmdHistory.putCommand(Cmd);
		cmdHistory.save();
	}
}
