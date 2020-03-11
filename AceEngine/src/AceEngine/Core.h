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
