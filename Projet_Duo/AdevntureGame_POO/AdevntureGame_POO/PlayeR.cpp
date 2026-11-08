#include "PlayeR.h"
#include <iostream>
#include <conio.h>

Action Player::playerInput()
{
	while (true) {
		int input = _getch();



		switch (input) {
		case'z':
		case 'Z':return Action::MOVE_UP;
		case'd':
		case 'D':return Action::MOVE_RIGHT;
		case's':
		case 'S':return Action::MOVE_DOWN;
		case'q':
		case 'Q':return Action::MOVE_LEFT;
		case ' ':return Action::Attack;
		}
	}

}

Vector2 Player::getDirection(Action direction)
{
	if (direction == Action::None || direction == Action::Attack) // Permet d'esquiver les touches inconnus et de définir si le joueur attaque ou non
		return { 0, 0 };
	return g_directions[(int)direction - 1];
}

void Player::move(Vector2 dir)
{
	pos = pos + dir;
}

Player* createPlayer()
{
	std::cout << "Choose your character class:\n";
	std::cout << "1. Warrior \n";
	std::cout << "2. Mage (1 HP)\n";
	int choice = 0;
	std::cin >> choice;
	Vector2 startPos{ 0, 0 }; // Starting position for the player
	Player* player = nullptr;
	switch (choice) {
	case 1:
		return new Warrior(startPos);
	case 2:
		return new Mage(startPos);
	case 3:
		return new WarriorMage(startPos);
	default:
		std::cout << "Invalid choice. Defaulting to Warrior.\n";
		return new Warrior(startPos);
	}
}

void Mage::onUpdate(Map& map, std::vector<Entity*>& others)
{
	Entity::onUpdate(map, others);        // déplacement + collisions habituels
	if (lastAction == Action::Attack && dynamic_cast<Mage*>(this) )
		castSpell(others);
}
void Mage::castSpell(std::vector<Entity*>& others)
{
	for (Entity* o : others) {
		if (o == this || !o->isAlive())
			continue;
		Vector2 d = o->getPos() - pos;
		if (d.x * d.x <= 1 && d.y * d.y <= 1)   // touche les 8 cases autour du mage
			o->takeDamage();
	}
}
