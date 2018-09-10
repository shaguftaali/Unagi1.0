#include "..\..\Includes\Geometry\Mesh.h"
#include <cassert>

namespace Geometry
{
    Mesh::Mesh():
    m_IsDirty(false),
    m_IsStatic(false)
    {
        m_NumOfVert = 0;
        m_vertexPos.clear();
        m_faces.clear();
        renderMeshData.Clear();
       
        
    }
    Mesh::Mesh(vector<Vector3> aPos, vector<vector<Index>> aFace) :
     m_IsDirty(false),
     m_IsStatic(false)
    {
    }

    Mesh::Mesh(Mesh * aMesh)
    {
    }

    Mesh::~Mesh() 
    {
    }

    void Mesh::SetPosition(vector<Vector3> a_Position)
    {
        m_NumOfVert = (uint32_t)a_Position.size();
        m_vertexPos = a_Position;
        auto i = 0;
        for (auto v=halfEdgeMesh.verticesBegin();v!=halfEdgeMesh.verticesEnd();v++,i++)
        {
            v->position = a_Position[i];
        }
        //m_I
    }

    void Mesh::SetColor(vector<Vector3> a_Color)
    {
        assert(a_Color.size() == m_NumOfVert);

        auto i = 0;

        for (auto v=halfEdgeMesh.verticesBegin();v!=halfEdgeMesh.verticesEnd();v++,i++)
        {
            v->color = a_Color[i];
        }
    }

    void Mesh::SetColor(Vector3 a_color)
    {

    }

    void Mesh::SetNormal(vector<Vector3> a_Normal)
    {
    }

    void Mesh::SetUV(vector<Vector2> a_TexCoord)
    {
    }

    bool Mesh::IsDirty() const
    {
        return m_IsDirty;
    }

  

    void Mesh::BuildHalfEdgeMesh()
    {
        halfEdgeMesh.build(m_faces, m_vertexPos);
        m_NumOfVert = (int)m_vertexPos.size();

    }

    void Mesh::SetFaceData(vector<vector<Index>> a_Face)
    {
        m_faces = std::move(a_Face);
    }

    void Mesh::UpdateRenderMeshData()
    {
        renderMeshData.Clear();
        auto vertexOffset = 0;
        for (auto &f: m_faces)
        {
            if(f.size()>=3)
            {
                for(unsigned int j=1;j<f.size()-1;j++)
                {
                    renderMeshData.m_indices.push_back(0 + vertexOffset);
                    renderMeshData.m_indices.push_back(j + vertexOffset);
                    renderMeshData.m_indices.push_back(j+1 + vertexOffset);
                }
                vertexOffset += f.size();
            }
        }

        for(auto &f:m_faces)
        {
            for (unsigned int vetexInd : f)
            {
                renderMeshData.m_VertexPos.push_back(m_vertexPos[vetexInd]);

                renderMeshData.m_VertexColor.emplace_back(0.5f, 0.5f, 0.5f);

                renderMeshData.m_VertexNormal.emplace_back(0.0f, 0.0f, 0.0f);

                renderMeshData.m_VerticesCoord.emplace_back(0.0f, 0.0f);
                //renderMeshData

                
            }
        }
    }
   
}

