#include "stdafx.h"
#include "Monster.h"

AMonster::AMonster(const FVector2D& InLocation, const char InMesh)
{
	Location = InLocation;
	Mesh = InMesh;
}

AMonster::~AMonster()
{
}
