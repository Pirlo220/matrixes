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
  Matrix(int cols, int rows, int ownerID, string name);
  ~Matrix(void);
  T& operator ()(int column, int row, int ownerID, string name);
  int getCols();
  int getRows();
  string getName();
  int getOwnerID();
};

#endif 
