#include "stdafx.h"
#include "World.h"
#include "Actor.h"

#include "Player.h"
#include "Monster.h"
#include "Wall.h"
#include "Floor.h"
#include "Goal.h"

UWorld::UWorld()
{

}

UWorld::~UWorld()
{
	for (auto Actor : Actors)
	{
		delete Actor;
	}
	Actors.clear();
}

void UWorld::Load(std::string MapName)
{
	std::ifstream MapStream(MapName);

	if (!MapStream.is_open())
	{
		return;
	}

	int Y = 0;
	while (!MapStream.eof())
	{
		std::string Line;
		std::getline(MapStream, Line);
		for (int X = 0; X < Line.length(); ++X)
		{
			char Tile = Line[X];
			SpawnActor<AFloor>()->SetActorLocation({ X, Y });

			switch (Tile)
			{
			case 'P':
				SpawnActor<APlayer>()->SetActorLocation({ X, Y });
				break;
			case 'G':
				SpawnActor<AGoal>()->SetActorLocation({ X, Y });
				break;
			case '#':
				SpawnActor<AWall>()->SetActorLocation({ X, Y });
				break;
			case 'M':
				SpawnActor<AMonster>()->SetActorLocation({ X, Y });
				break;
			default:
				break;
			}
		}
		Y++;
	}
}

void UWorld::Tick()
{
	for (auto Actor : Actors)
	{
		Actor->Tick();
	}
}

void UWorld::Render()
{
	for (auto Actor : Actors)
	{
		Actor->Render();
	}
}