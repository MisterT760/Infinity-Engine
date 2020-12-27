#pragma once
#ifdef INF_PLATFORM_WINDOWS
	#ifdef INF_DLL
		#define INFINITY_API __declspec(dllexport)
	#else
		#define INFINITY_API __declspec(dllimport)
	#endif
#else
	#error Unsupported Platform!
#endif // INF_PLATFORM