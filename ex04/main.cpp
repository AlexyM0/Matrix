#include "vector.hpp"
#include <iostream>

int main()
{
    try
    {
        Vector<float> u1({0.0, 0.0, 0.0});
        std::cout << u1.norm_1() << ", " << u1.norm() << ", " << u1.norm_inf() << std::endl;

        Vector<float> u2({1.0, 2.0, 3.0});
        std::cout << u2.norm_1() << ", " << u2.norm() << ", " << u2.norm_inf() << std::endl;

        Vector<float> u3({-1.0, -2.0});
        std::cout << u3.norm_1() << ", " << u3.norm() << ", " << u3.norm_inf() << std::endl;
    }
    catch(const char* e)
    {
        std::cout << "Error: " << e << std::endl;
    }

    return 0;
}