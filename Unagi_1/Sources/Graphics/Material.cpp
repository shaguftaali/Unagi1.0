#include "..\..\Includes\Graphics\Material.h"

using namespace Maths;

namespace Garphics
{
    Material::Material():
        m_Ambient(GREEN),
        m_Diffuse(GRAY),
        m_Specular(WHITE),
        m_Emission(BLACK),
        m_Shininess(1.0)
    {
       
    }
    Material::Material(const Material & mat)
    {
        m_Ambient = mat.m_Ambient;
        m_Diffuse = mat.m_Diffuse;
        m_Specular = mat.m_Specular;
        m_Emission = mat.m_Emission;
        m_Shininess = mat.m_Shininess;
    }
    Material::Material(Shader * a_Shader):
    m_Ambient(GREEN),
    m_Diffuse(GRAY),
    m_Specular(WHITE),
    m_Emission(BLACK),
    m_Shininess(1.0)
    {
        m_ShaderPtr = a_Shader;
    }
    Material::~Material()
    {
    }
    void Garphics::Material::AttachShader(Shader * a_Shader)
    {
        m_ShaderPtr = a_Shader;
    }

}

