#pragma once
#include "SpriteComponent.h"

class USpriteAnimationComponent : public USpriteComponent
{
public:
	USpriteAnimationComponent();
	virtual ~USpriteAnimationComponent();

	virtual void Tick() override;
	virtual void Render() override;

	inline void SetTextureLocation(const FVector2D& InTextureLocation)
	{
		TextureLocation = InTextureLocation;
	}

protected:
	FVector2D TextureLocation;

	float DeltaSeconds = 0.0f;
};

