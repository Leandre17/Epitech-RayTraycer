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
    m_vectorData = std::vector<double>(numDims, 0.0);
}

Vector3D::Vector3D(std::vector<double> inputData) {
    m_nDims = inputData.size();
    m_vectorData = inputData;
}

int Vector3D::GetNumDims() const { return m_nDims; }
double Vector3D::GetElement(int index) const { return m_vectorData[index]; }
void Vector3D::SetElement(int index, double value) { m_vectorData[index] = value; }

double Vector3D::norm() {
    double cumulativeSum = 0.0;

    for (int i = 0; i < m_nDims; ++i) cumulativeSum += (m_vectorData.at(i) * m_vectorData.at(i));
    return sqrt(cumulativeSum);
}

Vector3D Vector3D::Normalized() {
    double vecNorm = this->norm();

    Vector3D result(m_vectorData);
    return result * (1.0 / vecNorm);
}

void Vector3D::Normalize() {
    double vecNorm = this->norm();

    for (int i = 0; i < m_nDims; ++i) {
        double temp = m_vectorData.at(i) * (1.0 / vecNorm);
        m_vectorData.at(i) = temp;
    }
}

Vector3D Vector3D::operator+(const Vector3D &rhs) const {
    std::vector<double> resultData;

    for (int i = 0; i < m_nDims; ++i) resultData.push_back(m_vectorData.at(i) + rhs.m_vectorData.at(i));
    Vector3D result(resultData);
    return result;
}

Vector3D Vector3D::operator-(const Vector3D &rhs) const {
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
    std::vector<double> resultData;

    for (int i = 0; i < rhs.m_nDims; ++i) resultData.push_back(lhs * rhs.m_vectorData.at(i));
    Vector3D result(resultData);
    return result;
}

double Vector3D::dot(const Vector3D &a, const Vector3D &b) {
    double cumulativeSum = 0.0;

    for (int i = 0; i < a.m_nDims; ++i) cumulativeSum += a.m_vectorData.at(i) * b.m_vectorData.at(i);
    return cumulativeSum;
}

Vector3D Vector3D::cross(const Vector3D &a, const Vector3D &b) {
    std::vector<double> resultData;

    resultData.push_back((a.m_vectorData.at(1) * b.m_vectorData.at(2)) - (a.m_vectorData.at(2) * b.m_vectorData.at(1)));
    resultData.push_back(-((a.m_vectorData.at(0) * b.m_vectorData.at(2)) - (a.m_vectorData.at(2) * b.m_vectorData.at(0))));
    resultData.push_back((a.m_vectorData.at(0) * b.m_vectorData.at(1)) - (a.m_vectorData.at(1) * b.m_vectorData.at(0)));
    Vector3D result(resultData);
    return result;
}
