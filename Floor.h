#pragma once
#include "Actor.h"
class AFloor : public AActor
{
public:
	AFloor(const FVector2D InLocation = {0, 0}, const char InMesh = ' ');
	virtual ~AFloor();
};

