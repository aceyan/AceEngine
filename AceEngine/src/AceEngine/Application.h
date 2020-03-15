#pragma once

#include "Core.h"
#include "Window.h"

namespace AceEngine
{
	class ACE_ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> _window;
	};

	Application* CreateApplication();
}