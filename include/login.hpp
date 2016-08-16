#ifndef LOGIN_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define LOGIN_H

#include <cstdlib>
#include <string>


int login();
bool isGranted(std::string user, std::string mPass);

#endif
