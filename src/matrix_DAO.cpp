#include <matrix_DAO.hpp>
#include <pqxx/pqxx>
#include <iostream>
/*
void save_matrix_content(Matrix<float> *matrix){
 
}*/

int save_matrix(Matrix<float> *matrix){
  int id = -1;
  try{
    pqxx::connection c("dbname=matrixes user=matrixuser");
    pqxx::work txn(c); 
    pqxx::result r = txn.exec(
			      "INSERT INTO matrixes "
			      "(name, owner_id, number_cols, number_rows) VALUES("	   
			      + txn.quote(matrix->getName()) + ", "
			      + txn.quote(matrix->getOwnerID()) + ", "
			      + txn.quote(matrix->getCols()) + ", "
			      + txn.quote(matrix->getRows()) +	   
			      ") returning id");

    txn.commit();

    int dimension = matrix->getCols() * matrix->getRows();
    int p = 0;
   
 
      for(int i = 0; i < matrix->getRows();i++){
   for(int c = 0; c <  matrix->getCols();c++){
      //cout << "Pos (" << c << ", " << i << ") Value: " << matrix->operator()(c, i) << endl;
	matrix->assign(i,c, 0.40f + p);
	p++;
      }
    }
   

    for(int i = 0; i < matrix->getRows();i++){
      for(int c = 0; c <  matrix->getCols();c++){
	cout << "Pos (" << i << ", " << c << ") Post Value: " << matrix->operator()(i, c) << endl;
	cout << "Real Poos " << (i * matrix->getCols()) + c << endl;
      }
    }
    
    id = r[0][0].as<int>();

  } catch (const std::exception &e) {
	// There's no need to check our database calls for errors.  If
	// any of them fails, it will throw a normal C++ exception.
	std::cerr << e.what() << std::endl;
	return -1;
  }
  return id;
}
