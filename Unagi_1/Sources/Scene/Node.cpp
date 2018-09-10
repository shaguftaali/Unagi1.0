#include "..\..\Includes\Scene\Node.h"
#include "../../Includes/Graphics/Renderer.h"

using namespace Garphics;
namespace EnvironmentScene
{
    Node::Node(const char * name) :
        isPickable((true)),
        m_NodeName(name),
        m_InstanceID(uID++),
        m_Transform(Transform())
    {
        m_ParentNode = nullptr;

    }
    void Node::AddChild(std::shared_ptr<Node> a_node)
    {
        a_node->SetParent(this);
        a_node->UpdateWorldModelMatrix();
        m_ChildNodesPtr.push_back(a_node);
    }
    void Node::AttachComponent(Component * a_Component)
    {
        if(a_Component->GetComponentType()==EComponentType::RENDERER)
        {
            Renderer* renderer = GetComponent<Renderer>();
            if(renderer!=nullptr)
            {
                renderer = dynamic_cast<Renderer*>(a_Component);
            }
        }
        m_ComponentPtr.push_back(a_Component);
        a_Component->SetAttachedNode(this);
    }
    bool Node::HasComponent(EComponentType comType)
    {
        for (auto &component : m_ComponentPtr)
        {
            return component->GetComponentType() == comType;
        }
        return false;
    }
    void Node::UpdateWorldModelMatrix()
    {
        GetWorldTransform();
    }
    void Node::SetParent(Node * parentNode)
    {
        m_ParentNode = parentNode;
    }
    void Node::SetPosition(float x, float y, float z)
    {
        m_Transform.m_LocalPosition = Vector3(x, y, z);
        m_Transform.isDirty = true;
    }
    void Node::SetPosition(const Vector3& a_pos)
    {
        m_Transform.m_LocalPosition = a_pos;
        m_Transform.isDirty = true;
    }
    void Node::SetLocalScale(float x, float y, float z)
    {
        m_Transform.m_EulerAngle = Vector3(x, y, z);
        //m_Transform.m_Rotation=ToQ
    }
    void Node::SetLocalEulerAngle(float x, float y, float z)
    {
    }
    void Node::SetRotation(float angle, Vector3 axis)
    {
    }
}
