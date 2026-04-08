#include "stdafx.h"
#include "ResourceManager.h"
#include "Engine.h"

UResourceManager::UResourceManager()
{
}

UResourceManager::~UResourceManager()
{
	for (auto Resource : Resources)
	{
		if (Resource.second.Surface)
		{
			SDL_FreeSurface(Resource.second.Surface);
		}
		if (Resource.second.Texture)
		{
			SDL_DestroyTexture(Resource.second.Texture);
		}
	}

	Resources.clear();
}

Resource* UResourceManager::LoadTexture(std::string FileName, bool bIsColorKey, Uint8 InColorR, Uint8 InColorG, Uint8 InColorB)
{
	if (Resources.find(FileName) == Resources.end())
	{
		Resource NewResource;
		NewResource.Surface = SDL_LoadBMP(FileName.c_str());

		if (bIsColorKey)
		{
			Uint32 ColorKey = SDL_MapRGB(NewResource.Surface->format, InColorR, InColorG, InColorB);

			SDL_SetColorKey(NewResource.Surface, SDL_TRUE, ColorKey);
		}

		NewResource.Texture = SDL_CreateTextureFromSurface(GEngine->GetRenderer(), NewResource.Surface);
		Resources[FileName] = NewResource;
	}	

	return &Resources[FileName];
}