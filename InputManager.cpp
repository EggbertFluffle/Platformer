#include "InputManager.h"

#include <raylib.h>
#include <cstdlib>
#include <array>

InputManager::InputManager(): 
	useController(false),
	gamepadID(0),
	deadzone(0.25) {}

void InputManager::toggleGamepad() {
	useController = !useController;
}

void InputManager::setGamepadID(int g) {
	gamepadID = g;
}

float InputManager::getHorizontalAxis() {

	if(useController) {
		float t = GetGamepadAxisMovement(gamepadID, GAMEPAD_AXIS_LEFT_X);
		return (std::abs(t) > deadzone ? (t > 0 ? 1.0f : -1.0f) : 0);
	}
	return (getActionDown(ACTION_LEFT) ? -1 : 0) + (getActionDown(ACTION_RIGHT) ? 1 : 0);
}

float InputManager::getVerticalAxis() {
	if(useController) {
		float t = GetGamepadAxisMovement(gamepadID, 1);
		return (std::abs(t) > deadzone ? (t > 0 ? 1.0f : -1.0f) : 0);
	}
	return (getActionDown(ACTION_DOWN) ? 1 : 0) + (getActionDown(ACTION_UP) ? -1 : 0);
}

bool InputManager::getActionPressed(int action) {
	return (bool)IsKeyPressed(keyBinds[action]);
}

bool InputManager::getActionDown(int action) {
	return (bool)IsKeyDown(keyBinds[action]);
}

void InputManager::setAllBinds(const int binds[]) {
	for(int i = 0; i < ACTION_COUNT;i++) {
		keyBinds[i] = binds[i];
	}
}

void InputManager::setBind(int action, int key) {
	keyBinds[action] = key;
}
