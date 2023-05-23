#ifndef MATERIAL_H
#define MATERIAL_H
#include <glm/glm.hpp>

struct CMaterial
{
    glm::vec3 m_vAmbient{0.0f, 0.0f, 0.0f};
    glm::vec3 m_vDiffuse{0.0f, 0.0f, 0.0f};
    glm::vec3 m_vSpecular{0.0f, 0.0f, 0.0f};
    float m_fShininess{0.0f};
};
#endif


