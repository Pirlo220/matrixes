#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include "login.h"

using namespace std;

int main() {
	int p = login();
/*	char c = ' ';
	string password;	
	cout << "Please type in your password: \n";
	do{		
		c=getch();
		if(c==13){
			cout << "\nPlease type in your password: \n";
			password = "";
		}
		if(c >= 33 && c <= 122){//[0-9][A-Z,a-z]
			password += c;
			cout << '*';
		}
		else if (c == 8){//backspace implementation
			cout << '\b';
			cout << ' ';
			cout << '\b';
			password = password.substr(0, password.size()-1);
		}	
	}while(!isGranted(password));	
	return EXIT_SUCCESS;
}

bool isGranted(string mPass){
	return (mPass == ACCESS);
}*/
return EXIT_SUCCESS;
}
