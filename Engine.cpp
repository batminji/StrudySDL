#include "stdafx.h"
#include "Engine.h"
#include "World.h"

UEngine* UEngine::Instance = nullptr;
int UEngine::KeyCode = 0;

UEngine::UEngine()
{
	Init();
}

UEngine::~UEngine()
{
	Terminate();
}

void UEngine::Init()
{
	bIsRunning = true;
	World = new UWorld();
}

void UEngine::Terminate()
{
	delete World;
	World = nullptr;
}

void UEngine::Run()
{
	while (bIsRunning)
	{
		Input();
		Tick();
		Render();
	}
}

void UEngine::Input()
{
	KeyCode = _getch();
	if (KeyCode == 'f')
	{
		GEngine->GetWorld()->Save("SaveLevel.txt");
	}
	if (KeyCode == 'q')
	{
		bIsRunning = false;
	}
}

void UEngine::Tick()
{
	World->Tick();
}

void UEngine::Render()
{
	World->Render();
}