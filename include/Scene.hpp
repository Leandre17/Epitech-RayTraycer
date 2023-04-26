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
#include "PointLight.hpp"

namespace RayTracer {
    class Scene {
        public:
            Scene();

            // Function to perform the rendering.
            bool Render(RayTracer::Image &outputImage);

        private:
            RayTracer::Camera m_camera;
            // The list of objects in the scene.
            std::vector<std::unique_ptr<RayTracer::AObject>> m_objectList;

            // The list of lights in the scene.
            std::vector<std::unique_ptr<RayTracer::ALight>> m_lightList;
    };
} // namespace RayTracer

