/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-raytracer-johanna.bureau
** File description:
** main
*/

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
#include "Primitives.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "raytracer");
    std::vector<sf::RectangleShape> rects;
    RayTracer::Camera cam{{Math::Point3D(0, 0, -1)}, {}};
    RayTracer::Sphere s(Math::Point3D(0, 0, 0), 0.5);
    s.translate({1, 1, 0});
    for ( double y = 0; y <= 2; y += .004) {
        for (double x = 0; x <= 2; x += .004) {
            sf::RectangleShape rectangle;
            rectangle.setSize(sf::Vector2f(1, 1));
            rectangle.setPosition((x / 2) * 500, 500 - (y / 2) * 500);
            double u = x;
            double v = y;
            RayTracer::Ray r = cam.ray(u, v);
            if (s.hits(r)) {
                rectangle.setFillColor(sf::Color::Red);
            } else {
                rectangle.setFillColor(sf::Color::Blue);
            }
            rects.push_back(rectangle);
        }
    }
    window.setFramerateLimit(1);
    while (window.isOpen()) {
        sf::Event event;
        for (auto rectangle : rects) window.draw(rectangle);
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.display();
        window.clear();
    }
    return 0;
}
