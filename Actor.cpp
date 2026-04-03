#include "stdafx.h"
#include "Actor.h"
#include "Engine.h"
#include "Component.h"

AActor::AActor(const FVector2D& InLocation, const char InMesh)
	: Location(InLocation), Mesh(InMesh)
{
}

AActor::~AActor()
{
	for (auto Component : Components)
	{
		delete Component;
	}
	Components.clear();
}

void AActor::BeginPlay()
{
}

void AActor::Tick()
{
	for (auto Component : Components)
	{
		Component->Tick();
	}
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