#include "stdafx.h"
#include "BGActor.h"
#include "AudioComponent.h"

ABGActor::ABGActor()
{
	Audio = CreateDefaultSubObject<UAudioComponent>("Audio");
	Audio->Load("./Data/bgm.mp3");
}

ABGActor::~ABGActor()
{
	
}

void ABGActor::BeginPlay()
{
	__super::BeginPlay();

	Audio->Play();
}
