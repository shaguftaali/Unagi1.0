#pragma once
#include <stddef.h>
#include <memory>
#include "Transform.h"


using namespace Garphics;

namespace EnvironmentScene
{

    class Node
    {
    public:
        Node(const char* name);
        Node(Transform& a_Trans, const char* name);
        Node(const Node& node);

        virtual ~Node();


        void                AddChild(std::shared_ptr<Node> _node);
        //void                AttachComponent(Garphics::Component)
    };

    typedef std::shared_ptr<Node> NodePtr;
}
