#include "..\..\Includes\Scene\Transform.h"
#include "../../Includes/Maths/Math.h"
#include <cmath>


namespace EnvironmentScene
{
    Transform::Transform():
    m_Position(Vector3(0,0,0)),
    m_LocalPosition(Vector3(0,0,0)),
  //  m_Rotation(Quaternion()),
    m_LocalScale(Vector3(1,1,1)),
    isDirty(false)
    {
        UpdateLocalTransformMatrix();
    }
    Transform::~Transform() = default;
    
    
    const Matrix4 & Transform::GetLocalTransformMat() const
    {
        return  m_LocalTransformMat;
    }
    const Matrix4 & Transform::GetWorldTransformMat() const
    {
        return m_WorldTransformMat;
    }
    Matrix4 Transform::Translate(Matrix4 & mat, float _x, float _y, float _z)
    {
        Matrix4 tansMat(
           Vector4( 1, 0, 0,_x),
           Vector4(0, 1, 0, _y),
           Vector4( 0, 0, 1,_z),
           Vector4(0, 0, 0, 1)
        );
        mat = tansMat * mat;
        return mat;
    }
    Matrix4 Transform::Rotate(Matrix4 & mat, float angleInDeg, const Vector3 & axis)
    {
        const auto radian = Maths::ToRadian(angleInDeg);

        auto c = cos(radian);
        auto s = sin(radian);
        auto v = 1 - c;

        return Matrix4();
    }
    Matrix4 Transform::Scale(Matrix4 & mat, float sx, float sy, float sz)
    {
        return Matrix4();
    }
    void Transform::UpdateLocalTransformMatrix()
    {
    }
}
