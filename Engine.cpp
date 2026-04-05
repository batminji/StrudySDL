#include "stdafx.h"
#include "Engine.h"
#include "ResourceManager.h"
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
	// TTF Init
	TTF_Init();
	// BGM Init
	Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

	Window = SDL_CreateWindow("SDL Engine", WINDOWX, WINDOWY, WINDOWW, WINDOWH, SDL_WINDOW_SHOWN);
	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

	State = SDL_GetKeyboardState(NULL);

	ResourceManager = new UResourceManager();

	bIsRunning = true;
	World = new UWorld();
	TileSize = World->GetTileSize();

	InitBuffer();
}

void UEngine::Terminate()
{
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	SDL_Quit();

	delete World;
	World = nullptr;

	delete ResourceManager;
	ResourceManager = nullptr;

	TermBuffer();
}

void UEngine::Run()
{
	World->BeginPlay();

	while (bIsRunning)
	{
		LastTime = SDL_GetTicks();

		SDL_PollEvent(&Event);

		Input();
		Tick();
		Render();

		DeltaSeconds = (float)(SDL_GetTicks() - LastTime) / 1000.f;

		// SDL_Log("%f", DeltaSeconds);
	}
}

void UEngine::Stop()
{
	bIsRunning = false;
}

void UEngine::InitBuffer()
{
	// Console Double Buffuring
	// ScreenBufferHandle[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	// ScreenBufferHandle[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	// 
	// CONSOLE_CURSOR_INFO ConsoleCursorInfo;
	// ConsoleCursorInfo.dwSize = 1;
	// ConsoleCursorInfo.bVisible = FALSE;
	// SetConsoleCursorInfo(ScreenBufferHandle[0], &ConsoleCursorInfo);
	// SetConsoleCursorInfo(ScreenBufferHandle[1], &ConsoleCursorInfo);
}

void UEngine::Clear()
{
	// Clear
	SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
	SDL_RenderClear(Renderer);

	// Console Clear
	// DWORD DW;
	// FillConsoleOutputCharacter(ScreenBufferHandle[ActiveScreenBufferIndex], ' ', 80 * 25, COORD{0, 0}, &DW);
}

void UEngine::Render(const FVector2D& InLocation, const char InMesh)
{
	// Console Render
	// char MeshString[2] = { 0, };
	// MeshString[0] = InMesh;
	// 
	// SetConsoleCursorPosition(ScreenBufferHandle[ActiveScreenBufferIndex], COORD{(short)(InLocation.X * 2), (short)InLocation.Y});
	// WriteFile(ScreenBufferHandle[ActiveScreenBufferIndex], MeshString, 1, NULL, NULL);
}

void UEngine::Render(const FVector2D& InLocation, int InColorR, int InColorG, int InColorB)
{
	SDL_SetRenderDrawColor(Renderer, InColorR, InColorG, InColorB, 255);
	SDL_RenderDrawPoint(Renderer, InLocation.X, InLocation.Y);

	SDL_Rect Rect = { InLocation.X * TileSize, InLocation.Y * TileSize, TileSize, TileSize };
	SDL_RenderFillRect(Renderer, &Rect);
}

void UEngine::Render(const FVector2D& InLocation, SDL_Texture* InTexture, const FVector2D& InTextureLocation, const FVector2D& InTextureSize)
{
	SDL_Rect SRCRect = { InTextureLocation.X * InTextureSize.X, InTextureLocation.Y * InTextureSize.Y, InTextureSize.X, InTextureSize.Y };
	SDL_Rect DSTRect = { InLocation.X * TileSize, InLocation.Y * TileSize, TileSize, TileSize };
	SDL_RenderCopy(Renderer, InTexture, &SRCRect, &DSTRect);
}

void UEngine::Render(const FVector2D& InLocation, SDL_Texture* InTextTexture, int InX, int InY)
{
	SDL_Rect DSTRect = {InLocation.X * TileSize, InLocation.Y * TileSize, InX, InY};
	SDL_RenderCopy(Renderer, InTextTexture, NULL, &DSTRect);
}

void UEngine::Flip()
{
	// Buffer Flip
	// SetConsoleActiveScreenBuffer(ScreenBufferHandle[ActiveScreenBufferIndex]);
	// ActiveScreenBufferIndex = !ActiveScreenBufferIndex;
}

void UEngine::TermBuffer()
{
	// CloseHandle(ScreenBufferHandle[0]);
	// CloseHandle(ScreenBufferHandle[1]);
}

void UEngine::Input()
{
	
}

void UEngine::Tick()
{
	if (Event.type == SDL_KEYDOWN)
	{
		SDL_Keycode KeyCode = Event.key.keysym.sym;
		if (KeyCode == SDL_QUIT)
		{
			bIsRunning = false;
		}
		if (KeyCode == SDLK_ESCAPE)
		{
			bIsRunning = false;
		}
	}

	World->Tick();
}

void UEngine::Render()
{
	World->Render();

	SDL_RenderPresent(Renderer);
}