#pragma once
#include <stddef.h>
#include <memory>
#include "Transform.h"
#include "../Scene/Component.h"
#include <string>
#include <vector>
#include "../Maths/Vector3.h"
#include "../Geometry/Mesh.h"


namespace EnvironmentScene
{

    class Node
    {
    public:
        Node(const char* name);
       // Node(Transform& a_Trans, const char* name);
       // Node(const Node& node);

        virtual ~Node();


        void                     AddChild(std::shared_ptr<Node> _node);
        void                     AttachComponent(Component* a_Component);
        bool                     HasComponent(EComponentType comType);
        void                     UpdateWorldModelMatrix();

        void                     SetParent(Node* parentNode);
        void                     SetPosition(float x, float y, float z);
        void                     SetPosition(Vector3 a_pos);
        void                     SetLocalScale(float x, float y, float z);
        void                     SetLocalEulerAngle(float x, float y, float z);
        void                     SetRotation(float angle, Vector3 axis);
        inline  void             SetName(const char* name) { m_NodeName = name; }

        Node*                    GetParent();
        uint32_t                 GetNumberOfChilds();
        std::shared_ptr<Node>    GetChildNodeAt(uint32_t index);
        const Transform&         GetWorldTransform();
        Mesh*                    GetMesh();

        inline Transform&       GetTransformComponent() { return m_Transform; }
        inline int              GetInstanceID();
        inline string           GetName() { return m_NodeName; }

        //void                    


        template <typename T>
        T* GetComponent()
        {
            for (auto m_Component :m_Component )
            {
                if(dynamic_cast<T*>(m_Component))
                {
                    return (T*)m_Component;
                }
            }
            return nullptr;
        }

    protected:
        Transform           m_Transform;

    private:

        std::string         m_NodeName;
        const int           m_InstanceID;

        std::vector<std::shared_ptr<Node>>      m_ChildNodesPtr;
        std::vector<Component*>                  m_ComponentPtr;
        Node*                                   m_ParentNode;

       
      
    public:
        static  int uID;
        bool                isPickable;
    };

    typedef std::shared_ptr<Node> NodePtr;
    
   
}
