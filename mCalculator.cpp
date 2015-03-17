/* nama : mCalculator */
#include "Calculator.h"

int main() {
	Calculator c;
	int Mode;
	string cmd;
	cout<<" Masukan mode calculator : "<<endl;
	cout<<" 1. Ekspresi "<<endl;
	cout<<" 2. Settings "<<endl;
	cin>>Mode;
	cout<<" Masukan command : ";
	cin>>cmd;
	c.executeCommand(cmd);
	return 0;
}