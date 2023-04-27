/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** Transform
*/

#pragma once

#include "Algo.hpp"
#include "Ray.hpp"

namespace RayTracer {
// Define direction flag values.
constexpr bool FORWARD = true;
constexpr bool BACKWARD = false;

class Transform {
public:
    Transform();
    ~Transform() = default;
    // Function to set translation, rotation and scale components.
    void SetTransform(const Vector3D &translation, const Vector3D &rotation, const Vector3D &scale);
    // Functions to return the transform matrices.
    Matrix GetForward();
    Matrix GetBackward();
    // Function to apply the transform.
    RayTracer::Ray Apply(const RayTracer::Ray &inputRay, bool dirFlag);
    Vector3D Apply(const Vector3D &inputVector, bool dirFlag);

private:
    Matrix forward{4, 4};
    Matrix backward{4, 4};
};
} // namespace RayTracer
