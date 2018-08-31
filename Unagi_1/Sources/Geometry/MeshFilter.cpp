#include "..\..\Includes\Geometry\MeshFilter.h"

namespace Geometry
{
    MeshFilter::MeshFilter(Mesh * a_Mesh)
    {
        m_MeshPtr = a_Mesh;
        if(m_MeshPtr!=nullptr)
        {
            uint32_t vertexNumber = 0;
            InitMeshData(vertexNumber);
            SetUpGLData();
            InitIndexBuffer();
        }


    }
    MeshFilter::MeshFilter(const MeshFilter & a_MeshFilter)
    {
    }
    MeshFilter::~MeshFilter()
    {
    }
    void MeshFilter::SetVertexBufferPositionData(const int & offset, const size_t & size, const void * data) const
    {
        glBufferSubData(GL_ARRAY_BUFFER, sizeof(GLfloat)*(0 + offset)*m_MeshPtr->renderMeshData.m_VertexPos.size(), sizeof(GLfloat)*size * 3, data);
    }
    void MeshFilter::SetVertexBufferColorData(const int & offset, const size_t & size, const void * data) const
    {
        glBufferSubData(GL_ARRAY_BUFFER, sizeof(GLfloat)*(3 + offset)*m_MeshPtr->renderMeshData.m_VertexColor.size(), sizeof(GLfloat)*size * 3, data);
    }
    void MeshFilter::SetVertexBufferNormalData(const int & offset, const size_t & size, const void * data) const
    {
        glBufferSubData(GL_ARRAY_BUFFER, sizeof(GLfloat)*(3+3 + offset)*m_MeshPtr->renderMeshData.m_VertexColor.size(), sizeof(GLfloat)*size * 3, data);
    }
    void MeshFilter::SetVertexBufferUVData(const int & offset, const size_t & size, const void * data) const
    {
        glBufferSubData(GL_ARRAY_BUFFER, sizeof(GLfloat)*(3+3+3 + offset)*m_MeshPtr->renderMeshData.m_VertexColor.size(), sizeof(GLfloat)*size * 2, data);
    }
    void MeshFilter::SetUpGLData()
    {
        InitVertexArrayBuffer();
        BindVertexObject();
        
    }
    void MeshFilter::InitIndexBuffer()
    {
        BindVertexObject();
        m_IBOPtr = new IndexBuffer(m_IndicesDataPtr, m_IndexCount);
        UnBindVertexOject();
    }
    void MeshFilter::InitVertexArrayBuffer()
    {
        glGenVertexArrays(1, &m_VAO);
        glGenBuffers(1, &m_VBO);
    }
    void MeshFilter::InitMeshData(Index & numOfVert)
    {
        numOfVert = (int)m_MeshPtr->renderMeshData.m_VertexPos.size();
        vector<uint32_t> updatedIndices;
        updatedIndices = m_MeshPtr->renderMeshData.m_indices;

        m_IndexCount = (uint32_t)updatedIndices.size();
        m_IndicesDataPtr = new GLuint[m_IndexCount];

        for(uint32_t i;i<m_IndexCount;i++)
        {
            m_IndicesDataPtr[i] = updatedIndices[i];
        }
    }
    void MeshFilter::InitGLBuffer(Index & numOfVert)
    {
        if(numOfVert>0)
        {
            SetVertexBufferPositionData(0, numOfVert, &m_MeshPtr->renderMeshData.m_VertexPos[0]);
            SetVertexBufferColorData(0, numOfVert, &m_MeshPtr->renderMeshData.m_VertexColor[0]);
            SetVertexBufferNormalData(0, numOfVert, &m_MeshPtr->renderMeshData.m_VertexNormal[0]);
            SetVertexBufferUVData(0, numOfVert, &m_MeshPtr->renderMeshData.m_VerticesCoord[0]);
        }

        glVertexAttribPointer(SHADER_VERTEX_INDEX, 3, GL_FLOAT, GL_FALSE, 0, nullptr);
        glEnableVertexAttribArray(SHADER_VERTEX_INDEX);

        glVertexAttribPointer(SHADER_COLOR_INDEX, 3, GL_FLOAT, GL_FALSE, 0, (void*)(sizeof(float)*numOfVert*3));
        glEnableVertexAttribArray(SHADER_COLOR_INDEX);


        glVertexAttribPointer(SHADER_NORMAL_INDEX, 3, GL_FLOAT, GL_FALSE, 0, (void*)(sizeof(float)*numOfVert*6));
        glEnableVertexAttribArray(SHADER_NORMAL_INDEX);

        glVertexAttribPointer(SHADER_TEXCORD_INDEX, 2, GL_FLOAT, GL_FALSE,0, (void*)(sizeof(float)*numOfVert * 9));
        glEnableVertexAttribArray(SHADER_NORMAL_INDEX);



    }
    void MeshFilter::BindVertexObject() const
    {
        glBindVertexArray(m_VAO);
        glBindBuffer(m_VBO);
    }
    void MeshFilter::UnBindVertexOject() const
    {
    }
    void MeshFilter::UpdateBufferSize() const
    {
    }
    void MeshFilter::UpdateVertexBuffer() const
    {
    }
}