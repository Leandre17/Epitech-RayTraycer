
#ifndef RAY_H
#define RAY_H

#include "Algo.hpp"

namespace RayTracer {
class Ray {
public:
    Ray();
    Ray(const Vector3D &point1, const Vector3D &point2);

    Vector3D GetPoint1() const;
    Vector3D GetPoint2() const;

public:
    Vector3D m_point1{3};
    Vector3D m_point2{3};
    Vector3D m_lab{3};
};
} // namespace RayTracer

#endif
