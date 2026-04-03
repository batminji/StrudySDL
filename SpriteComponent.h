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

	int ZOrder;

	FVector2D Location;

	Resource* MyResource;
	FVector2D TextureSize;
};

