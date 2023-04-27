/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** IObject
*/

#pragma once

#include "Algo.hpp"
#include "Ray.hpp"
#include "Transform.hpp"

namespace RayTracer {
class IObject {
public:
    virtual ~IObject() = default;
    virtual bool TestIntersection(const Ray &castRay, Vector3D &intPoint, Vector3D &localNormal, Vector3D &localColor) = 0;
    virtual void SetTransformMatrix(const Transform &transformMatrix) = 0;
    // Function to test whether two floating-point numbers are close to being equal.
    virtual bool CloseEnough(const double f1, const double f2) = 0;

    Vector3D m_baseColor{3};
    RayTracer::Transform m_transformMatrix;
};

class AObject : public IObject {
public:
    AObject() = default;
    virtual ~AObject() = default;
    virtual bool TestIntersection(const Ray &castRay, Vector3D &intPoint, Vector3D &localNormal, Vector3D &localColor);
    void SetTransformMatrix(const Transform &transformMatrix);
    bool CloseEnough(const double f1, const double f2);
};
} // namespace RayTracer
