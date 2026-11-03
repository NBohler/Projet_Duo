#include <iostream>
#include "Entity.h"
#include "PlayeR.h"
#include "Utilities.h"

int main()
{
	Warrior player1;
	std::cout << player1.getLife()<<'\n';
	player1.takeDamage();
	std::cout << player1.getLife() << '\n';
	std::cout << player1.isAlive();

	//Game* game = Game::GetInstance();
	//game->Run();
	//// on oublie pas de delete dans le destructeur
	//return 0;
}
