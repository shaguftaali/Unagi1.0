#pragma once
#include <GL/glew.h>

namespace Garphics
{
    enum class TextureType
    {
        DIFFUSE = 0,
        SPECULAR,
        NORMAL,
        BUMP,
        REFLECTION

    };

    class Texture
    {
    public:
        Texture();
        ~Texture();

        void        LoadTexture(const char* texturePath);
        friend class Shader;

    private:
        GLuint     textureID;
    };
}
