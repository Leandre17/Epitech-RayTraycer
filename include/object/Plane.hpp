/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Plane
*/

#pragma once
#include "IObject.hpp"
#include "Transform.hpp"

namespace RayTracer {
class Plane : public AObject {
public:
    Plane() = default;
    ~Plane() override = default;

    // Override the function to test for intersections.
    virtual bool TestIntersection(const RayTracer::Ray &castRay, Vector3D &intPoint, Vector3D &localNormal,
                                  Vector3D &localColor) override;
};
} // namespace RayTracer
