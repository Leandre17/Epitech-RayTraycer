/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** qbMatrix
*/

#pragma once

#include <math.h>
#include <exception>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>
#include "Vector.hpp"

class Matrix {
public:
    Matrix();
    Matrix(int nRows, int nCols);
    Matrix(int nRows, int nCols, const double* inputData);
    Matrix(const Matrix& inputMatrix);
    Matrix(int nRows, int nCols, const std::vector<double>& inputData);
    ~Matrix();

    // Configuration methods.
    bool Resize(int numRows, int numCols);
    void SetToIdentity();

    // Element access methods.
    double GetElement(int row, int col) const;
    double GetElement(int elem) const;
    bool SetElement(int row, int col, double elementValue);
    int GetNumRows() const;
    int GetNumCols() const;

    // Compute matrix inverse.
    bool Inverse();
    bool operator==(const Matrix& rhs);

    // Overload the assignment operator.
    Matrix operator=(const Matrix& rhs);

    // Overload +, - and * operators (friends).
    friend Matrix operator*(const Matrix& lhs, const Matrix& rhs);

    // Matrix * Vector3D.
    friend Vector3D operator*(const Matrix& lhs, const Vector3D& rhs);

    bool Separate(Matrix& matrix1, Matrix& matrix2, int colNum);
    bool Join(const Matrix& matrix2);


private:
    int Sub2Ind(int row, int col) const;
    bool CloseEnough(double f1, double f2);
    void SwapRow(int i, int j);
    void MultAdd(int i, int j, double multFactor);
    void MultRow(int i, double multFactor);
    int FindRowWithMaxElement(int colNumber, int startingRow);

    double* m_matrixData;
    int m_nRows, m_nCols, m_nElements;
};
