#pragma once

#include "Core.h"

namespace AceEngine
{
	class ACE_ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}