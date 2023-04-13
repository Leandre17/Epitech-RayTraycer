
#include "Vector.hpp"
#include "camera.hpp"
#include "RayTracer.hpp"
#include <iostream>

void write_color(Math::Vector3D vector)
{
    std::cout << vector.X << " "<< vector.Y << " "<< vector.Z << "\n";
}

int main() {
    RayTracer::Camera cam{{}, {}};
    RayTracer::Sphere s(Math::Point3D(0, 0, -1), 1);
    std::cout << "P3\n1000 1000\n255\n";
    for (/* go through the Y axis */ double y = 0; y < 100; y += .1) {
        for (/* go through the X axis */ double x = 0; x < 100; x += .1) {
            double u = x/* get a certain amount of X */;
            double v = y/* get a certain amount of Y */;
            RayTracer::Ray r = cam.ray(u, v);
            if (s.hits(r)) {
                // std::cout << x << ", " << y << " hits\n";
                write_color({255, 0, 0});
            } else {
                // std::cout << x << ", " << y << " don't hits\n";
                write_color({0, 0, 255});
            }
        }
    }
}