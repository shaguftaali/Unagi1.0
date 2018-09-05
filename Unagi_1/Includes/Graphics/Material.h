#pragma once
#include "Shader.h"
#include "../Maths/Math.h"

using namespace Maths;

namespace Garphics
{

    class  Material
    {
    public:
        Material();
        Material(const Material& mat);
        Material(Shader* a_Shader);
        ~Material();

        void        AttachShader(Shader* a_Shader);
        inline Shader*      GetShader() { return m_ShaderPtr; }

    private:
        Color       m_Ambient;
        Color       m_Diffuse;
        Color       m_Specular;
        Color       m_Emission;


        float       m_Shininess;
        Shader*     m_ShaderPtr;

    };
}
