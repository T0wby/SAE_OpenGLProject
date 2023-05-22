#pragma once
#include <glm/glm.hpp>

struct DrawData
{
	glm::mat4 m_projectionViewMatrix;
	glm::vec3 m_cameraPosition;
	glm::vec3 m_lightPosition;
};

