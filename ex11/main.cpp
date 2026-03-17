#include "matrix.hpp"
#include <iostream>

int main()
{
    try
    {
        std::cout << "=== Test determinant ===\n\n";

        // Test 1 : 2x2
        Matrix<double> u1({ { 1., -1.}, {-1., 1.} });
        std::cout << "Determinant test 1: " << u1.determinant() << std::endl; // 0.0

        // Test 2 : 3x3 diagonal
        Matrix<double> u2({ {2., 0., 0.}, {0., 2., 0.}, {0., 0., 2.} });
        std::cout << "Determinant test 2: " << u2.determinant() << std::endl; // 8.0

        // Test 3 : 3x3 générale
        Matrix<double> u3({ {8., 5., -2.}, {4., 7., 20.}, {7., 6., 1.} });
        std::cout << "Determinant test 3: " << u3.determinant() << std::endl; // -174.0

        // Test 4 : 4x4
        Matrix<double> u4({ {8., 5., -2., 4.}, {4., 2.5, 20., 4.}, {8., 5., 1., 4.}, {28., -4., 17., 1.} });
        std::cout << "Determinant test 4: " << u4.determinant() << std::endl; // 1032

    }
    catch(const char* e)
    {
        std::cout << "Error: " << e << std::endl;
    }

    return 0;
}