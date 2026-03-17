#include "matrix.hpp"
#include <iostream>

int main()
{
    try
    {
        std::cout << "=== Test trace ===\n";

        // Test 1
        Matrix<float> u1({ {1., 0.}, {0., 1.} });
        std::cout << u1.trace() << std::endl;  // 2.0

        // Test 2
        Matrix<float> u2({ {2., -5., 0.}, {4., 3., 7.}, {-2., 3., 4.} });
        std::cout << u2.trace() << std::endl;  // 9.0

        // Test 3
        Matrix<float> u3({ {-2., -8., 4.}, {1., -23., 4.}, {0., 6., 4.} });
        std::cout << u3.trace() << std::endl;  // -21.0
    }
    catch(const char* e)
    {
        std::cout << "Error: " << e << std::endl;
    }

    return 0;
}