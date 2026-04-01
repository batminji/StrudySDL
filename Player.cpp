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
		switch (Event.key.keysym.sym)
		{
		case SDLK_w:
			AddActorLocalOffset({ 0, -1 });
			break;
		case SDLK_s:
			AddActorLocalOffset({ 0, 1 });
			break;
		case SDLK_a:
			AddActorLocalOffset({ -1, 0 });
			break;
		case SDLK_d:
			AddActorLocalOffset({ 1, 0 });
			break;
		default:
			break;
		}
	}
}