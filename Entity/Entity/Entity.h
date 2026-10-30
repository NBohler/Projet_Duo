#pragma once
#include "Utilites.h"

enum Action
{
	MOVE_UP,
	MOVE_RIGHT,
	MOVE_DOWN,
	MOVE_LEFT,
	Attack
};

static const Vector g_directions[4] = {
	{0,-1},  // Up
	{0, 1},  // Down
	{-1, 0}, // Left
	{1, 0}   // Right
};


class Entity
{

	void move() {};

	bool collision() {};

	bool is_ennemy_here{};
};