#include "PlayeR.h"
#include <string>
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

Vector2 getDirection(Action player_action)
{
	return g_directions[(int)player_action - 1];
}


void move(Vector2 dir, std::string currentMap, Player player)
{
	
}

void spell()
{

}
