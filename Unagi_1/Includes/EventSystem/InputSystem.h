#pragma once
#include "../UI/Window.h"
#include <string>
#include "../Scene/Scene.h"
using namespace UI;
using namespace EnvironmentScene;

namespace InputSystem
{
    class Input
    {
    public:
        Input(WindowPtr WindowPtr, Scene* scene);
        ~Input();

        bool KeyPressed(std::string key);
        bool IsKeyPressed(int keyVal);
        bool keyReleased(std::string key);
        bool IsMouseButtonDown(int button);
        bool IsMouseButtonUp(int button);
        //void GetHoveredObject(const Vector2& pos, bool getElement = true, bool transformed = false);

    private:
        WindowPtr m_WindowPtr;
        Scene* mScene;
    };
}