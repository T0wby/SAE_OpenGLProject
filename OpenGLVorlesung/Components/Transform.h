#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Component.h"
#include <glm/glm.hpp>

class CTransform : public IComponent
{
public:

	// Inherited via IComponent
	virtual const int Initialize(void) const override;
	virtual int Update(void) override;
	virtual void Draw(void) override;
	virtual void Finalize(void) override;

	glm::vec3 m_position{};
	glm::vec3 m_rotation{};
	glm::vec3 m_scale{ 1.0f,1.0f,1.0f };
	glm::mat4x4 m_transformMatrix{};
	glm::mat4x4 m_positionMatrix{};
	glm::mat4x4 m_rotationMatrix{};
	glm::mat4x4 m_scaleMatrix{};

};
#endif // !TRANSFORM_H




