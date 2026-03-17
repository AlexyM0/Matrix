#include "matrix.hpp"
#include <iostream>

int main()
{
    try
    {
        std::cout << "=== Test rank ===\n\n";

        // Test 1 : identité 3x3
        Matrix<double> u1({ {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.} });
        std::cout << u1.rank() << std::endl; // 3

        // Test 2 : matrice 3x4
        Matrix<double> u2({ {1., 2., 0., 0.}, {2., 4., 0., 0.}, {-1., 2., 1., 1.} });
        std::cout << u2.rank() << std::endl; // 2

        // Test 3 : matrice 3x3
        Matrix<double> u3({ {8., 5., -2.}, {4., 7., 20.}, {21., 18., 7.} });
        std::cout << u3.rank() << std::endl; // 3

    }
    catch(const char* e)
    {
        std::cout << "Error: " << e << std::endl;
    }

    return 0;
}