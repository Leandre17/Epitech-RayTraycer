/*
** EPITECH PROJECT, 2023
** Visual Studio Live Share (Espace de travail)
** File description:
** scene
*/

#pragma once

#include <SDL2/SDL.h>
#include <memory>
#include <vector>
#include "Camera.hpp"
#include "Image.hpp"
#include "Plane.hpp"
#include "Sphere.hpp"
#include "Cone.hpp"
#include "Cylindre.hpp"
#include "PointLight.hpp"
#include "parsing_obj.hpp"

namespace RayTracer {
    class Scene {
        public:
            Scene(RayTracer::Parsing_OBJ parsing);
            bool Render(RayTracer::Image &outputImage);
            RayTracer::Camera m_camera;
            std::vector<std::unique_ptr<RayTracer::IObject>> m_objectList;
            std::vector<std::unique_ptr<RayTracer::ILight>> m_lightList;
        private:
    };
} // namespace RayTracer

