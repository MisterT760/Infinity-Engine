#include "InfinityApp.h"
#include "Log.h"

namespace Infinity
{
	Infinity::InfinityApp::InfinityApp() :
		m_Core()
	{
	}

	Infinity::InfinityApp::~InfinityApp()
	{
	}

	void Infinity::InfinityApp::InitializeEngine()
	{
		//Initialize the loggers
		Infinity::Log::Initialize();

		INF_ENGINE_TRACE("Initializing engine modules...");

		m_Core.Initialize();

		INF_ENGINE_TRACE("Engine initialization complete.");
	}

	void Infinity::InfinityApp::Run()
	{
		//Check engine state and Tick necessary modules
		while (m_Core.GetEngineState())
		{
			m_Core.Tick(0.0f);
		}
	}

	void Infinity::InfinityApp::TerminateEngine()
	{
		INF_ENGINE_TRACE("Terminating engine modules...");

		m_Core.Terminate();

		INF_ENGINE_TRACE("Engine modules terminated. ByeBye!");
	}
}
