/*
** EPITECH PROJECT, 2023
** raytraycer
** File description:
** Image
*/

#pragma once
#include "Color.hpp"
#include <vector>
#include <map>
#include <tuple>
#include <iostream>

namespace RayTracer {
    class Image {
        public:
            Image(const int width, const int height);
            ~Image() = default;
            void SetPixel(const int x, const int y, const double red, const double green, const double blue);
            void Display();
            void Display(std::string filepath);
            int GetWidth();
            int GetHeight();
        private:
            int width;
            int height;
            std::map<std::tuple<int, int>, RayTracer::Color> pixels;
    };

} // namespace RayTracer
