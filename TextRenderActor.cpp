#include "stdafx.h"
#include "TextRenderActor.h"
#include "TextComponent.h"


ATextRenderActor::ATextRenderActor()
{
	TextComponent = CreateDefaultSubObject<UTextComponent>("TextRender");

}

ATextRenderActor::~ATextRenderActor()
{
}
