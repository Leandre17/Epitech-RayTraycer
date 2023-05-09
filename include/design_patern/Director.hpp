/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-raytracer-johanna.bureau
** File description:
** Director
*/

#pragma once

#include "Builder.hpp"

namespace RayTracer {
    class Director {
        public:
            Director(Builder::IceCreamBuilder builder);
            ~Director();
            Director(const Director &other);
            Director(Director &&other);
            Director &operator=(const Director &other);
            Director &operator=(Director &&other);
            void createIceCream();

        protected:
        private:
            Builder::IceCreamBuilder m_builder;
    };
}
