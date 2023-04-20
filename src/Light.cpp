/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-raytracer-johanna.bureau
** File description:
** Light
*/

#include "Light.hpp"

Light::Light(double ambient, double diffuse, Math::Point3D point) : ambient{ambient}, diffuse{diffuse}, origin{point} {
    
}