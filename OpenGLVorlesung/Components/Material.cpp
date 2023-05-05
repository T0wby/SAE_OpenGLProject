#include "Material.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

const GLsizei I_SHADER_COUNT = 1;

// Global Variables
unsigned int I_SHADER_PROGRAM = 0;

const int CMaterial::Initialize(void) const
{
    // VertexShader
    GLuint iVertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(iVertexShader, I_SHADER_COUNT, &m_sVertexShader, NULL); // Binding iVertexShader with the const char m_sVertexShader
    glCompileShader(iVertexShader);


    // FragmentShader
    GLuint iFragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(iFragmentShader, I_SHADER_COUNT, &m_sFragmentShader, NULL); // Binding iFragmentShader with the const char m_sFragmentShader
    glCompileShader(iFragmentShader);

    // ShaderBuffer(Programm)
    I_SHADER_PROGRAM = glCreateProgram();
    glAttachShader(I_SHADER_PROGRAM, iVertexShader);
    glAttachShader(I_SHADER_PROGRAM, iFragmentShader);
    glLinkProgram(I_SHADER_PROGRAM);

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
