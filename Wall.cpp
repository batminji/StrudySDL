#include "stdafx.h"
#include "Wall.h"

AWall::AWall(const FVector2D& InLocation, const char InMesh, const int InZOrder)
{
	Location = InLocation;
	Mesh = InMesh;
	ZOrder = InZOrder;
}

AWall::~AWall()
{
}
