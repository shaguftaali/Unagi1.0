#pragma once
#include "../Maths/Quaternion.h"
#include "../Maths/Vector3.h"
#include "../Maths/Matrix4.h"


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

        Matrix4 Translate(Matrix4& mat, float _x, float _y, float _z);
        Matrix4 Rotate(Matrix4& mat, float angleInDeg, const Vector3& axis);
        Matrix4 Scale(Matrix4& mat, float sx, float sy, float sz);

        bool isDirty;

    private:
        Vector3         m_Position;
    //    QuaternionF     m_Rotation;
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
