#include "stdafx.h"
#include "Goal.h"

AGoal::AGoal(const FVector2D& InLocation, const char InMesh)
{
	Location = InLocation;
	Mesh = InMesh;
}

AGoal::~AGoal()
{
}
