#pragma once

struct Button {
	bool pressed = false;
	//bool changed = false;
};

enum {
	BUTTON_UP,
	BUTTON_DOWN,
	BUTTON_COUNT

};

struct Input
{
	Button keyboard[BUTTON_COUNT];
};
