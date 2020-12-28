#include "InfinityCore.h"
#include "Log.h"

#include <Windows.h>
#include <GLFW/glfw3.h>

namespace Infinity
{
	InfinityCore::InfinityCore() :
		m_Window(),
		m_bRunning(true)
	{
	}

	InfinityCore::~InfinityCore()
	{
	}

	void InfinityCore::Initialize()
	{
		INF_ENGINE_TRACE("Initializing core...");

		//Initialize GLFW
		if (!glfwInit())
		{
			INF_ENGINE_FATAL("Failed to initialize GLFW!");
		}

		//Create new window
		int width, height;
		GetDesktopResolution(width, height);
		m_Window = glfwCreateWindow(width, height, "Infinity Editor", NULL, NULL);

		INF_ENGINE_TRACE("Core initialized.");
	}

	void InfinityCore::Tick(float delta)
	{
		//Check if the window needs to be closed, if it is no need to keep running
		m_bRunning = !glfwWindowShouldClose(m_Window);
		if (m_bRunning)
		{
			glfwPollEvents();
		}
	}

	void InfinityCore::Terminate()
	{
		INF_ENGINE_TRACE("Terminating core...");

		//Terminate GLFW
		glfwTerminate();

		INF_ENGINE_TRACE("Core terminated.");
	}

	void InfinityCore::GetDesktopResolution(int& width, int& height)
	{
#ifdef INF_PLATFORM_WINDOWS
		//Get desktop window handle
		RECT rDesktop;
		const HWND hDesktop = GetDesktopWindow();

		//Get window rect
		GetWindowRect(hDesktop, &rDesktop);

		//Return window width and height
		width = rDesktop.right;
		height = rDesktop.bottom;
#else
#error Unsupported platform!
#endif

	}
}