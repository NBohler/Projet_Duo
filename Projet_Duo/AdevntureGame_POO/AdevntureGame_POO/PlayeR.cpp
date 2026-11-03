#include "PlayeR.h"
#include <conio.h>

Action Player::playerInput()
{
	int input = _getch();

	Action direction = Action::None;

	switch (input) {
	case 'Z':direction = Action::MOVE_UP; break;
	case 'D':direction = Action::MOVE_RIGHT; break;
	case 'S':direction = Action::MOVE_DOWN; break;		
	case 'Q':direction = Action::MOVE_LEFT; break;	
	case ' ':direction = Action::Attack; break;
	}

	return direction;
}

Vector2 getDirection(Action direction)
{
	return g_directions[(int)direction - 1];
}


