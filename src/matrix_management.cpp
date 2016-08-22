#include <matrix_management.hpp>
#include "menu.cpp"

bool run_option(int option, int matrix_id){
  return true;
}

bool run_app(int matrix_id){
  system("clear");
  print_menu(matrix_id);
  int selected_option = -1;
  cin >> selected_option;
  return run_option(selected_option, matrix_id);
}
