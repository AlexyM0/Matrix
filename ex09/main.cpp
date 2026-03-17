#include "matrix.hpp"
#include <iostream>

int main() {
    try {
        std::cout << "=== Test transpose ===\n\n";

        // Test 1 : matrice 2x3
        Matrix<float> a1({ {1., 2., 3.}, {4., 5., 6.} });
        std::cout << "Matrice a1:\n";
        a1.PrintMat();
        Matrix<float> b1 = a1.transpose();
        std::cout << "Transposée de a1:\n";
        b1.PrintMat();
        std::cout << "\n";

        // Test 2 : matrice identité 3x3
        Matrix<float> a2({ {1., 0., 0.}, {0., 1., 0.}, {0., 0., 1.} });
        std::cout << "Matrice a2:\n";
        a2.PrintMat();
        Matrix<float> b2 = a2.transpose();
        std::cout << "Transposée de a2:\n";
        b2.PrintMat();
        std::cout << "\n";

        // Test 3 : matrice 3x2
        Matrix<float> a3({ {7., 8.}, {9., 10.}, {11., 12.} });
        std::cout << "Matrice a3:\n";
        a3.PrintMat();
        Matrix<float> b3 = a3.transpose();
        std::cout << "Transposée de a3:\n";
        b3.PrintMat();
        std::cout << "\n";

    } catch(const char* e) {
        std::cerr << "Error: " << e << std::endl;
    }

    return 0;
}