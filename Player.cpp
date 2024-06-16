#include <raylib.h>
#include <raymath.h>
#include <string>
#include <raylib.h>
#include <iostream>
#include <sys/select.h>

#include "Player.h"
#include "Globals.h"
#include "InputManager.h"
#include "Stage.h"

Player::Player(const char* t):
	inputManager(),
	tag(t),

	friction(0.92),
	jumpForce(-1000),
	acceleration(8500),
	isGrounded(false),
	maxJumps(2),
	jumpCount(0),
	debug(false),

	dashSpeed(2400),
	dashing(false),
	dashDuration(0.07),
	dashCooldown(false),
	dashCooldownDuration(0.75)
{
	position = {0.0f, 0.0f};
	velocity = {0.0f, 0.0f};
	dimensions = {25.0f, 50.0f};
}

void Player::update(float& deltaTime, Stage* currentStage) {
	// Horizontal movement
	float xaxis = inputManager.getHorizontalAxis();

	if(debug) {
		float yaxis = inputManager.getVerticalAxis();
		position.x += xaxis;
		position.y += yaxis;

		return;
	}

	if(!dashing) {
		velocity.x += acceleration * xaxis * deltaTime;
		velocity.x *= pow(friction, deltaTime * 128);
	}

	double currentTime = GetTime();
	if(!dashCooldown && inputManager.getActionDown(ACTION_DASH)) {
		velocity.x = dashSpeed * xaxis;
		velocity.y = 0.0f;
		dashing = true;
		dashCooldown = true;
		dashStartTime = currentTime;
	} else if(dashing && currentTime - dashStartTime > dashDuration) {
		dashing = false;
	} else if(currentTime - dashStartTime > dashCooldownDuration) {
		dashCooldown = false;
	}

	position.x += velocity.x * deltaTime;

	// Vertical movement
	if(!dashing) velocity.y += GRAVITY * deltaTime;

	if(jumpCount != 0 && (inputManager.getActionPressed(ACTION_JUMP) || inputManager.getActionPressed(ACTION_UP))) {
		velocity.y = jumpForce;
		isGrounded = false;
		jumpCount--;
	}

	position.y += velocity.y * deltaTime;

	checkForCollisions(currentStage);
}

void Player::checkForCollisions(Stage* currentStage) {
	std::vector<Barrier*>* barriers = currentStage->getBarriers();
	for(std::vector<Barrier*>::iterator it = barriers->begin(); it != barriers->end(); it++) {
		Barrier* b = *it;
		
		bool horizontalIntersection = position.x + dimensions.x > b->position.x && position.x < b->position.x + b->dimensions.x;
		bool verticalIntersection = position.y + dimensions.y > b->position.y && position.y < b->position.y + b->dimensions.y;

		if(horizontalIntersection && verticalIntersection) {
			int horizontalOffset = position.x + (dimensions.x / 2) < b->position.x + (b->dimensions.x / 2)
				? b->position.x - (position.x + dimensions.x) 
				: b->position.x + b->dimensions.x - position.x;
			int verticalOffset = position.y + (dimensions.y / 2) < b->position.y + (b->dimensions.y / 2)
				? b->position.y - (position.y + dimensions.y)
				: b->position.y + b->dimensions.y - position.y;

			if(std::abs(horizontalOffset) < std::abs(verticalOffset)) {
				position.x += horizontalOffset;
				velocity.x = 0;
			} else {
				position.y += verticalOffset;
				if(velocity.y > 0 && verticalOffset < 0) {
					isGrounded = true;
					jumpCount = maxJumps;
				} 
				velocity.y = 0;
			}
		}
	}
}

void Player::render() {
	DrawRectangle(position.x, position.y, dimensions.x, dimensions.y, (dashing ? BLUE : (dashCooldown ? GRAY : BLACK)));
	DrawText(tag.c_str(), position.x - 35, position.y - 25, 24, BLACK);
}

void Player::setPos(int x, int y) {
	position.x = x;
	position.y = y;
}

void Player::setTag(const char* t) {
	tag = std::string(t);
}

InputManager* Player::getInputManager() {
	return &inputManager;
}
