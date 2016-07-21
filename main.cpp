#include <iostream>
#include <cstdlib>
#include <string>
#include <conio.h>
#include "login.cpp"
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

int main() {
	int p = login();
	if(p == 1){
		//do{
			cin.clear();
			std::cout << "\nPlease try to overflow the buffer: \n";
			float f;
			f = 18446744073709551610u;
			//std::cin >> f; // let user put his name
			//cout.setf(ios::fixed);
			
			/*
			//executes loop if the input fails (e.g., no characters were read)
while (std::cout << "Enter a number" && !(std::cin >> num)) {
    std::cin.clear(); //clear bad input flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
    std::cout << "Invalid input; please re-enter.\n";
}
			*/
		 std::cout << std::setprecision(3) << f;
			//cout << f;
		//} while(1==1);		
	}
	return EXIT_SUCCESS;
}
