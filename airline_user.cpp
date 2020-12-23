#include <iostream>
#include <string>
#include "admin.h"
using namespace std;

int main(){
	int emp_user;
	cout<< "------------------------------------------------------------"<<endl;
	cout<< "------------------------------------------------------------"<<endl;
	printf("\t Enter 1 to continues as User(To Book Tickets)\n");
	printf("\t Enter 2 to continues as admin.\n");
	cin>> emp_user;
	if (emp_user == 2)
	{
		string pass;
		cout << "Enter Admin Password: "<< endl;
		cin >> pass;
		while(pass != "Hoodooloo"){
			cout << "Invalid Pass Word Please Try Again: " << endl;
			cin >> pass;
		}
		admin();
		
	}
	
}
