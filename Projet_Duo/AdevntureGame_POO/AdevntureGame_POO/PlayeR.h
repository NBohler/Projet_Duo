#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(int life) : Entity(life) {}
	Action playerInput();    // Utilisé pour recuperer l'action du joueurs 
	void getCollision() override;
	void virtual playerMove(Vector2 dir);
};

class Warrior : public Player
{
public:
	Warrior() : Player(4) {};
	void isAlive();

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
