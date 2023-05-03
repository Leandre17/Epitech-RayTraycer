/*
** EPITECH PROJECT, 2023
** raytraycer
** File description:
** factory
*/

#pragma once

#include "IObject.hpp"
#include "ILight.hpp"
#include <memory>
#include <string>

namespace RayTracer {
    enum class OBJECTTYPE {SPHERE, PLANE, CONE, CYLINDRE, NONE};
    enum class LIGHTTYPE {POINT, NONE};
    class Factory {
        public:
            Factory() = default;
            ~Factory() = default;
            // Factory for Object
            static std::unique_ptr<IObject> CreateObject(OBJECTTYPE name);
            static std::unique_ptr<IObject> CreateSphere();
            static std::unique_ptr<IObject> CreatePlane();
            static std::unique_ptr<IObject> CreateCone();
            static std::unique_ptr<IObject> CreateCylindre();
            // factory for light
            static std::unique_ptr<ILight> CreateLight(LIGHTTYPE name);
            static std::unique_ptr<ILight> CreatePoint();

    };
}
