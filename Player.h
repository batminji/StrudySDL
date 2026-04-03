#pragma once
#include "Actor.h"

class USpriteAnimationComponent;

class APlayer : public AActor
{
public:
	APlayer(const FVector2D& InLocation = { 0, 0 }, const char InMesh = ' ');
	virtual ~APlayer();

	virtual void BeginPlay() override;
	virtual void Tick() override;

	USpriteAnimationComponent* SpriteAnimationComponent;

	void ProcessBeginOverlap(class AActor* OtherActor);

protected:
	int Direction = 3;
	float DeltaSeconds = 0.0f;
	int SpriteIndex = 0;
};

