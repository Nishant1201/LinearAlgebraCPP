#ifndef LINEARSYSTEMHEADERDEF
#define LINEARSYSTEMHEADERDEF
#include "Vector.hpp"
#include "Matrix.hpp"

class LinearSystem
{
private:
   int mSize;           // size of linear system
   Matrix* mpA;         // matrix for linear system (my pointer to matrix object A)
   Vector* mpb;         // vector for linear system

   // Copy constructor is private.
   // Objects of class become non-copyable. 
   LinearSystem(const LinearSystem& otherLinearSystem){};
public:
   // Only allow constructor that specifies matrix and 
   // vector to be used. No default constructor.
   LinearSystem(const Matrix& A, const Vector& b);

   // destructor frees memory allocated
   ~LinearSystem();

   // Method for solving system
   // virtual Vector Solve();
   Vector GaussElimination();
};

#endif
