#include "Vector.hpp"
#include "Matrix.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Default initialization of A." << std::endl;
    Matrix A(3, 3);
    std::cout << A ;

    std::cout << "Using the Copy Constructor, to create B = A." << std::endl;
    Matrix B = A;
    std::cout << B ;

    std::cout << "Changing A to an Identity Matrix." << std::endl;
    A(0,0) = 1; A(1,1) = 1; A(2,2) = 1;
    std::cout << "A changed to Identity Matrix" << std::endl;
    std::cout << A ;

    std::cout << "Deep copy check for copy constructor." << std::endl;
    std::cout << "B should remain unchanged" << std::endl;
    std::cout << B ;
    
    std::cout << "Creating Matrix C with same dimensions as A." << std::endl;
    Matrix C(A.GetNumberOfRows(), A.GetNumberOfColumns());
    std::cout << "Changing contents of C to all ones. " << std::endl;
    for(int i=0; i<C.GetNumberOfRows(); i++)
        for(int j=0; j<C.GetNumberOfColumns(); j++)
            C(i,j) = 1.0;
    std::cout << C ;

    std::cout << "Testing the unary - operator, creating D=-C." << std::endl;
    Matrix D = -C;
    std::cout << D ;

    std::cout << "Matrix Addition with overloaded binary + operator." << std::endl;
    std::cout << "D = A + C" << std::endl;
    D = A + C;
    std::cout << D ;

    std::cout <<"Matrix Subtraction with overloaded binary - operator." << std::endl;
    std::cout << "E = B - C" << std::endl;
    Matrix E = B - C;
    std::cout << E;

    std::cout << "Matrix Scalar multiplication." << std::endl;
    myReal k = 2.0;
    std::cout << "k = " << k <<", E*k" << std::endl;
    std::cout << E*k ;

    std::cout << "Matrix Multiplied by a Vector." << std::endl;
    Vector v1(E.GetNumberOfColumns());
    for(int i = 0; i<v1.GetSize(); i++)
        v1[i] = 0.5;
    std::cout << E*v1 ;

    std::cout << "Vector Multiplied by a Matrix." << std::endl;
    Vector v2(E.GetNumberOfRows());
    for(int i = 0; i<v2.GetSize(); i++)
        v2[i] = 1.0/3.0;
    std::cout << v2*E ;

    std::cout << "Computing Determinant of a Square Matrix." << std::endl;
    Matrix F(4,4);
    F(0,0) = 1; F(0,1) = 0; F(0,2) = 2; F(0,3) = -1;
    F(1,0) = 3; F(1,1) = 0; F(1,2) = 0; F(1,3) = 5;
    F(2,0) = 2; F(2,1) = 1; F(2,2) = 4; F(2,3) = -3;
    F(3,0) = 1; F(3,1) = 0; F(3,2) = 5; F(3,3) = 0;
    std::cout << F ;
    std::cout << "Determinant = " << F.CalculateDeterminant() << std::endl;

    Matrix G(3,3);
    G(0,0) = 6; G(0,1) = 1; G(0,2) = 1;
    G(1,0) = 4; G(1,1) = -2; G(1,2) = 5;
    G(2,0) = 2; G(2,1) = 8; G(2,2) = 7;
    std::cout << G ;
    std::cout << "Determinant = " << G.CalculateDeterminant() << std::endl;  

    return 0;
}
