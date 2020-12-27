#include "InfinityEditor.h"

//
InfinityEditor::InfinityEditor()
{
}

InfinityEditor::~InfinityEditor()
{
}

void InfinityEditor::Initialize()
{
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