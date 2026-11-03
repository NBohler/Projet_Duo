#include <iostream>
#include "Entity.h"
#include "PlayeR.h"
#include "Utilities.h"

int main()
{
	Warrior player1;
	std::cout << player1.getLife()<<'\n';
	player1.takeDamage();
	std::cout << player1.getLife();
}
