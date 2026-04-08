#pragma once
#include "Component.h"
#include "RenderableComponent.h"

class UTextComponent : public UComponent, public IRenderableComponent
{
public:
	UTextComponent();
	virtual ~UTextComponent();

	virtual void BeginPlay() override;
	virtual void Tick() override;
	virtual void Render() override;

	void SetText(const std::string& InText);

	inline void SetColor(SDL_Color InColor)
	{
		Color = InColor;
		UpdateTextResource();
	}
	inline void SetOffset(const FVector2D& InOffset)
	{
		Offset = InOffset;
	}
	inline void SetZOrder(const int InZOrder)
	{
		ZOrder = InZOrder;
	}

protected:
	std::string Text;
	SDL_Color Color;
	FVector2D Offset;

	Resource* MyResource;
	void ResetResource();

	int ZOrder;

	void UpdateTextResource();
};

