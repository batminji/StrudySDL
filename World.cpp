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

void UWorld::Load(const std::string MapName)
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

	MapStream.close();
}

void UWorld::Save(const std::string SaveFileName)
{
	FVector2D MaxSize = GetMaxMapSize();

	std::vector<std::string> MapBuffer(MaxSize.Y + 1, std::string(MaxSize.X + 1, ' '));
	SaveActors(MapBuffer);

	std::ofstream MapStream(SaveFileName);
	if (MapStream.is_open())
	{
		for (const std::string& Line : MapBuffer)
		{
			MapStream << Line << std::endl;
		}
		MapStream.close();
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

void UWorld::SaveActors(std::vector<std::string>& MapBuffer)
{
	for (auto Actor : Actors)
	{
		FVector2D Location = Actor->GetActorLocation();
		int X = Location.X;
		int Y = Location.Y;

		if (dynamic_cast<APlayer*>(Actor))
		{
			MapBuffer[Y][X] = 'P';
		}
		else if (dynamic_cast<AMonster*>(Actor))
		{
			MapBuffer[Y][X] = 'M';
		}
		else if (dynamic_cast<AWall*>(Actor))
		{
			MapBuffer[Y][X] = '#';
		}
		else if (dynamic_cast<AGoal*>(Actor))
		{
			MapBuffer[Y][X] = 'G';
		}
	}
}

const FVector2D& UWorld::GetMaxMapSize() const
{
	int MaxX = 0, MaxY = 0;
	for (auto Actor : Actors)
	{
		FVector2D Location = Actor->GetActorLocation();
		if (Location.X > MaxX)
		{
			MaxX = Location.X;
		}
		if (Location.Y > MaxY)
		{
			MaxY = Location.Y;
		}
	}

	return { MaxX, MaxY };
}