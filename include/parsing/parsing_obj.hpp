/*
** EPITECH PROJECT, 2023
** B-OOP-400-BDX-4-1-raytracer-johanna.bureau
** File description:
** parsing_obj
*/

#include <iostream>
#include <stdlib.h>
#include <libconfig.h++>
#include <string.h>
#include <stdio.h>
#include <vector>

#ifndef PARSING_OBJ_HPP_
#define PARSING_OBJ_HPP_

using tab_int = std::vector<int>;

namespace RayTracer {

    class Parsing_OBJ {
        public:
            Parsing_OBJ(char *filename);
            ~Parsing_OBJ() = default;

            int parse_camera(void);
            int parse_primitives(void);
            int parse_lights(void);

            int print_informations(void);
            int print_tab(std::vector<tab_int> tab);
            int manage_parsing(void);
            //general
            std::string m_filename;
            libconfig::Config m_cfg;
            //camera
            int m_camera_width;
            int m_camera_height;
            double m_camera_pos_x;
            double m_camera_pos_y;
            double m_camera_pos_z;
            int m_camera_rotX;
            int m_camera_rotY;
            int m_camera_rotZ;
            double m_camera_fov;
            //primitives
            int m_primitives_nbSpheres;
            int m_primitives_nbPlanes;
            std::vector<tab_int> m_primitives_tab_spheres;
            std::vector<tab_int> m_primitives_tab_planes;
            //lights
            float m_lights_ambient;
            float m_lights_diffuse;
            int m_lights_nb_points;
            int m_lights_nb_directional;
            std::vector<tab_int> m_lights_tab_points;
            std::vector<tab_int> m_lights_tab_directional;
        protected:
        private:
    };

}

#endif /* !PARSING_OBJ_HPP_ */
