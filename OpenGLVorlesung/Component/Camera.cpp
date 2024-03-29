#include "Camera.h"

const int CCamera::Intialize(void) const
{
    return 0;
}

const int CCamera::Update(void) const
{
    auto view = glm::mat4x4(1.0f);
    auto projection = glm::mat4x4(1.0f);

    view = glm::lookAt(m_pos, m_pos + m_orientation, m_up);
    projection = glm::perspective(glm::radians(m_cameraData.fFOVdegree), static_cast<float>(m_iWidth) / m_iHeight, m_cameraData.fNearPlane, m_cameraData.fFarPlane);

    glUniformMatrix4fv(glGetUniformLocation(m_cameraData.iShaderID, m_cameraData.sName), 1, GL_FALSE, glm::value_ptr(projection * view));

    return 0;
}

void CCamera::Draw(void) const
{
}

void CCamera::Finalize(void)
{
}
