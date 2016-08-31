#include <matrix_management.hpp>
#include "menu.cpp"
#include <cstring>
#include <stdlib.h>     /* atoi */
#include "matrix.cpp"
#include "matrix_DAO.cpp"
#include <LibConstants.hpp>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <string>
#include <errno.h>
#include "logger.cpp"
#include <iomanip>

namespace Management{
  
  int run_option(int option, int matrix_id, int user_id){
    int selected_id = matrix_id;
    if(matrix_id <= 0 && option > 6){
      cout << "Opción no válida." << endl;
    } else {  
      switch(option){
      case 0:{
	// Do nothing
      }
	break;
      case 1: 
	{
	  if(matrix_id <= 0){
	    cout << "Primero debes seleccionar una matriz" << endl;
	  } else {
	    cout << "  Mostrando contenido de matriz con id: " << matrix_id << endl;
	    Matrix<float> matrix = get_matrix_by_ID(matrix_id, user_id);
	    for(int r = 0; r < matrix.getRows();r++){
	      cout << "  |";
	      for(int c = 0; c <  matrix.getCols();c++){
		cout << fixed << setprecision(2);
		cout <<  matrix.operator()(r,c) << " | " ;
		}
		    cout << endl;
		  }
	   
	    }
	    cout<< endl << " Pulse enter para continuar...";
	    cin.get();	  
	  }
	  break;
  
	case 2 : 
	  { 
	    cout << "  Buscar por:" << endl;
	    cout << "[1] Identificador" << endl;
	    cout << "[2] Nombre" << endl;
	    cout << "[0] Volver menú" << endl;
	    int opt = 0;
	    while(!(cin >> opt) || (opt > 2 && opt < 0)){
	      cout << " Formato Incorrecto!! Vuelve a introducirlo : ";
	      cin.clear();
	      cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    }
	    string nombre_a_buscar = "";
	    int id_a_buscar = 0;
	    if(opt == 1){
	      cin.ignore(1024, '\n');
	      id_a_buscar = atoi(UtilsLibrary::get_user_input(" Introduce identificador a buscar: ", false, 5).c_str());
	    } else if(opt == 2){
	      cin.ignore(1024, '\n');
	      nombre_a_buscar = UtilsLibrary::get_user_input(" Introduce cadena a buscar: ", false, 20);
	    } else {
	      break;
	    }
	    	    
	    vector<Matrix<float> > result = get_matrixes(nombre_a_buscar, id_a_buscar, user_id);

	    for(int i = 0; i < result.size(); i++) {
	      Matrix<float> n = result.at(i);
	      std::cout << "Matriz con ID: " << n.getID() << " Nombre: "<< n.getName() << endl;
	    }
	   
	    cout << "Tamaño resultado " << result.size();

	    cout<< endl << " Pulse enter para continuar...";
	    cin.get();
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
	    Matrix<float> mMatrix(rows, cols, user_id, name);
	    Matrix<float> *c = &mMatrix;
	    selected_id =  save_matrix(c);
	    cin.ignore(1024, '\n');
	    if(selected_id > 0){
	      cout << " Matriz creada con ID: " << selected_id << endl;
	      std::ostringstream stream;
	      stream << "Created Matrix with ID: " << selected_id;
	      std::string message = stream.str();
	      log(message);
	    } else {
	      cerr << "Matriz no creada";
	      log_error("No Matriz Creada");
	    }
	
	    cout << " Pulse enter para continuar...";
	    cin.get();
	    //mMatrix.Matrix<float>::~Matrix();    
	  }
	  break;  
      case 4: {
	int id = atoi(UtilsLibrary::get_user_input(" Introduce el id de la matriz que quieres seleccionar: ", false, 5).c_str());
	Matrix<float> matrix = get_matrix_by_ID(id, user_id);
	if(matrix.getID() == id){
	  selected_id = id;
	} else {
	  cerr << "No ha sido posible seleccionar esa matriz" << endl;
	  cout<< endl << " Pulse enter para continuar...";
	  cin.get();
	}
      }
	break;
      case 6:
	{
	  selected_id =  AppValues::EXIT_CODE;
	}
	break;
      case 7:
	{
	  Matrix<float> matrix = get_matrix_by_ID(selected_id, user_id);
	  cout << " Introduce Número de Columna: ";
	  int col = 0;    
	  while(!(cin >> col) || (col > matrix.getCols() - 1)){
	    cout << " Formato Incorrecto!! Vuelve a introducirlo : ";
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	  }
	  
	  cout << " Introduce Número de Fila: ";
	  int row = 0;
	  while(!(cin >> row) || (row > matrix.getRows() - 1)){
	    cout << " Formato Incorrecto!! Vuelve a introducirlo : ";
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	  }

	  cout << " Introduce valor: ";
	  int value = 0;
	  while(!(cin >> value)){
	    cout << " Formato Incorrecto!! Vuelve a introducirlo : ";
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	  }
	 	  
	  bool resultado = update_matrix_content(selected_id, col, row, value);
	  if(!resultado){
	    cerr << "Error en la actualización" << endl;
	  }
	  cin.ignore(1024, '\n');
	  cout<< endl << " Pulse enter para continuar...";	  
	  cin.get();
	}
	break;
      case 9: 
	{	 
	  Matrix<float> matrix = get_matrix_by_ID(selected_id, user_id);
	  cout << " Introduce Número de Fila a modificar: ";
	  int row = 0;
	  while(!(cin >> row) || (row > matrix.getRows() - 1)){
	    cout << " Formato Incorrecto!! Vuelve a introducirlo : ";
	    cin.clear();
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	  }
	  for(int pos = 0; pos < matrix.getCols(); pos++){
	    std::ostringstream stream;
	    stream << " -->  Introduce nuevo valor en posición " << pos << ": ";
	    cout << stream.str();
	    int value = 0;
	    while(!(cin >> value)){
	      cout << " Formato Incorrecto!! Vuelve a introducirlo : ";
	      cin.clear();
	      cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    }
	    bool resultado = update_matrix_content(selected_id, pos, row, value);
	    if(!resultado){
	      cerr << "Error en la actualización" << endl;
	    }
	  }
	  cin.ignore(1024, '\n');	  
	  cout<< endl << " Pulse enter para continuar...";
	  cin.get();
	}
	break;	
      }
    }
    return selected_id;
  }
  
  

  int run_app(int matrix_id, int user_id){
      system("clear");
      print_menu(matrix_id);
      int selected_option = -1;
      selected_option = atoi(UtilsLibrary::get_user_input(" INTRODUCE UNA OPCIÓN: ", false, 2).c_str());
      return run_option(selected_option, matrix_id, user_id);
    }
  }
