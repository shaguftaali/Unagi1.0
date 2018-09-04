#pragma once
#include "../Geometry/Mesh.h"
#include "Material.h"
#include "Component.h"
#include "../Camera/Camera.h"
#include "../Geometry/MeshFilter.h"

using namespace Unagi;
namespace Garphics
{
    enum class RenderMode
    {
        TRIANGLE,
        LINE,
        POINTS
    };

    class Renderer: public Component
    {
        Renderer(Mesh* a_Mesh, Material* a_Material);
        Renderer(const Renderer& renderer);
        ~Renderer() override;

        void            Render();
        void            SendProjectionMatrixData(const Matrix4& projectionMat);
        void            SendViewMatrixData(const Matrix4& viewMat);
        void            SendModelMatrixData(const Matrix4& modelMat);
        void            SendCameraPosData(CameraPtr cam);
        //void            SendLightData
        void            SendMaterialData();

        Material&       GetMaterial();
        Mesh*           GetMesh();
        MeshFilter*     GetMeshFilter();

        inline void     SetRenderMode(RenderMode a_Mode) { m_RenderMode = a_Mode; }
        inline void     SetMaterial(Material* a_Material) { m_Material = *a_Material; }
        void            SetMesh(Mesh* a_Mesh);

    private:
        Matrix4         GetModelMatrix() const;
        
        MeshFilter*     m_MeshFilterPtr;
        Mesh            m_Mesh;
        Material        m_Material;
        RenderMode      m_RenderMode;

    };
}
