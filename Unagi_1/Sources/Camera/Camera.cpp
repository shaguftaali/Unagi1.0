#include "..\..\Includes\Camera\Camera.h"

#define PI 3.14159

Matrix4 Unagi::Camera::Prespective(float fov, float aspectRatio, float near, float far)
{
    const float radian = (float)fov*PI / 180.0;
    float A = -(far + near) / (far - near);
    float B = (-2 * far*near) / (far - near);

    return Matrix4();
}
