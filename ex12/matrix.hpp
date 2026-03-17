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

    Matrix<K> inverse() const
    {
        if (rows() != cols())
            throw "Matrix is not square";

        size_t n = rows();

        // Étape 1 : créer la matrice augmentée [A | I]
        Matrix<K> aug(n, 2 * n);
        for (size_t i = 0; i < n; i++)
        {
            for (size_t j = 0; j < n; j++)
                aug[i][j] = (*this)[i][j];      // partie gauche = A
            aug[i][n + i] = 1;                  // partie droite = I
        }

        // Étape 2 : transformer la partie gauche en identité
        for (size_t i = 0; i < n; i++)
        {
            // Trouver un pivot non nul
            if (aug[i][i] == 0)
            {
                size_t swap_row = i + 1;
                while (swap_row < n && aug[swap_row][i] == 0)
                    swap_row++;
                if (swap_row == n)
                    throw "Matrix is singular, no inverse";

                // swap manuel
                for (size_t j = 0; j < 2 * n; j++)
                {
                    K tmp = aug[i][j];
                    aug[i][j] = aug[swap_row][j];
                    aug[swap_row][j] = tmp;
                }
            }

            // Normaliser le pivot
            K pivot = aug[i][i];
            for (size_t j = 0; j < 2 * n; j++)
                aug[i][j] /= pivot;

            // Éliminer les autres lignes
            for (size_t k = 0; k < n; k++)
            {
                if (k != i)
                {
                    K factor = aug[k][i];
                    for (size_t j = 0; j < 2 * n; j++)
                        aug[k][j] -= factor * aug[i][j];
                }
            }
        }

        // Étape 3 : extraire l’inverse (partie droite)
        Matrix<K> inv(n, n);
        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < n; j++)
                inv[i][j] = aug[i][n + j];

        return inv;

    }

    K determinant() const
    {
        if (rows() != cols())
            throw "Matrix is not square";

        size_t n = rows();
        Matrix<K> temp = *this;
        K det = 1;
        int swap_sign = 1; // pour gérer les swaps

        for (size_t i = 0; i < n; i++)
        {
            // Trouver pivot non nul
            if (temp[i][i] == 0)
            {
                size_t swap_row = i + 1;
                while (swap_row < n && temp[swap_row][i] == 0)
                    swap_row++;

                if (swap_row == n)
                    return 0; // colonne entière = 0 -> det = 0

                for (size_t j = 0; j < n; j++)
                {
                    K tmp = temp[i][j];
                    temp[i][j] = temp[swap_row][j];
                    temp[swap_row][j] = tmp;
                }
                swap_sign *= -1; // chaque swap change le signe
            }

            // Élimination sous le pivot
            for (size_t j = i + 1; j < n; j++)
            {
                if (temp[j][i] != 0)
                {
                    K factor = temp[j][i] / temp[i][i];
                    for (size_t k = i; k < n; k++)
                        temp[j][k] -= factor * temp[i][k];
                }
            }
        }

        // Multiplier les diagonales
        for (size_t i = 0; i < n; i++)
            det *= temp[i][i];

        // Appliquer le signe des swaps
        det *= swap_sign;

        return det;
    }

    Matrix<K> row_echelon() const
    {
        Matrix<K> result = *this;

        size_t lead = 0;
        size_t rowCount = result.rows();
        size_t colCount = result.cols();

        for (size_t r = 0; r < rowCount; r++)
        {
            if (lead >= colCount)
                break;

            size_t i = r;

            // Trouver pivot non nul
            while (result[i][lead] == 0)
            {
                i++;
                if (i == rowCount)
                {
                    i = r;
                    lead++;
                    if (lead == colCount)
                        return result;
                }
            }

            // 🔁 SWAP MANUEL (pas std::swap)
            if (i != r)
            {
                for (size_t j = 0; j < colCount; j++)
                {
                    K tmp = result[r][j];
                    result[r][j] = result[i][j];
                    result[i][j] = tmp;
                }
            }

            // Normaliser la ligne pivot
            K pivot = result[r][lead];
            if (pivot != 0)
            {
                for (size_t j = 0; j < colCount; j++)
                    result[r][j] /= pivot;
            }

            // Élimination
            for (size_t i2 = 0; i2 < rowCount; i2++)
            {
                if (i2 != r)
                {
                    K factor = result[i2][lead];
                    for (size_t j = 0; j < colCount; j++)
                        result[i2][j] -= factor * result[r][j];
                }
            }

            lead++;
        }

        return result;
    }
    
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
