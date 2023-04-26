/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Vector
*/

#pragma once

#include <math.h>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <vector>

class Vector3D {
public:
    Vector3D();
    Vector3D(int numDims);
    Vector3D(std::vector<double> inputData);
    ~Vector3D() = default;

    int GetNumDims() const;
    double GetElement(int index) const;
    void SetElement(int index, double value);
    // Return the length of the vector.
    double norm();
    // Return a normalized copy of the vector.
    Vector3D Normalized();
    // Normalize the vector in place.
    void Normalize();
    Vector3D operator+(const Vector3D &rhs) const;
    Vector3D operator-(const Vector3D &rhs) const;
    Vector3D operator*(const double &rhs) const;
    friend Vector3D operator*(const double &lhs, const Vector3D &rhs);

    static double dot(const Vector3D &a, const Vector3D &b);
    static Vector3D cross(const Vector3D &a, const Vector3D &b);

private:
    std::vector<double> m_vectorData;
    int m_nDims;
};
