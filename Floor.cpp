#include "stdafx.h"
#include "Floor.h"

AFloor::AFloor(const FVector2D InLocation, const char InMesh, const int InZOrder)
{
	Location = InLocation;
	Mesh = InMesh;
	ZOrder = InZOrder;
}

AFloor::~AFloor()
{
}
