#pragma once
#include <vector>
#include <string>

class AActor;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	void Load(const std::string MapName);

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
	std::vector<AActor*> Actors;
};

