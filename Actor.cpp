#include "stdafx.h"
#include "Actor.h"
#include "Engine.h"

AActor::AActor(const FVector2D& InLocation, int InColorR, int InColorG, int InColorB, const char InMesh, const int InZOrder)
	: Location(InLocation), ColorR(InColorR), ColorG(InColorG), ColorB(InColorB), Mesh(InMesh), ZOrder(InZOrder)
{

}

AActor::~AActor()
{
}

void AActor::BeginPlay()
{
}

void AActor::Tick()
{
}

void AActor::Render()
{
	GEngine->Render(Location, Mesh);

	GEngine->Render(Location, ColorR, ColorG, ColorB);
}

void AActor::SetActorLocation(const FVector2D& NewLocation)
{
	Location = NewLocation;
}

void AActor::AddActorLocalOffset(const FVector2D& Offset)
{
	Location.X += Offset.X;
	Location.Y += Offset.Y;
}
