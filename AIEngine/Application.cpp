#include "Application.h"
#include "Core.h"

#include "Window.h"
#include "Config.h"

#include <iostream>

namespace AIEngine
{
	Application::Application()
	{
	}

	void Application::Init(int argc, char** argv)
	{
		Logger::Init();
		Config::Init(argc, argv);
		
		AIE_CORE_INFO("Application::Init");

		m_window = Window::CreateWindow();

		if (!m_window)
		{
			AIE_CORE_ERROR("Failed to Init window.");
			m_isRunning = false;

			return;
		}

		m_isRunning = true;
	}
	void Application::Stop()
	{
		AIE_CORE_INFO("Application::Stop");
	
		m_window->Stop();
		delete m_window;

		m_isRunning = false;
	}
	void Application::Update()
	{
		AIE_CORE_INFO("Application::Update");

		m_window->Update();

		if (m_window->CloseEventTriggered())
		{
			m_isRunning = false;
		}
	}
	const bool Application::IsRunning() const
	{
		return m_isRunning;
	}
}
