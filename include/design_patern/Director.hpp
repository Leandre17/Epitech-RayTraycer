/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-raytracer-johanna.bureau
** File description:
** Director
*/

#pragma once

#include "Builder.hpp"
#include "Scene.hpp"

namespace RayTracer {
    class Director {
        public:
            Director(Builder::IceCreamBuilder builder);
            ~Director();
            Director(const Director &other);
            Director(Director &&other);
            Director &operator=(const Director &other);
            Director &operator=(Director &&other);
            void createIceCream(RayTracer::Scene &scene, RayTracer::Parsing_OBJ &parsing);

        protected:
        private:
            Builder::IceCreamBuilder m_builder;
    };
}
