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
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	__super::Tick();

	SDL_Event Event = GEngine->GetEvent();
	if (Event.type == SDL_KEYDOWN)
	{
		const Uint8* State = GEngine->GetState();

		if (State[SDL_SCANCODE_UP] || State[SDL_SCANCODE_W])
		{
			AddActorLocalOffset({ 0, -1 });
		}
		if (State[SDL_SCANCODE_DOWN] || State[SDL_SCANCODE_S])
		{
			AddActorLocalOffset({ 0, 1 });
		}
		if (State[SDL_SCANCODE_LEFT] || State[SDL_SCANCODE_A])
		{
			AddActorLocalOffset({ -1, 0 });
		}
		if (State[SDL_SCANCODE_RIGHT] || State[SDL_SCANCODE_D])
		{
			AddActorLocalOffset({ 1, 0 });
		}
	}
}