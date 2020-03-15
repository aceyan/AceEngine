#pragma once

#ifdef ACE_ENGINE_PLATFORM_WINDOWS
	#ifdef ACE_ENGINE_BUILD_DLL
		#define ACE_ENGINE_API __declspec(dllexport)
	#else 
		#define ACE_ENGINE_API __declspec(dllimport)
	#endif //ACE_ENGINE_BUILD_DLL
#else
   #error AceEngine only support Windows
#endif

#ifdef ACE_DEBUG
#define ACE_ENABLE_ASSERTS
#endif

#ifdef ACE_ENABLE_ASSERTS
#define ACE_GAME_ASSERT(x, ...) { if(!(x)) { ACE_GAME_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define ACE_CORE_ASSERT(x, ...) { if(!(x)) { ACE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define ACE_ASSERT(x, ...)
#define ACE_CORE_ASSERT(x, ...)
#endif