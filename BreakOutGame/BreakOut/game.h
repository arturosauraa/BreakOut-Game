#pragma once
#include "player.h"
#include "ball.h"
#include "brick.h"

class Game
{
    public:
    int screen_width;
    int screen_height;
    Game();
    void Draw();
    void Update();

    private:
    Player player;
    Ball ball;
    Brick brick;
};
