#ifndef __MATRIX_HH__
#define __MATRIX_HH__

#include <array>
#include <type_traits>
#include <utility>

using namespace std;

template <typename T, int Row, int Col> class Matrix {
public:
  array<T, Row * Col> mdata;
  Matrix(const Matrix &mat) { mdata = mat.mdata; }

  template <typename... TList>
  Matrix(TList... tlist) : mdata(forward<T>(tlist)...) {}

  Matrix operator+(const Matrix &m) const {
    Matrix tmp(*this);
    for (int i = 0; i < Row * Col; i++)
      tmp.mdata[i] += m.mdata[i];
    return tmp;
  }

  T getElement(const int &r, const int &c) const { return mdata[r * Col + c]; }
  void setElement(const int &r, const int &c, const T &e) {
    mdata[r * Col + c] = e;
  }
};

#endif