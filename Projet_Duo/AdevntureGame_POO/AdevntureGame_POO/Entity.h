#pragma once
#include "Utilities.h"

enum Action
{
	None = 0,
	MOVE_UP,
	MOVE_RIGHT,
	MOVE_DOWN,
	MOVE_LEFT,
	Attack
};

static const Vector2 g_directions[4] = 
{
	{0,-1},  // Up
	{0, 1},  // Down
	{-1, 0}, // Left
	{1, 0}   // Right
};

class Entity 
{
	void move();	      // Va gérer les déplacements 
	void virtual getCollision();	 // Permet de faire les collisions 
	void isAlive(Entity character);		//Vérification de si le joueur ou l'ennemi est en vie 
	void takeDamage(); //Permet au joueur et aux ennemies de prendres des dégats 
	Vector2 getDirection();
public:
	int life_point = 1;
};

