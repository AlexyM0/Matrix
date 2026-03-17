#include "vector.hpp"
#include <iostream>

int main()
{
    try
    {
        Vector<float> v1({1.0, 0.0});
        Vector<float> v2({1.0, 0.0});
        std::cout << Vector<float>::angle_cos(v1, v2) << std::endl;

        Vector<float> v3({-1.0, 1.0});
        Vector<float> v4({1.0, -1.0});
        std::cout << Vector<float>::angle_cos(v3, v4) << std::endl;

        Vector<float> v5({2.0, 0.0});
        Vector<float> v6({0.0, 2.0});
        std::cout << Vector<float>::angle_cos(v5, v6) << std::endl;
    }
    catch(const char* e)
    {
        std::cout << "Error: " << e << std::endl;
    }

    return 0;
}