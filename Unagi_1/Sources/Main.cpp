
#include <GL/glew.h>
#include "GLFW/glfw3.h"
#include "../Includes/UI/Window.h"
#include "../Includes/EventSystem/InputSystem.h"
#include "../Includes/Geometry/Box.h"
#include "../Includes/Graphics/Shader.h"
#include "../Includes/Graphics/Material.h"
#include "../Includes/Graphics/Renderer.h"
#include "../Includes/Scene/Node.h"


using namespace UI;
using namespace InputSystem;
using namespace EnvironmentScene;
using namespace Garphics;

const uint32_t SCR_WIDTH = 800;
const uint32_t SCR_HEIGHT = 600;

void KeyBoardEventHandler(const WindowPtr window, Input& input);

int main(int argc, char* argv[])
{
    WindowPtr window(new Window(SCR_WIDTH, SCR_HEIGHT, "UNAGI"));

    CameraPtr cam(new Camera());
    cam->SetAspectRatio((float)SCR_WIDTH / (float)SCR_HEIGHT);
    cam->SetFOV(45);

    Box boxMesh;
    Shader boxShader("", "");
    Material boxMat(&boxShader);
    boxMat.SetAmbient(Vector4(.5f, 0.1f, 0.1f, 1.0f));
    
    Renderer boxRenderer(&boxMesh, &boxMat);

    NodePtr boxNodePtr(new Node("box"));
    boxNodePtr->AttachComponent(&boxRenderer);
    boxNodePtr->SetLocalScale(0.25f, 0.25f, 0.25f);
    boxNodePtr->SetPosition(0.0, 2.0, 0.0);

    Scene rootScene(cam);
    rootScene.AddToScene(boxNodePtr);

    Input input(window, &rootScene);

    while (!window->IfWindowClosed())
    {
        window->SetBGColor(0.2f, 0.3f, 0.6f, 1.0f);
        window->Update();

        KeyBoardEventHandler(window, input);

        rootScene.Render();
        window->Update();
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
