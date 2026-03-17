#ifndef MATRIX_STRUCT_H
#define MATRIX_STRUCT_H

#include <iostream>
#include <vector>
#include "vector.hpp"

template <typename K>
struct Matrix
{
private:
    std::vector<std::vector<K>> _mat;
    

public:


    Matrix<K> transpose()
    {
        std::vector<std::vector<K>> result(_mat[0].size(), std::vector<K>(_mat.size(), 0));
        
        for (size_t i = 0; i < _mat.size(); i++)
        {
            for (size_t j = 0; j < _mat[i].size(); j++)
            {
                result[j][i] = _mat[i][j];
            }
        }
        return Matrix<K>(result);
    }

    K trace() const
    {
        if (rows() != cols())
            throw "Matrix is not square";
        K sum = 0;
        for (size_t i = 0; i < rows(); i++)
            sum += _mat[i][i];
        return sum; 
    }

    Vector<K> mul_vec(const Vector<K>& vec) const
    {
        if (vec.size() != cols())
            throw "Invalid dimensions";

        std::vector<K> result(rows(), 0);

        for (size_t i = 0; i < rows(); i++)
        {
            for (size_t j = 0; j < cols(); j++)
            {
                result[i] += _mat[i][j] * vec[j];
            }
        }

        return Vector<K>(result);
    }

    Matrix<K> mul_mat(const Matrix<K>& mat) const
    {
        if (cols() != mat.rows())
            throw "Invalid dimensions";

        std::vector<std::vector<K>> result(rows(), std::vector<K>(mat.cols(), 0));

        for (size_t i = 0; i < rows(); i++)
        {
            for (size_t j = 0; j < mat.cols(); j++)
            {
                for (size_t k = 0; k < cols(); k++)
                {
                    result[i][j] += _mat[i][k] * mat[k][j];
                }
            }
        }

        return Matrix<K>(result);
    }
    
    Matrix(std::vector<std::vector<K>> mat) : _mat(mat)
    {
        if (_mat.empty())
            throw("Matrix is not valid");
        size_t base = _mat[0].size();
        for (size_t i = 0; i < _mat.size(); i++)
        {
            if (_mat[i].size() != base)
                throw("Matrix is not valid");
        }
    }

    Matrix(size_t rows, size_t cols)
    {
        if (rows == 0 || cols == 0)
            throw("Matrix size invalid");

        _mat = std::vector<std::vector<K>>(rows, std::vector<K>(cols, 0));
    }

    ~Matrix() {}

    static Matrix<K> lerp(const Matrix<K>& A, const Matrix<K>& B, float t)
    {
        if (A.rows() != B.rows() || A.cols() != B.cols())
            throw("Matrices must have same size");

        Matrix<K> result(A.rows(), A.cols());

        for (size_t i = 0; i < A.rows(); i++)
        {
            for (size_t j = 0; j < A.cols(); j++)
            {
                result[i][j] = A[i][j] + (B[i][j] - A[i][j]) * t;
            }
        }
        return result;
    }

    void PrintMat() const
    {
        for (size_t i = 0; i < _mat.size(); ++i)
        {
            std::cout << "| ";
            for (size_t j = 0; j < _mat[i].size(); ++j)
                std::cout << _mat[i][j] << " ";
            std::cout << "|" << std::endl;
        }
    }

    void PrintShape() const
    {
        size_t r = _mat.size();
        size_t c = r > 0 ? _mat[0].size() : 0;
        std::cout << "Matrix shape is " << r << "x" << c << std::endl;
    }

    void IsSquare() const
    {
        size_t r = _mat.size();
        size_t c = r > 0 ? _mat[0].size() : 0;
        PrintMat();
        if (r == c)
            std::cout << "This matrix is square" << std::endl;
        else
            std::cout << "This matrix is not square" << std::endl;
    }

    void add(Matrix<K> &mat)
    {
        if (_mat.size() != mat.size())
            throw("Matrix must be the same size");
        for (size_t i = 0; i < _mat.size(); i++)
            for (size_t j = 0; j < _mat[i].size(); j++)
                _mat[i][j] += mat[i][j];
    }

    void sub(Matrix<K> &mat)
    {
        if (_mat.size() != mat.size())
            throw("Matrix must be the same size");
        for (size_t i = 0; i < _mat.size(); i++)
            for (size_t j = 0; j < _mat[i].size(); j++)
                _mat[i][j] -= mat[i][j];
    }

    void scl(K nbr)
    {
        for (size_t i = 0; i < _mat.size(); i++)
            for (size_t j = 0; j < _mat[i].size(); j++)
                _mat[i][j] *= nbr;
    }

    static Matrix<K> ReshapeVectorToMatrix(const Vector<K>& v, size_t rows, size_t cols)
    {
        if (v.size() != rows * cols)
            throw("Invalid reshape size");
        std::vector<std::vector<K>> mat(rows, std::vector<K>(cols));
        size_t index = 0;
        for (size_t i = 0; i < rows; i++)
            for (size_t j = 0; j < cols; j++)
                mat[i][j] = v[index++];
        return Matrix<K>(mat);
    }

    size_t rows() const { return _mat.size(); }
    size_t cols() const { return _mat[0].size(); }
    size_t size() const { return _mat.size(); }

    std::vector<K>& operator[](size_t i) { return _mat[i]; }
    const std::vector<K>& operator[](size_t i) const { return _mat[i]; }
};

template <typename K>
Vector<K> Vector<K>::ReshapeMatrixToVector(const Matrix<K>& m)
{
    std::vector<K> vec;
    for (size_t i = 0; i < m.rows(); i++)
        for (size_t j = 0; j < m.cols(); j++)
            vec.emplace_back(m[i][j]);
    return Vector<K>(vec);
}

#endif
