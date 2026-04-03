#include "stdafx.h"
#include "Engine.h"
#include "World.h"
#include "MyGM.h"

int SDL_main(int argc, char* argv[])
{
	GEngine->GetWorld()->SetGameMode(new AMyGM());

	GEngine->GetWorld()->Load("NewLevel.txt");

	GEngine->Run();

	delete GEngine;

	return 0;
}