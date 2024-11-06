#pragma once

class Texture
{
public:
    unsigned int ID;
    Texture(const char* imagePath, bool flip_vertically_on_load = false);
    void bindTexture(unsigned int textureUnit = 0) const;
    static void unbindTexture(unsigned int textureUnit = 0);
};
