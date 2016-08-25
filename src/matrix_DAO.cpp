#include <matrix_DAO.hpp>
#include <pqxx/pqxx>
#include <iostream>
/*
void save_matrix_content(Matrix<float> *matrix){
 
}*/

void save_matrix_content(pqxx::transaction_base &txn, int id_matrix, int col_index, int row_index, float value){
  // pqxx::connection c("dbname=matrixes user=matrixuser");
  //pqxx::work txn(c); 
  txn.exec(
	   "INSERT INTO matrix_content(id_matrix, col_index, row_index, value) "
	   "VALUES (" +
	   txn.quote(id_matrix) + ", " +
	   txn.quote(col_index) + ", " +
	   txn.quote(row_index) + ", " +
	   txn.quote(value) +
	   ")");
  //txn.commit();
}

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

   
  
    
     /*
    for(int i = 0; i < matrix->getRows();i++){
      for(int c = 0; c <  matrix->getCols();c++){
	cout << "Pos (" << i << ", " << c << ") Post Value: " << matrix->operator()(i, c) << endl;
	cout << "Real Poos " << (i * matrix->getCols()) + c << endl;
      }
    }
    */
    id = r[0][0].as<int>();
    for(int r = 0; r < matrix->getRows();r++){
      for(int c = 0; c <  matrix->getCols();c++){
      	//matrix->assign(r,c, 0.00f);
	save_matrix_content(txn,id, c, r, 0.00f);
      }
    }
    txn.commit();
  } catch (const std::exception &e) {
	// There's no need to check our database calls for errors.  If
	// any of them fails, it will throw a normal C++ exception.
	std::cerr << e.what() << std::endl;
	return -1;
  }
  return id;
}
