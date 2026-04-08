#pragma once
#include "Actor.h"

class UTextComponent;

class ATextRenderActor : public AActor
{
public:
	ATextRenderActor();
	virtual ~ATextRenderActor();

	UTextComponent* TextComponent;
};

