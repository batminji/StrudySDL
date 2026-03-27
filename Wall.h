#pragma once
#include "Actor.h"
class AWall : public AActor
{
public:
	AWall(const FVector2D& InLocation = {0, 0}, const char InMesh = '#', const int InZOrder = 1);
	virtual ~AWall();
};

