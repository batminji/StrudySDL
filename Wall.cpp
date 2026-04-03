#include "stdafx.h"
#include "Wall.h"
#include "Engine.h"
#include "ResourceManager.h"

AWall::AWall(const FVector2D& InLocation, const char InMesh)
{
	Location = InLocation;
	Mesh = InMesh;

	// MyResource = GEngine->GetResourceManager()->LoadTexture("Data/wall.bmp");
	// 
	// TextureLocation = { 0, 0 };
	// TextureSize = { MyResource->Image->w, MyResource->Image->h };
}

AWall::~AWall()
{
}
