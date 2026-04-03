#include "stdafx.h"
#include "Goal.h"
#include "Engine.h"
#include "ResourceManager.h"
#include "SpriteComponent.h"
#include "CollisionComponent.h"

AGoal::AGoal(const FVector2D& InLocation, const char InMesh)
{
	Location = InLocation;
	Mesh = InMesh;

	// Sprite Component
	SpriteComponent = CreateDefaultSubObject<USpriteComponent>("Sprite");

	Resource* MyResource = GEngine->GetResourceManager()->LoadTexture("Data/Goal.bmp", true, 255, 255, 255);
	SpriteComponent->SetResource(MyResource);
	SpriteComponent->SetTextureSize({ MyResource->Image->w, MyResource->Image->h });
	SpriteComponent->SetZOrder(10);

	// Collision Component
	CollisionComponent = CreateDefaultSubObject<UCollisionComponent>("Collision");
	CollisionComponent->SetbIsGenerateHit(false);
	CollisionComponent->SetbIsGenerateOverlap(true);
}

AGoal::~AGoal()
{
}
