/*
** EPITECH PROJECT, 2023
** Raytracer
** File description:
** ILight
*/

#pragma once

#include <memory>
#include "Algo.hpp"
#include "IObject.hpp"
#include "Ray.hpp"

namespace RayTracer {
class ILight {
public:
    virtual ~ILight() = default;
    virtual bool ComputeIllumination(const Vector3D &intPoint, const Vector3D &localNormal,
                                     const std::vector<std::unique_ptr<RayTracer::IObject>> &objectList,
                                     const std::unique_ptr<RayTracer::IObject> &currentObject, Vector3D &color,
                                     double &intensity) = 0;

public:
    Vector3D m_color{3};
    Vector3D m_location{3};
    double m_intensity;
};
class ALight : public ILight {
public:
    // Constructor / destructor.
    ALight() = default;
    virtual ~ALight() = default;

    // Function to compute illumination contribution.
    virtual bool ComputeIllumination(const Vector3D &intPoint, const Vector3D &localNormal,
                                     const std::vector<std::unique_ptr<RayTracer::IObject>> &objectList,
                                     const std::unique_ptr<RayTracer::IObject> &currentObject, Vector3D &color,
                                     double &intensity);
};
} // namespace RayTracer
