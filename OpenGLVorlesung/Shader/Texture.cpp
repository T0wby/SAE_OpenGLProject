#include "Texture.h"
#include <glad/glad.h>
#include <iostream>

//#define STB_IMAGE_IMPLEMENTATION
//#include "stb/stb_image.h"
//
//unsigned int I_TEXTURE = 0;
//unsigned int I_TEXTURE_2 = 0;
//int I_WIDTH = 0, I_HEIGHT = 0, I_CHANNELS = 0;
//
//void CTexture::Initialize(void)
//{
//    glGenTextures(1, &I_TEXTURE);
//    //glGenTextures(1, &I_TEXTURE_2);
//
//    glActiveTexture(GL_TEXTURE0); // Texture unit GL_TEXTURE0 is always by default activated
//    glBindTexture(GL_TEXTURE_2D, I_TEXTURE);
//    //glActiveTexture(GL_TEXTURE1);
//    //glBindTexture(GL_TEXTURE_2D, I_TEXTURE_2);
//
//    // set the texture wrapping/filtering options (on the currently bound texture object)
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
//    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//
//    stbi_set_flip_vertically_on_load(true);
//
//    unsigned char* texdata = stbi_load(m_sTexture.c_str(), &I_WIDTH, &I_HEIGHT, &I_CHANNELS, 0);
//
//    if (texdata)
//    {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, I_WIDTH, I_HEIGHT, 0, GL_RGB, GL_UNSIGNED_BYTE, texdata);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }
//
//    /*texdata = stbi_load(m_sTextureTwo.c_str(), &I_WIDTH, &I_HEIGHT, &I_CHANNELS, 0);
//
//    if (texdata)
//    {
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, I_WIDTH, I_HEIGHT, 0, GL_RGBA, GL_UNSIGNED_BYTE, texdata);
//        glGenerateMipmap(GL_TEXTURE_2D);
//    }
//    else
//    {
//        std::cout << "Failed to load texture" << std::endl;
//    }*/
//
//
//    stbi_image_free(texdata);
//}
