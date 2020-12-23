#pragma once

namespace AIEngine
{
	class Window
	{
	public:
		static Window* CreateWindow();
		virtual void Stop() = 0;
		virtual void Update() = 0;
	protected:
		virtual int Init() = 0;
	};
}
