/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-raytracer-johanna.bureau
** File description:
** Primitives
*/

#pragma once
#include "RayTracer.hpp"

namespace RayTracer {
    class Sphere {
        public :
            Sphere(Math::Point3D, double);
            bool hits(RayTracer::Ray);
            void translate(Math::Vector3D translate);
            void rotate(double angle, Math::Vector3D axis);
            ~Sphere() = default;
        private:
            Math::Point3D center;
            double radius;
            double rotation_angle;
            Math::Vector3D rotation_axis;
    };

    class Plane {
        public:
            Plane(Math::Point3D pointa, Math::Point3D pointb, Math::Point3D pointc, Math::Point3D pointd);
            bool hits(RayTracer::Ray);
            void translate(Math::Vector3D translate);
            ~Plane() = default;
        private:
            Math::Point3D pointa;
            Math::Point3D pointb;
            Math::Point3D pointc;
            Math::Point3D pointd;

    };
}

namespace Math {
     class Matrix3D {
        public:
            Matrix3D() {
                for (int i = 0; i < 9; i++) {
                    data[i] = 0;
                }
            }

            Matrix3D(double a, double b, double c,
                    double d, double e, double f,
                    double g, double h, double i) {
                data[0] = a; data[1] = b; data[2] = c;
                data[3] = d; data[4] = e; data[5] = f;
                data[6] = g; data[7] = h; data[8] = i;
            }

            double& operator()(int row, int col) {
                return data[row * 3 + col];
            }

            double operator()(int row, int col) const {
                return data[row * 3 + col];
            }

            Vector3D operator*(const Vector3D& v) const {
                return Vector3D(
                    data[0] * v.X + data[1] * v.Y + data[2] * v.Z,
                    data[3] * v.X + data[4] * v.Y + data[5] * v.Z,
                    data[6] * v.X + data[7] * v.Y + data[8] * v.Z
                );
            }

            Matrix3D operator*(const Matrix3D& m) const {
                Matrix3D result;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        double sum = 0;
                        for (int k = 0; k < 3; k++) {
                            sum += data[i * 3 + k] * m.data[k * 3 + j];
                        }
                        result(i, j) = sum;
                    }
                }
                return result;
            }

        private:
            double data[9];
    };

    inline Vector3D rotate(Vector3D v, double angle, Vector3D axis) {
        double radians = angle * M_PI / 180.0;
        double c = cos(radians);
        double s = sin(radians);
        double t = 1 - c;
        double x = axis.X, y = axis.Y, z = axis.Z;

        Matrix3D rotation_matrix(
            t*x*x + c,   t*x*y - s*z, t*x*z + s*y,
            t*x*y + s*z, t*y*y + c,   t*y*z - s*x,
            t*x*z - s*y, t*y*z + s*x, t*z*z + c
        );

        return rotation_matrix * v;
    }

    inline Point3D rotate(Point3D p, double angle, Vector3D axis) {
        Vector3D v = p.to_vector();
        v = rotate(v, angle, axis);
        return Point3D(v.X, v.Y, v.Z);
    }
}