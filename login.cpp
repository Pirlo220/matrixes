
#include <string>
#include "login.h"

const std::string ACCESS = "password";

int login(){

	return 1;
}

bool isGranted(std::string mPass){
	return (mPass == ACCESS);
}
