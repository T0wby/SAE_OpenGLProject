#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>

auto CCamera::GetViewMatrix() const -> const glm::mat4
{
	return glm::lookAt(m_pos, m_pos + m_orientation, m_up);
}

auto CCamera::GetProjectionMatrix() const -> const glm::mat4
{
	return glm::perspective(glm::radians(m_cameraData.fFOVdegree), static_cast<float>(m_iWidth / m_iHeight), m_cameraData.fNearPlane, m_cameraData.fFarPlane);
}

auto CCamera::GetCamMatrix() const -> const glm::mat4
{
	auto view = glm::mat4x4(1.0f);
	view = glm::lookAt(m_pos, m_pos + m_orientation, m_up);
	auto projection = glm::mat4x4(1.0f);
	projection = glm::perspective(glm::radians(m_cameraData.fFOVdegree), static_cast<float>(m_iWidth / m_iHeight), m_cameraData.fNearPlane, m_cameraData.fFarPlane);
	return projection * view;
}

int CCamera::Initialize(void)
{
	return 0;
}

int CCamera::Update(void)
{

	return 0;
}

void CCamera::Draw(void)
{
}

void CCamera::Finalize(void)
{
}

void CCamera::CalcOrientation(glm::vec3 a_front)
{
	m_orientation = glm::normalize(a_front);
}
