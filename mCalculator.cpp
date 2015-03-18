/* nama : mCalculator */
#include "Calculator.h"

int main() {
	Calculator c;
	int Mode;
	string cmd;
	cout<<" Masukan mode calculator : "<<endl;
	cout<<" 1. Ekspresi "<<endl;
	cout<<" 2. Settings (Set) "<<endl;
	cout <<" 3. Exit " << endl;
	cout<<"Mode yang dipilih : ";
	cin>>Mode;
	c.setMode(Mode);
	while (Mode != 3)
	{
		if (c.getMode() == 2) {
			//cout<<" Masukan command : ";
			//cin>>cmd;
			cmd = "Set";
			c.executeCommand(cmd);
		}
		else if (c.getMode() == 1) {
			cmd = "";
			c.executeCommand(cmd);
		}
		cout<<" Masukan mode calculator : "<<endl;
		cout<<" 1. Ekspresi "<<endl;
		cout<<" 2. Settings (Set) "<<endl;
		cout <<" 3. Exit " << endl;
		cout<<"Mode yang dipilih : ";
		cin>>Mode;
		c.setMode(Mode);
	}
	
	return 0;
}