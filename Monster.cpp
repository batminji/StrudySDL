#include "stdafx.h"
#include "Monster.h"
#include "Engine.h"
#include "ResourceManager.h"
#include "SpriteComponent.h"

AMonster::AMonster(const FVector2D& InLocation, const char InMesh)
{
	Location = InLocation;
	Mesh = InMesh;

	Direction = rand() % 4;

	SpriteComponent = CreateDefaultSubObject<USpriteComponent>("Sprite");

	Resource* MyResource = GEngine->GetResourceManager()->LoadTexture("Data/monster.bmp", true, 255, 255, 255);
	SpriteComponent->MyResource = MyResource;

	SpriteComponent->TextureLocation = { 0, 0 };
	SpriteComponent->TextureSize = { MyResource->Image->w, MyResource->Image->h };

	SpriteComponent->ZOrder = 20;
}

AMonster::~AMonster()
{
}

void AMonster::Tick()
{
	DeltaTime += GEngine->GetDeltaSeconds();
	if (DeltaTime > 1.0f)
	{
		Direction = ++Direction % 4;
		if (Direction == 0)
		{
			AddActorLocalOffset({ 0, -1 });
		}
		if (Direction == 1)
		{
			AddActorLocalOffset({ 0, 1 });
		}
		if (Direction == 2)
		{
			AddActorLocalOffset({ -1, 0 });
		}
		if (Direction == 3)
		{
			AddActorLocalOffset({ 1, 0 });
		}
		DeltaTime = 0.0f;
	}
}
