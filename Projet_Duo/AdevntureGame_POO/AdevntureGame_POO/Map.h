#pragma once
#include <vector>
#include <fstream>
#include "Utilities.h"


enum E_CellType
{
    Ground = 0,
    Water,
    Mountain,
    Exit,
    Count
};

struct TileInfo
{
    char symbol;
    bool isWalkable;
    bool isSwimmable;
};

struct Map
{
    int* cells = nullptr;
    int width = 0;
    int height = 0;
    TileInfo tileInfos[E_CellType::Count];
    Vector2 playerSpawn;
    std::vector<Vector2> enemySpawn;

    int Get1DCell(int x, int y) const
    {
        return y * width + x;
    }
};