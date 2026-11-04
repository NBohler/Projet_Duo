#include "Map.h"
#include <sstream>
#include <fstream>



int get1DCell(Vector2 pos, int width)
{
    return pos.y * width + pos.x;
}


static void InitTileInfos(TileInfo t[E_CellType::Count])
{
    t[E_CellType::Ground] = { '.', true, false };
    t[E_CellType::Water] = { '~', false, true };
    t[E_CellType::Mountain] = { 'A', false, false };
    t[E_CellType::Exit] = { 'E', true, false };
}

static E_CellType TypeFromChar(char c)
{
    if (c == '~') return E_CellType::Water;
    if (c == 'A') return E_CellType::Mountain;
    if (c == 'E') return E_CellType::Exit;
    return E_CellType::Ground;
}

char Map[10][20] =
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
