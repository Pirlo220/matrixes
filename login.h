#ifndef LOGIN_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define LOGIN_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>

using namespace std;

int login();
bool isGranted(string mPass);

#endif
