#include "stdafx.h"
#include "BGMComponent.h"

UBGMComponent::UBGMComponent()
	:Music(nullptr)
{
	
}

UBGMComponent::~UBGMComponent()
{
	Stop();
	if (Music)
	{
		Mix_FreeMusic(Music);
		Music = nullptr;
	}
}

void UBGMComponent::BeginPlay()
{
	
}

void UBGMComponent::Tick()
{

}

void UBGMComponent::LoadBGM(const std::string& InPath)
{
	if (Music)
	{
		Mix_FreeMusic(Music);
		Music = nullptr;
	}

	Music = Mix_LoadMUS(InPath.c_str());
	if (!Music)
	{
		SDL_Log("Mix_LoadMUS Error: %s\n", Mix_GetError());
	}
}

void UBGMComponent::Play(int InLoop)
{
	if (Music)
	{
		Mix_PlayMusic(Music, InLoop);
	}
}

void UBGMComponent::Stop()
{
	Mix_HaltMusic();
}

void UBGMComponent::Pause()
{
	Mix_PauseMusic();
}

void UBGMComponent::Resume()
{
	Mix_ResumeMusic();
}

void UBGMComponent::SetVolume(int InVolume)
{
	Mix_VolumeMusic(InVolume);
}