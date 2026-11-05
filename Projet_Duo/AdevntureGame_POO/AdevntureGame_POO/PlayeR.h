#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(int life, Vector2 position = Vector2{}) : Entity(life, position) {}
	Action playerInput();    // Utilisé pour recuperer l'action du joueurs 
	Vector2 getDirection(Action direction); //Récupère la direction du joueur ou de l'ennemi
	void move(Vector2 dir) override;
	void onCollision(Entity* other) override { other->takeDamage(); }
protected:
	Vector2 chooseDirection(std::vector<Entity*>& others) override
	{
		return getDirection(playerInput());
	}
};

class Warrior : public Player
{
public:
	Warrior(Vector2 position) : Player(40, position) {};

};

class Mage : public Player
{
public:
	Mage(Vector2 position) : Player(1, position) {};
};

class WarriorMage : public Player
{
public:
	WarriorMage(Vector2 position) : Player(4, position) {};
};
