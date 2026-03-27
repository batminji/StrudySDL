#pragma once

class AActor
{
public:
	AActor(const FVector2D& InLocation = { 0, 0 }, const char InMesh = ' ', const int InZorder = 0);
	virtual ~AActor();

	virtual void BeginPlay();
	virtual void Tick();
	virtual void Render();

	void SetActorLocation(const FVector2D& NewLocation);
	inline const FVector2D GetActorLocation() const
	{
		return Location;
	}
	void AddActorLocalOffset(const FVector2D& Offset);

	inline const int GetZOrder() const
	{
		return ZOrder;
	}

protected:
	FVector2D Location;
	int ZOrder;
	char Mesh;
};

