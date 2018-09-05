#pragma once
#include "Texture.h"
#include <stddef.h>
#include <string>
#include "../Maths/Vector4.h"
#include "../Maths/Matrix4.h"
#include <vector>

using namespace std;
namespace Garphics
{
    class Uniform
    {
    public:
        string name;
        int size;
        uint32_t location;
    };

    class VertexAttribute
    {
    public:
        string name;
        int size;
        uint32_t location;
    };



    class Shader
    {
    public:
        Shader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);
        Shader(const Shader& a_Shader);
        ~Shader();


        void                ActivateShader();
        void                DeactivateShader();
        void                AddTexture(const char* texturePath, TextureType _texType);


        void                SetUniform1f(string name, float _v1);
        void                SetUniform1i(string name, int _v1);
        void                SetUniform2f(string name, float _v1, float _v2);
        void                SetUniform3f(string name, float _v1,float _v2, float _v3);
        void                SetUniform4f(string name, float _v1, float _v2, float _v3, float _v4);
        void                SetUniform4f(string name, Vector4 v4);
        void                SetUniformMat2f(string name, float* _val);
        void                SetUniformMat3f(string name, float* _val);
        void                SetUniformMat4f(string name, float* _val);
        void                SetUniform4fArray(string name, uint32_t numOfElement, float* arrayList);
        void                SetUniformMat4(const string name, const Matrix4& mat);

        uint32_t            GetShaderID() const { return shaderID; }

    private:
        uint32_t                    shaderID;
        vector<Uniform>             m_Uniforms;
        vector<VertexAttribute>     m_Attributes;

        void                        CompileShader(uint32_t shader, string type);
        Texture m_Texture[5] = {};
        
        
    };

}
