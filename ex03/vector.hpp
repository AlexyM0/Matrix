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

        K dot(const Vector<K>& v) const
        {
           if (v.size() != _vec.size())
            throw("Vectors must have same dimension");

            K result = 0;
            for (size_t i = 0; i < _vec.size(); i++)
                result += _vec[i] * v[i];

            return result;
                
        }
        static Vector<K> lerp(const Vector<K>& u, const Vector<K>& v, float t)
        {
            if (u.size() != v.size())
                throw("Vectors must have same dimension");

            std::vector<K> result(u.size());

            for (size_t i = 0; i < u.size(); i++)
            {
                result[i] = u[i] + (v[i] - u[i]) * t;
            }

            return Vector<K>(result);
        }
        
       static Vector<K> linear_combination(const std::vector<Vector<K>>& u, const std::vector<K>& coefs)
        {
            if (u.size() != coefs.size())
                throw ("number of vectors and coefs must be equal");

            if (u.empty())
                throw ("vector list cannot be empty");

            size_t dim = u[0].size();

            std::vector<K> result(dim, 0);

            for (size_t i = 0; i < u.size(); i++)
            {
                if (u[i].size() != dim)
                    throw ("all vectors must have the same size");

                for (size_t j = 0; j < dim; j++)
                {
                    result[j] += coefs[i] * u[i][j];
                }
            }

            return Vector<K>(result);
        }

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
