#ifndef LIB_CONSTANTS_H
#define LIB_CONSTANTS_H

//  File Name : LibConstants.hpp    Purpose : Global Constants for Lib Utils
namespace MenuValuesConstants
{
  const int MostrarMenu = 0;
  const int MostrarMatriz = 1;
  const int BuscarMatriz = 2;
  const int NuevaMatriz = 3;
  const int SeleccionarMatriz = 4;
  const int Historico = 5;
  const int Salir = 6;
  const int ModifCelda = 7;
  const int IntCelda = 8;
  const int ModifFila = 9;
  const int IntFilas = 10;
  const int SumaFila = 11;
  const int MediaFila = 12;
  const int ModifColumna = 13;
  const int IntColumnas = 14;
  const int OrdenarFila = 15;
  const int OrdenarColumna = 16;  
}
namespace AppValues {
#define OUT_LEN 128
#define OPSLIMIT 500000
#define MEMLIMIT 5000000
#define KEY_LEN crypto_box_SEEDBYTES
#define USER_NAME_MAX_LENGTH 16
#define USER_PASSW_MAX_LENGTH 12
const int MAX_COLS = 10;
const int MAX_ROWS = 10;
}
#endif
