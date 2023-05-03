/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ALight
*/

#include "ILight.hpp"

// Function to compute illumination.
bool RayTracer::ALight::ComputeIllumination(const Vector3D &, const Vector3D &,
                                            const std::vector<std::unique_ptr<RayTracer::IObject>> &,
                                            const std::unique_ptr<RayTracer::IObject> &, Vector3D &, double &) {
    return false;
}
