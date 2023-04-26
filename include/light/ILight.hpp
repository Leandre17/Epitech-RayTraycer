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
            virtual bool ComputeIllumination(const qbVector<double> &intPoint, const qbVector<double> &localNormal,
                                            const std::vector<std::unique_ptr<RayTracer::AObject>> &objectList,
                                            const std::unique_ptr<RayTracer::AObject> &currentObject, qbVector<double> &color,
                                            double &intensity) = 0;
        public:
            qbVector<double> m_color{3};
            qbVector<double> m_location{3};
            double m_intensity;
    };
    class ALight : public ILight {
        public:
            // Constructor / destructor.
            ALight() = default;
            virtual ~ALight() = default;

            // Function to compute illumination contribution.
            virtual bool ComputeIllumination(const qbVector<double> &intPoint, const qbVector<double> &localNormal,
                                            const std::vector<std::unique_ptr<RayTracer::AObject>> &objectList,
                                            const std::unique_ptr<RayTracer::AObject> &currentObject, qbVector<double> &color,
                                            double &intensity);

    };
} // namespace RayTracer
