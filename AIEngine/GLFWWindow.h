#pragma once

#include "Window.h"

#include <GLFW/glfw3.h>


namespace AIEngine
{
    class GLFWWindow :
        public Window
    {
        GLFWwindow* window;
        // Inherited via Window
    public:
        virtual int Init() override;
        virtual void Stop() override;
        virtual void Update() override;
    };
}
