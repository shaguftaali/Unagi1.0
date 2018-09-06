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
        m_Material.GetShader()->ActivateShader();
        m_MeshFilterPtr->BindVertexObject();
        m_MeshFilterPtr->GetIBO()->Bind();
        m_MeshFilterPtr->UpdateVertexBuffer();

        if(m_RenderMode==RenderMode::LINE)
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        }
        else if (m_RenderMode==RenderMode::POINTS)
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
        }
        else
        {
            glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        }
        
        glDrawElements(GL_TRIANGLES, m_MeshFilterPtr->GetIndexCount(), GL_UNSIGNED_INT, nullptr);
        m_MeshFilterPtr->UnBindVertexOject();
        m_MeshFilterPtr->GetIBO()->Unbind();
        m_Material.GetShader()->DeactivateShader();
    }
    void Renderer::SendProjectionMatrixData(const Matrix4 & projectionMat)
    {
        //m_Material.GetShader()->SetUniform4f("projection", const_cast<float*>(projectionMat.elements));
        m_Material.GetShader()->SetUniformMat4("projection", projectionMat);
    }
    void Renderer::SendViewMatrixData(const Matrix4 & viewMat)
    {
        m_Material.GetShader()->SetUniformMat4("view", viewMat);
    }
    void Renderer::SendModelMatrixData(const Matrix4 & modelMat)
    {
        m_Material.GetShader()->SetUniformMat4("model", modelMat);
    }
    void Renderer::SendCameraPosData(CameraPtr cam)
    {
        auto camPos = cam->GetCamPos();
        m_Material.GetShader()->SetUniform3f("viewPos", camPos.x, camPos.y, camPos.z);
    }
    void Renderer::SendMaterialData()
    {
        m_Material.GetShader()->SetUniform4f("material.ambient", m_Material.m_Ambient);
        m_Material.GetShader()->SetUniform4f("material.diffuse", m_Material.m_Diffuse);
        m_Material.GetShader()->SetUniform4f("material.specular", m_Material.m_Specular);
        m_Material.GetShader()->SetUniform4f("material.emission", m_Material.m_Emission);
        m_Material.GetShader()->SetUniform1f("material.shininess", m_Material.m_Shininess);
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
            m_MeshFilterPtr->AttachMesh(a_Mesh);
        }
    }
    Matrix4 Renderer::GetModelMatrix() const
    {
        return Matrix4();
    }
}