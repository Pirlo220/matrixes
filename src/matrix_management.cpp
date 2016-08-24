#include <matrix_management.hpp>
#include "menu.cpp"
#include <cstring>
#include <stdlib.h>     /* atoi */
#include "matrix.cpp"
#include "matrix_DAO.cpp"

bool run_option(int option, int matrix_id){
  switch(option){
  case 1: 
    cout << "option 1 selected";
    break;
  
  case 2 : 
    cout << "option 2 selected";
    break;
  
  case 3: 
    string name = UtilsLibrary::get_user_input(" Introduce Nombre Para la Matriz: ", false, 20);
    cout << " Introduce Número de Columnas: ";
    int cols = 0;    
    while(!(cin >> cols)){
      cout << " Formato Incorrecto!! Vuelve a introducirlo : ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    
    cout << " Introduce Número de Filas: ";
    int rows = 0;
    while(!(cin >> rows)){
      cout << " Formato Incorrecto!! Vuelve a introducirlo : ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    Matrix<float> mMatrix(cols, rows, 1, name);
    Matrix<float> *c = &mMatrix;
    int id =  save_matrix(c);
    cout << "Matriz Guaradada con ID: " << id << endl;
    cout << "  " << endl;
    //mMatrix.Matrix<float>::~Matrix();    
 break;  
  }
  cout << " return true" << endl;
  return true;
}

bool run_app(int matrix_id){
  system("clear");
  print_menu(matrix_id);
  int selected_option = -1;
  selected_option = atoi(UtilsLibrary::get_user_input(" INTRODUCE UNA OPCIÓN: ", false, 2).c_str());
  bool resultado = run_option(selected_option, matrix_id);
  cout << "Resultado <<<" << resultado;
  return resultado;
}
