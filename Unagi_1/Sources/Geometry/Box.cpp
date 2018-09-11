#include "..\..\Includes\Geometry\Box.h"

Geometry::Box::Box():
Mesh(),
m_width(1.0f),
m_height(1.0f),
m_Depth(1.0f)
{
    Box::InitMesh();
    BuildHalfEdgeMesh();
   // UpdateRenderMeshData();
}

Geometry::Box::Box(Box & a_Box):
Mesh(),
m_width(a_Box.m_width),
m_height(a_Box.m_height),
m_Depth(a_Box.m_Depth)
{
   Box::InitMesh();
   // BuildHalfEdgeMesh();
  //  UpdateRenderMeshData();
}

Geometry::Box::Box(float width, float height, float depth):
m_width(width),
m_height(height),
m_Depth(depth)
{
   Box::InitMesh();
    BuildHalfEdgeMesh();
    UpdateRenderMeshData();
}

Geometry::Box::~Box()
{
}

void Geometry::Box::InitMesh()
{
    InitVeritices();
    InitIndices();
    InitNormals();
    SetColor(Vector3(0.5, 0.5, 0.5));
}

void Geometry::Box::InitNormals()
{
    vector<Vector3> vertNom{
        //right
        Vector3(1, 0, 0),  Vector3(1, 0, 0), Vector3(1, 0, 0),
        Vector3(1, 0, 0),  Vector3(1, 0, 0),  Vector3(1,0, 0),

        //front
        Vector3(0, 0,-1),  Vector3(0, 0,-1),  Vector3(0, 0,-1),
        Vector3(0, 0,-1),  Vector3(0, 0,-1),  Vector3(0, 0,-1),

        //left
        Vector3(-1, 0, 0),  Vector3(-1, 0, 0),  Vector3(-1, 0, 0),
        Vector3(-1, 0, 0),  Vector3(-1, 0, 0),  Vector3(-1, 0, 0),

        //bottom
        Vector3( 0, 1, 0),  Vector3( 0, 1, 0),  Vector3( 0, 1, 0),
        Vector3( 0, 1, 0),  Vector3( 0, 1, 0),  Vector3( 0, 1, 0),


        //top
        Vector3(0,-1, 0),  Vector3(0,-1, 0),  Vector3(0,-1, 0),
        Vector3(0,-1, 0),  Vector3(0,-1, 0),  Vector3(0,-1, 0),


        //back
        Vector3(0, 0, 1),  Vector3(0, 0, 1),  Vector3(0, 0, 1),
        Vector3(0, 0, 1),  Vector3(0, 0, 1),  Vector3(0, 0, 1),
    };
    renderMeshData.m_VertexNormal = vertNom;
   // SetNormal(vertNom);
}

void Geometry::Box::InitVeritices()
{
    float X = m_width / 2.0;
    float Y = m_height / 2.0f;
    float Z = m_Depth / 2.0f;
    //std::vector<Vector3> vecPos{
    //    //right
    //    Vector3( X, Y,-Z), Vector3( X, Y, Z), Vector3( X,-Y, Z),
    //    Vector3( X,-Y, Z), Vector3( X,-Y,-Z), Vector3( X, Y,-Z),

    //    //front
    //    Vector3( X, Y,-Z), Vector3( X,-Y,-Z), Vector3(-X,-Y,-Z),
    //    Vector3(-X,-Y,-Z), Vector3(-X, Y,-Z), Vector3( X, Y,-Z),

    //    //left
    //    Vector3(-X, Y,-Z), Vector3(-X,-Y,-Z), Vector3(-X,-Y, Z),
    //    Vector3(-X,-Y, Z), Vector3(-X, Y, Z), Vector3(-X, Y,-Z),

    //    //bottom
    //    Vector3(-X, Y, Z), Vector3( X, Y, Z), Vector3( X, Y,-Z),
    //    Vector3( X, Y,-Z), Vector3(-X, Y,-Z), Vector3(-X, Y, Z),

    //    //top
    //    Vector3( X,-Y, Z), Vector3(-X,-Y, Z), Vector3(-X,-Y,-Z),
    //    Vector3(-X,-Y,-Z), Vector3( X,-Y,-Z), Vector3( X,-Y, Z),


    //    //back
    //    Vector3(-X, Y, Z), Vector3(-X,-Y, Z), Vector3( X,-Y, Z),
    //    Vector3( X,-Y, Z), Vector3( X, Y, Z), Vector3(-X, Y, Z),

    //};

    std::vector<Vector3> vecPos{
       Vector3(-X,  Y, -Z),
       Vector3(-X, -Y, -Z),
       Vector3(X, -Y, -Z),
       Vector3(X,  Y, -Z),
       
       Vector3(-X,  Y,  Z),
       Vector3(-X, -Y,  Z),
       Vector3(X, -Y,  Z),
       Vector3(X,  Y,  Z)
    };
    m_vertexPos = vecPos;
   // SetPosition(vecPos);
   
   
}

void Geometry::Box::InitIndices()
{
    //vector<vector<Index>> verIndices{
    //    //right
    //    {0,1,2,2,3,0},

    //    //front
    //    {0,3,4,4,5,0},

    //    //left
    //    {5,4,7,7,6,5},

    //    //bottom
    //    {6,1,0,0,5,6},

    //    //top
    //    {2,7,4,4,3,2},

    //    //back
    //    {6,7,2,2,1,6}
    //};

    std::vector<std::vector<uint32_t > >verIndices{
        { 0,   3,  2,  1 },
    { 4,   5,  6,  7 },
    { 4,   0,  1,  5 },
    { 3,   7,  6,  2 },
    { 0,   4,  7,  3 },
    { 5,   1,  2,  6 }
    };

    m_faces = verIndices;
    //SetFaceData(verIndices);
}
