#include "../../Includes/Graphics/Shader.h"
#include <vector>
#include <cassert>
#include <fstream>
#include <sstream>
#include <iostream>

namespace Garphics
{
    // Helper Function
    int GetUniformLocation(const std::string &name, vector<Uniform> uniformList);


    Shader::Shader(const char * vertexPath, const char * fragmentPath, const char * geometryPath)
    {
        string vertexCode;
        string fragmentCode;
        string geometryCode;

        ifstream vShaderFile;
        ifstream fShaderFile;
        ifstream gShaderFile;

        vShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
        fShaderFile.exceptions(ifstream::failbit | ifstream::badbit);
        gShaderFile.exceptions(ifstream::failbit | ifstream::badbit);

        try
        {
            vShaderFile.open(vertexPath);
            fShaderFile.open(fragmentPath);

            stringstream vShaderStream, fShaderStream;
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();

            vShaderFile.close();
            fShaderFile.close();

            vertexCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();

            if(geometryPath!=nullptr)
            {
                gShaderFile.open(geometryPath);
                stringstream gShaderStream;
                gShaderStream << gShaderFile.rdbuf();
                gShaderFile.close();
                geometryCode = gShaderStream.str();
            }

        }
        catch(ifstream::failure e)
        {
            cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << endl;
        }

        const char* vShaderCode = vertexCode.c_str();
        const char* fShaderCode = fragmentCode.c_str();

        uint32_t vertex, fragment;

        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertex, 1, &vShaderCode, nullptr);
        glCompileShader(vertex);
        CompileShader(shaderID, "VERTEX");

        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragment, 1, &fShaderCode, nullptr);
        CompileShader(fragment, "FRAGMENT");

        uint32_t geometry;
        if(geometryPath!=nullptr)
        {
            const char* gShaderCode = geometryCode.c_str();
            geometry = glCreateShader(GL_GEOMETRY_SHADER);
            glShaderSource(geometry, 1, &gShaderCode, nullptr);
            glCompileShader(geometry);
            CompileShader(geometry, "GEOMETRY");
        }

        shaderID = glCreateProgram();
        glAttachShader(shaderID, vertex);
        glAttachShader(shaderID, fragment);
        if(geometryPath!=nullptr)
        {
            glAttachShader(shaderID, geometry);
        }
            
        glLinkProgram(shaderID);
        CompileShader(shaderID,"PROGRAM");


        glDeleteShader(vertex);
        glDeleteShader(fragment);
        if(geometryPath!=nullptr)
        {
            glDeleteShader(geometry);
        }

        int nAttributes, nUniforms;
        glGetProgramiv(shaderID, GL_ACTIVE_ATTRIBUTES, &nAttributes);
        glGetProgramiv(shaderID, GL_ACTIVE_UNIFORMS, &nUniforms);
        m_Attributes.resize(nAttributes);
        m_Uniforms.resize(nUniforms);

        char buffer[128];
        for (int i=0;i<nAttributes;i++)
        {
            GLenum glType;
            glGetActiveAttrib(shaderID, i, sizeof(buffer), 0, &m_Attributes[i].size, &glType, buffer);
            m_Attributes[i].name = string(buffer);
            m_Attributes[i].location = glGetAttribLocation(shaderID, buffer);
        }

        for (int i = 0; i < nUniforms; ++i)
        {
            GLenum glType;
            glGetActiveUniform(shaderID, i, sizeof(buffer), 0, &m_Uniforms[i].size, &glType, buffer);
            m_Uniforms[i].n = std::string(buffer);
            // TODO think of clean way to manage type conversions of OpenGL and custom type
            // TODO This method will not get the name for uniform location if its a struct or array.
            //m_Uniforms[i].Type = SHADER_TYPE_BOOL;

            m_Uniforms[i].location = glGetUniformLocation(shaderID, buffer);
        }
    }
    Shader::Shader(const Shader & a_Shader)
    {
    }
    Shader::~Shader()
    {
    }
    void Shader::ActivateShader()
    {
        glUseProgram(shaderID);

        for (int i=0;i<sizeof(m_Texture)/sizeof(m_Texture[0]);i++)
        {
            glActiveTexture(GL_TEXTURE0 + i);
            glBindTexture(GL_TEXTURE_2D, m_Texture[i].textureID);
        }
    }
    void Shader::DeactivateShader()
    {
        glUseProgram(0);
    }
    void Shader::AddTexture(const char * texturePath, TextureType _texType)
    {
    }
    void Shader::SetUniform1f(string name, float _v1)
    {
    }
    void Shader::SetUniform1i(string name, int _v1)
    {
    }
    void Shader::SetUniform2f(string name, float _v1, float _v2)
    {
    }
    void Shader::SetUniform3f(string name, float _v1, float _v2, float _v3)
    {
    }
    void Shader::SetUniform4f(string name, float _v1, float _v2, float _v3, float _v4)
    {
    }
    void Shader::SetUniform4f(string name, Vector4 v4)
    {
    }
    void Shader::SetUniformMat2f(string name, float * _val)
    {
    }
    void Shader::SetUniformMat3f(string name, float * _val)
    {
    }
    void Shader::SetUniformMat4f(string name, float * _val)
    {
    }
    void Shader::SetUniform4fArray(string name, uint32_t numOfElement, float * arrayList)
    {
    }
    void Shader::SetUniformMat4(const string name, const Matrix4 & mat)
    {
        glUniformMatrix4fv(glGetUniformLocation(shaderID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
    }
    void Shader::CompileShader(uint32_t shader, string type)
    {
        int success;
        char infoLog[1024];
        if(type!="PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if(!success)
            {
                glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
                
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if(!success)
            {
                glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
                std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
            }
        }
    }
    
}
