#include "matrix.hpp"
#include <iostream>

int main()
{
    try
    {
        std::cout << "=== Test row_echelon ===\n\n";

        // Test 1
        Matrix<float> u1({
            {1., 0., 0.},
            {0., 1., 0.},
            {0., 0., 1.}
        });
        std::cout << "Test 1:\n";
        u1.row_echelon().PrintMat();
        std::cout << "\n";

        // Test 2
        Matrix<float> u2({
            {1., 2.},
            {3., 4.}
        });
        std::cout << "Test 2:\n";
        u2.row_echelon().PrintMat();
        std::cout << "\n";

        // Test 3
        Matrix<float> u3({
            {1., 2.},
            {2., 4.}
        });
        std::cout << "Test 3:\n";
        u3.row_echelon().PrintMat();
        std::cout << "\n";

        // Test 4
        Matrix<float> u4({
            {8., 5., -2., 4., 28.},
            {4., 2.5, 20., 4., -4.},
            {8., 5., 1., 4., 17.}
        });
        std::cout << "Test 4:\n";
        u4.row_echelon().PrintMat();
        std::cout << "\n";
    }
    catch(const char* e)
    {
        std::cout << "Error: " << e << std::endl;
    }

    return 0;
}