#ifndef VECTORHEADERDEF
#define VECTORHEADERDEF

#include <iostream>

typedef double myReal;

class Vector
{
   private:
      myReal* mData;       // data stored in vector
      int mSize;           // size of vector
   public:
      Vector(int size);
      Vector(const Vector& otherVector);
      ~Vector();
      int GetSize() const;
      myReal& operator[](int i);       // zero-based indexing
      // read-only zero-based indexing 
      myReal Read(int i) const;
      myReal& operator()(int i);       // one-based indexing
      // assignment
      Vector& operator=(const Vector& otherVector);
      Vector operator+() const;        // unary +
      Vector operator-() const;        // unary -
      Vector operator+(const Vector& v1) const;    // binary +
      Vector operator-(const Vector& v1) const;    // binary -
      // scalar multiplication
      Vector operator*(myReal k) const;
      // Overload * operator for dot product
      myReal operator*(const Vector& v1) const;
      // p-norm method
      myReal CalculateNorm(int p=2) const;
      // Obtain the unit vector corresponding to this vector
      Vector unit_vector() const;
      // declare length function as a friend
      friend int length(const Vector& v);
      friend std::ostream& operator<<(std::ostream& os, const Vector v1);
};

// Prototype signature of length() friend function
int length(const Vector& v);
std::ostream& operator<<(std::ostream& os, const Vector v1);

#endif