#include <iostream>

void print_menu(bool complete){
  cout << " ======================" << endl;
  cout << "     == OPCIONES ==" << endl;
  cout << " ======================" << endl << endl;

  cout << "  0.-  Mostar Menú" << endl;
  cout << "  1.-  Mostar Matriz" << endl;
  cout << "  2.-  Buscar Matrices Guardadas" << endl;
  cout << "  3.-  Nueva Matriz" << endl;
  cout << "  4.-  Seleccionar Matriz" << endl;
  cout << "  5.-  Mostrar Histórico de Movimientos" << endl;
  cout << "  6.-  Salir" << endl;
  if(complete){
    cout << "  7.- Modificar Celda" << endl;
    cout << "  8.- Intercambiar Celdas" << endl;
    cout << "  9.- Modificar Fila" << endl;
    cout << "  10.- Intercambiar Filas" << endl;
    cout << "  11.- Mostrar Suma Fila" << endl;
    cout << "  12.- Mostrar Media Fila" << endl;
    cout << "  13.- Modificar Columna" << endl;
    cout << "  14.- Intercambiar Columnas" << endl;
    cout << "  15.- Ordenar Fila" << endl;
    cout << "  16.- Ordenas Columna" << endl;  
  }
  cout << endl;
  cout << " INTRODUCE UNA OPCIÓN: ";
}
