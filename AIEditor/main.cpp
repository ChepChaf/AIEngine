#include "AIEngine.h"

#include <iostream>

#include <GLFW/glfw3.h>

#pragma comment(lib, "AIEngine")

int main(void)
{
    AIEngine::Application* app = new AIEngine::Application();

    app->Init();
    while (app->IsRunning())
    {
        app->Update();
    }
    
    app->Stop();
    
    delete app;

    return 0;
}