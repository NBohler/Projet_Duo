#include "Map.h"
#include <iostream>

static const char* rawLevel1[10] = {
    "....................",
    "....................",
    "....................",
    "....................",
    "....................",
    "....................",
    "....................",
    "....................",
    "....................",
    "....................",

};

static const char* rawLevel2[10] = {
   "....................",
   "....................",
   "....................",
   "....................",
   "....................",
   "....................",
   "....................",
   "....................",
   "....................",
   "....................",
};

static const char* rawLevel3[10] = {
    "....................",
    "....................",
    "....................",
    "....................",
    "....................",
    "....................",
    "....................",
    "....................",
    "....................",
    "....................",
};

Map::Map(const char* rawData[10], Vector2 spawn)
    : width(20), height(10), playerSpawn(spawn) {
    initTileInfos();
    LoadFromFile(rawData);
}

Map::~Map() {}

void Map::initTileInfos() {
    tileInfos[E_CellType::Ground] = { '.', true, true };
    tileInfos[E_CellType::Mountain] = { 'A', false, false };
    tileInfos[E_CellType::Water] = { '~', false, true };
    tileInfos[E_CellType::Enemy] = { 'X', false, false };
    tileInfos[E_CellType::Exit] = { 'E', true, true };
}

char Map::getCell(Vector2 pos) const {
    return rawGrid[pos.y][pos.x];
}

void Map::parseRow(const char* rowData, int y) {
    for (int x = 0; x < width; ++x) {
        rawGrid[y][x] = rowData[x];
        if (rowData[x] == 'X') {
            enemySpawn.push_back({ x, y });
        }
    }
}

void Map::LoadFromFile(const char* rawData[10]) {
    enemySpawn.clear();
    for (int y = 0; y < height; ++y) {
        parseRow(rawData[y], y);
    }
}

void Map::Draw(Vector2 playerPos,
    const std::vector<Vector2>& enemies) const {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Vector2 pos = { x, y };
            if (pos.x == playerPos.x && pos.y == playerPos.y) {
                std::cout << 'H';
            }
            else {
                bool isEnemy = false;
                for (const auto& e : enemies) {
                    if (e.x == x && e.y == y) isEnemy = true;
                }
                if (isEnemy) std::cout << 'X';
                else std::cout << rawGrid[y][x];
            }
        }
        std::cout << '\n';
    }
}

std::vector<Map*> loadAllMaps() {
    std::vector<Map*> levels;
    levels.push_back(new Map(rawLevel1, { 0, 0 }));
    levels.push_back(new Map(rawLevel2, { 1, 1 }));
    levels.push_back(new Map(rawLevel3, { 0, 9 }));
    return levels;
}

void freeAllMaps(std::vector<Map*>& levels) {
    for (size_t i = 0; i < levels.size(); ++i) {
        delete levels[i];
    }
    levels.clear();
}