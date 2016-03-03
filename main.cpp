#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
	char c = (char) 0;
	string password1="password";
	string password;
	
	cout << "Please type in your password: ";
	//cin >> password;
	cout << "Valor de c " << c;
	while(c!=10){
		cout << "Dentro" << int(c);
		c=getchar();
		if(c!=13){
			password += c;
			cout << '*';
		}		
	}
	if(password == password1){
		cout << "Welcome !!";
		cout<< "\n";
		system("pause");
		return EXIT_SUCCESS;
	}
	else {
		cout << "Please type in the correct password: ";
		cout << "\n";
		cin >> password;
	}
	system("pause");
	return EXIT_SUCCESS;
}
