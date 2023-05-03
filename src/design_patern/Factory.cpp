/*
** EPITECH PROJECT, 2023
** raytraycer
** File description:
** Factory
*/

#include "Factory.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Cone.hpp"
#include "Cylindre.hpp"

std::unique_ptr<RayTracer::IObject> RayTracer::Factory::CreateSphere() {
    return std::make_unique<RayTracer::Sphere>();
}

std::unique_ptr<RayTracer::IObject> RayTracer::Factory::CreatePlane() {
    return std::make_unique<RayTracer::Plane>();
}

std::unique_ptr<RayTracer::IObject> RayTracer::Factory::CreateCone() {
    return std::make_unique<RayTracer::Cone>();
}

std::unique_ptr<RayTracer::IObject> RayTracer::Factory::CreateCylindre() {
    return std::make_unique<RayTracer::Cylinder>();
}

std::unique_ptr<RayTracer::IObject> RayTracer::Factory::CreateObject(RayTracer::OBJECTTYPE name) {
    switch (name) {
        case RayTracer::OBJECTTYPE::SPHERE: return RayTracer::Factory::CreateSphere();
        case RayTracer::OBJECTTYPE::PLANE: return RayTracer::Factory::CreatePlane();
        case RayTracer::OBJECTTYPE::CONE: return RayTracer::Factory::CreateCone();
        case OBJECTTYPE::CYLINDRE: return CreateCylindre();
        default:
            return nullptr;
    }
    return nullptr;
}
