#include <iostream>
#include <LibConstants.hpp>

void print_menu(bool complete){
  cout << " ======================" << endl;
  cout << "     == OPCIONES ==" << endl;
  cout << " ======================" << endl << endl;

  cout << " " << MenuValuesConstants::MostrarMenu << ".- Mostar Menú" << endl;
  cout << " " << MenuValuesConstants::MostrarMatriz << ".- Mostar Matriz" << endl;
  cout << " " << MenuValuesConstants::BuscarMatriz << ".- Buscar Matrices Guardadas" << endl;
  cout << " " << MenuValuesConstants::NuevaMatriz << ".- Nueva Matriz" << endl;
  cout << " " << MenuValuesConstants::SeleccionarMatriz << ".- Seleccionar Matriz" << endl;
  cout << " " << MenuValuesConstants::Historico << ".- Mostrar Histórico de Movimientos" << endl;
  cout << " " << MenuValuesConstants::Salir << ".- Salir" << endl;
  if(complete){
    cout << " " << MenuValuesConstants::ModifCelda << ".- Modificar Celda" << endl;
    cout << " " << MenuValuesConstants::IntCelda << ".- Intercambiar Celdas" << endl;
    cout << " " << MenuValuesConstants::ModifFila << ".- Modificar Fila" << endl;
    cout << " " << MenuValuesConstants::IntFilas << ".- Intercambiar Filas" << endl;
    cout << " " << MenuValuesConstants::SumaFila << ".- Mostrar Suma Fila" << endl;
    cout << " " << MenuValuesConstants::MediaFila << ".- Mostrar Media Fila" << endl;
    cout << " " << MenuValuesConstants::ModifColumna << ".- Modificar Columna" << endl;
    cout << " " << MenuValuesConstants::IntColumnas << ".- Intercambiar Columnas" << endl;
    cout << " " << MenuValuesConstants::OrdenarFila << ".- Ordenar Fila" << endl;
    cout << " " << MenuValuesConstants::OrdenarColumna << ".- Ordenar Columna" << endl;  
  }
  cout << endl;
  cout << " INTRODUCE UNA OPCIÓN: ";
}
