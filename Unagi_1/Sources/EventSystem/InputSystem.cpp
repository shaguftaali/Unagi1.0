#include "..\..\Includes\EventSystem\InputSystem.h"
#include "../../Includes/Maths/Vector2.h"


namespace InputSystem
{

    Vector2 mousePos;
    void mouse_cursor_callback(GLFWwindow* window, double xPos, double yPos);
    void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);

    Input::Input(WindowPtr WindowPtr, Scene * scene):
    m_WindowPtr(WindowPtr),
    mScene(scene)
    {
        glfwSetCursorPosCallback(m_WindowPtr->m_windowPtr, mouse_cursor_callback);
        glfwSetInputMode(m_WindowPtr->m_windowPtr, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
    }

    Input::~Input()
    {
    }


    bool Input::KeyPressed(std::string key)
    {
        const char c = *key.c_str();
        int keyVal = int(c);
        return glfwGetKey(m_WindowPtr->m_windowPtr,keyVal)==GLFW_PRESS;
    }
    bool Input::IsKeyPressed(int keyVal)
    {
        return glfwGetKey(m_WindowPtr->m_windowPtr,keyVal)==GLFW_PRESS;
    }
    bool Input::keyReleased(std::string key)
    {
        return !KeyPressed(key);
    }
    bool Input::IsMouseButtonDown(int button)
    {
        return (glfwGetMouseButton(m_WindowPtr->m_windowPtr,button)==GLFW_PRESS);
    }
    bool Input::IsMouseButtonUp(int button)
    {
        return glfwGetMouseButton(m_WindowPtr->m_windowPtr,button)==GLFW_RELEASE;
    }
    void mouse_cursor_callback(GLFWwindow * window, double xPos, double yPos)
    {
        double m_xPos;
        double m_yPos;
        glfwGetCursorPos(window, &m_xPos, &m_yPos);
       /* std::cout << "x " << xPos << " y " << yPos << std::endl;*/
        std::cout << "x " << m_xPos << " y " << m_yPos << std::endl;
        mousePos.x = static_cast<float>(xPos);
        mousePos.y = static_cast<float>(yPos);
    }
    void mouse_button_callback(GLFWwindow * window, int button, int action, int mods)
    {
    }
}
