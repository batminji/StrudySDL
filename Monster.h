#pragma once
#include "Actor.h"

class USpriteComponent;

class AMonster : public AActor
{
public:
	AMonster(const FVector2D& InLocation = { 0, 0 }, const char InMesh = ' ');
	virtual ~AMonster();

	virtual void Tick() override;

	USpriteComponent* SpriteComponent;

protected:
	int Direction;
	float DeltaTime;
};

