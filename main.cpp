#include "stdafx.h"
#include "Engine.h"
#include "World.h"

// 사용할 라이브러리 파일 추가
#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

#define WINDOWX 500
#define WINDOWY 500
#define WINDOWW 640
#define WINDOWH 480

std::random_device RandomDevice;
std::default_random_engine dre(RandomDevice());

std::uniform_int_distribution<int> uidX(0, WINDOWW);
std::uniform_int_distribution<int> uidY(0, WINDOWH);
std::uniform_int_distribution<int> uidW(0, 30);
std::uniform_int_distribution<int> uidH(0, 30);
std::uniform_int_distribution<int> uidRadius(0, 30);

std::uniform_int_distribution<int> uidR(0, 255);
std::uniform_int_distribution<int> uidG(0, 255);
std::uniform_int_distribution<int> uidB(0, 255);

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

void NewDrawCircle(SDL_Renderer* Renderer, Uint8 ColorR, Uint8 ColorG, Uint8 ColorB, int CenterX, int CenterY, int Radius, bool bIsFill)
{
	SDL_SetRenderDrawColor(Renderer, ColorR, ColorG, ColorB, 255);

	for (int Theta = 0; Theta < 360; ++Theta)
	{
		float Radian = (float)Theta + 3.14f / 180.0f;
		int X = 10 * SDL_cos(Theta) + CenterX;
		int Y = 10 * SDL_sin(Theta) + CenterY;
		SDL_RenderDrawPoint(Renderer, X, Y);
	}
}

void DrawCircleTeacher(SDL_Renderer* Renderer)
{
	SDL_SetRenderDrawColor(Renderer, 255, 0, 0, 0);

	int Radius = 200;
	int CenterX = 500;
	int CenterY = 500;
	int Size = 15;

	for (int Theta = 0; Theta <= 360; Theta += Size)
	{
		float Radian1 = (float)Theta * 3.141592f / 180.0f;
		float Radian2 = (float)(Theta + Size) * 3.141592f / 180.0f;
		int X1 = Radius * SDL_cos(Radian1) + CenterX;
		int Y1 = Radius * SDL_sin(Radian1) + CenterY;
		int X2 = Radius * SDL_cos(Radian2) + CenterX;
		int Y2 = Radius * SDL_sin(Radian2) + CenterY;
		//SDL_RenderDrawPoint(MyRender, X, Y);
		SDL_RenderDrawLine(Renderer, X1, Y1, X2, Y2);
	}
}

void DrawCircle(SDL_Renderer* Renderer, Uint8 ColorR, Uint8 ColorG, Uint8 ColorB, int CenterX, int CenterY, int Radius, bool bIsFill) {
	SDL_SetRenderDrawColor(Renderer, ColorR, ColorG, ColorB, 255);

	for (int Y = -Radius; Y <= Radius; ++Y) {
		for (int X = -Radius; X <= Radius; ++X) {

			int Distance = SDL_sqrt(X * X + Y * Y);

			if (bIsFill) {
				if (Distance <= Radius) {
					SDL_RenderDrawPoint(Renderer, CenterX + X, CenterY + Y);
				}
			}
			else {
				int InnerRadius = Radius - 1;
				if (Distance <= Radius && Distance > InnerRadius) {
					SDL_RenderDrawPoint(Renderer, CenterX + X, CenterY + Y);
				}
			}
		}
	}
}

void DrawWave(SDL_Renderer* Renderer, int CenterX, int CenterY, float Radius, float Time) {
	float WaveFrequency = 10.0f;		// 파동의 빈도 (얼마나 촘촘한가)
	float WaveSpeed = 30.0f;			// 파동의 속도
	float WaveSharpness = 4.0f;			// 파동의 날카로움


	for (int Y = -Radius; Y <= Radius; ++Y) {
		for (int X = -Radius; X <= Radius; ++X) {
			
			float DX = (float)X / Radius;
			float DY = (float)Y / Radius;
			float Distance = SDL_sqrt(DX * DX + DY * DY);

			if (Distance < 0.5f) {
				float falloff = 2.0f * (0.5f - Distance);
				falloff = SDL_max(0.0f, SDL_min(1.0f, falloff));

				float WaveAngle = (Distance * WaveSharpness * M_PI * WaveFrequency) - (Time * WaveSpeed);
				float WaveIntensity = falloff * sin(WaveAngle);

				Uint8 ColorValue = static_cast<Uint8>((WaveIntensity * 0.5f + 0.5f) * 255);

				SDL_SetRenderDrawColor(Renderer, ColorValue / 2, ColorValue / 2, ColorValue, 255);
				SDL_RenderDrawPoint(Renderer, CenterX + X, CenterY + Y);
			}
		}
	}
}

int SDL_main(int argc, char* argv[])
{
	bool bIsRunning = true;
	float Time = 0.0f;

	// Initialize
	SDL_Init(SDL_INIT_EVERYTHING);			// `SDL_INIT_EVERYTHING`: all of the above subsystems
	// Create Window
	SDL_Window* Window = SDL_CreateWindow("SDL Engine", WINDOWX, WINDOWY, WINDOWW, WINDOWH, SDL_WINDOW_SHOWN);
	// Create Renderer
	SDL_Renderer* Renderer = SDL_CreateRenderer(Window, -1, 0);
	
	// Running
	while (bIsRunning)
	{
		Time += 0.016f;

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

		DrawWave(Renderer, WINDOWW / 2, WINDOWH / 2, 400.0f, Time);

		// Draw Rects
		int RectCounts = 0;
		for (int i = 0; i < RectCounts; ++i)
		{
			Uint8 ColorR = uidR(dre);
			Uint8 ColorG = uidG(dre);
			Uint8 ColorB = uidB(dre);

			int RectX = uidX(dre);
			int RectY = uidY(dre);
			int RectW = uidW(dre);
			int RectH = uidH(dre);

			bool bIsFill = rand() % 2;
			
			DrawRect(Renderer, ColorR, ColorG, ColorB, RectX, RectY, RectW, RectH, bIsFill);
		}
		
		// Draw Circle
		int CircleCounts = 0;
		for (int i = 0; i < CircleCounts; ++i)
		{
			Uint8 ColorR = uidR(dre);
			Uint8 ColorG = uidG(dre);
			Uint8 ColorB = uidB(dre);

			int CenterX = uidX(dre);
			int CenterY = uidY(dre);
			int Radius = uidRadius(dre);

			bool bIsFill = rand() % 2;

			DrawCircle(Renderer, ColorR, ColorG, ColorB, CenterX, CenterY, Radius, bIsFill);
			//DrawCircle(Renderer, 255, 0, 0, 100, 100, 100, 50, false);
		}

		// Render CPU -> GPU
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