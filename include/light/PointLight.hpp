/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** pointlight
*/

#pragma once

#include "ILight.hpp"

namespace RayTracer {
class PointLight : public ALight {
public:
    PointLight();
    virtual ~PointLight() override = default;
    // Function to compute illumination.
    virtual bool ComputeIllumination(const Vector3D &intPoint, const Vector3D &localNormal,
                                     const std::vector<std::unique_ptr<RayTracer::AObject>> &objectList,
                                     const std::unique_ptr<RayTracer::AObject> &currentObject, Vector3D &color,
                                     double &intensity) override;
};
} // namespace RayTracer
