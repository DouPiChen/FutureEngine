#pragma once

#ifdef FE_PLATFORM_WINDOWS
	#ifdef FE_BUILD_DLL
		#define FE_API __declspec(dllexport)
	#else
		#define FE_API __declspec(dllimport)
	#endif // FE_BUILD_DLL
#else
	#error FutureEngine only supports Windows!
#endif
