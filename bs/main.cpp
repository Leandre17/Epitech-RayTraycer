
#include "Point.hpp"
#include "Vector.hpp"
#include "camera.hpp"
#include "RayTracer.hpp"
#include <iostream>

int main() {
    RayTracer::Camera cam;
    RayTracer::Sphere s(Math::Point3D(0, 0, -1), 0.5);
    for (/* go through the Y axis */ double y = 0; y < 300; y += 1) {
        for (/* go through the X axis */ double x = 0; x < 300; x += 1) {
            double u = x/* get a certain amount of X */;
            double v = y/* get a certain amount of Y */;
            RayTracer::Ray r = cam.ray(u, v);
            if (s.hits(r)) {
                std::cout << x << ", " << y << " hits\n";
                // something
            } else {
                std::cout << x << ", " << y << " don't hits\n";
                // something else
            }
        }
    }
}