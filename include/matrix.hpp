#ifndef MATRIX_H
#define MATRIX_H

template <typename T>
class Matrix
{
private:
	int mGridWidth;
	int mGridHeight;
	T *mGrid;
	Matrix();

public:
	Matrix(int gridWidth, int gridHeight);
	~Matrix(void);
	T& operator ()(int column, int row);
	int GetWidth();
	int GetHeight();
};

#endif 
