#pragma once
#include "Character.h"

class USpriteAnimationComponent;
class UCollisionComponent;

class APlayer : public ACharacter
{
public:
	APlayer(const FVector2D& InLocation = { 0, 0 }, const char InMesh = ' ');
	virtual ~APlayer();

	virtual void BeginPlay() override;
	virtual void Tick() override;

protected:
	USpriteAnimationComponent* SpriteAnimationComponent;
	UCollisionComponent* CollisionComponent;

	virtual void ReceiveHit(AActor* OtherActor) override;
	virtual void ProcessBeginOverlap(class AActor* OtherActor) override;

protected:
	int Direction = 3;
	float DeltaSeconds = 0.0f;
	int SpriteIndex = 0;
};

