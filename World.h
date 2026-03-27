#pragma once

class AActor;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	void Load(const std::string MapName);
	void Save(const std::string SaveFileName);

	template<typename ClassName>
	AActor* SpawnActor()
	{
		AActor* NewActor = new ClassName;
		Actors.push_back(NewActor);

		return NewActor;
	}

	void Tick();
	void Render();

	inline std::vector<AActor*>& GetAllActorsOfClass()
	{
		return Actors;
	}

protected:
	const FVector2D& GetMaxMapSize() const;
	void SaveActors(std::vector<std::string>& MapBuffer);
	void SortActors();

	std::vector<AActor*> Actors;
};

