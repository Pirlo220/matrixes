
#include <string>
#include "login.hpp"
#include <iostream>

#define PI 3.1415
const std::string ACCESS = "password";

int login(){
	char c = ' ';
	std::string password;	
	std::cout << "Please type in your password: \n";
	do{		
		c=getch();
		if(c==13){
			std::cout << "\nPlease type in your password: \n";
			password = "";
		}
		if(c >= 33 && c <= 122){//[0-9][A-Z,a-z]
			password += c;
			std::cout << '*';
		}
		else if (c == 8){//backspace implementation
			std::cout << '\b';
			std::cout << ' ';
			std::cout << '\b';
			password = password.substr(0, password.size()-1);
		}	
	}while(!isGranted(password));	
	return 1;
}

bool isGranted(std::string mPass){
	return (mPass == ACCESS);
}
