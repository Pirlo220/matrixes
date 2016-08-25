#include "matrix.hpp"

template <typename T>
Matrix<T>::Matrix(int rows = 1, int cols = 1, int ownerID=1, string name="empty")
  : mRows(rows), mCols(cols),mOwnerID(ownerID), mName(name)
{
	mGrid = new T [mCols * mRows];
}

template <typename T>
Matrix<T>::~Matrix(void)
{
	delete[] mGrid;
}

template <typename T>
T& Matrix<T>::operator ()( int row, int column)
{
  return mGrid[(row * mCols) + column];
}

template <typename T>
float Matrix<T>::assign (int row, int column, float value)
{
  mGrid[(row * mCols) + column] = value;
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
