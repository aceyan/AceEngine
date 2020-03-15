#include "Acepch.h"
#include "WindowsWindow.h"
#include <iostream> 
#include <glfw3.h> 
namespace AceEngine
{
	WindowsWindow::WindowsWindow(const WindowProperties & props) : Window(props)
	{
		Init(props);
	}
	WindowsWindow::~WindowsWindow()
	{
		ShutDown();
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(_window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		Window::SetVSync(enabled);
		if (enabled)
		{
			glfwSwapInterval(1);
		}
		else
		{
			glfwSwapInterval(0);
		}
	}

	void WindowsWindow::Init(const WindowProperties & props)
	{
		ACE_CORE_INFO("create window {0} ({1}, {2})", props.title, props.width, props.height);


		glfwInit();

		// Create a GLFWwindow object that we can use for GLFW's functions    
		_window = glfwCreateWindow(props.width, props.height, props.title.c_str(), nullptr, nullptr);
		if (_window == nullptr)
		{
			ACE_CORE_ASSERT(false,"Failed to create GLFW window");
			glfwTerminate();
			return;
		}
		glfwMakeContextCurrent(_window);
		SetVSync(true);
	}
	void WindowsWindow::ShutDown()
	{
		glfwDestroyWindow(_window);
	}
}




