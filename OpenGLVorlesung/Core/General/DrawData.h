#pragma once
#include <glm/glm.hpp>

struct DrawData
{
	DrawData() = default;
	DrawData(const DrawData&) = default;
	DrawData(DrawData&&) = default;
	DrawData& operator= (const DrawData&) = default;
	DrawData& operator= (DrawData&&) = default;
	~DrawData() = default;
	
	glm::mat4 m_projectionViewMatrix{};
	glm::vec3 m_cameraPosition{};
	glm::vec3 m_lightPosition{};
	glm::vec3 m_lightAmbient{};
	glm::vec3 m_lightDiffuse{};
	glm::vec3 m_lightSpecular{};
};

