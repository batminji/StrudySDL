#include "stdafx.h"
#include "Goal.h"
#include "Engine.h"
#include "ResourceManager.h"

AGoal::AGoal(const FVector2D& InLocation, const char InMesh)
{
	Location = InLocation;
	Mesh = InMesh;

	// MyResource = GEngine->GetResourceManager()->LoadTexture("Data/floor.bmp", true, 255, 255, 255);
	// 
	// TextureLocation = { 0, 0 };
	// TextureSize = { MyResource->Image->w, MyResource->Image->h };
}

AGoal::~AGoal()
{
}
