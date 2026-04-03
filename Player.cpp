#include "stdafx.h"
#include "Player.h"
#include "Engine.h"
#include "World.h"
#include "ResourceManager.h"
#include "GameplayStatics.h"
#include "SpriteAnimationComponent.h"
#include "CollisionComponent.h"

APlayer::APlayer(const FVector2D& InLocation, const char InMesh)
{
	Location = InLocation;
	Mesh = InMesh;

	// Sprite Animation Component
	SpriteAnimationComponent = CreateDefaultSubObject<USpriteAnimationComponent>("Sprite");

	Resource* MyResource = GEngine->GetResourceManager()->LoadTexture("Data/player.bmp", true, 255, 0, 255);
	SpriteAnimationComponent->MyResource = MyResource;

	SpriteAnimationComponent->TextureLocation = { 0, 0 };
	SpriteAnimationComponent->TextureSize = { MyResource->Image->w / 5, MyResource->Image->h / 5};
	SpriteAnimationComponent->ZOrder = 100;

	// Collision Component
	CollisionComponent = CreateDefaultSubObject<UCollisionComponent>("Collision");
	CollisionComponent->bIsGenerateHit = true;
	CollisionComponent->bIsGenerateOverlap = true;
}

APlayer::~APlayer()
{
}

void APlayer::BeginPlay()
{
	__super::BeginPlay();

	// OnActorBeginOverlap = [&](AActor* Other) {
	// 
	// 	};
	// 
	// OnActorBeginOverlap = &APlayer::ProcessBeginOverlap;
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
		if (!PredictMovement(Location))
		{
			Offset.X = Offset.X * -1;
			Offset.Y = Offset.Y * -1;
			AddActorLocalOffset(Offset);
		}
	}

	DeltaSeconds += UGameplayStatics::GetWorldDeltaSeconds();
	if (DeltaSeconds >= 0.1f)
	{
		SpriteIndex = ++SpriteIndex % 5;
		DeltaSeconds = 0.0f;
	}

	TextureLocation = { SpriteIndex, Direction };
}

void APlayer::ReceiveHit(AActor* OtherActor)
{

}

void APlayer::ProcessBeginOverlap(AActor* OtherActor)
{

}

bool APlayer::PredictMovement(FVector2D InLocation)
{
	for (auto Other : GEngine->GetWorld()->GetAllActorsOfClass()) 
	{
		for (auto OtherComponent : Other->Components)
		{
			UCollisionComponent* OtherCollision = dynamic_cast<UCollisionComponent*>(OtherComponent);
			if (OtherCollision)
			{
				if (OtherCollision->Owner == this)
				{
					return true;
				}
				if (OtherCollision->bIsGenerateHit && InLocation.X == Other->GetActorLocation().X && InLocation.Y == Other->GetActorLocation().Y)
				{
					ReceiveHit(Other);
					return false;
				}
			}
		}
	}
	return true;
}
