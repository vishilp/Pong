#pragma once

struct Button {
	bool pressed;
	bool changed;
};

enum {
	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_LEFT,
	BUTTON_RIGHT,
	BUTTON_COUNT

};

struct Input
{
	Button keyboard[BUTTON_COUNT];
};
