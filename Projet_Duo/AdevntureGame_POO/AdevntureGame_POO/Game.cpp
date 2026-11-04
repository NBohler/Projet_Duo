#include "Game.h"

#include "Map.h"
#include <iostream>

// Définition de la fonction en premier
void Game::RunGameLoop() {
    std::vector<Map*> maps = loadAllMaps();
    int levelIdx = 0;
    bool running = true;

    while (running && levelIdx < (int)maps.size()) {
        Map* currentMap = maps[levelIdx];
        currentMap->Draw({ 0, 0 }, currentMap->GetEnemySpawn());
        running = false;
    }

    freeAllMaps(maps);
}