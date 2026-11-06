#include "Map.h"
#include <iostream>

static const int rawLevel1[10][20] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,2},
    {0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1},
    {2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}
};

static const int rawLevel2[10][20] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,2,2,2,0,1,1,1,0,0,0,0,2,2,0,0,0,0,0,0},
    {0,2,2,2,0,1,1,1,0,0,0,0,2,2,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0},
    {0,0,1,1,1,0,0,0,2,2,2,0,0,0,0,0,0,0,0,0},
    {0,0,1,1,1,0,0,0,2,2,2,0,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},
    {0,2,2,0,0,1,1,0,0,0,0,0,0,0,0,0,2,2,0,0},
    {0,2,2,0,0,1,1,0,0,2,2,2,0,0,0,0,2,2,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4}
};

static const int rawLevel3[10][20] = {
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,2,2,2,0,1,1,1,0,0,0,0,2,2,0,0,0,0,0,0},
    {0,2,2,2,0,1,1,1,0,0,0,0,2,2,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0,0,0,0,0},
    {0,0,1,1,1,0,0,0,2,2,2,0,0,0,0,0,0,0,0,4},
    {0,0,1,1,1,0,0,0,2,2,2,0,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},
    {0,2,2,0,0,1,1,0,0,0,0,0,0,0,0,0,2,2,0,0},
    {0,2,2,0,0,1,1,0,0,2,2,2,0,0,0,0,2,2,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

Map::~Map() {}

Map::Map(const int source[10][20], Vector2 spawn)
    : width(20), height(10), playerSpawn(spawn) {
    initTileInfos();
    enemySpawn.clear();
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            grid[y][x] = source[y][x];
            if (grid[y][x] == E_CellType::Enemies) {
                enemySpawn.push_back({ x, y });
            }
        }
    }
}

void Map::initTileInfos() {
    tileInfos[E_CellType::Ground] = { '.', true, true };
    tileInfos[E_CellType::Mountain] = { 'A', false, false };
    tileInfos[E_CellType::Water] = { '~', false, true };
    tileInfos[E_CellType::Enemies] = { 'X', false, false };
    tileInfos[E_CellType::Exit] = { 'E', true, true };
}

char Map::getCell(Vector2 pos) const {
    int type = grid[pos.y][pos.x];
    return tileInfos[type].symbol;
}

void Map::Draw(Vector2 playerPos, const std::vector<Vector2>& enemies)
const {
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
                else std::cout << getCell(pos);
            }
        }
        std::cout << '\n';
    }
}


std::vector<Map*> loadAllMaps() {
    std::vector<Map*> levels;
    levels.push_back(new Map(rawLevel1, { 0, 0 }));
    levels.push_back(new Map(rawLevel2, { 0, 0 }));
    levels.push_back(new Map(rawLevel3, { 0, 0 }));
    return levels;
}

void freeAllMaps(std::vector<Map*>& levels) {
    for (size_t i = 0; i < levels.size(); ++i) {
        delete levels[i];
    }
    levels.clear();
}

bool Map::isWalkable(Vector2 p) const {
    if (p.x < 0 || p.x >= width || p.y < 0 || p.y >= height)
        return false;
    int c = grid[p.y][p.x];
    return tileInfos[c].isWalkable;
}