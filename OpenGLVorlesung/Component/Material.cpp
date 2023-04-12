#include "Material.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

unsigned int I_SHADER_PROGRAMM = 0;
const GLsizei I_SHADER_NUMB = 1;

const int CMaterial::Intialize(void) const
{
    auto sVertArr = m_sVertexShader.c_str();

    auto iVertexShader = static_cast<GLuint>(glCreateShader(GL_VERTEX_SHADER)); // shader erstellen
    glShaderSource(iVertexShader, I_SHADER_NUMB, &sVertArr, NULL); // datei angeben
    glCompileShader(iVertexShader); // kompilieren

    auto sFragArr = m_sFragmentShader.c_str();

    auto iFragmentShader = static_cast<GLuint>(glCreateShader(GL_FRAGMENT_SHADER)); // shader erstellen
    glShaderSource(iFragmentShader, I_SHADER_NUMB, &sFragArr, NULL); // datei angeben
    glCompileShader(iFragmentShader); // kompilieren

    I_SHADER_PROGRAMM = glCreateProgram();
    glAttachShader(I_SHADER_PROGRAMM, iVertexShader);
    glAttachShader(I_SHADER_PROGRAMM, iFragmentShader);
    glLinkProgram(I_SHADER_PROGRAMM);

    glDeleteShader(iVertexShader);
    glDeleteShader(iFragmentShader);

    return 0;
}

const int CMaterial::Update(void) const
{
    return 0;
}

void CMaterial::Draw(void) const
{
    glUseProgram(I_SHADER_PROGRAMM);
}

void CMaterial::Finalize(void)
{
}
