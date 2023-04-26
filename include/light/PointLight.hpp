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
            virtual bool ComputeIllumination(const qbVector<double> &intPoint, const qbVector<double> &localNormal,
                                            const std::vector<std::unique_ptr<RayTracer::AObject>> &objectList,
                                            const std::unique_ptr<RayTracer::AObject> &currentObject, qbVector<double> &color,
                                            double &intensity) override;
    };
} // namespace RayTracer

