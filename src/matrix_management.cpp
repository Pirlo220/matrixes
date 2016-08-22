#include <matrix_management.hpp>
#include "menu.cpp"
#include <cstring>
#include <stdlib.h>     /* atoi */

bool run_option(int option, int matrix_id){
  switch(option){
  case 1: {
    cout << '1';
    int i = 0;
    cin >> i;
    break;
  }
  case 2 : {
    cout << '2';
    break;
  }
  }
  return true;
}

bool run_app(int matrix_id){
  system("clear");
  print_menu(matrix_id);
  int selected_option = -1;
  selected_option = atoi(UtilsLibrary::get_user_input(" INTRODUCE UNA OPCIÓN: ", false, 2).c_str());
  return run_option(selected_option, matrix_id);
}
