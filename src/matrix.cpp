#include "matrix.hpp"

template <typename T>
Matrix<T>::Matrix(int gridWidth = 1, int gridHeight = 1)
	: mGridWidth(gridWidth), mGridHeight(gridHeight)
{
	mGrid = new T [mGridWidth * mGridHeight];
}

template <typename T>
Matrix<T>::~Matrix(void)
{
	delete[] mGrid;
}

template <typename T>
T& Matrix<T>::operator ()(int column, int row)
{
	return mGrid[column * mGridWidth + row];
}

template <typename T>
int Matrix<T>::GetWidth()
{
	return mGridWidth;
}

template <typename T>
int Matrix<T>::GetHeight()
{
	return mGridHeight;
}
