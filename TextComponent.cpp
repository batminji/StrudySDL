#include "stdafx.h"
#include "TextComponent.h"
#include "Engine.h"
#include "Actor.h"

UTextComponent::UTextComponent()
	: Text("Hello World"), Color({ 255, 255, 255, 255 }), Offset({0, 0})
{
	MyResource = new Resource();
	MyResource->Surface = nullptr;
	MyResource->Texture = nullptr;
	
}

UTextComponent::~UTextComponent()
{
	if (MyResource)
	{
		if (MyResource->Surface)
		{
			SDL_FreeSurface(MyResource->Surface);
		}
		if (MyResource->Texture)
		{
			SDL_DestroyTexture(MyResource->Texture);
		}
		
		delete MyResource;
		MyResource = nullptr;
	}
}

void UTextComponent::BeginPlay()
{
}

void UTextComponent::Tick()
{
}

void UTextComponent::Render()
{
	if (MyResource && MyResource->Texture)
	{
		FVector2D Temp = { Owner->GetActorLocation().X + Offset.X, Owner->GetActorLocation().Y + Offset.Y };
		GEngine->Render(Temp, MyResource->Texture, MyResource->Surface->w, MyResource->Surface->h);
	}
}

void UTextComponent::SetText(const std::string& InText)
{
	Text = InText;
	UpdateTextResource();
}

void UTextComponent::ResetResource()
{
	if (MyResource)
	{
		if (MyResource->Texture)
		{
			SDL_DestroyTexture(MyResource->Texture);
		}
		if (MyResource->Surface)
		{
			SDL_FreeSurface(MyResource->Surface);
		}
	}
}

void UTextComponent::UpdateTextResource()
{
	if (Text.empty())
	{
		return;
	}

	ResetResource();

	// TTF¸¦ ÀÐ¾î¼­ ºñÆ®¸ÊÀ¸·Î ¸¸µê -> Surface
	MyResource->Surface = TTF_RenderText_Solid(GEngine->GetFont(), Text.c_str(), Color);
	// Surface¸¦ Texture·Î ¸¸µê
	MyResource->Texture = SDL_CreateTextureFromSurface(GEngine->GetRenderer(), MyResource->Surface);
}
