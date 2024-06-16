#include "App.h"
#include "Globals.h"

#include <raylib.h>

App::App() {
	InitWindow(WIDTH, HEIGHT, "Fighter");

	SetTargetFPS(120);
	SetExitKey(KEY_Q);
}

void App::run() {
	while (!WindowShouldClose()) {
		gameManager.update();

		BeginDrawing();
		ClearBackground(RAYWHITE);

		gameManager.render();
		drawDebug();

		EndDrawing();
	}
}

void App::drawDebug() {
	DrawFPS(0, 0);
}
