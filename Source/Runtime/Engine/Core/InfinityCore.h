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

/*
*
*/
struct GLFWwindow;

namespace Infinity
{
	class INFINITY_API InfinityCore
	{
	public:
		InfinityCore();
		~InfinityCore();

		//This module should be use to initialize core features (Logger, Window, etc)
		void Initialize();
		void Tick(float delta);
		void Terminate();

		bool GetEngineState() { return m_bRunning; }

	private:
		//Function to get desktop resolution (implementation is platform dependent)
		void GetDesktopResolution(int& width, int& height);

		//GLFW window handle
		GLFWwindow* m_Window;
		bool m_bRunning;
	};
}