#include "..\..\Includes\Graphics\Renderer.h"
namespace Garphics
{
    Renderer::Renderer(Mesh* a_Mesh, Material* a_Material):
    Component(),
    m_Mesh(a_Mesh)
    {
        m_Type = EComponentType::RENDERER;
        m_MeshFilterPtr = new MeshFilter(a_Mesh);
        m_Material = *a_Material;

    }

    Renderer::Renderer(const Renderer& renderer):
    Component(),
    m_Mesh(renderer.m_Mesh)
    {
        m_Type = renderer.m_Type;
        m_MeshFilterPtr = renderer.m_MeshFilterPtr;
        m_Material = renderer.m_Material;
    }

    Renderer::~Renderer()
    {
        delete m_MeshFilterPtr;
        m_MeshFilterPtr = nullptr;
    }

    void Renderer::Render()
    {
    }
    void Renderer::SendProjectionMatrixData(const Matrix4 & projectionMat)
    {
    }
    void Renderer::SendViewMatrixData(const Matrix4 & viewMat)
    {
    }
    void Renderer::SendModelMatrixData(const Matrix4 & modelMat)
    {
    }
    void Renderer::SendCameraPosData(CameraPtr cam)
    {
    }
    void Renderer::SendMaterialData()
    {
    }
    Material & Renderer::GetMaterial()
    {
        // TODO: insert return statement here
    }
    Mesh * Renderer::GetMesh()
    {
        return nullptr;
    }
    MeshFilter * Renderer::GetMeshFilter()
    {
        return nullptr;
    }
    void Renderer::SetMesh(Mesh * a_Mesh)
    {
        m_Mesh = *a_Mesh;
        if(m_MeshFilterPtr!=nullptr)
        {
            m_MeshFilterPtr->Att
        }
    }
    Matrix4 Renderer::GetModelMatrix() const
    {
        return Matrix4();
    }
}