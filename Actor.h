#pragma once
struct FVector2D
{
	int X;
	int Y;
};

class AActor
{
public:
	AActor(const FVector2D& InLocation = { 0, 0 }, const char InMesh = ' ');
	virtual ~AActor();

	virtual void BeginPlay();
	virtual void Tick();
	virtual void Render();

	void SetActorLocation(const FVector2D& NewLocation);
	void AddActorLocalOffset(const FVector2D& Offset);

protected:
	FVector2D Location;
	char Mesh;
};

