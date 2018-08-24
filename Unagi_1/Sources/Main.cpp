

#include "../Includes/UI/Window.h"
#include "../Includes/EventSystem/InputSystem.h"

using namespace UI;
using namespace InputSystem;
using namespace EnvironmentScene;

const uint32_t SCR_WIDTH = 800;
const uint32_t SCR_HEIGHT = 600;

void KeyBoardEventHandler(const WindowPtr window, Input& input);

int main(int argc, char* argv[])
{
    WindowPtr window(new Window(SCR_WIDTH, SCR_HEIGHT, "UNAGI"));

    Scene rootScene;

    Input input(window, &rootScene);

    while (!window->IfWindowClosed())
    {
        window->SetBGColor(0.2f, 0.3f, 0.6f, 1.0f);
        window->Update();

        KeyBoardEventHandler(window, input);
    }

    return 0;
}

void KeyBoardEventHandler(const WindowPtr window, Input& input)
{
    if(input.IsKeyPressed(GLFW_KEY_ESCAPE))
    {
        window->Close();
    }


}
