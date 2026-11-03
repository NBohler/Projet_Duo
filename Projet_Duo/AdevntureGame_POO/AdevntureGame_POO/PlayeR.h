#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(int life) : Entity(life) {}
	Action playerInput();
};

class Warrior : public Player
{
public:
	Warrior() : Player(4) {};
};

class Mage : public Player
{
public:
	Mage() : Player(1) {};
};

class WarriorMage : public Player
{
public:
	WarriorMage() : Player(4) {};
};

