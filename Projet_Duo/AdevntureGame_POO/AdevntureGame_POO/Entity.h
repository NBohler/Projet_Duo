#pragma once
#include "Utilities.h"
#include"Map.h"

enum Action
{
	MOVE_UP,
	MOVE_RIGHT,
	MOVE_DOWN,
	MOVE_LEFT,
	Attack
};

class Entity
{

	void move();

	bool collision() {};

	bool is_ennemy_here{};
};
