#pragma once
#include <vector>
#include "Utilities.h"

enum E_CellType {
    Ground = 0,
    Mountain = 1,
    Water = 2,
    Enemy = 3,
    Exit = 4,
    Count = 5
};

struct TileInfo {
    char symbol;
    bool isWalkable;
    bool isSwimmable;
};

class Map {
private:
    char rawGrid[10][20];
    int width;
    int height;
    TileInfo tileInfos[E_CellType::Count];
    Vector2 playerSpawn;
    std::vector<Vector2> enemySpawn;

    void initTileInfos();
    void parseRow(const char* rowData, int y);

public:
    Map(const char* rawData[10], Vector2 spawn);
    ~Map();

    char getCell(Vector2 pos) const;
    void LoadFromFile(const char* rawData[10]);
    void Draw(Vector2 playerPos, const std::vector<Vector2>& enemies) const;
    int GetWidth() const { return width; }
    int GetHeight() const { return height; }
    Vector2 GetPlayerSpawn() const { return playerSpawn; }
    const std::vector<Vector2>& GetEnemySpawn() const {
        return enemySpawn;
    }
};

std::vector<Map*> loadAllMaps();
void freeAllMaps(std::vector<Map*>& levels);