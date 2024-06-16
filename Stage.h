#pragma once

#include "Barrier.h"

#include <vector>

class Stage {
	std::vector<Barrier*> barriers;

public: 
	void addBarrier(Barrier* b);
	std::vector<Barrier*>* getBarriers();
	void render();

	void cleanStage();
};
