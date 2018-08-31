#pragma once
#include "../Maths/Vector3.h"
#include "../Maths/Matrix4.h"

namespace  Unagi
{
    class Camera
    {
    public:
        Camera();
        Camera(const Vector3& pos, const Vector3& _front, const Vector3& up);
        Camera(float camFov, float _aspestratio, float camNear, float camFar);
        Camera(Camera& cam);
        ~Camera();


    private:
        Matrix4             Prespective(float fov, float aspectRatio, float near, float far);


    };
}
