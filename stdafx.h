#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <Windows.h>
#include <algorithm>
#include <random>

// SDL
#include "SDL.h"
#include "SDL_main.h"
#pragma comment(lib, "SDL2")
#pragma comment(lib, "SDL2main")

// Struct
#include "FVector.h"

#define WINDOWX 50
#define WINDOWY 50
#define WINDOWW 600
#define WINDOWH 600

//std::random_device RandomDevice;
//std::default_random_engine dre(RandomDevice());
//
//std::uniform_int_distribution<int> uidX(0, WINDOWW);
//std::uniform_int_distribution<int> uidY(0, WINDOWH);
//std::uniform_int_distribution<int> uidW(0, 30);
//std::uniform_int_distribution<int> uidH(0, 30);
//std::uniform_int_distribution<int> uidRadius(0, 30);
//
//std::uniform_int_distribution<int> uidR(0, 255);
//std::uniform_int_distribution<int> uidG(0, 255);
//std::uniform_int_distribution<int> uidB(0, 255);