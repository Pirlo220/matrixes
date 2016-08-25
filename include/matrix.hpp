#ifndef MATRIX_H
#define MATRIX_H

template <typename T>
class Matrix
{
private:
  int mCols;
  int mRows;
  string mName;
  int mOwnerID;
  T *mGrid;
  Matrix();

public:
  Matrix(int rows, int cols, int ownerID, string name);
  ~Matrix(void);
  T& operator ()(int row, int column);
  float assign (int row, int column, float value);
  int getCols();
  int getRows();
  string getName();
  int getOwnerID();
};

#endif 
