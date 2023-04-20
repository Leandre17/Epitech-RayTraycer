/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-raytracer-johanna.bureau
** File description:
** Light
*/

#pragma once

#include <algorithm>
#include <limits>
#include "Vector.hpp"
#include "Primitives.hpp"
#include "RayTracer.hpp"

const int kPrimaryRay = 0;
const float kInfinity = std::numeric_limits<float>::max();
const float kEpsilon = 0.001;
const int kShadowRay = 1;

class Light {
    public:
        Light() = default;
        Light(double ambient, double diffuse, Math::Point3D point);
        ~Light() = default;

    private:
        double ambient;
        double diffuse;
        Math::Point3D origin;
        Math::Vector3D dir;
};






class Vec2f {
public:
    float x, y;

    Vec2f() : x(0), y(0) {}
    Vec2f(float xx) : x(xx), y(xx) {}
    Vec2f(float xx, float yy) : x(xx), y(yy) {}
};

struct IsectInfo {
    double tNear;
    int index;
    Vec2f uv;
    RayTracer::Sphere *hitObject;

    IsectInfo() : tNear(kInfinity), index(0), uv(Vec2f(0, 0)), hitObject(nullptr) {}

    IsectInfo(float tNear, int index, const Vec2f &uv, RayTracer::Sphere *hitObject)
        : tNear(tNear), index(index), uv(uv), hitObject(hitObject) {}
};

bool trace(const Math::Vector3D &orig, const Math::Vector3D &dir,
           const std::vector<std::unique_ptr<RayTracer::Sphere>> &objects,
           IsectInfo &isect)
{
    isect.tNear = kInfinity;
    isect.hitObject = nullptr;

    for (const auto &object : objects) {
        IsectInfo currIsect;
        if (object->hits((RayTracer::Ray){(Math::Point3D)orig, dir})) {
            if (currIsect.tNear < isect.tNear && currIsect.tNear > kEpsilon) {
                isect = currIsect;
                isect.hitObject = object.get();
            }
        }
    }

    return (isect.hitObject != nullptr);
}

bool castRay(
    const Math::Vector3D &orig, const Math::Vector3D &dir,
    const std::vector<std::unique_ptr<RayTracer::Sphere>> &objects,
    const std::unique_ptr<Light> &light)
{
    bool vis = false;
    Math::Vector3D hitColor;
    IsectInfo isect;
    if (trace(orig, dir, objects, isect)) {
        Math::Vector3D hitPoint = orig + dir * isect.tNear;
        Math::Vector3D hitNormal;
        Vec2f hitTexCoordinates;
        //isect.hitObject->getSurfaceProperties(hitPoint, dir, isect.index, isect.uv, hitNormal, hitTexCoordinates);
        Math::Vector3D L = - light->dir;
        IsectInfo isectShad;
        vis = !trace(hitPoint + hitNormal * 1, L, objects, isectShad);
        hitColor = {128, 128, 128}; // color shadow -> grey
        // hitColor = vis * isect.hitObject->albedo * light->intensity * light->color * std::max(0.0, dot(hitNormal, L));
    }

    return vis;
}
