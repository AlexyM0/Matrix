#include "vector.hpp"
#include <iostream>

int main()
{
    try
    {
        Vector<float> u1({0., 0., 1.});
        Vector<float> v1({1., 0., 0.});
        Vector<float> r1 = Vector<float>::cross_product(u1, v1);
        r1.PrintVec();

        Vector<float> u2({1., 2., 3.});
        Vector<float> v2({4., 5., 6.});
        Vector<float> r2 = Vector<float>::cross_product(u2, v2);
        r2.PrintVec();

        Vector<float> u3({4., 2., -3.});
        Vector<float> v3({-2., -5., 16.});
        Vector<float> r3 = Vector<float>::cross_product(u3, v3);
        r3.PrintVec();
    }
    catch(const char* e)
    {
        std::cout << "Error: " << e << std::endl;
    }

    return 0;
}