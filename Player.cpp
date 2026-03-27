#include "stdafx.h"
#include "Player.h"
#include "Engine.h"

APlayer::APlayer(const FVector2D& InLocation, char InMesh)
{
	Location = InLocation;
	Mesh = InMesh;
}

APlayer::~APlayer()
{
}

void APlayer::Tick()
{
	Move();
}

void APlayer::Move()
{
	switch (UEngine::KeyCode)
	{
	case 'w':
		AddActorLocalOffset({ 0, -1 });
		break;
	case 's':
		AddActorLocalOffset({ 0, 1 });
		break;
	case 'a':
		AddActorLocalOffset({ -1, 0 });
		break;
	case 'd':
		AddActorLocalOffset({ 1, 0 });
		break;
	default:
		break;
	}
}
