#include "Shader.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

const GLsizei I_SHADER_ID = 1;

unsigned int I_SHADER_PROGRAM = 0;

auto CShader::GetShaderID(void) const -> const int
{
	return I_SHADER_ID;
}

auto CShader::GetShaderProgram(void) const -> const unsigned int
{
	return I_SHADER_PROGRAM;
}

void CShader::SendMat4ToShader(const std::string& a_sName, const glm::mat4& a_mat) const
{
    glUniformMatrix4fv(glGetUniformLocation(I_SHADER_PROGRAM, a_sName.c_str()), 1, GL_FALSE, glm::value_ptr(a_mat));
}

void CShader::SendVec3ToShader(const std::string& a_sName, const glm::vec3& a_vec) const
{
    glUniform3fv(glGetUniformLocation(I_SHADER_PROGRAM, a_sName.c_str()), 1, glm::value_ptr(a_vec));
}

void CShader::Initialize(void)
{
    const int buffersize{ 1024 };
    int success{};
    char infoLog[buffersize];

    // VertexShader
    auto sVertArr = m_sVertexShader.c_str();
    auto iVertexShader = static_cast<GLuint>(glCreateShader(GL_VERTEX_SHADER));
    glShaderSource(iVertexShader, I_SHADER_ID, &sVertArr, NULL); // Binding iVertexShader with the string m_sVertexShader
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
    glShaderSource(iFragmentShader, I_SHADER_ID, &sFragArr, NULL); // Binding iFragmentShader with the string m_sFragmentShader
    glCompileShader(iFragmentShader);

    glGetShaderiv(iFragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(iFragmentShader, buffersize, nullptr, infoLog);
        std::cout << "ERR: FragmentShader compilation failed!\n" << infoLog << std::endl;
    }

    // ShaderBuffer(Programm)
    I_SHADER_PROGRAM = glCreateProgram();
    glAttachShader(I_SHADER_PROGRAM, iVertexShader);
    glAttachShader(I_SHADER_PROGRAM, iFragmentShader);
    glLinkProgram(I_SHADER_PROGRAM);

    glGetProgramiv(I_SHADER_PROGRAM, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(I_SHADER_PROGRAM, buffersize, nullptr, infoLog);
        std::cout << "ERR: Shader Linking failed!\n" << infoLog << std::endl;
    }

    glDeleteShader(iVertexShader);
    glDeleteShader(iFragmentShader);
}

void CShader::Draw(void)
{
    glUseProgram(I_SHADER_PROGRAM);
}
