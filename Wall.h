#pragma once
#include "Actor.h"

class USpriteComponent;

class AWall : public AActor
{
public:
	AWall(const FVector2D& InLocation = { 0, 0 }, const char InMesh = ' ');
	virtual ~AWall();

	USpriteComponent* SpriteComponent;
};

