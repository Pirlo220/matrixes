#include "matrix.hpp"

template <typename T>
Matrix<T>::Matrix(int rows = 1, int cols = 1, int ownerID=1, string name="empty")
  : mRows(rows), mCols(cols),mOwnerID(ownerID), mName(name)
{
  //mGrid = new T[mCols * mRows];
  // mGrid.reserve(mCols * mRows);
  std::vector<float> v(mCols * mRows);
  mGrid = v;
  mID = -1;
}


template <typename T>
T& Matrix<T>::operator ()( int row, int column)
{
  //cout << "Accediendo ... " << (row * mCols) + column << endl;
  return mGrid.at((row * mCols) + column);
}

template <typename T>
float Matrix<T>::assign (int row, int column, float value)
{
  // cout << "vector size" << mGrid.size() << endl;
  // cout << "Asignando ... " << (row * mCols) + column << endl;
  //mGrid[(row * mCols) + column] = value;
  mGrid[(row * mCols) + column] = value;
   //cout << "ASIGNADO ... " <<  mGrid.at((row * mCols) + column) << endl;
}

template <typename T>
Matrix<T>::~Matrix(void)
{
 
  //delete[] mGrid;
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

template <typename T>
int Matrix<T>::getID()
{
  return mID;
}

template <typename T>
void Matrix<T>::setID(int id)
{
  mID = id;
}
/*
template <typename T>
void Matrix<T>::setContent(T *content)
{
  mGrid = content;
}

template <typename T>
T* Matrix<T>::getContent()
{
  return mGrid;
}
*/



