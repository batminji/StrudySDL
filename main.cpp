#include "stdafx.h"
#include "Engine.h"
#include "World.h"

// 사용할 라이브러리 파일 추가

int SDL_main(int argc, char* argv[])
{
	GEngine->GetWorld()->Load("NewLevel.txt");

	GEngine->Run();

	delete GEngine;

	return 0;
}