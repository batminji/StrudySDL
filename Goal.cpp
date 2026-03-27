#include "stdafx.h"
#include "Goal.h"

AGoal::AGoal(const FVector2D& InLocation, const char InMesh, const int InZOrder)
{
	Location = InLocation;
	Mesh = InMesh;
	ZOrder = InZOrder;
}

AGoal::~AGoal()
{
}
