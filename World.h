#pragma once

class AActor;
class AGameMode;

class UBGMComponent;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	void SetGameMode(AGameMode* NewGameMode);

	void Load(const std::string MapName);
	void Save(const std::string SaveFileName);

	template<typename ClassName>
	AActor* SpawnActor()
	{
		AActor* NewActor = new ClassName;
		Actors.emplace_back(NewActor);
		NewActor->SetWorld(this);

		return NewActor;
	}

	void BeginPlay();
	void Tick();
	void Render();

	template<typename T>
	AActor* GetActorOfClass()
	{
		for (auto Actor : Actors)
		{
			T* Target = dynamic_cast<T*>(Actor);
			if (Target)
			{
				return Target;
			}
		}
		return nullptr;
	}

	template<typename T>
	std::vector<AActor*> GetActorsOfClass()
	{
		std::vector<AActor*> TempActors{};
		for (auto Actor : Actors)
		{
			T* Target = dynamic_cast<T*>(Actor);
			if (Target)
			{
				TempActors.emplace_back(Target);
			}
		}
		return TempActors;
	}

	inline std::vector<AActor*>& GetAllActorsOfClass()
	{
		return Actors;
	}

	inline const int GetTileSize() const
	{
		return TileSize;
	}

	void PlayBGM(const std::string& InPath);
	void StopBGM();

protected:
	int TileSize = 50;

	const FVector2D& GetMaxMapSize() const;
	void SaveActors(std::vector<std::string>& MapBuffer);
	void SortActors();

	std::vector<AActor*> Actors;

	UBGMComponent* BGMComponent;
};

