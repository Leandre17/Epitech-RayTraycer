/*
** EPITECH PROJECT, 2023
** raytraycer
** File description:
** Image
*/

#include "Image.hpp"

RayTracer::Image::Image(const int width, const int height) : width{width}, height{height} {
    // for (int x = 0; x < width; x++)
    //     for (int y = 0; y < height; y++)
    //         this->pixels[std::tuple<int, int>{x, y}] = (RayTracer::Color){0, 0, 0};
}

void RayTracer::Image::SetPixel(const int x, const int y, const double red, const double green, const double blue) {
    // std::cerr << x << ", " << y << "" << red << " " << green << " " << blue << "\n";
    this->pixels[std::tuple<int, int>{y, x}] = (RayTracer::Color){red, green, blue};
}

void RayTracer::Image::Display() {
    std::cout << "P3\n" << width << " " << height << "\n255\n";
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            std::cout << this->pixels[std::tuple<int, int>{y, x}];
}

int RayTracer::Image::GetWidth() { return width; }
int RayTracer::Image::GetHeight() { return height; }
