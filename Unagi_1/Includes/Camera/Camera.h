#pragma once
#include "../Maths/Matrix4.h"
#include "../../Includes/Maths/Vector3.h"
#include <stddef.h>
#include <memory>

namespace  Unagi
{
    class Camera
    {
    public:
        Camera();
        Camera(const Vector3& pos, const Vector3& _target, const Vector3& up);
        Camera(float camFov, float _aspestratio, float camNear, float camFar);
        Camera(Camera& cam);
        ~Camera();


        void                SetFrustrum(float camFov, float aspectRatio, float camNear, float camFar);
        void                SetPositions(const Vector3& pos, const Vector3& _target, const Vector3& up);

        inline void			SetFOV(float camFov) { m_FOV = camFov; UpdateProjectionMatrix(); }
        inline void			SetAspectRatio(float aspect) { m_AspectRatio = aspect; UpdateProjectionMatrix(); }
        inline void			SetNearPlane(float _near) { m_Near = _near; UpdateProjectionMatrix(); }
        inline void			SetFarPlane(float _far) { m_Far = _far; UpdateProjectionMatrix(); }

        inline void			SetPosition(const Vector3& pos) { m_Position = pos; UpdateViewMatrix(); }
        inline void			SetTarget(const Vector3& _target) { m_Target = _target; UpdateViewMatrix(); }
        inline void			SetUp(const Vector3& _up) { m_Up = _up; UpdateViewMatrix(); }

        inline Matrix4&	GetViewMatrix() { return m_ViewMatrix; }
        inline Matrix4&	GetProjectionMatrix() { return m_ProjectionMatrix; }
        inline Vector3&	GetCamPos() { return m_Position; }


    private:
        Matrix4             Prespective(float fov, float aspectRatio, float near, float far);
        Matrix4             LookAt(Vector3 eyePos, Vector3 target, Vector3 up);

        void                UpdateProjectionMatrix();
        void                UpdateViewMatrix();

        Vector3             m_Position;
        Vector3             m_Target;
        Vector3             m_Up;

        float               m_FOV;
        float               m_AspectRatio;
        float               m_Near;
        float               m_Far;

        Matrix4             m_ProjectionMatrix;
        Matrix4             m_ViewMatrix;



    };

    typedef std::shared_ptr<Camera> CameraPtr;
}
