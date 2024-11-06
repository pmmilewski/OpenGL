#include "Texture.h"

#include <iostream>
#include <ostream>
#include "stb_image.h"

Texture::Texture(const char* imagePath, bool flip_vertically_on_load,
    int wrapS, int wrapT,
    int minFilter, int magFilter,
    bool mipMap)
{
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapS);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, minFilter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, magFilter);

    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(flip_vertically_on_load);
    unsigned char *data = stbi_load(imagePath, &width, &height, &nrChannels, 0);
    if (data)
    {
        int format = nrChannels == 3 ? GL_RGB : nrChannels == 4 ? GL_RGBA : -1;
        if (format == -1)
        {
            std::cout << "Not supported image format: " << imagePath << '\n';
            
        }
        else
        {
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
            if (mipMap)
            {
                glGenerateMipmap(GL_TEXTURE_2D);
            }
        }
    }
    else
    {
        std::cout << "Failed to load texture: " << imagePath << '\n';
    }

    stbi_image_free(data);
    glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::bindTexture(unsigned int textureUnit) const
{
    glActiveTexture(GL_TEXTURE0 + textureUnit);
    glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::unbindTexture(unsigned int textureUnit)
{
    glActiveTexture(GL_TEXTURE0 + textureUnit);
    glBindTexture(GL_TEXTURE_2D, 0);
}
