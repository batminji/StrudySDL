#include "stdafx.h"
#include "Player.h"
#include "Engine.h"
#include "ResourceManager.h"
#include "GameplayStatics.h"
#include "SpriteAnimationComponent.h"

APlayer::APlayer(const FVector2D& InLocation, const char InMesh)
{
	Location = InLocation;
	Mesh = InMesh;

	SpriteAnimationComponent = CreateDefaultSubObject<USpriteAnimationComponent>("Sprite");

	Resource* MyResource = GEngine->GetResourceManager()->LoadTexture("Data/player.bmp", true, 255, 0, 255);
	SpriteAnimationComponent->MyResource = MyResource;

	SpriteAnimationComponent->TextureLocation = { 0, 0 };
	SpriteAnimationComponent->TextureSize = { MyResource->Image->w / 5, MyResource->Image->h / 5};
	SpriteAnimationComponent->ZOrder = 100;
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	__super::BeginPlay();

	OnActorBeginOverlap = [&](AActor* Other) {

		};
}

void APlayer::Tick()
{
	__super::Tick();

	SDL_Event Event = GEngine->GetEvent();

	FVector2D Offset{ 0, 0 };
	if (Event.type == SDL_KEYDOWN)
	{
		const Uint8* State = GEngine->GetState();

		if (State[SDL_SCANCODE_UP] || State[SDL_SCANCODE_W])
		{
			Offset.Y--;
			Direction = 2;
		}
		if (State[SDL_SCANCODE_DOWN] || State[SDL_SCANCODE_S])
		{
			Offset.Y++;
			Direction = 3;
		}
		if (State[SDL_SCANCODE_LEFT] || State[SDL_SCANCODE_A])
		{
			Offset.X--;
			Direction = 0;
		}
		if (State[SDL_SCANCODE_RIGHT] || State[SDL_SCANCODE_D])
		{
			Offset.X++;
			Direction = 1;
		}
	}

	if (Offset.X != 0 || Offset.Y != 0)
	{
		AddActorLocalOffset(Offset);
	}

	DeltaSeconds += UGameplayStatics::GetWorldDeltaSeconds();
	if (DeltaSeconds >= 0.1f)
	{
		SpriteIndex = ++SpriteIndex % 5;
		DeltaSeconds = 0.0f;
	}

	TextureLocation = { SpriteIndex, Direction };
}

void APlayer::ProcessBeginOverlap(AActor* OtherActor)
{

}
