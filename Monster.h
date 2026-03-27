#pragma once
#include "Actor.h"
class AMonster : public AActor
{
public:
	AMonster(const FVector2D& InLocation = {0, 0}, const char InMesh = 'M', const int InZOrder = 2);
	virtual ~AMonster();
};

