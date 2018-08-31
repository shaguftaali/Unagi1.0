#pragma once
#include "Mesh.h"

namespace Geometry
{
    class Box :public Mesh
    {
    public:
        Box();
        Box(Box& a_Box);
        Box(float width, float height, float depth);
        ~Box();

    private:
        float   m_width;
        float   m_height;
        float   m_Depth;

        void    InitMesh() override;
        void    InitNormals() override;
        void    InitVeritices() override;
        void    InitIndices() override;
    };
}
