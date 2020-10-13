#ifndef MATRIXHEADERDEF
#define MATRIXHEADERDEF

#include <iostream>

#include "Vector.hpp"

typedef double myReal;

class Matrix
{
   private:
      myReal** mData;            // entries of matrix
      int mNumRows, mNumCols;    // dimensions
   public:
      Matrix(int numRows, int numCols);      // constructor
      Matrix(const Matrix& otherMatrix);     // copy constructor
      ~Matrix();
      int GetNumberOfRows() const;
      int GetNumberOfColumns() const;
      myReal& operator()(int i, int j);   // 0 based indexing
      //overloaded assignment operator
      Matrix& operator=(const Matrix& otherMatrix);
      Matrix operator+() const;           // unary +
      Matrix operator-() const;           // unary -
      Matrix operator+(const Matrix& m1) const;    // binary +
      Matrix operator-(const Matrix& m1) const;    // binary -
      // scalar multiplication
      Matrix operator*(myReal k) const;
      myReal CalculateDeterminant() const;
      // declare vector multiplication friendship
      friend Vector operator*(const Matrix& m, const Vector& v);
      friend Vector operator*(const Vector& v, const Matrix& m);

      friend std::ostream& operator<<(std::ostream&, const Matrix&);
};

// prototype signatures for friend operators
Vector operator*(const Matrix& m, const Vector& v);
Vector operator*(const Vector& v, const Matrix& m);
std::ostream& operator<<(std::ostream&, const Matrix&);

#endif