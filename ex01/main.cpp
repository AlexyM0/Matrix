#include "vector.hpp"
#include <iostream>

int main()
{
    try
    {
        Vector<float> v1({1, 2});
        Vector<float> v2({3, 4});

        //2*(1,2) = (2,4)
        //-1*(3,4) = (-3,-4)
        std::vector<Vector<float>> u = {v1, v2};
        std::vector<float> coefs = {2, -1};

        Vector<float> result = Vector<float>::linear_combination(u, coefs);

        result.PrintVec();

    }
    catch(const char* e)
    {
        std::cout << "Error: " << e << std::endl;
    }
    return 0;
}