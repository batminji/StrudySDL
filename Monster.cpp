#include "stdafx.h"
#include "Monster.h"

AMonster::AMonster(const FVector2D& InLocation, const char InMesh, const int InZOrder)
{
	Location = InLocation;
	Mesh = InMesh;
	ZOrder = InZOrder;
}

AMonster::~AMonster()
{
}
