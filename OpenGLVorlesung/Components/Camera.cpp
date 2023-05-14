#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>

const int CCamera::Initialize(void) const
{
    /*glUseProgram(m_cameraData.iShaderID);
    glUniform1i(glGetUniformLocation(m_cameraData.iShaderID, "texture1"), 0);
    glUniform1i(glGetUniformLocation(m_cameraData.iShaderID, "texture2"), 1);*/
    return 0;
}

const int CCamera::Update(void) const
{
    auto view = glm::mat4x4(1.0f);
    auto projection = glm::mat4x4(1.0f);
    glm::mat4 trans = glm::mat4(1.0f);

    //            Our pos, direction of our rotation, that is up
    view = glm::lookAt(m_pos, m_pos + m_orientation, m_up);

    projection = glm::perspective(glm::radians(m_cameraData.fFOVdegree), static_cast<float>(m_iWidth / m_iHeight), m_cameraData.fNearPlane, m_cameraData.fFarPlane);
    trans = glm::rotate(trans, static_cast<float>(glfwGetTime()), glm::vec3(0.0f, 0.0f, 1.0f));


    glUniformMatrix4fv(glGetUniformLocation(m_cameraData.iShaderID, "view"), 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(m_cameraData.iShaderID, "projection"), 1, GL_FALSE, glm::value_ptr(projection));
    
    glUniformMatrix4fv(glGetUniformLocation(m_cameraData.iShaderID, "transform"), 1, GL_FALSE, glm::value_ptr(trans));

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
