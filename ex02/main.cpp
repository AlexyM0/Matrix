#include "vector.hpp"
#include "matrix.hpp"
#include <iostream>

int main()
{
    try
    {
        Vector<float> a({0, 0});
        Vector<float> b({10, 20});

        float t = 0.5f;

        Vector<float> mid = Vector<float>::lerp(a, b, t);

        std::cout << "Vector A:" << std::endl;
        a.PrintVec();

        std::cout << "\nVector B:" << std::endl;
        b.PrintVec();

        std::cout << "\nLerp(A, B, 0.5):" << std::endl;
        mid.PrintVec();


        Matrix<float> A({
            {1, 2},
            {3, 4}
        });

        Matrix<float> B({
            {5, 6},
            {7, 8}
        });

        Matrix<float> C = Matrix<float>::lerp(A, B, t);

        std::cout << "\nMatrix A:" << std::endl;
        A.PrintMat();

        std::cout << "\nMatrix B:" << std::endl;
        B.PrintMat();

        std::cout << "\nLerp(A, B, 0.5):" << std::endl;
        C.PrintMat();
    }
    catch(const char* e)
    {
        std::cout << "Error: " << e << std::endl;
    }

    return 0;
}
