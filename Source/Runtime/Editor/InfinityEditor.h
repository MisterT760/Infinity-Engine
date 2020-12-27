#pragma once
#include <InfinityEngine.h>

//Game class
class InfinityEditor : public Infinity::InfinityApp
{
public:
	InfinityEditor();
	~InfinityEditor();

	virtual void Initialize() override;
	virtual void Terminate() override;

};

