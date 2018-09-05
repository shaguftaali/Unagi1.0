#pragma once

#include <GL/glew.h>


#include "Mesh.h"
#include "IndexBuffer.h"

namespace Geometry
{

#define SHADER_VERTEX_INDEX     0
#define SHADER_COLOR_INDEX      1
#define SHADER_NORMAL_INDEX     2
#define SHADER_TEXCORD_INDEX    3
//#define RENDE

    class MeshFilter
    {
    public:
        explicit MeshFilter(Mesh* a_Mesh);
        MeshFilter(const MeshFilter& a_MeshFilter);
        ~MeshFilter();


        inline GLuint&          GetVAO() { return  m_VAO; }
        inline IndexBuffer*     GetIBO() { return m_IBOPtr; }
        inline Index            GetIndexCount() const { return m_IndexCount; }
        inline Mesh*            GetMesh() const { return m_MeshPtr; }


        void                    SetVertexBufferPositionData(const int& offset, const size_t& size, const void* data) const;
        void                    SetVertexBufferColorData(const int& offset, const size_t& size, const void* data) const;
        void                    SetVertexBufferNormalData(const int& offset, const size_t& size, const void* data) const;
        void                    SetVertexBufferUVData(const int& offset, const size_t& size, const void* data) const;

        void                    AttachMesh(Mesh* a_Mesh);

    private:
        GLuint                  m_VAO;
        GLuint                  m_VBO;
        Index                   m_IndexCount;

        Mesh*                   m_MeshPtr;
        GLuint*                 m_IndicesDataPtr;
        IndexBuffer*             m_IBOPtr;

        void                    SetUpGLData();
        void                    InitIndexBuffer();
        void                    InitVertexArrayBuffer();
        void                    InitMeshData(Index& numOfVert);
        void                    InitGLBuffer(Index& numOfVert);

    public:
        void                    BindVertexObject() const;
        void                    UnBindVertexOject() const;
        void                    UpdateBufferSize()  const;
        void                    UpdateVertexBuffer() const;

    };
}
