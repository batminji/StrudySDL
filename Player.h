#pragma once
#include "Actor.h"
class APlayer : public AActor
{
public:
	APlayer(const FVector2D& InLocation = {0, 0}, int InColorR = 255, int InColorG = 255, int InColorB = 255, const char InMesh = 'P', const int InZOrder = '3');
	virtual ~APlayer();

	virtual void Tick() override;
};

