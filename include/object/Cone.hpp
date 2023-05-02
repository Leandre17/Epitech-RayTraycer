/*
** EPITECH PROJECT, 2023
** raytraycer
** File description:
** Cone
*/

#pragma once

#include "IObject.hpp"
#include "Transform.hpp"
#include <array>

namespace RayTracer {
    class Cone : public AObject {
        public:
            Cone() = default;
            ~Cone() override = default;

            // Override the function to test for intersections.
            virtual bool TestIntersection(const RayTracer::Ray &castRay, Vector3D &intPoint, Vector3D &localNormal, Vector3D &localColor) override;			
    };
}
