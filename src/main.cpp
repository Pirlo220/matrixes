// rememb-o-matic
#include <iostream>
#include <cstdlib>
#include <string>
#include "login.cpp"
#include <iomanip>
#include <cmath>
#include <limits>
#include <new>
using namespace std;

int main() {
  int pass = init_login();
  if(pass == 1){
    std::cout << "YOU'RE IN!!"<<endl;
    return EXIT_SUCCESS;
  } else {
    std::cout << "FAIL!!"<<endl; 
}
		//do{
			//cin.clear();
			//std::cout << "\nPlease try to overflow the buffer: \n";
			//float f;
			//f = 18446744073709551610u;
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
	/*
	int row = 1;
	int col = 1;
	std::cout << "Enter a row: ";	
	cin >> row;
	std::cout << "Enter a column: ";	
	cin >> col;
	float matrix [1][1];
	std::cout << "Select a row: " << matrix;
		std::cout << "matrix[] --> " << matrix[9][9];
	int posRow;
	int posCol;
	float value = 0;
	std::cout << "Select a row: ";
	cin >> posRow;
	std::cout << "Select a col: ";
	cin >> posCol;
	std::cout << "enter a value: ";
	cin >> value;	
	matrix[posRow][posCol] = value;
	std::cout << "Select a row: " << matrix;
	std::cout << "matrix[" << posRow  <<"][" << posCol << "] --> " << matrix[posRow][posCol];	
	//std::cout << std::setprecision(3) << f;
	//cout << f;
	//} while(1==1);		
	}*/


//Example for dynamic memory
//http://www.cplusplus.com/doc/tutorial/dynamic/
  // int i,n;
  // int * p;
  // cout << "How many numbers would you like to type? ";
  // cin >> i;
  // p= new (nothrow) int[i];
  // if (p == nullptr)
  //   cout << "Error: memory could not be allocated";
  // else
  // {
  //   for (n=0; n<i; n++)
  //   {
  //     cout << "Enter number: ";
  //     cin >> p[n];
  //   }
  //   cout << "You have entered: ";
  //   for (n=0; n<i; n++)
  //     cout << p[n] << ", ";
  //   delete[] p;
  // }
  // 	}
  // 	return EXIT_SUCCESS;
}
