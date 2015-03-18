/* nama : mCalculator */
#include "Calculator.h"

int main() {
	Calculator c; //ctor
	int Mode;
	string cmd, exp;
	system("CLS");
	cout<<"Calclulator"<<endl<<endl;
	cout<<" Masukan mode calculator : "<<endl;
	cout<<" 1. Ekspresi "<<endl;
	cout<<" 2. Settings (Set) "<<endl<<endl;
	cout<<"Mode yang dipilih : ";
	cin>>Mode; cout<<endl;
	c.setMode(Mode);//

	if (c.getMode() == 2) {
		cmd = "Set";
		c.executeCommand(cmd);
		c.setMode(1);
		cout<<endl;
		cout<<"-----------------------------------------------------------------------------------------------"<<endl;
		cout<<"Masukan command : ";
		cin.ignore();
		getline(cin,cmd); cout<<endl; cout<<endl;
		c.executeCommand(cmd);
	}
	else if (c.getMode() == 1) {
		cout<<endl;
		cout<<"-----------------------------------------------------------------------------------------------"<<endl;
		cout<<"Masukan command : ";
		cin.ignore();
		getline(cin,cmd); cout<<endl; cout<<endl;
		c.executeCommand(cmd);

	}
	
	return 0;
}