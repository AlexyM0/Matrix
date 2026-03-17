#include "vector.hpp"
#include <iostream>

int main()
{
    try
    {
        Vector<float> a({1, 2, 3});
        Vector<float> b({4, 5, 6});

        float d = a.dot(b);

        std::cout << "Dot product: " << d << std::endl;
    }
    catch(const char* e)
    {
        std::cout << "Error: " << e << std::endl;
    }

    return 0;
}
