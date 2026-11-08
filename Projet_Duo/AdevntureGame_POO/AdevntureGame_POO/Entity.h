#pragma once
#include "Utilities.h"
#include "Map.h"

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
	{0, -1},  // Up
	{1, 0},  // Right
	{0, 1},  // Down
	{-1, 0}, // Left
};

class Entity
{
public:
	Entity(int life, Vector2 position = Vector2{}) : life_point(life), pos(position) {}
	virtual void move(Vector2 dir);	      // Va gérer les déplacements 
	bool isAlive();		//Vérification de si le joueur ou l'ennemi est en vie 
	void takeDamage(); //Permet au joueur et aux ennemies de prendres des dégats 
	int getLife(); //Permet de récupérer les points de vie de l'entité
	Vector2 getPos(); //Permet de récupérer la position de l'entité
	virtual ~Entity() = default;
	virtual void onUpdate(Map& map, std::vector<Entity*>& others);   // mouvement + collisions
	virtual void onCollision(Entity* other) = 0;
	virtual Vector2 chooseDirection(std::vector<Entity*>& others) = 0;

protected:
    Vector2 pos = Vector2{};
	int life_point;

};
