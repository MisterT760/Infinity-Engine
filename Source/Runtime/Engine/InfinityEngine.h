#pragma once

//----------
//Only for use with Infinity App's
//----------
#include "Core/InfinityApp.h"

//----------
//Infinity Entrypoint
//----------
#ifdef INF_PLATFORM_WINDOWS
extern Infinity::InfinityApp* Infinity::CreateApp();

int main(int argc, char** argv)
{
	//Create the application
	Infinity::InfinityApp* app = Infinity::CreateApp();

	//Initialize the engine
	app->InitializeEngine();

	//Initialize the app
	app->Initialize();

	//Run the application
	app->Run();

	//Terminate the app
	app->Terminate();

	//Terminate the engine
	app->TerminateEngine();

	//Delete the application
	delete app;
}
#endif // INF_PLATFORM_WINDOWS
