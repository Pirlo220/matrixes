#ifndef MATRIX_MANAGEMENT_HPP    // To make sure you don't declare the function more than once by including the header multiple times.
#define MATRIX_MANAGEMENT_HPP

#include <cstdlib>
#include <string>

int run_option(int option, int matrix_id, int user_id);
int run_app(int matrix_id, int user_id);
int select_matrix(int matrix_id, int user_id);
int save_matrix(int rows, int cols, int user_id, string name);
#endif
