#include <raylib.h>
#include <string>

#include "Stage.h"
#include "InputManager.h"

class Player {
	// Components
	InputManager inputManager;

	// Visual
	std::string tag;
	Vector2 dimensions;

	// Physics
	Vector2 position;
	Vector2 velocity;
	float friction;
	int jumpForce;
	int acceleration;
	bool isGrounded;
	int maxJumps;
	int jumpCount;
	bool debug;

	// Dashing
	int dashSpeed;
	bool dashing;
	double dashDuration;
	bool dashCooldown;
	double dashCooldownDuration;
	double dashStartTime;

public: 
	Player(const char* t);

	void setPos(int x, int y);
	void setTag(const char* t);
	void update(float& deltaTime, Stage* currentStage);
	void checkForCollisions(Stage* currentStage);
	void render();

	InputManager* getInputManager();
};
