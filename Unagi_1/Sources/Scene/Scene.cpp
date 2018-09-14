
#include "../../Includes/Scene/Scene.h"
#include "../../Includes/Graphics/Renderer.h"

using namespace Garphics;

namespace EnvironmentScene
{
  
    Scene::Scene(CameraPtr cam):
        m_AnchorPtr(new Node("Anchor"))
    {
        m_CameraPtr = cam;
    }
    Scene::~Scene()
    {
    }
    void Scene::Render()
    {
        for (auto &node:m_RenderQueue)
        {
            node->UpdateWorldModelMatrix();
        }

        for (auto &node : m_RenderQueue)
        {
            if(node->HasComponent(EComponentType::RENDERER))
            {
                Renderer* renderer = node->GetComponent<Renderer>();
                if(renderer!=nullptr)
                {
               //     renderer->SendViewMatrixData(m_CameraPtr->GetViewMatrix());
                //    renderer->SendProjectionMatrixData(m_CameraPtr->GetProjectionMatrix());
                //    renderer->SendModelMatrixData(node->GetTransformComponent().GetWorldTransformMat());

               //     renderer->SendMaterialData();
                    renderer->Render();

                }
            }
        }
    }
    void Scene::AddToScene(NodePtr node)
    {
        m_RenderQueue.push_back(node);

    }
    void Scene::TraversAllChildNode(Node & a_Node)
    {
    }
    void Scene::CreateAnchor()
    {
    }
}
