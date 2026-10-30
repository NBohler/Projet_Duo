#pragma once
#include <vector>
enum Move
{
	MOVE_UP,
	MOVE_RIGHT,
	MOVE_DOWN,
	MOVE_LEFT,

};

static const Vector g_directions[4] = {
	{0,-1},  // Up
	{0, 1},  // Down
	{-1, 0}, // Left
	{1, 0}   // Right
};


class Entity
{
	struct Entities 
	{
		pos = Vector;
	};
	void move() {};

	void collision() {};
};