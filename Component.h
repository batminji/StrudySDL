#pragma once

class AActor;

class UComponent
{
public:
	UComponent();
	virtual ~UComponent();

	virtual void BeginPlay() = 0;
	virtual void Tick() = 0;

	inline void SetOwner(AActor* InOwner)
	{
		Owner = InOwner;
	}

	inline AActor* GetOwner() const
	{
		return Owner;
	}

protected:
	class AActor* Owner;
};

