#ifndef VECTOR_STRUCT_H
#define VECTOR_STRUCT_H

#include <iostream>
#include <vector>

template <typename K>
class Matrix;

template <typename K>
struct Vector
{
    private:
        std::vector<K> _vec;

    public:
        Vector(std::vector<K> vec) : _vec(vec) {}
        ~Vector() {}

        void PrintVec() const
        {
            std::cout << "(";
            for (size_t i = 0; i < _vec.size(); i++)
            {
                std::cout << _vec[i];
                if (i != _vec.size() - 1)
                    std::cout << ", ";
            }
            std::cout << ")" << std::endl;
        }

        static Vector<K> ReshapeMatrixToVector(const Matrix<K>& m);

        void add(Vector<K> &vec)
        {
            if (_vec.size() != vec.size())
                throw("Vectors must be the same dimension");
            for (size_t i = 0; i < _vec.size(); i++)
                _vec[i] += vec[i];
        }

        void sub(Vector<K> &vec)
        {
            if (_vec.size() != vec.size())
                throw("Vectors must be the same dimension");
            for (size_t i = 0; i < _vec.size(); i++)
                _vec[i] -= vec[i];
        }

        void scl(K nbr)
        {
            for (size_t i = 0; i < _vec.size(); i++)
                _vec[i] *= nbr;
        }

        K& operator[](size_t i) { return _vec[i]; }
        const K& operator[](size_t i) const { return _vec[i]; }

        size_t size() const { return _vec.size(); }
};

#endif
