#include "Game.h"
#include "Map.h"
#include "Ennemies.h"
#include "PlayeR.h"
#include <iostream>


// Définition de la fonction en premier
void RunGameLoop() {
    std::vector<Map*> maps = loadAllMaps();
    int levelIdx = 0;
    bool running = true;
	Warrior hero({ 0,0 });
	std::vector<Enemy*> enemies = createEnemiesGroup();
	std::vector<Entity*> entities;
	entities.push_back(&hero);                 // toujours en premier
	for (Enemy* e : enemies)
		entities.push_back(e);
	while (running && levelIdx < (int)maps.size()) {
		system("cls");
		Map* currentMap = maps[levelIdx];
		std::vector<Vector2> enemyPositions;
		for (Enemy* e : enemies)
			if (e->isAlive())
				enemyPositions.push_back(e->getPos());
		currentMap->Draw(hero.getPos(), enemyPositions);
		for (Entity* e : entities)
			if (e->isAlive())
				e->onUpdate(*currentMap, entities);
		if (not hero.isAlive())
			running = false;
	}
	freeEnemyGroup(enemies);
	freeAllMaps(maps);
}
