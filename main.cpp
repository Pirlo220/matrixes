#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main() {
	string password1="password";
	string password;
	
	cout << "Please type in your password: ";
	cin >> password;
	
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
