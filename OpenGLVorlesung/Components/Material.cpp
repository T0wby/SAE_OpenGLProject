#include "Material.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

const GLsizei I_SHADER_ID = 1;

// Global Variables
unsigned int I_SHADER_PROGRAM = 0;

auto CMaterial::GetShaderID(void) const -> const int
{
    return I_SHADER_ID;
}

const int CMaterial::Initialize(void) const
{
    const int buffersize{ 1024 };
    int success{};
    char infoLog[buffersize];

    // VertexShader
    auto sVertArr = m_sTestVertexShader.c_str();
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
    auto sFragArr = m_sTestFragmentShader.c_str();
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

    return 0;
}

const int CMaterial::Update(void) const
{
    return 0;
}

void CMaterial::Draw(void)
{
    glUseProgram(I_SHADER_PROGRAM);
}

void CMaterial::Finalize(void)
{
}
