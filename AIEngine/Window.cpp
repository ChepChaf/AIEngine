#include "Window.h"
#include "Core.h"

#include "GLFWWindow.h"

#include <iostream>

namespace AIEngine
{
	Window* Window::CreateWindow()
	{
		Window* window = new GLFWWindow();

		if (window->Init() < 0)
		{
			AIE_CORE_ERROR("Failed to init window.");

			delete window;
			window = nullptr;

			return nullptr;
		}

		return window;
	}
}
