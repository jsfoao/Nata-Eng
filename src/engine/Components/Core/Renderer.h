#pragma once
#include "../../ECS/ECS.h"
#include "../../Color/Color.h"

enum class RenderLayer
{
	Default,
	Background,
	Player,
	Foreground,
	Gizmo,
	UI
};

class Renderer : public Component
{
public:
	RenderLayer renderLayer = RenderLayer::Default;
	Color color;
	Color outlineColor;
	bool outline;

public:
	Renderer();
	~Renderer();
	void render() override;
};