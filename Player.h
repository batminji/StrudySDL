#pragma once
#include "Actor.h"

class USpriteAnimationComponent;
class UCollisionComponent;

class APlayer : public AActor
{
public:
	APlayer(const FVector2D& InLocation = { 0, 0 }, const char InMesh = ' ');
	virtual ~APlayer();

	virtual void BeginPlay() override;
	virtual void Tick() override;

	USpriteAnimationComponent* SpriteAnimationComponent;
	UCollisionComponent* CollisionComponent;

	virtual void ReceiveHit(AActor* OtherActor) override;

	void ProcessBeginOverlap(class AActor* OtherActor);

protected:
	int Direction = 3;
	float DeltaSeconds = 0.0f;
	int SpriteIndex = 0;

	bool PredictMovement(FVector2D InLocation); // Movement Component로 만들어야 함
};

