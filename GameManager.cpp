#include "GameManager.h"
#include "Globals.h"
#include "Stage.h"

GameManager::GameManager() {
	currentStage = new Stage();
	currentStage->addBarrier(new Barrier(0, HEIGHT - 10, WIDTH, 10));
	currentStage->addBarrier(new Barrier(-10, 0, 20, HEIGHT));
	currentStage->addBarrier(new Barrier(WIDTH - 10, 0, 20, HEIGHT));

	currentStage->addBarrier(new Barrier(0, HEIGHT - 100, 250, 250));
	currentStage->addBarrier(new Barrier(950, 100, 25, 750));

	players.push_back(new Player("Eggbert"));
	players[0]->setPos(WIDTH / 2, HEIGHT / 2);
	players[0]->getInputManager()->setAllBinds(DEFAULT_BINDS);
}

void GameManager::update() {
	float deltaTime = GetFrameTime();
	for(Player* player : players) {
		player->update(deltaTime, currentStage);
	}
}

void GameManager::render() {
	for(Player* player : players) {
		player->render();
	}
	currentStage->render();
}
