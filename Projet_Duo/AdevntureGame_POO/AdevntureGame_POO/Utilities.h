#pragma once

struct Vector2
{
    int x = 0;
    int y = 0;
    Vector2 operator-(const Vector2& other) const
    {
        return { x - other.x, y - other.y };
    }
    Vector2 operator+(const Vector2& other) const
    {
        return { x + other.x, y + other.y };
    }
    bool operator==(const Vector2& other) const
    {
        return x == other.x && y == other.y;
    }
};
static const Vector2 g_directions[4] = {
    {0,-1},  // Up
    {0, 1},  // Down
    {-1, 0}, // Left
    {1, 0}   // Right
};