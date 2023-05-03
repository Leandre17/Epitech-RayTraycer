/*
** EPITECH PROJECT, 2023
** raytraycer
** File description:
** factory
*/

#pragma once

#include "IObject.hpp"
#include <memory>
#include <string>

namespace RayTracer {
    enum class OBJECTTYPE {SPHERE, PLANE, CONE, CYLINDRE, NONE};
    class Factory {
        public:
            Factory() = default;
            ~Factory() = default;
            static std::unique_ptr<IObject> CreateObject(OBJECTTYPE name);
            static std::unique_ptr<IObject> CreateSphere();
            static std::unique_ptr<IObject> CreatePlane();
            static std::unique_ptr<IObject> CreateCone();
            static std::unique_ptr<IObject> CreateCylindre();

    };
}
