/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-raytracer-johanna.bureau
** File description:
** main
*/


#include <iostream>
#include <string.h>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
#include "Primitives.hpp"

static void help(void)
{
    std::cout << "USAGE: ./raytracer <SCENE_FILE>" << std::endl;
    std::cout << "  SCENE_FILE: scene configuration" << std::endl;
}

int main(int argc, char **argv)
{
    if (argc == 2 && strcmp(argv[1], "--help") == 0) {
        help();
        return (0);
    }
    sf::RenderWindow window(sf::VideoMode(500, 500), "raytracer");
    std::vector<sf::RectangleShape> rects;
    RayTracer::Camera cam{{Math::Point3D(0.5, 0.5, 3)}, {}};
    RayTracer::Sphere s(Math::Point3D(0, 0, 1), 0.5);

    window.setFramerateLimit(1);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
                if (event.key.code == sf::Keyboard::D) {
                    std::cout << "droite" << std::endl;
                    s.translate({-0.1, 0, 0});
                }
                if (event.key.code == sf::Keyboard::Q) {
                    std::cout << "gauche" << std::endl;
                    s.translate({0.1, 0, 0});
                }
                if (event.key.code == sf::Keyboard::Z) {
                    std::cout << "haut" << std::endl;
                    s.translate({0, -0.1, 0});
                }
                if (event.key.code == sf::Keyboard::S) {
                    std::cout << "bas" << std::endl;
                    s.translate({0, 0.1, 0});
                }
                if (event.key.code == sf::Keyboard::R) {
                    std::cout << "rotate" << std::endl;
                    s.rotate(45, Math::Vector3D(0, 1, 0));
                }
            }
        }

        // Efface la fenêtre
        window.clear();
        rects.clear();
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

        // Dessine tous les rectangles
        for (auto rectangle : rects) window.draw(rectangle);

        // Affiche la fenêtre
        window.display();
    }
    return 0;
}
