#pragma once

#include <raylib.h>
#include <raymath.h>

struct Barrier {
	Vector2 position;
	Vector2 dimensions;

	Barrier(float x, float y, float w, float h);
	void render();
};
