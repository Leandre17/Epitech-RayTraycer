/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** Color
*/

#pragma once

#include <ostream>

namespace RayTracer {

    class Color {
        public:
            Color() = default;
            Color(double, double, double);
            Color(int, int, int);
            Color(Color &&) = default;
            Color(const Color &) = default;
            Color &operator=(Color &&) = default;
            Color &operator=(const Color &) = default;
            ~Color() = default;

            int getRed() const;
            int getGreen() const;
            int getBlue() const;
        private:
            int red;
            int green;
            int blue;
    };

}
std::ostream &operator<<(std::ostream &, const RayTracer::Color &);


