#pragma once
#include "Entity.h"

class Player : Entity
{
	Action playerInput();    // Utilisé pour recuperer l'action du joueurs 
	void getCollision();
	void virtual playerMove(Vector2 dir);
};

class Warrior : Player
{
	int life_point = 4;
	void isAlive();

};

class Mage : Player
{
	int life_point = 1;
};

class WarriorMage : Player
{
	int life_point = 4;
};
