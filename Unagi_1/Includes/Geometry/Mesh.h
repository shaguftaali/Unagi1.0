#pragma once
#include <vector>
#include "../Maths/Vector3.h"
#include "../Maths/Vector2.h"
#include "HalfEdgeMesh.h"


using namespace std;

namespace Geometry
{
    struct RendererMeshData
    {
        std::vector<Vector3>     m_VertexPos;
        std::vector<Vector3>     m_VertexNormal;
        std::vector<uint32_t>    m_indices;
        std::vector<Vector3>     m_VertexColor;
        std::vector<Vector2>     m_VerticesCoord;


        void Clear()
        {
            m_VertexPos.clear();
            m_VertexNormal.clear();
            m_indices.clear();
            m_VertexColor.clear();
            m_VerticesCoord.clear();
        }
    };

    typedef uint32_t Index;

    class Mesh
    {
    public:
        Mesh();
        Mesh(vector<Vector3>aPos, vector<vector<Index>>aFace);
        explicit Mesh(Mesh* aMesh);
        ~Mesh();

        void            SetPosition(Index at, const Vector3& a_Position);
        void            SetColor(Index at, const Vector3& a_Color);
        void            SetNormal(Index at, const Vector3& a_Normal);
        void            SetUV(Index at, const Vector2& a_TexCoord);


        void            SetPosition(vector<Vector3> a_Position);
        void            SetColor(vector<Vector3> a_Color);
        void            SetColor(Vector3 a_color);
        void            SetNormal(vector<Vector3> a_Normal);
        void            SetUV(vector<Vector2> a_TexCoord);


        bool            IsDirty() const;


        void            BuildHalfEdgeMesh();
        void            SetFaceData(vector<vector<Index>> a_Face);
                   

    protected:
        bool            m_IsDirty;

        virtual void    InitMesh();
        virtual  void   InitVeritices();
        virtual  void   InitNormals();
        virtual  void   InitIndices();

    public:

        bool m_IsDirty;
        bool m_IsStatic;


        Index                   m_NumOfVert;

        vector<Vector3>         m_vertexPos;
        vector<vector<Index>>   m_faces;


        RendererMeshData        renderMeshData;
        HalfEdgeMesh            halfEdgeMesh;


        void    UpdateRenderMeshData();

    };
}
