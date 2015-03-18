/* nama : mCalculator */
#include "Calculator.h"

int main() {
	Calculator c; //ctor
	int Mode;
	string cmd, exp;
	system("CLS");
	cout<<"Calclulator"<<endl<<endl;
	cout<<"Settings awal pada calculator ini adalah :"<<endl;
	cout<<"Aritmatika untuk jenis operator"<<endl;
	cout<<"Angka arab untuk jenis agka"<<endl;
	cout<<"Postfiks untuk jenis ekspresi"<<endl;
	c.setMode(1);
	while (1) {
		cout<<"-----------------------------------------------------------------------------------------------"<<endl;
		cout<<"Masukan command : ";
		cin.ignore();
		getline(cin,cmd); cout<<endl;
		if (cmd == "Set") {
			c.setMode(2); cout<<endl;
		}
		c.executeCommand(cmd);
	}
	
	return 0;
}