#include "PlayeR.h"
#include <conio.h>

Action Player::playerInput()
{
	int input = _getch();

	Action direction = Action::None;

	switch (input) {
	case'z':
	case 'Z':direction = Action::MOVE_UP; break;
	case'd':
	case 'D':direction = Action::MOVE_RIGHT; break;
	case's':
	case 'S':direction = Action::MOVE_DOWN; break;
	case'q':
	case 'Q':direction = Action::MOVE_LEFT; break;
	case ' ':direction = Action::Attack; break;
	}

	return direction;
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