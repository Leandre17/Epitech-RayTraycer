/*
** EPITECH PROJECT, 2023
** raytraycer
** File description:
** Ray
*/

#pragma once
#include "Algo.hpp"

namespace RayTracer {
class Ray {
public:
    Ray();
    Ray(const Vector3D &point1, const Vector3D &point2);
    Vector3D GetPoint1() const;
    Vector3D GetPoint2() const;
    Vector3D point1{3};
    Vector3D point2{3};
    Vector3D distance{3};
};
} // namespace RayTracer
