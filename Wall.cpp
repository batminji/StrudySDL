#include "stdafx.h"
#include "Wall.h"
#include "Engine.h"
#include "ResourceManager.h"
#include "SpriteComponent.h"
#include "CollisionComponent.h"

AWall::AWall(const FVector2D& InLocation, const char InMesh)
{
	Location = InLocation;
	Mesh = InMesh;

	// Sprite Component
	SpriteComponent = CreateDefaultSubObject<USpriteComponent>("Sprite");

	Resource* MyResource = GEngine->GetResourceManager()->LoadTexture("Data/wall.bmp");
	SpriteComponent->MyResource = MyResource;

	SpriteComponent->TextureSize = { MyResource->Image->w, MyResource->Image->h };

	SpriteComponent->ZOrder = 5;

	// Collision Component
	CollisionComponent = CreateDefaultSubObject<UCollisionComponent>("Collision");
	CollisionComponent->bIsGenerateHit = true;
	CollisionComponent->bIsGenerateOverlap = true;
}

AWall::~AWall()
{
}
