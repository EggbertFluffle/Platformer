#pragma once

#include <vector>

#include "Player.h"
#include "Stage.h"

class GameManager {
	std::vector<Player*> players;
	Stage* currentStage;

public:
	GameManager();

	void update();
	void render();
};
