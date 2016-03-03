#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>

using namespace std;

int main() {
	char c = ' ';
	string password1="password";
	string password;

	cout << "Please type in your password: ";
	
	while(c!=13){	
		c=getch();
		if(c!=13){
			password += c;
			cout << '*';
		}		
	}
	if(password == password1){
		cout<< "\n";
		cout << "Welcome !!";
		cout<< "\n";
		system("pause");
		return EXIT_SUCCESS;
	}
	else {
		cout << "\n";
		cout << "Please type in the correct password: ";
		cout << "\n";
		cin >> password;
	}
	system("pause");
	return EXIT_SUCCESS;
}
