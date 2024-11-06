#pragma once

class Texture
{
public:
    unsigned int ID;
    Texture(const char* imagePath);\
    void bindTexture();
    void unbindTexture();
};
