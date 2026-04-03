#pragma once

class UComponent;

class AActor
{
public:
	AActor(const FVector2D& InLocation = { 0, 0 }, const char InMesh = ' ');
	virtual ~AActor();

	virtual void BeginPlay();
	virtual void Tick();
	// virtual void Render();

	void SetActorLocation(const FVector2D& NewLocation);
	inline FVector2D GetActorLocation() const
	{
		return Location;
	}
	inline FVector2D GetActorTextureLocation() const
	{
		return TextureLocation;
	}

	void AddActorLocalOffset(const FVector2D& Offset);

	std::vector<UComponent*> Components;

protected:
	FVector2D Location;
	FVector2D TextureLocation;

	template<typename T>
	T* CreateDefaultSubObject(std::string ComponentName)
	{
		T* Temp = new T;
		Temp->Owner = this;
		Components.push_back(Temp);

		return Temp;
	}

	char Mesh;
};

