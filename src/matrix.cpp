#include "matrix.hpp"

template <typename T>
Matrix<T>::Matrix(int cols = 1, int rows = 1, int ownerID=1, string name="empty")
  : mCols(cols), mRows(rows),mOwnerID(ownerID), mName(name)
{
	mGrid = new T [mCols * mRows];
}

template <typename T>
Matrix<T>::~Matrix(void)
{
	delete[] mGrid;
}

template <typename T>
T& Matrix<T>::operator ()(int column, int row, int ownerID, string name)
{
	return mGrid[column * mCols + row];
}

template <typename T>
int Matrix<T>::getCols()
{
	return mCols;
}

template <typename T>
int Matrix<T>::getRows()
{
	return mRows;
}

template <typename T>
string Matrix<T>::getName()
{
	return mName;
}

template <typename T>
int Matrix<T>::getOwnerID()
{
	return mOwnerID;
}
