#pragma once
#include "../src/engine/Engine.h"
#include <iostream>
#include "SDL/SDL.h"
#include "../src/engine/Vector/Vector2.h"
#include "../src/engine/Color/Color.h"
#include <string>

class Debug
{
public:
	static void Log(std::string str);

	static void DrawLine(Vector2 a, Vector2 b);
	static void DrawLine(Vector2 a, Vector2 b, Color color);
};