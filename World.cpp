#include "stdafx.h"
#include "World.h"
#include "Engine.h"
#include "Actor.h"
#include "GameMode.h"

#include "Player.h"
#include "Monster.h"
#include "Wall.h"
#include "Floor.h"
#include "Goal.h"

#include "Component.h"
#include "SpriteComponent.h"
#include "RenderableComponent.h"
#include "AudioComponent.h"
#include "BGActor.h"
#include "YoudieActor.h"

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

void UWorld::SetGameMode(AGameMode* NewGameMode)
{
	Actors.emplace_back(NewGameMode);
}

void UWorld::Load(const std::string MapName)
{
	std::ifstream MapStream(MapName);

	if (!MapStream.is_open())
	{
		return;
	}

	int MaxX = -1;
	int MaxY = -1;

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

			if (MaxX < X + 1)
			{
				MaxX = X + 1;
			}
		}
		Y++;
	}

	MaxY = Y;

	// Window Size 동적으로 변경
	SDL_SetWindowSize(GEngine->GetWindow(), MaxX * TileSize, MaxY * TileSize);

	// Text Render 추가
	SpawnActor<AYoudieActor>();
	if (GEngine->GetMixOpenAudio() != -1)
	{
		SpawnActor<ABGActor>();
	}
	
	MapStream.close();

	// SortActors();
	std::sort(Actors.begin(), Actors.end(),
		[](AActor* First, AActor* Second) -> int {

			IRenderableComponent* FirstRenderComponent = nullptr;
			for (auto Component : First->Components)
			{
				FirstRenderComponent = dynamic_cast<IRenderableComponent*>(Component);
				if (FirstRenderComponent)
				{
					break;
				}
			}

			if (!FirstRenderComponent)
			{
				return 0;
			}

			IRenderableComponent* SecondRenderComponent = nullptr;
			for (auto Component : Second->Components)
			{
				SecondRenderComponent = dynamic_cast<IRenderableComponent*>(Component);
				if (SecondRenderComponent)
				{
					break;
				}
			}

			if (!SecondRenderComponent)
			{
				return 0;
			}

			return (FirstRenderComponent->ZOrder < SecondRenderComponent->ZOrder ? 1 : 0);
		}
	);
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

void UWorld::BeginPlay()
{
	for (auto Actor : Actors)
	{
		Actor->BeginPlay();
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
	GEngine->Clear();

	// 모든 Actor 중에서, Render 가능한 Component가 있으면 Render
	for (auto Actor : Actors)
	{		
		for (auto Component : Actor->Components)
		{
			IRenderableComponent* RenderComponent = dynamic_cast<IRenderableComponent*>(Component);
			if (RenderComponent && RenderComponent->bIsVisible)
			{
				RenderComponent->Render();
			}
		}
	}

	GEngine->Flip();
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

void UWorld::SortActors()
{
	//std::sort(Actors.begin(), Actors.end(), [](const AActor* A, const AActor* B)
	//	{
	//		// return ((A->GetZOrder() < B->GetZOrder()) ? true : false);
	//		return 1;
	//	});
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