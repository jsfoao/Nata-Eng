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
	static void Log(float a);
	static void Log(int a);
	static void Log(Vector2 vec);

	static void DrawLine(Vector2 a, Vector2 b);
	static void DrawLine(Vector2 a, Vector2 b, Color color);

	static void DrawRay(Vector2 point, Vector2 direction);
	static void DrawRay(Vector2 point, Vector2 direction, Color color);

	static void DrawSquareWire(Vector2 pos, Vector2 scale);
	static void DrawSquareWire(Vector2 pos, Vector2 scale, Color color);
	static void DrawSquareFill(Vector2 pos, Vector2 scale);
	static void DrawSquareFill(Vector2 pos, Vector2 scale, Color color);

	static void DrawCircleWire(Vector2 pos, float radius, int resolution);
	static void DrawCircleWire(Vector2 pos, float radius, int resolution, Color color);
};