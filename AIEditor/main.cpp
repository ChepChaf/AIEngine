#include "AIEngine.h"

#include <iostream>

#include <GLFW/glfw3.h>

#pragma comment(lib, "AIEngine")

int main(int argc, char** argv)
{
    AIEngine::Application* app = new AIEngine::Application();

    app->Init(argc, argv);
    while (app->IsRunning())
    {
        app->Update();
    }
    
    app->Stop();
    
    delete app;

    return 0;
}