#ifndef VECTOR_STRUCT_H
#define VECTOR_STRUCT_H

#include <iostream>
#include <vector>
#include <cmath>

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

        static float my_sqrt(float x) 
        {
            if (x <= 0) return 0;
                float res = x;
            for(int i = 0; i < 10; i++)
                res = 0.5f * (res + x / res); 
            return res;
        }
        
        static float angle_cos(const Vector<K>& u, const Vector<K>& v)
        {
            if (u.size() != v.size())
                throw "Vectors must have same dimension";

            float dot_product = 0;
            float norm_u_sq = 0;
            float norm_v_sq = 0;

            for (size_t i = 0; i < u.size(); i++)
            {
                dot_product = std::fma(u[i], v[i], dot_product);
                norm_u_sq = std::fma(u[i], u[i], norm_u_sq);
                norm_v_sq = std::fma(v[i], v[i], norm_v_sq);
            }
            float n_u = my_sqrt(norm_u_sq);
            float n_v = my_sqrt(norm_v_sq);

            return dot_product / (n_u * n_v);
        }

        float norm_1() const
        {
            float result = 0;
            for (size_t i = 0; i < _vec.size(); i++)
                result += std::max(_vec[i], -_vec[i]);
            return result;
        }

        float norm() const
        {
            float result = 0;
            for (size_t i = 0; i < _vec.size(); i++)
                result += _vec[i] * _vec[i];
            return std::pow(result, 0.5);
        }

        float norm_inf() const
        {
            float result = 0;
            for (size_t i = 0; i < _vec.size(); i++)
            {
                float temp = std::max(_vec[i], -_vec[i]);
                if (temp > result)
                    result = temp;
            }
            return result;
        }

        K dot(const Vector<K>& v)
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
