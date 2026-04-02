#include "stdafx.h"
#include "Player.h"
#include "Engine.h"

APlayer::APlayer(const FVector2D& InLocation, int InColorR, int InColorG, int InColorB, char InMesh, const int InZOrder)
{
	Location = InLocation;
	Mesh = InMesh;
	ZOrder = InZOrder;
	ColorR = InColorR;
	ColorG = InColorG;
	ColorB = InColorB;

	Load("Data/player.bmp", 255, 0, 255, {0, 0}, {50, 50});

}

APlayer::~APlayer()
{
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

	DeltaSeconds += GEngine->GetDeltaSeconds();
	if (DeltaSeconds >= 0.1f)
	{
		SpriteIndex = ++SpriteIndex % 5;
		DeltaSeconds = 0.0f;
	}

	TextureLocation = { SpriteIndex, Direction};
}