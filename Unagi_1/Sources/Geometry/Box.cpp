#include "..\..\Includes\Geometry\Box.h"

Geometry::Box::Box():
Mesh(),
m_width(1.0f),
m_height(1.0f),
m_Depth(1.0f)
{
    InitMesh();
}

Geometry::Box::Box(Box & a_Box):
Mesh(),
m_width(a_Box.m_width),
m_height(a_Box.m_height),
m_Depth(a_Box.m_Depth)
{
    InitMesh();
}

Geometry::Box::Box(float width, float height, float depth):
m_width(width),
m_height(height),
m_Depth(depth)
{
    InitMesh();
}

Geometry::Box::~Box()
{
}

void Geometry::Box::InitMesh()
{
    SetVeritices();
    SetIndices();
}

void Geometry::Box::SetNormals()
{
   


}

void Geometry::Box::SetVeritices()
{
    float X = m_width / 2.0;
    float Y = m_height / 2.0f;
    float Z = m_Depth / 2.0f;
    std::vector<Vector3> vecPos{
        Vector3(X, Y,-Z),   //0
        Vector3(X, Y, Z),   //1
        Vector3(X,-Y, Z),   //2
        Vector3(X,-Y,-Z),   //3
        Vector3(-X,-Y,-Z),  //4
        Vector3(-X, Y,-Z),  //5
        Vector3(-X, Y, Z),  //6
        Vector3(-X,-Y, Z)   //7

    };
}

void Geometry::Box::SetIndices()
{
    std::vector<uint32_t> verIndices{
        0,1,2,
        0,1,3,

        5,0,3,
        5,3,4,

        5,4,6,
        4,7,6,

        1,6,7,
        6,7,1,

        4,7,2,
        7,2,3

    };
}
