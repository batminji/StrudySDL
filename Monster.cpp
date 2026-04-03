#include "stdafx.h"
#include "Monster.h"
#include "Engine.h"
#include "World.h"
#include "ResourceManager.h"
#include "SpriteComponent.h"
#include "CollisionComponent.h"

AMonster::AMonster(const FVector2D& InLocation, const char InMesh)
{
	Location = InLocation;
	Mesh = InMesh;

	Direction = rand() % 4;

	// Sprite Component
	SpriteComponent = CreateDefaultSubObject<USpriteComponent>("Sprite");

	Resource* MyResource = GEngine->GetResourceManager()->LoadTexture("Data/monster.bmp", true, 255, 255, 255);
	SpriteComponent->SetResource(MyResource);
	SpriteComponent->SetTextureSize({ MyResource->Image->w, MyResource->Image->h });
	SpriteComponent->SetZOrder(20);

	// Collision Component
	CollisionComponent = CreateDefaultSubObject<UCollisionComponent>("Collision");
	CollisionComponent->SetbIsGenerateHit(true);
	CollisionComponent->SetbIsGenerateOverlap(true);
}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
	DeltaTime += GEngine->GetDeltaSeconds();

	FVector2D Offset = { 0, 0 };

	if (DeltaTime > 0.1f)
	{
		Direction = rand() % 4;
		if (Direction == 0)
		{
			Offset.Y--;
		}
		if (Direction == 1)
		{
			Offset.Y++;
		}
		if (Direction == 2)
		{
			Offset.X--;
		}
		if (Direction == 3)
		{
			Offset.X++;
		}
		DeltaTime = 0.0f;
	}

	if (Offset.X != 0 || Offset.Y != 0)
	{
		AddActorLocalOffset(Offset);
		if (!PredictMove(Location))
		{
			Offset.X = Offset.X * -1;
			Offset.Y = Offset.Y * -1;
			AddActorLocalOffset(Offset);
		}
	}
}

void AMonster::ReceiveHit(AActor* OtherActor)
{

}

void AMonster::ProcessBeginOverlap(AActor* OtherActor)
{
	SDL_Log("Monster Collide Player");
}