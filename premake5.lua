workspace "AceEngine"
	architecture "x64"
	startproject "Game"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


include "AceEngine/ThirdParty/glad"

project "AceEngine"
	location "AceEngine"
	kind "SharedLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "Acepch.h"
	pchsource "AceEngine/src/Acepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/ThirdParty/glad/include",
		"%{prj.name}/ThirdParty/GLFW/include",
		"%{prj.name}/ThirdParty/spdlog/include"
	}

	libdirs 
	{
		"%{prj.name}/ThirdParty/GLFW/lib-vc2017"
	}

	links
	{
		"glfw3.lib",
		"opengl32.lib",
		"Glad"
	}

	defines
		{
			"GLFW_INCLUDE_NONE",
			"ACE_ENGINE_BUILD_DLL",
			"ACE_ENGINE_PLATFORM_WINDOWS"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Game")
		}

	filter "system:windows"
		systemversion "10.0.18362.0"

		filter "configurations:Debug"
			defines "ACE_DEBUG"
			runtime "Debug"
			symbols "On"

		filter "configurations:Release"
			defines "ACE_Release"
			runtime "Release"
			optimize "On"

		filter "configurations:Dist"
			defines "ACE_Dist"
			runtime "Release"
			optimize "On"


project "Game"
	location "Game"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{

		"AceEngine/ThirdParty/spdlog/include",
		"AceEngine/src"
	}

	links
	{
		"AceEngine"
	}

	filter "system:windows"

		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.18362.0"

		defines
		{
			"ACE_ENGINE_PLATFORM_WINDOWS"
		}
		

		filter "configurations:Debug"
			defines "ACE_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "ACE_Release"
			optimize "On"

		filter "configurations:Dist"
			defines "ACE_Dist"
			optimize "On"