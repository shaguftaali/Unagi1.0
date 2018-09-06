#include "..\..\Includes\Graphics\Material.h"

using namespace Maths;

namespace Garphics
{
    Material::Material(Shader * a_Shader):
    m_Ambient(GREEN),
    m_Diffuse(GRAY),
    m_Specular(WHITE),
    m_Emission(BLACK),
    m_Shininess(1.0)
    {
        m_ShaderPtr = a_Shader;
    }
    void Garphics::Material::AttachShader(Shader * a_Shader)
    {
        m_ShaderPtr = a_Shader;
    }

}

