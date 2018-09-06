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

        inline void			SetAmbient(const Color &col) { m_Ambient = col; }
        inline void			SetDiffuse(const Color &col) { m_Diffuse = col; }
        inline void			SetSpecular(const Color &col) { m_Specular = col; }
        inline void			SetEmission(const Color &col) { m_Emission = col; }
        inline void			SetShininess(float shine) { m_Shininess = shine; }

        void        AttachShader(Shader* a_Shader);
        inline Shader*      GetShader() { return m_ShaderPtr; }
        friend  class  Renderer;
    private:
        Color       m_Ambient;
        Color       m_Diffuse;
        Color       m_Specular;
        Color       m_Emission;


        float       m_Shininess;
        Shader*     m_ShaderPtr;

    };
}
