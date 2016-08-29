#include <matrix_DAO.hpp>
#include <pqxx/pqxx>
#include <iostream>

void save_matrix_content(pqxx::transaction_base &txn, int id_matrix, int col_index, int row_index, float value){
  txn.exec(
	   "INSERT INTO matrix_content(id_matrix, col_index, row_index, value) "
	   "VALUES (" +
	   txn.quote(id_matrix) + ", " +
	   txn.quote(col_index) + ", " +
	   txn.quote(row_index) + ", " +
	   txn.quote(value) +
	   ")");
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
    id = r[0][0].as<int>();
    for(int r = 0; r < matrix->getRows();r++){
      for(int c = 0; c <  matrix->getCols();c++){
      	matrix->assign(r,c, 0.00f);
	save_matrix_content(txn,id, c, r, 0.00f);
      }
    }
    matrix->setID(id);
    txn.commit();
  } catch (const std::exception &e) {
	// There's no need to check our database calls for errors.  If
	// any of them fails, it will throw a normal C++ exception.
	std::cerr << e.what() << std::endl;
	return -1;
  }
  return id;
}

Matrix<float> get_matrix_by_ID(int matrix_id){
  try
    {
      pqxx::connection c("dbname=matrixes user=matrixuser");
      pqxx::work txn(c);

      pqxx::result r = txn.exec(
				"SELECT number_rows, number_cols, owner_id, name, id " 
				"FROM matrixes " 			   
				"WHERE id=" + txn.quote(matrix_id));
 
      if(r.size() == 1){
	Matrix<float> mMatrix(r[0][0].as<int>(),
			      r[0][1].as<int>(),
			      r[0][2].as<int>(),
			      r[0][3].as<string>());
	mMatrix.setID(r[0][4].as<int>());
	pqxx::result content = txn.exec(
				"SELECT col_index, row_index, value " 
				"FROM matrix_content " 			   
				"WHERE id_matrix =" + txn.quote(matrix_id));
	
	for ( pqxx::result::const_iterator row = content.begin(); row != content.end();++row){
	  mMatrix.assign(row[1].as<int>(), row[0].as<int>(), row[2].as<float>());
	}
	return mMatrix;
      }
    } catch (const std::exception &e) {
    // There's no need to check our database calls for errors.  If
      // any of them fails, it will throw a normal C++ exception.
    std::cerr << e.what() << std::endl;
   
  }
  Matrix<float> emptyMatrix(0, 0, 0,"");
  Matrix<float> *vacia = &emptyMatrix;
  return emptyMatrix;
}
