/* nama : mCalculator */
#include "Calculator.h"

int main() {
	Calculator c;
	int Mode;
	string cmd, exp;
	system("CLS");
	cout<<"Calclulator"<<endl<<endl;
	cout<<" Masukan mode calculator : "<<endl;
	cout<<" 1. Ekspresi "<<endl;
	cout<<" 2. Settings (Set) "<<endl<<endl;
	cout<<"Mode yang dipilih : ";
	cin>>Mode; cout<<endl;
	c.setMode(Mode);
	if (c.getMode() == 2) {
		cout<<"Masukan command 'Set' : ";
		cin>>cmd; cout<<endl;
		c.executeCommand(cmd);
		c.setMode(1);
		c.executeCommand(exp);
	}
	else if (c.getMode() == 1) {
		c.executeCommand(cmd);
	}
	
	return 0;
}