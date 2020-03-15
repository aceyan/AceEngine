#pragma once

#include <string>

namespace AceEngine 
{
	struct WindowProperties
	{
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowProperties(const std::string& Title = "AceEngine",
			unsigned int Width = 1280,
			unsigned int Height = 720) : title(Title), width(Width), height(Height)
		{

		}
	};

	class Window
	{
	public:
		Window(const WindowProperties& props = WindowProperties()) : _title(props.title), _width(props.width), _height(props.height) {};

		virtual ~Window() = default;
		virtual void OnUpdate() = 0;

		virtual void SetVSync(bool enabled) { _isVSync = enabled; };


		inline std::string GetTitile() { return _title; };
		inline unsigned int GetWidth() { return _width; };
		inline unsigned int GetHeight() { return _height; };
		inline bool IsVSync() { return _isVSync; };
		
		static std::unique_ptr<Window> Create(const WindowProperties& props = WindowProperties());
	protected:
		std::string _title;
		unsigned int _width;
		unsigned int _height;
		bool _isVSync = false;


	};
}


