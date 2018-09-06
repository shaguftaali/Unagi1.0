#pragma once
#include "../Maths/Quaternion.h"

using namespace Maths;
namespace EnvironmentScene
{
    class Transform
    {
    public:
        Transform();
        ~Transform();

        const Matrix4& GetLocalTransformMat() const;
        const Matrix4& GetWorldTransformMat() const;

        Matrix4 Translate()

    private:
        Vector3         m_Position;
        QuaternionF     m_Rotation;
        Vector3         m_LocalPosition;
        Vector3         m_EulerAngle;
        Vector3         m_LocalScale;

        Matrix4         m_LocalTransformMat;
        Matrix4         m_WorldTransformMat;
        
        void            UpdateLocalTransformMatrix();
        friend class Node;

        //Matrix4 Translate(Ma)
    };
}
