#include <matrix_DAO.hpp>
#include <pqxx/pqxx>

int save_matrix(Matrix<float> *matrix){
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
  
  return r[0][0].as<int>();
}
