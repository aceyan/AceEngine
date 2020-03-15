#include "Acepch.h"
#include "Window.h"

#ifdef ACE_ENGINE_PLATFORM_WINDOWS
#include "Platforms/WindowsWindow.h"
#endif

namespace AceEngine
{
	std::unique_ptr<Window> AceEngine::Window::Create(const WindowProperties& props)
	{
#ifdef ACE_ENGINE_PLATFORM_WINDOWS
		return std::make_unique<WindowsWindow>(props);
		//return nullptr;
#else
		return nullptr;
#endif
	}
}

