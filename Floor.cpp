#include "stdafx.h"
#include "Floor.h"
#include "Engine.h"
#include "ResourceManager.h"
#include "SpriteComponent.h"

AFloor::AFloor(const FVector2D& InLocation, const char InMesh)
{
	Location = InLocation;
	Mesh = InMesh;
	Name = "Floor";

	SpriteComponent = CreateDefaultSubObject<USpriteComponent>("Sprite");

	Resource* MyResource = GEngine->GetResourceManager()->LoadTexture("Data/floor.bmp");
	SpriteComponent->SetResource(MyResource);
	SpriteComponent->SetTextureSize({ MyResource->Surface->w, MyResource->Surface->h });
	SpriteComponent->SetZOrder(0);
}

AFloor::~AFloor()
{
}
