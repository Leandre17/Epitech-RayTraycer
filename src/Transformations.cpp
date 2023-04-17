/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-raytracer-johanna.bureau
** File description:
** Transformations
*/

#include "Primitives.hpp"

void RayTracer::Sphere::translate(Math::Vector3D translate)
{
    this->center += translate;
}
