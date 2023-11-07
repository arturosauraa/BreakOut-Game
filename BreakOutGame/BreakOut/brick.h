#pragma once
#include <raylib.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <raymath.h>
#include <deque>
#include "player.h"

class Brick
{
    public:
        float x, y, width, height;
        std::deque<Vector2> bricksPos;
        Brick();
        void Draw();
        void Update();
        void Creation();
        

    private:
    Player player;
};