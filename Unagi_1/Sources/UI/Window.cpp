#include <GL/glew.h>
#include "../../Includes/UI/Window.h"

//#include <GLFW/glfw3.h>




namespace UI
{
    void framebuffer_size_callback(GLFWwindow* window, int width, int height);

    UI::Window::Window(int width, int height, const char * name) :
        m_width(width),
        m_height(height),
        m_windowTitle(name),
        m_windowPtr(nullptr)
    {
       init();
    }

    UI::Window::~Window()
    {
       // glfwTerminate();
        m_windowPtr = nullptr;
    }

    int UI::Window::IfWindowClosed()
    {
        return glfwWindowShouldClose(m_windowPtr);
    }

    void UI::Window::Update()
    {
        glfwSwapBuffers(m_windowPtr);
        glfwPollEvents();
    }

    void UI::Window::Close()
    {
        glfwSetWindowShouldClose(m_windowPtr, true);
    }

    void UI::Window::SetBGColor(float r, float g, float b, float a)
    {
        glClearColor(r, g, b, a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    
    void UI::Window::init()
    {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);

        m_windowPtr = glfwCreateWindow(m_width, m_height, m_windowTitle, nullptr, nullptr);
        if (m_windowPtr == nullptr)
        {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            return;
        }
        glfwMakeContextCurrent(m_windowPtr);
        glfwSwapInterval(0);
        glfwSetFramebufferSizeCallback(m_windowPtr, framebuffer_size_callback);

        glewExperimental = GL_TRUE;
        GLenum err = glewInit();
        if(GLEW_OK!=err)
        {
            std::cout << "Error : " << glewGetErrorString(err) << std::endl;
        }
        glEnable(GL_DEPTH_TEST);
    }

    void framebuffer_size_callback(GLFWwindow * window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }

}

