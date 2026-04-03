#pragma once
#include "Component.h"
#include "RenderableComponent.h"

class USpriteComponent : public UComponent, public IRenderableComponent
{
public:
	USpriteComponent();
	virtual ~USpriteComponent();

	virtual void BeginPlay() override;
	virtual void Tick() override;

	virtual void Render() override;

	inline void SetZOrder(const int InZOrder)
	{
		ZOrder = InZOrder;
	}

	inline int const GetZOrder() const
	{
		return ZOrder;
	}

	inline void SetLocation(const FVector2D InLocation)
	{
		Location = InLocation;
	}

	inline void SetResource(Resource* InResource)
	{
		MyResource = InResource;
	}

	inline void SetTextureSize(const FVector2D InTextureSize)
	{
		TextureSize = InTextureSize;
	}

protected:
	int ZOrder;

	FVector2D Location;

	Resource* MyResource;
	FVector2D TextureSize;
};

