#include <iostream>
#include "Entity.h"
#include "PlayeR.h"
#include "Utilities.h"

int main()
{
	//Warrior player1({0, 0});
	//std::cout << player1.getLife()<<'\n';
	//player1.takeDamage();
	//std::cout << player1.getLife() << '\n';

	//Mage player2({1, 1});
	//std::cout << player2.getLife() << '\n';
	//player2.takeDamage();
	//std::cout << player2.isAlive()<< '\n';

	Warrior hero({ 0,0 });
	std::cout << "Appuie sur Z, Q, S, D (espace pour quitter)\n";

	while (true) {
		Action a = hero.playerInput();
		if (a != Action::None && a != Action::Attack) {      // protège getDirection
			hero.move(hero.getDirection(a));
		}
		std::cout << hero.getPos().x << " " << hero.getPos().y << "\n";
	}


}