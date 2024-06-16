#pragma once

#include <array>
#include <raylib.h>
#include <type_traits>

#define ACTION_COUNT 11
typedef enum {
    ACTION_UP = 0,
	ACTION_DOWN = 1,
	ACTION_LEFT = 2,
	ACTION_RIGHT = 3,
	ACTION_DASH = 4,
	ACTION_CROUCH = 5,
	ACTION_JUMP = 6,
	ACTION_MAJOR_INTERACT = 7,
	ACTION_MINOR_INTERACT = 8,
	ACTION_MAJOR_ATTACK = 9,
	ACTION_MINOR_ATTACK = 10
} InputManagerActions;

class InputManager {
	std::array<int, ACTION_COUNT> keyBinds;
	bool useController;
	int gamepadID;
	float deadzone;

public:
	InputManager();

	bool getActionPressed(int action);
	bool getActionDown(int action);

	float getHorizontalAxis();
	float getVerticalAxis();

	void setBind(int action, int key);
	void setAllBinds(const int binds[]);

	void toggleGamepad();
	void setGamepadID(int g);
};
