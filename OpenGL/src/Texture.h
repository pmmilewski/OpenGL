#pragma once
#include <glad/glad.h>

class Texture
{
public:
    unsigned int ID;
    Texture(const char* imagePath, bool flip_vertically_on_load = false,
        int wrapS = GL_REPEAT, int wrapT = GL_REPEAT,
        int minFilter = GL_NEAREST, int magFilter = GL_LINEAR_MIPMAP_LINEAR,
        bool mipMap = true);
    void bindTexture(unsigned int textureUnit = 0) const;
    static void unbindTexture(unsigned int textureUnit = 0);
};
