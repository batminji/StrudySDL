#pragma once
#include <vector>
#include <string>

class AActor;

class UWorld
{
public:
	UWorld();
	virtual ~UWorld();

	void Load(std::string MapName);
	template<typename ClassName>
	AActor* SpawnActor()
	{
		AActor* NewActor = new ClassName;
		Actors.push_back(NewActor);

		return NewActor;
	}

	void Tick();
	void Render();

protected:
	std::vector<AActor*> Actors;
};

