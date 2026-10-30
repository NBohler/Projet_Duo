#include "Entity.h"
#include <iostream>
#include <conio.h>

void Entity::move()
{
	int input = getch();

	switch (input) {
	case 'Z':Action::MOVE_UP; break;

	case 'D':Action::MOVE_RIGHT; break;

	case 'S':Action::MOVE_DOWN; break;

	case 'Q':Action::MOVE_LEFT; break;
	}

}
