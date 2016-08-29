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

namespace Management{
  
  int run_option(int option, int matrix_id){
    int selected_id = matrix_id;
    if(matrix_id <= 0 && option > 6){
      cout << "Opción no válida." << endl;
    } else {  
      switch(option){
      case 1: 
	{
	  if(matrix_id <= 0){
	    cout << "Primero debes seleccionar una matriz" << endl;
	  } else {
	    cout << "  Mostrando contenido de matriz con id: " << matrix_id << endl;
	    Matrix<float> matrix = get_matrix_by_ID(matrix_id);
	    for(int r = 0; r < matrix.getRows();r++){
	      for(int c = 0; c <  matrix.getCols();c++){
		  cout << matrix.operator()(r,c) << " | " ;
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
	    Matrix<float> mMatrix(rows, cols, 1, name);
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
  
	case 6:
	  {
	    selected_id =  AppValues::EXIT_CODE;
	  }
	  break;
	}
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
  }
