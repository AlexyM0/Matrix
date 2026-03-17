#include "matrix.hpp"
#include <iostream>

int main()
{
    try
    {
        std::cout << "=== Test inverse ===\n\n";

        // Test 1 : identité 3x3
        Matrix<double> u1({ {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.} });
        std::cout << "Inverse test 1:\n";
        u1.inverse().PrintMat();
        std::cout << std::endl;

        // Test 2 : matrice diagonale 3x3
        Matrix<double> u2({ {2., 0., 0.}, {0., 2., 0.}, {0., 0., 2.} });
        std::cout << "Inverse test 2:\n";
        u2.inverse().PrintMat();
        std::cout << std::endl;

        // Test 3 : matrice 3x3 générale
        Matrix<double> u3({ {8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.} });
        std::cout << "Inverse test 3:\n";
        u3.inverse().PrintMat();
        std::cout << std::endl;

    }
    catch(const char* e)
    {
        std::cout << "Error: " << e << std::endl;
    }

    return 0;
}