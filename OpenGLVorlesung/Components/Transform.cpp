#include "Transform.h"
#include <glad/glad.h>
#include <glm/gtx/euler_angles.hpp>
#include <glm/gtx/transform.hpp>

int CTransform::Initialize(void)
{
    return 0;
}

int CTransform::Update(void)
{

	//update the transformmatrix of this class
	m_transformMatrix = m_positionMatrix * m_rotationMatrix * m_scaleMatrix;

	//update the positionmatrix of this class
	m_positionMatrix = glm::translate(m_position);

	//update the rotationmatrix of this class
	m_rotationMatrix = glm::yawPitchRoll(m_rotation.y, m_rotation.x, m_rotation.z);

	//update the scalematrix of this class
	m_scaleMatrix = glm::scale(m_scale);

	//update the transformmatrix of this class
	m_transformMatrix = m_positionMatrix * m_rotationMatrix * m_scaleMatrix;

    return 0;
}

void CTransform::Draw(void)
{

}

void CTransform::Finalize(void)
{
}
