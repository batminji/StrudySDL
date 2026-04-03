#pragma once
#include "Actor.h"

class USpriteComponent;
class UCollisionComponent;

class AGoal : public AActor
{
public:
	AGoal(const FVector2D& InLocation = { 0, 0 }, const char InMesh = ' ');
	virtual ~AGoal();
	
protected:
	USpriteComponent* SpriteComponent;
	UCollisionComponent* CollisionComponent;
};

