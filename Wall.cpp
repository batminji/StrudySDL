#include "stdafx.h"
#include "Wall.h"

AWall::AWall(const FVector2D& InLocation, const char InMesh)
{
	Location = InLocation;
	Mesh = InMesh;
}

AWall::~AWall()
{
}
