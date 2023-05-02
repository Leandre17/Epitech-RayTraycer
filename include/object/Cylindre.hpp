/*
** EPITECH PROJECT, 2023
** raytraycer
** File description:
** Cylindre
*/

#pragma once
#include "IObject.hpp"
#include "Transform.hpp"
#include <array>

namespace RayTracer {
    class Cylinder : public AObject {
        public:
            Cylinder() = default;
            ~Cylinder() override = default;
            virtual bool TestIntersection(const RayTracer::Ray &castRay, Vector3D &intPoint,
                                                                            Vector3D &localNormal, Vector3D &localColor) override;
    };
}
