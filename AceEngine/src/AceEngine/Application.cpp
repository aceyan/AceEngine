#include "Acepch.h"
#include "Application.h"
#include <glad/glad.h>

namespace AceEngine
{
	Application::Application()
	{
		//_window = std::unique_ptr<Window>(Window::Create());//?
		_window = Window::Create();
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (true)
		{
			glClearColor(1, 1, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			_window->OnUpdate();
		}
	}
}


