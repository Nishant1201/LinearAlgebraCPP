#include "Vector.hpp"
#include "Matrix.hpp"
#include "LinearSystem.hpp"

int main(int argc, char *argv[])
{   
    Matrix A(3,3);
    Vector b(3);
    Vector x(3);

    std::cout << "Gauss Elimination without Pivoting" << std::endl;
    A(0,0) = 4.0; A(0,1) = -2.0; A(0,2) = 1.0;
    A(1,0) = -2.0; A(1,1) = 4.0; A(1,2) = -2.0;
    A(2,0) = 1.0; A(2,1) = -2.0; A(2,2) = 4.0;
    b[0] = 11.0; b[1] = -16.0; b[2] = 17.0;

    LinearSystem ls1(A,b);
    x = ls1.GaussElimination();
    std::cout << "x1 = " << x << std::endl;

    A(0,0) = 6.0; A(0,1) = -4.0; A(0,2) = 1.0;
    A(1,0) = -4.0; A(1,1) = 6.0; A(1,2) = -4.0;
    A(2,0) = 1.0; A(2,1) = -4.0; A(2,2) = 6.0;
    b[0] = -14.0; b[1] = 36.0; b[2] = 6.0;

    LinearSystem ls2(A,b);
    x = ls2.GaussElimination();
    std::cout << "x = " << x << std::endl;

    
    b[0] = 22.0; b[1] = -18.0; b[2] = 7.0;
    LinearSystem ls3(A,b);
    x = ls3.GaussElimination();
    std::cout << "x = " << x << std::endl;

    std::cout << "Gauss Elimination with Pivoting" << std::endl;
    A(0,0) = 2.0; A(0,1) = -2.0; A(0,2) = 6.0;
    A(1,0) = -2.0; A(1,1) = 4.0; A(1,2) = 3.0;
    A(2,0) = -1.0; A(2,1) = 8.0; A(2,2) = 4.0;

    b[0] = 16.0; b[1] = 0.0; b[2] = -1.0;

    LinearSystem ls4(A,b);
    x = ls4.GaussElimination();
    std::cout << "x = " << x << std::endl;

    return 0;
}


