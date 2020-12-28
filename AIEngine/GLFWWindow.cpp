#include "GLFWWindow.h"

#include "Config.h"

namespace AIEngine
{
    int GLFWWindow::Init()
    {
        /* Initialize the library */
        if (!glfwInit())
            return -1;

        if (Config::GetIntValue("window_maximized"))
        {
            glfwWindowHint(GLFW_MAXIMIZED, GLFW_TRUE);
        }

        /* Init a windowed mode window and its OpenGL context */
        window = glfwCreateWindow(Config::GetIntValue("window_width"), Config::GetIntValue("window_height"), Config::GetValue("window_name").c_str(), NULL, NULL);
        if (!window)
        {
            glfwTerminate();
            return -1;
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(window);

        return 0;
    }

    void GLFWWindow::Update()
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();

        if (glfwWindowShouldClose(window))
        {
            m_shouldClose = true;
        }
    }

    bool GLFWWindow::CloseEventTriggered()
    {
        return m_shouldClose;
    }

    void GLFWWindow::Stop()
    {
        glfwTerminate();
    }
}