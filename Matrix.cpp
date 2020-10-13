#include <cmath>
#include <cassert>
#include "Matrix.hpp"
#include "Vector.hpp"

// Constructor for vector of a given length
// Allocates memory, and initialises entries
// to zero
Matrix::Matrix(int numRows, int numCols)
{
   assert(numRows > 0);
   assert(numCols > 0);
   mNumRows = numRows;
   mNumCols = numCols;
   mData = new myReal* [mNumRows];
   for (int i=0; i<mNumRows; i++)
   {
      mData[i] = new double [mNumCols];
   }
   for (int i=0; i<mNumRows; i++)
   {
      for (int j=0; j<mNumCols; j++)
      {
         mData[i][j] = 0.0;
      }
   }
}

// Overwritten copy constructor
// Allocate memory for new matrix, and copy
// entries into this matrix
Matrix::Matrix(const Matrix& otherMatrix)
{
   mNumRows = otherMatrix.mNumRows;
   mNumCols = otherMatrix.mNumCols;
   mData = new double* [mNumRows];
   for (int i=0; i<mNumRows; i++)
   {
      mData[i] = new double [mNumCols];
   }
   for (int i=0; i<mNumRows; i++)
   {
      for (int j=0; j<mNumCols; j++)
      {
         mData[i][j] = otherMatrix.mData[i][j];
      }
   }
}

// Overwritten destructor to correctly free memory
Matrix::~Matrix()
{
   for (int i=0; i<mNumRows; i++)
   {
      delete[] mData[i];
   }
   delete[] mData;
}

// Method to get number of rows of matrix
int Matrix::GetNumberOfRows() const
{
   return mNumRows;
}

// Method to get number of columns of matrix
int Matrix::GetNumberOfColumns() const
{
   return mNumCols;
}

// Overloading the round brackets
// Note that this uses `zero-based' indexing,
// and a check on the validity of the index
double& Matrix::operator()(int i, int j)
{
   assert(i > -1 && i < mNumRows);
   assert(j > -1 && j < mNumCols);
   return mData[i][j];
}

// Overloading the assignment operator
Matrix& Matrix::operator=(const Matrix& otherMatrix)
{
   assert(mNumRows = otherMatrix.mNumRows);
   assert(mNumCols = otherMatrix.mNumCols);

   for (int i=0; i<mNumRows; i++)
   {
      for (int j=0; j<mNumCols; j++)
      {
         mData[i][j] = otherMatrix.mData[i][j];
      }
   }
   return *this;
}

// Overloading the unary + operator
Matrix Matrix::operator+() const
{
   Matrix mat(mNumRows, mNumCols);
   for (int i=0; i<mNumRows; i++)
   {
      for (int j=0; j<mNumCols; j++)
      {
         mat(i,j) = mData[i][j];
      }
   }
   return mat;
}

// Overloading the unary - operator
Matrix Matrix::operator-() const
{
   Matrix mat(mNumRows, mNumCols);
   for (int i=0; i<mNumRows; i++)
   {
      for (int j=0; j<mNumCols; j++)
      {
         mat(i,j) = -mData[i][j];
      }
   }
   return mat;
}

// Overloading the binary + operator
Matrix Matrix::operator+(const Matrix& m1) const
{
   assert(mNumRows == m1.mNumRows);       
   assert(mNumCols == m1.mNumCols);
   Matrix mat(mNumRows, mNumCols);
   for (int i=0; i<mNumRows; i++)
   {
      for (int j=0; j<mNumCols; j++)
      {
         mat(i,j) = mData[i][j] + m1.mData[i][j];
      }
   }
   return mat;
}

// Overloading the binary - operator
Matrix Matrix::operator-(const Matrix& m1) const
{
   assert(mNumRows == m1.mNumRows);
   assert(mNumCols == m1.mNumCols);
   Matrix mat(mNumRows, mNumCols);
   for (int i=0; i<mNumRows; i++)
   {
      for (int j=0; j<mNumCols; j++)
      {
         mat(i,j) = mData[i][j] - m1.mData[i][j];
      }
   }
   return mat;
}

// Overloading scalar multiplication
Matrix Matrix::operator*(myReal k) const
{
   Matrix mat(mNumRows, mNumCols);
   for (int i=0; i<mNumRows; i++)
   {
      for (int j=0; j<mNumCols; j++)
      {
         mat(i,j) = k*mData[i][j];
      }
   }
   return mat;
}

// Overloading matrix multiplied by a vector
Vector operator*(const Matrix& m, const Vector& v)
{
   int original_vector_size = v.GetSize();
   assert(m.GetNumberOfColumns() == original_vector_size);
   int new_vector_length = m.GetNumberOfRows();
   Vector new_vector(new_vector_length);

   for (int i=0; i<new_vector_length; i++)
   {
      for (int j=0; j<original_vector_size; j++)
      {
         new_vector[i] += m.mData[i][j]*v.Read(j);
      }
   }

   return new_vector;
}

// Overloading vector multiplied by a matrix
Vector operator*(const Vector& v, const Matrix& m)
{
   int original_vector_size = v.GetSize();
   assert(m.GetNumberOfRows() == original_vector_size);
   int new_vector_length = m.GetNumberOfColumns();
   Vector new_vector(new_vector_length);
   
   for (int i=0; i<new_vector_length; i++)
   {
      for (int j=0; j<original_vector_size; j++)
      {
         new_vector[i] += v.Read(j)*m.mData[j][i];
      }
   }

   return new_vector;
}

// Calculate determinant of square matrix recursively
double Matrix::CalculateDeterminant() const
{
   assert(mNumRows == mNumCols);
   myReal determinant = 0.0;

   if (mNumRows == 1)
   {
      determinant = mData[0][0];
   }
   else
   {
      // More than one entry of matrix
      for (int i_outer=0; i_outer<mNumRows; i_outer++)
      {
         Matrix sub_matrix(mNumRows-1, mNumRows-1);
         for (int i=0; i<mNumRows-1; i++)
         {
            for (int j=0; j<i_outer; j++)
            {
               sub_matrix(i,j) = mData[i+1][j];
            }
            for (int j=i_outer; j<mNumRows-1; j++)
            {
               sub_matrix(i,j) = mData[i+1][j+1];
            }
         }
         myReal sub_matrix_determinant = sub_matrix.CalculateDeterminant();

         determinant += pow(-1.0, i_outer)*mData[0][i_outer]*sub_matrix_determinant;
      }
   }
   return determinant;
}

std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
   for(int i=0; i < m.mNumRows; i++)
   {
      for(int j=0; j < m.mNumCols; j++)
      {
         os << m.mData[i][j] <<"    ";
      }
      std::cout << std::endl;
   }
   //std::cout << std::endl;
   return os;
}
