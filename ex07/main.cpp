#include "matrix.hpp"
#include "vector.hpp"
#include <iostream>

int main()
{
    try
    {
        // -------------------------
        // Matrix × Vector tests
        // -------------------------
        std::cout << "=== Matrix × Vector ===\n";

        Matrix<float> m1({ {1., 0.}, {0., 1.} });
        Vector<float> v1({4., 2.});
        Vector<float> r1 = m1.mul_vec(v1);
        r1.PrintVec();  // [4] [2]

        Matrix<float> m2({ {2., 0.}, {0., 2.} });
        Vector<float> v2({4., 2.});
        Vector<float> r2 = m2.mul_vec(v2);
        r2.PrintVec();  // [8] [4]

        Matrix<float> m3({ {2., -2.}, {-2., 2.} });
        Vector<float> v3({4., 2.});
        Vector<float> r3 = m3.mul_vec(v3);
        r3.PrintVec();  // [4] [-4]

        // -------------------------
        // Matrix × Matrix tests
        // -------------------------
        std::cout << "\n=== Matrix × Matrix ===\n";

        Matrix<float> A1({ {1., 0.}, {0., 1.} });
        Matrix<float> B1({ {1., 0.}, {0., 1.} });
        Matrix<float> C1 = A1.mul_mat(B1);
        C1.PrintMat();  // [1, 0] [0, 1]

        Matrix<float> A2({ {1., 0.}, {0., 1.} });
        Matrix<float> B2({ {2., 1.}, {4., 2.} });
        Matrix<float> C2 = A2.mul_mat(B2);
        C2.PrintMat();  // [2, 1] [4, 2]

        Matrix<float> A3({ {3., -5.}, {6., 8.} });
        Matrix<float> B3({ {2., 1.}, {4., 2.} });
        Matrix<float> C3 = A3.mul_mat(B3);
        C3.PrintMat();  // [-14, -7] [44, 22]

    }
    catch(const char* e)
    {
        std::cout << "Error: " << e << std::endl;
    }

    return 0;
}