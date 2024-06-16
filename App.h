#pragma once

#include "GameManager.h"

class App {
	GameManager gameManager;

public:
	App();

	void run();
	void drawDebug();
};
