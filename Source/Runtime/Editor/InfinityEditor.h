#pragma once
#include <InfinityEngine.h>

//Game class
class InfinityEditor : public Infinity::InfinityApp
{
public:
	InfinityEditor();
	~InfinityEditor();

	//Functions for Initializing and Terminating the app
	virtual void Initialize() override;
	virtual void Terminate() override;
};

