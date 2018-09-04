#pragma once
#include "../Camera/Camera.h"
#include "Node.h"
#include <vector>

using namespace Unagi;

namespace EnvironmentScene
{
    class Scene
    {
    public:
        explicit Scene(CameraPtr cam);
        ~Scene();

        void Render();
        void AddToScene(NodePtr node);
        
    private:
        CameraPtr               m_CameraPtr;
        NodePtr                 m_AnchorPtr;
        std::vector<NodePtr>    m_RenderQueue;
        //std::vector<>
        

        void TraversAllChildNode(Node& a_Node);
        void CreateAnchor();
    };
}
