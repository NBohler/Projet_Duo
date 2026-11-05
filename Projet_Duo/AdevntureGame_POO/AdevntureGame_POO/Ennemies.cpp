#include "Ennemies.h"
#include "Entity.h"
#include "PlayeR.h"
#include <random>

Vector2 Enemy::getRandomDirection()
{
	static std::random_device rd;
	static std::mt19937 gen(rd());
	static std::uniform_int_distribution<> distrib(0, 3);

	return g_directions[distrib(gen)];
}


std::vector<Enemy*> createEnemiesGroup()
{
	std::vector<Enemy*> group;
	group.push_back(new Zombie({ 3, 3 }));
	group.push_back(new HeadlessZombie({ 5, 2 }));
	group.push_back(new SwimmerZombie({ 1, 4 }));
	return group;
}

void freeEnemyGroup(std::vector<Enemy*>& group)
{
	for (Enemy* e : group)
		delete e;
	group.clear();
}

void Enemy::move(Vector2 dir)
{ 
	pos = pos + dir;
}

Vector2 Zombie::getDirection(Vector2 target)
{
	if (target.x > pos.x)
		return { 1, 0 };   
	if (target.x < pos.x)
		return { -1, 0 };  
	if (target.y > pos.y)
		return { 0, 1 };   
	if (target.y < pos.y)
		return { 0, -1 }; 

	return { 0, 0 };
}

Vector2 HeadlessZombie::getDirection(Vector2 target)
{
	return getRandomDirection();
}

Vector2 SwimmerZombie::getDirection(Vector2 target)
{
	return getRandomDirection();
}

void Enemy::onCollision(Entity* other)
{
	if (dynamic_cast<Player*>(other))   // un ennemi ne blesse que le joueur
		other->takeDamage();
}