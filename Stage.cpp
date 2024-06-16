#include "Stage.h"
#include "Barrier.h"

void Stage::addBarrier(Barrier* b) {
	barriers.push_back(b);
}

std::vector<Barrier*>* Stage::getBarriers() {
	return &barriers;
}

void Stage::render() {
	for(std::vector<Barrier*>::iterator it = barriers.begin(); it != barriers.end(); it++) {
		(*it)->render();
	}
}

void Stage::cleanStage() {
	for(std::vector<Barrier*>::iterator it; it != barriers.end(); it++) {
		delete *it;
	}
}
