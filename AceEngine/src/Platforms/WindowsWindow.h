#pragma once
#include "AceEngine/Window.h"

struct  GLFWwindow;
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

