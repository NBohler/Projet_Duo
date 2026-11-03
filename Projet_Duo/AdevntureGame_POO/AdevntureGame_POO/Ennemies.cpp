#include "Ennemies.h"
#include "Entity.h"
#include <random>

Vector2 Enemy::getRandomDirection()
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<> distrib(0, 3);

	return g_directions[distrib(gen)];
}

void move(Enemy& characters,char map)
{ 
	Vector2 newPos = characters.pos;

}