/* nama : mCalculator */
#include "Calculator.h"

int main() {
	Calculator c; //ctor
	int Mode;
	string cmd;
	system("CLS");
	cout<<"Calclulator"<<endl<<endl;
	cout<<"Settings awal pada calculator ini adalah :"<<endl;
	cout<<"Aritmatika untuk jenis operator"<<endl;
	cout<<"Angka arab untuk jenis agka"<<endl;
	cout<<"Infiks untuk jenis ekspresi"<<endl;
	c.setMode(1);
	cout<<"Mode  yang dipilih adalah mode ekspresi"<<endl;
	cout<<"-----------------------------------------------------------------------------------------------"<<endl;
	//loop
	while (1) {
		cout<<"Masukan command : ";
		//cin.ignore();
		char temp[256];
		cin.getline(temp,256); cout<<endl;
		char* ttemp = strdup(temp);
		cmd = ttemp;
		//cout<<cmd<<endl;
		//printf("%s", ttemp);
		//getchar();
		if (cmd.compare("Set") == 0) {
			c.setMode(2); cout<<endl;
			c.executeCommand(cmd);
			system("CLS");
			cout<<"Settings yang sedang digunakan : "<<endl;
			if(c.getOperatorType() == 1) {
				cout<<"Setting Operator : Operator Aritmatika "<<endl;
			} else {
				cout<<"Setting Operator : Operator Logika dan Relasiona "<<endl;
			}
			if (c.getNumberType() == 1) {
				cout<<"Setting Angka : Angka Arab "<<endl;
			} else if (c.getNumberType() == 2) {
				cout<<"Setting Angka : Angka Romawi "<<endl;
			}
			else {
				cout<<"Logika"<<endl;
			}
			if (c.getExpressionType() == 1) {
				cout<<"Setting Ekspresi : Infiks "<<endl<<endl;
			} else if (c.getExpressionType() == 2) {
				cout<<"Setting Ekspresi : Posfiks "<<endl<<endl;
			}
			else {
				cout<<"Setting Ekspresi : Prefiks "<<endl<<endl;
			}
		}
		else {
			c.executeCommand(cmd);
			if(c.getOperatorType() == 1) {
				cout<<"Setting Operator : Operator Aritmatika "<<endl;
			} else {
				cout<<"Setting Operator : Operator Logika dan Relasiona "<<endl;
			}
			if (c.getNumberType() == 1) {
				cout<<"Setting Angka : Angka Arab "<<endl;
			} else if (c.getNumberType() == 2) {
				cout<<"Setting Angka : Angka Romawi "<<endl;
			}
			else {
				cout<<"Logika"<<endl;
			}
			if (c.getExpressionType() == 1) {
				cout<<"Setting Ekspresi : Infiks "<<endl<<endl;
			} else if (c.getExpressionType() == 2) {
				cout<<"Setting Ekspresi : Posfiks "<<endl<<endl;
			}
			else {
				cout<<"Setting Ekspresi : Prefiks "<<endl<<endl;
			}
		}
		//c.executeCommand(cmd);
		if (cmd.compare("Set") == 0) {
			cin.ignore();
		}
		c.setMode(1);
	}
	
	return 0;
}