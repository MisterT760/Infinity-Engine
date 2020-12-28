#pragma once

//
#include "InfinityCore.h"

namespace Infinity
{
	//Application class
	class INFINITY_API InfinityApp
	{
	public:
		InfinityApp();
		virtual ~InfinityApp();

		//Functions for Initializing, Running and Terminating the engine
		void InitializeEngine();
		virtual void Run();
		void TerminateEngine();

		//Pure virtual functions for app Initialization and Termination
		virtual void Initialize() = 0;
		virtual void Terminate() = 0;

	private:
		//
		InfinityCore m_Core;
	};

	//This function needs to be declared by the application
	InfinityApp* CreateApp();
}