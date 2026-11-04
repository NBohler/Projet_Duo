#include "Game.h"
#include "Map.h"
#include "PlayeR.h"
#include <iostream>

// Définition de la fonction en premier
void RunGameLoop() {
    std::vector<Map*> maps = loadAllMaps();
    int levelIdx = 0;
    bool running = true;

    Warrior hero({ 0,0 });

    while (running && levelIdx < (int)maps.size()) {
        system("cls");
        Map* currentMap = maps[levelIdx];
        currentMap->Draw(hero.getPos(), currentMap->GetEnemySpawn());
        hero.move(hero.getDirection(hero.playerInput()));
        if (not hero.isAlive()) {
            running = false;
        }
    }

    freeAllMaps(maps);
}
