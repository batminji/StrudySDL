#pragma once
#include "Component.h"
class UCollisionComponent : public UComponent
{
public:
	UCollisionComponent();
	~UCollisionComponent();

	virtual void BeginPlay() override;
	virtual void Tick() override;

	inline void SetbIsGenerateOverlap(int InbIsGenerateOverlap)
	{
		bIsGenerateOverlap = InbIsGenerateOverlap;
	}

	inline void SetbIsGenerateHit(int InbIsGenerateHit)
	{
		bIsGenerateHit = InbIsGenerateHit;
	}

	inline int GetbIsGenerateOverlap() const
	{
		return bIsGenerateOverlap;
	}

	inline int GetbIsGenerateHit() const
	{
		return bIsGenerateHit;
	}


protected:
	int bIsGenerateOverlap : 1;

	int bIsGenerateHit : 1;
};

