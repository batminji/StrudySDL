#include "stdafx.h"
#include "SpriteComponent.h"
#include "Engine.h"
#include "Actor.h"

USpriteComponent::USpriteComponent()
{
}

USpriteComponent::~USpriteComponent()
{
}

void USpriteComponent::BeginPlay()
{
}

void USpriteComponent::Tick()
{
}

void USpriteComponent::Render()
{
	GEngine->Render(Owner->GetActorLocation(), MyResource->Texture, Owner->GetActorTextureLocation(), TextureSize);
}
