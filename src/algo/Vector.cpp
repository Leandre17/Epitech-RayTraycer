/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Vector
*/

#include "Algo.hpp"

Vector3D::Vector3D() {
    m_nDims = 0;
    m_vectorData = std::vector<double>();
}

Vector3D::Vector3D(int numDims) {
    m_nDims = numDims;
    m_vectorData = std::vector<double>(numDims, static_cast<double>(0.0));
}

Vector3D::Vector3D(std::vector<double> inputData) {
    m_nDims = inputData.size();
    m_vectorData = inputData;
}

int Vector3D::GetNumDims() const {
    return m_nDims;
}

double Vector3D::GetElement(int index) const {
    return m_vectorData[index];
}

void Vector3D::SetElement(int index, double value) {
    m_vectorData[index] = value;
}

double Vector3D::norm() {
    double cumulativeSum = static_cast<double>(0.0);
    for (int i = 0; i < m_nDims; ++i) cumulativeSum += (m_vectorData.at(i) * m_vectorData.at(i));

    return sqrt(cumulativeSum);
}

Vector3D Vector3D::Normalized() {
    double vecNorm = this->norm();

    Vector3D result(m_vectorData);
    return result * (static_cast<double>(1.0) / vecNorm);
}

void Vector3D::Normalize() {
    double vecNorm = this->norm();

    for (int i = 0; i < m_nDims; ++i) {
        double temp = m_vectorData.at(i) * (static_cast<double>(1.0) / vecNorm);
        m_vectorData.at(i) = temp;
    }
}

Vector3D Vector3D::operator+(const Vector3D &rhs) const {
    if (m_nDims != rhs.m_nDims) throw std::invalid_argument("Vector dimensions do not match.");

    std::vector<double> resultData;
    for (int i = 0; i < m_nDims; ++i) resultData.push_back(m_vectorData.at(i) + rhs.m_vectorData.at(i));

    Vector3D result(resultData);
    return result;
}

Vector3D Vector3D::operator-(const Vector3D &rhs) const {
    if (m_nDims != rhs.m_nDims) throw std::invalid_argument("Vector dimensions do not match.");

    std::vector<double> resultData;
    for (int i = 0; i < m_nDims; ++i) resultData.push_back(m_vectorData.at(i) - rhs.m_vectorData.at(i));

    Vector3D result(resultData);
    return result;
}

Vector3D Vector3D::operator*(const double &rhs) const {
    std::vector<double> resultData;
    for (int i = 0; i < m_nDims; ++i) resultData.push_back(m_vectorData.at(i) * rhs);

    Vector3D result(resultData);
    return result;
}

Vector3D operator*(const double &lhs, const Vector3D &rhs) {
    // Perform scalar multiplication.
    std::vector<double> resultData;
    for (int i = 0; i < rhs.m_nDims; ++i) resultData.push_back(lhs * rhs.m_vectorData.at(i));

    Vector3D result(resultData);
    return result;
}

double Vector3D::dot(const Vector3D &a, const Vector3D &b) {
    // Check that the number of dimensions match.
    if (a.m_nDims != b.m_nDims)
        throw std::invalid_argument("Vector dimensions must match for the dot-product to be computed.");

    // Compute the dot product.
    double cumulativeSum = 0.0;
    for (int i = 0; i < a.m_nDims; ++i) cumulativeSum += a.m_vectorData.at(i) * b.m_vectorData.at(i);

    return cumulativeSum;
}

Vector3D Vector3D::cross(const Vector3D &a, const Vector3D &b) {
    // Check that the number of dimensions match.
    if (a.m_nDims != b.m_nDims)
        throw std::invalid_argument("Vector dimensions must match for the cross-product to be computed.");

    // Check that the number of dimensions is 3.
    /* Although the cross-product is also defined for 7 dimensions, we are
        not going to consider that case at this time. */
    if (a.m_nDims != 3)
        throw std::invalid_argument("The cross-product can only be computed for three-dimensional vectors.");

    // Compute the cross product.
    std::vector<double> resultData;
    resultData.push_back((a.m_vectorData.at(1) * b.m_vectorData.at(2)) - (a.m_vectorData.at(2) * b.m_vectorData.at(1)));
    resultData.push_back(-((a.m_vectorData.at(0) * b.m_vectorData.at(2)) - (a.m_vectorData.at(2) * b.m_vectorData.at(0))));
    resultData.push_back((a.m_vectorData.at(0) * b.m_vectorData.at(1)) - (a.m_vectorData.at(1) * b.m_vectorData.at(0)));

    Vector3D result(resultData);
    return result;
}
