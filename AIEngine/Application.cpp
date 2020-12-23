#include "Application.h"
#include "Core.h"

#include "Window.h"

#include <iostream>

namespace AIEngine
{
	void Application::Init()
	{
		Logger::Init();
		
		AIE_CORE_INFO("Application::Init");

		m_window = Window::CreateWindow();

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

		m_isRunning = false;
	}
	const bool Application::IsRunning() const
	{
		return m_isRunning;
	}
}
