#pragma once


namespace EnvironmentScene
{
    class Node;
    enum class EComponentType
    {
        MESH,
        MATERISL,
        RENDERER,
        OTHER
    };

    class Component
    {
    public:
        Component():
        m_IsEnable(true),
        m_Type(EComponentType::OTHER)
        {
            m_AttachedNodePtr = nullptr;
        }

        virtual ~Component()
        {
            m_AttachedNodePtr = nullptr;
        }

        Node*   GetAttachedNode()
        {
            return m_AttachedNodePtr;
        }

        EComponentType  GetComponentType() const
        {
            return m_Type;
        }

        void    SetAttachedNode(Node* a_Node)
        {
            m_AttachedNodePtr = a_Node;
        }

        void SetComponentType(EComponentType a_type)
        {
            m_Type = a_type;
        }

        void SetEnable(bool a_IsEnable)
        {
            m_IsEnable = a_IsEnable;
        }

        bool IsEnable()
        {
            return m_IsEnable;
        }
        
    protected:
        bool            m_IsEnable;
        Node*           m_AttachedNodePtr;
        EComponentType  m_Type;
    };
}
