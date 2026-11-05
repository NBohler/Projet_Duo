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
	std::vector<Entity*> enemies = createEnemiesGroup();
    for(Entity* enemy : enemies) {
        enemy->move(enemy->getPos());
	}
    while (running && levelIdx < (int)maps.size()) {
        system("cls");
        Map* currentMap = maps[levelIdx];
        std::vector<Vector2> enemyPositions;
        for (Entity* e : enemies)
            enemyPositions.push_back(e->getPos());
		currentMap->Draw(hero.getPos(), enemyPositions);
        for (Entity* e : enemies)
            e->move({ 0, 0 });
        hero.move(hero.getDirection(hero.playerInput()));
        if (not hero.isAlive()) {
            running = false;
        }
    }

    freeAllMaps(maps);
}
