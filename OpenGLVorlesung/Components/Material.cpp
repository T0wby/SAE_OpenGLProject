#include "Material.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

const GLsizei I_SHADER_ID = 1;

// Global Variables
unsigned int I_SHADER_PROGRAM = 0;
unsigned int I_TEXTURE = 0;
int I_WIDTH = 0, I_HEIGHT = 0, I_CHANNELS = 0;

auto CMaterial::GetShaderID(void) const -> const int
{
    return I_SHADER_ID;
}

auto CMaterial::GetShaderProgram(void) const -> const unsigned int
{
    return I_SHADER_PROGRAM;
}

const int CMaterial::Initialize(void) const
{
#pragma region Shader
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
#pragma endregion


    glGenTextures(1, &I_TEXTURE);

    glBindTexture(GL_TEXTURE_2D, I_TEXTURE);

    // set the texture wrapping/filtering options (on the currently bound texture object)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    unsigned char* texdata = stbi_load(m_sTexture.c_str(), &I_WIDTH, &I_HEIGHT, &I_CHANNELS, 0);

    if (texdata)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, I_WIDTH, I_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, texdata);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }


    stbi_image_free(texdata);

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
