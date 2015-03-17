/* nama : mCalculator */
#include "Calculator.h"

int main() {
	Calculator c;
	int Mode;
	string cmd;
	cout<<" Masukan mode calculator : "<<endl;
	cout<<" 1. Ekspresi "<<endl;
	cout<<" 2. Settings (Set) "<<endl;
	cout<<"Mode yang dipilih : ";
	cin>>Mode;
	c.setMode(Mode);
	if (c.getMode() == 2) {
		cout<<" Masukan command : ";
		cin>>cmd;
		c.executeCommand(cmd);
	}
	else if (c.getMode() == 1) {
		c.executeCommand(cmd);
	}
	
	return 0;
}