#pragma once
#include <glfw3.h> 
#include "AceEngine/Window.h"


namespace AceEngine
{
	class WindowsWindow : public Window
	{

	public:
		WindowsWindow(const WindowProperties& props = WindowProperties());
		virtual ~WindowsWindow() override;
		virtual void OnUpdate() override;
		virtual void SetVSync(bool enabled) override;

	private:
		void Init(const WindowProperties& props);
		void ShutDown();
		GLFWwindow* _window;
	};
}

