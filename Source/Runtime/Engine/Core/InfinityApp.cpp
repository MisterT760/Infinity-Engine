#include "InfinityApp.h"
#include "Log.h"

namespace Infinity
{
	Infinity::InfinityApp::InfinityApp()
	{
	}

	Infinity::InfinityApp::~InfinityApp()
	{
	}

	void Infinity::InfinityApp::InitializeEngine()
	{
		//Initialize the loggers
		Infinity::Log::Initialize();

		//
		INF_ENGINE_TRACE("Initializing engine modules...");

		//
		INF_ENGINE_TRACE("Engine initialization complete.");
	}

	void Infinity::InfinityApp::Run()
	{
		while (true)
		{

		}
	}

	void Infinity::InfinityApp::TerminateEngine()
	{
		//
		INF_ENGINE_TRACE("Terminating engine modules...");

		//
		INF_ENGINE_TRACE("Engine modules terminated. ByeBye");
	}
}
