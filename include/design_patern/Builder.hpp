/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-raytracer-johanna.bureau
** File description:
** Builder
*/

#pragma once

#include "IObject.hpp"
#include "Factory.hpp"
#include "Scene.hpp"
#include <memory>
#include <vector>

namespace RayTracer {
    namespace Builder {
        class IceCreamBuilder {
            public:
                IceCreamBuilder();
                ~IceCreamBuilder();
                IceCreamBuilder(const IceCreamBuilder &iceCreamBuilder);
                IceCreamBuilder(IceCreamBuilder &&iceCreamBuilder);
                IceCreamBuilder &operator=(const IceCreamBuilder &iceCreamBuilder);
                IceCreamBuilder &operator=(IceCreamBuilder &&iceCreamBuilder);
                void BuildIceCream(RayTracer::Scene &scene, RayTracer::Parsing_OBJ &parsing);
                void BuildSphere();
                void BuildCone();
                void render();
                int &getObjects();

            private:
                int m_objects;
        };
    }
}