#include <matrix_management.hpp>
#include "menu.cpp"
#include <cstring>
#include <stdlib.h>     /* atoi */
#include "matrix.cpp"
#include "matrix_DAO.cpp"
#include <LibConstants.hpp>

int run_option(int option, int matrix_id){
  int selected_id = -1;
  switch(option){
  case 1: 
    {
      cout << "option 1 selected";
    }
    break;
  
  case 2 : 
    {
      cout << "option 2 selected";
    }
    break;
  
  case 3: 
    {
      string name = UtilsLibrary::get_user_input(" Introduce Nombre Para la Matriz: ", false, 20);
      cout << " Introduce Número de Columnas: ";
      int cols = 0;    
      while(!(cin >> cols) || (cols > AppValues::MAX_COLS)){
	cout << " Formato Incorrecto!! Vuelve a introducirlo : ";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      cout << " Introduce Número de Filas: ";
      int rows = 0;
      while(!(cin >> rows) || (rows > AppValues::MAX_ROWS)){
	cout << " Formato Incorrecto!! Vuelve a introducirlo : ";
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
      }
      Matrix<float> mMatrix(cols, rows, 1, name);
      Matrix<float> *c = &mMatrix;
      selected_id =  save_matrix(c);
      cout << "Matriz Guaradada con ID: " << selected_id << endl;
      cout << "  " << endl;
      //mMatrix.Matrix<float>::~Matrix();    
    }
    break;  
  
  case 6:
    {
      selected_id =  AppValues::EXIT_CODE;
    }
    break;
  }
  return selected_id;
}

int run_app(int matrix_id){
  system("clear");
  print_menu(matrix_id);
  int selected_option = -1;
  selected_option = atoi(UtilsLibrary::get_user_input(" INTRODUCE UNA OPCIÓN: ", false, 2).c_str());
  return run_option(selected_option, matrix_id);
}
