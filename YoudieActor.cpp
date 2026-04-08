#include "stdafx.h"
#include "YoudieActor.h"
#include "TextComponent.h"

AYoudieActor::AYoudieActor()
{
	TextComponent->SetText("You Died.");
	Location = { 200, 150 };
}

AYoudieActor::~AYoudieActor()
{
}
