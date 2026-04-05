#pragma once
#include "Component.h"
class UBGMComponent : public UComponent
{
public:
	UBGMComponent();
	virtual ~UBGMComponent();

	virtual void BeginPlay() override;
	virtual void Tick() override;

	void LoadBGM(const std::string& InPath);

	void Play(int InLoop = -1);
	void Stop();
	void Pause();
	void Resume();

	void SetVolume(int InVolume);

protected:
	Mix_Music* Music;
};

