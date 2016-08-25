// rememb-o-matic
#include <iostream>
#include <cstdlib>
#include <string>
#include <mexceptions.hpp>
#include "login.cpp"
#include "matrix_management.cpp"
#include <iomanip>
#include <cmath>
#include <limits>
#include <new>
#include <sodium.h>

using namespace std;

int main() {
  bool granted = false;
  do{
    try{
      granted = login();
      if(!granted){
	std::cout <<endl;
	std::cout << "Wrong User or Password!. Try it again..."<<endl;
	std::cout <<endl;
      }     
    } catch(LockedUserException &e){
      std::cerr << "exception caught: " << e.message() << endl;    
    }
  } while(granted == false);

  if(granted == true){
   
    int matrix_id = 0;
    bool mcontinue = true;
    do {
      cout << "run_app" << endl;
      matrix_id = run_app(matrix_id);
    } while(matrix_id != AppValues::EXIT_CODE);    
  }

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
