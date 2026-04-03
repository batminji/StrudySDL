#pragma once
#include "Actor.h"

class UCollisionComponent;

class ACharacter : public AActor
{
public:
	ACharacter();
	virtual ~ACharacter();

protected:
	virtual bool PredictMove(FVector2D InLocation);
};

