#include "stdafx.h"
#include "Wall.h"
#include "Engine.h"
#include "ResourceManager.h"
#include "SpriteComponent.h"

AWall::AWall(const FVector2D& InLocation, const char InMesh)
{
	Location = InLocation;
	Mesh = InMesh;

	SpriteComponent = CreateDefaultSubObject<USpriteComponent>("Sprite");

	Resource* MyResource = GEngine->GetResourceManager()->LoadTexture("Data/wall.bmp");
	SpriteComponent->MyResource = MyResource;

	SpriteComponent->TextureLocation = { 0, 0 };
	SpriteComponent->TextureSize = { MyResource->Image->w, MyResource->Image->h };

	SpriteComponent->ZOrder = 5;
}

AWall::~AWall()
{
}
