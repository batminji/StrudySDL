#pragma once
#include "Character.h"

class USpriteComponent;
class UCollisionComponent;

class AMonster : public ACharacter
{
public:
	AMonster(const FVector2D& InLocation = { 0, 0 }, const char InMesh = ' ');
	virtual ~AMonster();

	virtual void Tick() override;

protected:
	USpriteComponent* SpriteComponent;
	UCollisionComponent* CollisionComponent;

	virtual void ReceiveHit(AActor* OtherActor) override;

	virtual void ProcessBeginOverlap(AActor* OtherActor) override;

protected:
	int Direction;
	float DeltaTime;
};

