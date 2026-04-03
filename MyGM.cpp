#include "stdafx.h"
#include "MyGM.h"
#include "Engine.h"

AMyGM::AMyGM()
{
}

AMyGM::~AMyGM()
{
}

void AMyGM::GameOver()
{
	static bool bGameOver = false;

	if (!bGameOver)
	{
		GEngine->SetPrintString("Game Over");
		bGameOver = true;
	}
}

void AMyGM::GameComplete()
{
	static bool bGameComplte = false;

	if (!bGameComplte)
	{
		GEngine->SetPrintString("Game Complete");

		bGameComplte = true;
	}
}
