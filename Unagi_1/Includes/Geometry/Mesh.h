#pragma once
#include <vector>
#include "../Maths/Vector3.h"
#include "../Maths/Vector2.h"


using namespace std;

namespace Geometry
{
    struct MeshFilter
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

    protected:
        virtual void    InitMesh();
        virtual  void   SetVeritices();
        virtual  void   SetNormals();
        virtual  void   SetIndices();


    };
}
