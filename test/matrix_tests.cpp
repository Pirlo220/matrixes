
#include <iostream>
#include <cstdlib>
#include <mexceptions.hpp>
//#include "login.cpp"
#include <iomanip>
#include <cmath>
#include <limits>
#include <new>
#include <assert.h>
#include <sodium.h>
#include <cstring>
#include "utils.cpp"
#include "matrix_management.cpp"

void seleccionar_matriz_id_correcto();
void seleccionar_matriz_id_no_existente();
/*
void seleccionar_matriz_id_no_numerico();
void seleccionar_matriz_id_negativo();

void crear_matriz();
void crear_matriz_fuera_limites();
void crear_matriz_dimensiones_negativos();

void modificar_fila_valores_correctos();
void modificar_fila_valor_negativo();
void modificar_fila_valor_no_numerico();
void modificar_fila_valor_fuera_limites();

void modificar_celda_valor_correcto();
void modificar_celda_valor_negativo();
void modificar_celda_valor_no_numerico();
void modificar_celda_valor_fuera_limites();
*/
#define USER_ID 1

int main(void){

  seleccionar_matriz_id_correcto();
  // seleccionar_matriz_id_no_existente();
}

void seleccionar_matriz_id_correcto(){
  int option = 4; 

  int expected = 85;
  int matrix_id = 85;
  int actual = select_matrix(matrix_id, USER_ID);
  
  assert(expected == actual);
}

void seleccionar_matriz_id_no_existente(){
  int option = 4; 

  int expected = -1;
  int matrix_id = -1;
  int actual = actual = select_matrix(matrix_id, USER_ID);
  cout << actual << " actual" << endl;
  assert(expected == actual);
}

