#ifndef MATRIX_DAO_HPP    
#define MATRIX_DAO_HPP

template <typename T>
int save_matrix(Matrix<T>* matrix);

Matrix<float> get_matrix_by_id(int matrix_id);

std::vector<Matrix<float> > get_matrixes(string nombre, int id, int owner_id);
#endif
