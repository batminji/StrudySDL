#include "stdafx.h"
#include "Engine.h"
#include "World.h"

// 사용할 라이브러리 파일 추가
#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

#define WINDOWW 640
#define WINDOWH 480

void DrawRect(SDL_Renderer* Renderer, Uint8 ColorR, Uint8 ColorG, Uint8 ColorB, int RectX, int RectY, int RectW, int RectH, bool bIsFill)
{
	SDL_SetRenderDrawColor(Renderer, ColorR, ColorG, ColorB, 255);
	SDL_Rect Rect = { RectX, RectY, RectW, RectH };
	if (bIsFill)
	{
		SDL_RenderFillRect(Renderer, &Rect);
	}
	else {
		SDL_RenderDrawRect(Renderer, &Rect);
	}
}

int SDL_main(int argc, char* argv[])
{
	bool bIsRunning = true;

	// Initialize
	SDL_Init(SDL_INIT_EVERYTHING);			// `SDL_INIT_EVERYTHING`: all of the above subsystems
	// Create Window
	SDL_Window* Window = SDL_CreateWindow("SDL Engine", 100, 100, WINDOWW, WINDOWH, SDL_WINDOW_SHOWN);
	// Create Renderer
	SDL_Renderer* Renderer = SDL_CreateRenderer(Window, -1, 0);
	
	// Running
	while (bIsRunning)
	{
		// Event Polling
		SDL_Event Event;
		SDL_PollEvent(&Event);

		switch (Event.type)
		{
		case SDL_QUIT:
			bIsRunning = false;
			break;
		default:
			break;
		}

		// Clear 
		SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
		SDL_RenderClear(Renderer);


		// Draw Rects
		int RectCounts = 100;
		for (int i = 0; i < RectCounts; ++i)
		{
			Uint8 ColorR = rand() % 255 + 1;
			Uint8 ColorG = rand() % 255 + 1;
			Uint8 ColorB = rand() % 255 + 1;

			int RectX = rand() % WINDOWW;
			int RectY = rand() % WINDOWH;
			int RectW = rand() % 100 + 1;
			int RectH = rand() % 100 + 1;

			int Fill = rand() % 2;
			
			DrawRect(Renderer, ColorR, ColorG, ColorB, RectX, RectY, RectW, RectH, Fill);
		}
		

		// Render Circle
		int CenterX = rand() % WINDOWW;
		int CenterY = rand() % WINDOWH;
		int Radius = rand() % 100 + 1;

		// Render
		SDL_RenderPresent(Renderer);
	}

	// Destroy Renderer
	SDL_DestroyRenderer(Renderer);
	// Destroy Window
	SDL_DestroyWindow(Window);

	// Quit (Terminate)
	SDL_Quit();
	return 0;
}

//int main()
//{
//	GEngine->GetWorld()->Load("NewLevel.txt");
//
//	GEngine->Run();
//
//	delete GEngine;
//
//	return 0;
//}