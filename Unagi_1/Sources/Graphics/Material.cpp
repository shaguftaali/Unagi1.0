#include "..\..\Includes\Graphics\Material.h"

namespace Garphics
{

    void Garphics::Material::AttachShader(Shader * a_Shader)
    {
        m_ShaderPtr = a_Shader;
    }

}

