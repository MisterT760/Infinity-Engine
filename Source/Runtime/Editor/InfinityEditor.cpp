#include "InfinityEditor.h"
#include "Core/Log.h"

InfinityEditor::InfinityEditor()
{
}

InfinityEditor::~InfinityEditor()
{
}

void InfinityEditor::Initialize()
{
	INF_LOG_INFO("TEST");
}

void InfinityEditor::Terminate()
{
}

/*
*	Function that create the app, basically the app entry point
*/
Infinity::InfinityApp* Infinity::CreateApp()
{
	return new InfinityEditor();
}