#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>

using namespace std;

int main() {
	char c = ' ';
	string password1="password";
	string password;

	cout << "Please type in your password: \n";
		
	while(c!=13){	
		c=getch();
		if(c >= 33 && c <= 122){//[A-Z,a-z]
			password += c;
			cout << '*';
		}
		else if (c == 8){
			cout << '\b';
			cout<<' ';
			cout << '\b';
			password = password.substr(0, password.size()-1);
		}
		if(c==13 ){
				
				
			cout << password;
			
		}//
		
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
