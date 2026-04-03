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
	SpriteComponent->SetResource(MyResource);
	SpriteComponent->SetTextureSize({ MyResource->Image->w, MyResource->Image->h });
	SpriteComponent->SetZOrder(5);

	// Collision Component
	CollisionComponent = CreateDefaultSubObject<UCollisionComponent>("Collision");
	CollisionComponent->SetbIsGenerateHit(true);
	CollisionComponent->SetbIsGenerateOverlap(true);
}

AWall::~AWall()
{
}
