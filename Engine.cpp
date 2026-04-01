#include "stdafx.h"
#include "Engine.h"
#include "World.h"

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
	SDL_Init(SDL_INIT_EVERYTHING);
	Window = SDL_CreateWindow("SDL Engine", WINDOWX, WINDOWY, WINDOWW, WINDOWH, SDL_WINDOW_SHOWN);
	Renderer = SDL_CreateRenderer(Window, -1, 0);

	bIsRunning = true;
	World = new UWorld();

	InitBuffer();
}

void UEngine::Terminate()
{
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	SDL_Quit();

	delete World;
	World = nullptr;

	TermBuffer();
}

void UEngine::Run()
{
	while (bIsRunning)
	{
		SDL_PollEvent(&Event);

		Input();
		Tick();
		Render();
	}
}

void UEngine::InitBuffer()
{
	ScreenBufferHandle[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	ScreenBufferHandle[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	ConsoleCursorInfo.dwSize = 1;
	ConsoleCursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(ScreenBufferHandle[0], &ConsoleCursorInfo);
	SetConsoleCursorInfo(ScreenBufferHandle[1], &ConsoleCursorInfo);
}

void UEngine::Clear()
{
	DWORD DW;
	FillConsoleOutputCharacter(ScreenBufferHandle[ActiveScreenBufferIndex], ' ', 80 * 25, COORD{0, 0}, &DW);
}

void UEngine::Render(const FVector2D& InLocation, const char InMesh)
{
	char MeshString[2] = { 0, };
	MeshString[0] = InMesh;

	SetConsoleCursorPosition(ScreenBufferHandle[ActiveScreenBufferIndex], COORD{(short)(InLocation.X * 2), (short)InLocation.Y});
	WriteFile(ScreenBufferHandle[ActiveScreenBufferIndex], MeshString, 1, NULL, NULL);
}

void UEngine::Render(const FVector2D& InLocation, int InColorR, int InColorG, int InColorB)
{
	int TileSize = 50;

	SDL_SetRenderDrawColor(Renderer, InColorR, InColorG, InColorB, 255);
	SDL_RenderDrawPoint(Renderer, InLocation.X, InLocation.Y);

	SDL_Rect Rect = { InLocation.X * TileSize, InLocation.Y * TileSize, TileSize, TileSize };
	SDL_RenderFillRect(Renderer, &Rect);
}

void UEngine::Flip()
{
	SetConsoleActiveScreenBuffer(ScreenBufferHandle[ActiveScreenBufferIndex]);
	ActiveScreenBufferIndex = !ActiveScreenBufferIndex;
}

void UEngine::TermBuffer()
{
	CloseHandle(ScreenBufferHandle[0]);
	CloseHandle(ScreenBufferHandle[1]);
}

void UEngine::Input()
{
	
}

void UEngine::Tick()
{
	switch (Event.type)
	{
	case SDL_QUIT:
		bIsRunning = false;
		break;
	default:
		break;
	}

	World->Tick();
}

void UEngine::Render()
{
	// Clear
	SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
	SDL_RenderClear(Renderer);

	World->Render();

	// Render CPU->GPU
	SDL_RenderPresent(Renderer);
}