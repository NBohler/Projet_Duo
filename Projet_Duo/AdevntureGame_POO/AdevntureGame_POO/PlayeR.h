#pragma once
#include "Entity.h"

class Player : public Entity
{
public:
	Player(int life, Vector2 position = Vector2{}) : Entity(life, position) {}
	Vector2 getPos(); //Permet de récupérer la position du joueur
	Action playerInput();    // Utilisé pour recuperer l'action du joueurs 
	Vector2 getDirection(Action direction); //Récupère la direction du joueur ou de l'ennemi
	Vector2 move(Vector2 position);
};

class Warrior : public Player
{
public:
	Warrior(Vector2 position) : Player(4, position) {};

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
