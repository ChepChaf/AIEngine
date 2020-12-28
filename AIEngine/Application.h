#pragma once

#include "Core.h"

#include "Window.h"

namespace AIEngine 
{
	class AIE_API Application
	{
		Window* m_window;
		bool m_isRunning;
	public:
		Application();
		void Init(int argc, char** argv);
		void Update();
		void Stop();
		const bool IsRunning() const;
	};
}


