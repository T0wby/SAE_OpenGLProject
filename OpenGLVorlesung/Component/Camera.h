#pragma once
#include "Component.h"
#include <../glad/glad.h>
#include <../GLFW/glfw3.h>
#include "../glm/glm.hpp"
#include "../glm/gtc/matrix_transform.hpp"
#include "../glm/gtc/type_ptr.hpp"
#include "../glm/gtx/vector_angle.hpp"


class CCamera : public IComponent
{
private:
	//ScreenSize
	int m_iWidth{ 0 };
	int m_iHeight{ 0 };
	
	glm::vec3 m_pos = {};
	glm::vec3 m_orientation = {}; //wie weit von 0 entfernt
	glm::vec3 m_up = {}; 

public:

	inline CCamera(int a_iWidth, int a_iHeight, glm::vec3 a_pos, glm::vec3 a_orient, glm::vec3 a_up )
		: m_iWidth(a_iWidth), m_iHeight(a_iHeight), m_pos(a_pos), m_orientation(a_orient), m_up(a_up) {}

	inline void SetCameraData(float a_fFOVdegree, float a_fNearPlane, float a_fFarPlane, GLuint a_iShaderID, const GLchar* a_sName)
	{
		m_cameraData = { a_fFOVdegree , a_fNearPlane , a_fFarPlane , a_iShaderID, a_sName };
	};
	// Inherited via IComponent
	virtual const int Intialize(void) const override;
	virtual const int Update(void) const override;
	virtual void Draw(void) const override;
	virtual void Finalize(void) override;

private:
	struct
	{
		float fFOVdegree;
		float fNearPlane;
		float fFarPlane;
		GLuint iShaderID;
		const GLchar* sName;
	} m_cameraData;
};

