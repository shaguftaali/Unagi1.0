#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <memory>


namespace UI
{

    class Window
    {
    public:
        Window(int width, int height, const char* name);

        ~Window();

        int         IfWindowClosed();
        void        Update();
        void        Close();
        void        SetBGColor(float r, float g, float b, float a);

    private:
        void        init();
    public:
        int             m_width;
        int             m_height;
        const char*     m_windowTitle;
        GLFWwindow*     m_windowPtr;
    };
}
typedef std::shared_ptr<UI::Window> WindowPtr;
