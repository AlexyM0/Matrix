#include "vector.hpp"
#include "matrix.hpp"
#include <iostream>

int main()
{
    try
    {
        std::cout << "=========== VECTOR TESTS ===========" << std::endl;

        Vector<float> v1({1, 2, 3});
        Vector<float> v2({4, 5, 6});

        std::cout << "Vector v1: ";
        v1.PrintVec();

        std::cout << "Vector v2: ";
        v2.PrintVec();

        // --- ADD ---
        std::cout << "\n--- Vector Addition (v1 + v2) ---" << std::endl;
        Vector<float> v_add = v1;
        v_add.add(v2);
        v_add.PrintVec();

        // --- SUB ---
        std::cout << "\n--- Vector Subtraction (v1 - v2) ---" << std::endl;
        Vector<float> v_sub = v1;
        v_sub.sub(v2);
        v_sub.PrintVec();

        // --- SCL ---
        std::cout << "\n--- Vector Scaling (v1 * 2) ---" << std::endl;
        Vector<float> v_scl = v1;
        v_scl.scl(2);
        v_scl.PrintVec();


        std::cout << "\n=========== MATRIX TESTS ===========" << std::endl;

        Matrix<float> m1({
            {1, 2, 3},
            {4, 5, 6}
        });

        Matrix<float> m2({
            {7, 8, 9},
            {10, 11, 12}
        });

        std::cout << "Matrix m1:" << std::endl;
        m1.PrintMat();

        std::cout << "Matrix m2:" << std::endl;
        m2.PrintMat();

        // --- ADD ---
        std::cout << "\n--- Matrix Addition (m1 + m2) ---" << std::endl;
        Matrix<float> m_add = m1;
        m_add.add(m2);
        m_add.PrintMat();

        // --- SUB ---
        std::cout << "\n--- Matrix Subtraction (m1 - m2) ---" << std::endl;
        Matrix<float> m_sub = m1;
        m_sub.sub(m2);
        m_sub.PrintMat();

        // --- SCL ---
        std::cout << "\n--- Matrix Scaling (m1 * 2) ---" << std::endl;
        Matrix<float> m_scl = m1;
        m_scl.scl(2);
        m_scl.PrintMat();
    }
    catch (const char* msg)
    {
        std::cerr << "Exception: " << msg << std::endl;
    }

    return 0;
}