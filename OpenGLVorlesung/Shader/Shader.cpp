#include "Shader.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

//const GLsizei I_SHADER_ID = 1;

//I_SHADER_PROGRAM = 0;

auto CShader::GetShaderID(void) const -> const int
{
	return m_iShaderID;
}

auto CShader::GetShaderProgram(void) const -> const unsigned int
{
	return m_iShaderProgram;
}

void CShader::SendMat4ToShader(const std::string& a_sName, const glm::mat4& a_mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(m_iShaderProgram, a_sName.c_str()), 1, GL_FALSE, glm::value_ptr(a_mat));
}

void CShader::SendVec3ToShader(const std::string& a_sName, const glm::vec3& a_vec) const
{
    glUniform3fv(glGetUniformLocation(m_iShaderProgram, a_sName.c_str()), 1, glm::value_ptr(a_vec));
}

void CShader::SendFloatToShader(const std::string& a_sName, const float& a_float) const
{
    glUniform1f(glGetUniformLocation(m_iShaderProgram, a_sName.c_str()), a_float);
}

void CShader::Initialize(void)
{
    const int buffersize{ 1024 };
    int success{};
    char infoLog[buffersize];

    // VertexShader
    auto sVertArr = m_sVertexShader.c_str();
    auto iVertexShader = static_cast<GLuint>(glCreateShader(GL_VERTEX_SHADER));
    glShaderSource(iVertexShader, m_iShaderID, &sVertArr, NULL); // Binding iVertexShader with the string m_sVertexShader
    glCompileShader(iVertexShader);

    glGetShaderiv(iVertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(iVertexShader, buffersize, nullptr, infoLog);
        std::cout << "ERR: VertexShader compilation failed!\n" << infoLog << std::endl;
    }

    // FragmentShader
    auto sFragArr = m_sFragmentShader.c_str();
    auto iFragmentShader = static_cast<GLuint>(glCreateShader(GL_FRAGMENT_SHADER));
    glShaderSource(iFragmentShader, m_iShaderID, &sFragArr, NULL); // Binding iFragmentShader with the string m_sFragmentShader
    glCompileShader(iFragmentShader);

    glGetShaderiv(iFragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(iFragmentShader, buffersize, nullptr, infoLog);
        std::cout << "ERR: FragmentShader compilation failed!\n" << infoLog << std::endl;
    }

    // ShaderBuffer(Programm)
    m_iShaderProgram = glCreateProgram();
    glAttachShader(m_iShaderProgram, iVertexShader);
    glAttachShader(m_iShaderProgram, iFragmentShader);
    glLinkProgram(m_iShaderProgram);

    glGetProgramiv(m_iShaderProgram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(m_iShaderProgram, buffersize, nullptr, infoLog);
        std::cout << "ERR: Shader Linking failed!\n" << infoLog << std::endl;
    }

    glDeleteShader(iVertexShader);
    glDeleteShader(iFragmentShader);
}

void CShader::Draw(void)
{
    glUseProgram(m_iShaderProgram);
}
