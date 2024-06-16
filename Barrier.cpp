#include "Barrier.h"

#include <raymath.h>

Barrier::Barrier(float x, float y, float w, float h) {
	position = {x, y};
	dimensions = {w, h};
}

void Barrier::render() {
	DrawRectangleV(position, dimensions, BLACK);
}
