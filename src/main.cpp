
#include "Image.hpp"
#include "Scene.hpp"

int main(int, char**) {
    RayTracer::Image m_image{1280, 720};
    RayTracer::Scene m_scene;

    m_scene.Render(m_image);
    m_image.Display();
}
