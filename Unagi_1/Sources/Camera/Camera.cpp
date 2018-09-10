#include "..\..\Includes\Camera\Camera.h"
#include <math.h>

#define PI 3.14159

Unagi::Camera::Camera()
{
    m_FOV = 60.0;
    m_AspectRatio = (float)800 / 600;
    m_Near = 0.01;
    m_Far = 100.0f;
    m_Position = Vector3(0, 0, -1.0f);
    m_Target = Vector3(0, 0, 3.0f);
    m_Up = Vector3(0, 1, 0);

}

Unagi::Camera::Camera(const Vector3 & pos, const Vector3 & _target, const Vector3 & up)
{
    m_FOV = 60.0;
    m_AspectRatio = (float)800 / 600;
    m_Near = 0.01;
    m_Far = 100.0f;
    m_Position = pos;
    m_Target = _target;
    m_Up = up;
}

Unagi::Camera::Camera(float camFov, float _aspectratio, float camNear, float camFar)
{
    m_FOV = camFov;
    m_AspectRatio = _aspectratio;
    m_Near = camNear;
    m_Far = camFar;
    m_Position = Vector3(0, 0, -1.0f);
    m_Target = Vector3(0, 0, 3.0f);
    m_Up = Vector3(0, 1, 0);
}

Unagi::Camera::~Camera()
{
}

void Unagi::Camera::SetFrustrum(float camFov, float aspectRatio, float camNear, float camFar)
{
    m_FOV = camFov;
    m_AspectRatio = aspectRatio;
    m_Near = camNear;
    m_Far = camFar;
}

void Unagi::Camera::SetPositions(const Vector3 & pos, const Vector3 & _target, const Vector3 & up)
{
    m_Position = pos;
    m_Target = _target;
    m_Up = up;
}

Matrix4 Unagi::Camera::Prespective(float fov, float aspectRatio, float near, float far)
{
    const float radian = (float)fov*PI / 180.0;
    float A = -(far + near) / (far - near);
    float B = (-2 * far*near) / (far - near);
    Matrix4 projectionMat = Matrix4(
        Vector4(1 /(m_AspectRatio* tanf(radian / 2)), 0, 0, 0),
        Vector4(0, 1 / tanf(radian / 2), 0, 0),
        Vector4(0, 0, A, -1),
        Vector4(0, 0, B, 0)
    );
    return projectionMat;
}

//reference Look At Camera  https://www.3dgep.com/understanding-the-view-matrix/#Look_At_Camera
Matrix4 Unagi::Camera::LookAt(Vector3 eyePos, Vector3 target, Vector3 up)
{
    Vector3 eyeDirection = (target - eyePos).Normalization();

    Vector3 xAxis = Vector3::CrossProduct(eyeDirection, up).Normalization();
    Vector3 yAxis = Vector3::CrossProduct(xAxis, eyeDirection).Normalization();

    float ex = -Vector3::DotProduct(xAxis, eyePos);
    float ey = -Vector3::DotProduct(yAxis, eyePos);
    float ez = Vector3::DotProduct(eyeDirection, eyePos);

    Matrix4 viewMat = {

        Vector4(xAxis.x,        xAxis.y,        xAxis.z,0),
        Vector4(yAxis.x,        yAxis.y,        yAxis.z,0),
        Vector4(-eyeDirection.x,-eyeDirection.y,-eyeDirection.z,0),
        Vector4(ex,             ey,             ez,1)
    };


    return viewMat;
}

void Unagi::Camera::UpdateProjectionMatrix()
{
    m_ProjectionMatrix = Prespective(m_FOV, m_AspectRatio, m_Near, m_Far);
}

void Unagi::Camera::UpdateViewMatrix()
{
    m_ViewMatrix = LookAt(m_Position, m_Target, m_Up);
}
