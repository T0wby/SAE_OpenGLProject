#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Component.h"
#include <glm/glm.hpp>
#include <iostream>

class CCamera : public IComponent
{
public:

	inline CCamera(int a_iWidth, int a_iHeight, glm::vec3 a_pos, glm::vec3 a_orient, glm::vec3 a_up)
		: m_iWidth(a_iWidth), m_iHeight(a_iHeight), m_pos(a_pos), m_orientation(a_orient), m_up(a_up) {}

	inline auto GetOrientation(void) const -> const glm::vec3 { return m_orientation; }
	inline auto GetUp(void) const -> const glm::vec3 { return m_up; }
	inline auto GetSpeed(void) const -> const float { return m_fSpeed; }

	inline void SetCameraData(float a_fFOVdegree, float a_fNearPlane, float a_fFarPlane, GLuint a_iShaderID, const GLchar* a_sName)
	{
		m_cameraData = { a_fFOVdegree , a_fNearPlane , a_fFarPlane , a_iShaderID, a_sName };
	}

	inline void SetPosition(glm::vec3 a_pos) 
	{ 
		m_pos += a_pos; 
		std::cout << "Camera Pos is X: " << m_pos.x << " Y: " << m_pos.y << " Z: " << m_pos.z << std::endl;

	}

	// Inherited via IComponent
	virtual const int Initialize(void) const override;
	virtual const int Update(void) const override;
	virtual void Draw(void) override;
	virtual void Finalize(void) override;

private:
	//ScreenSize
	int m_iWidth{ 0 };
	int m_iHeight{ 0 };

	glm::vec3 m_pos = {};
	glm::vec3 m_orientation = {};
	glm::vec3 m_up = {};
	float m_fSpeed = 0.1f;

	struct
	{
		float fFOVdegree;
		float fNearPlane;
		float fFarPlane;
		GLuint iShaderID;
		const GLchar* sName;
	} m_cameraData = {};
};
#endif // !CAMERA_H



