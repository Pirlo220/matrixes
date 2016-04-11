
#include <string>
#include "login.hpp"
#include <iostream>

#define PI 3.1415
const std::string ACCESS = "password";

int login(){
	#ifdef PI
		std::cout << "El valor PI es: " << PI << ": ten fe en el caos" << std::endl;
	#else
		std::cout << "PI no esta definido..." << endl;
	#endif
	return 1;
}

bool isGranted(std::string mPass){
	return (mPass == ACCESS);
}
