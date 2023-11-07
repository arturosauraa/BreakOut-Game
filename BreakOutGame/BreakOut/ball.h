# pragma once
#include "player.h"
#include "brick.h"


class Ball
{
    public:
        float x, y;
        float speed_x, speed_y;
        int radius;
        Ball();
        void Draw();
        void Update();
        void ResetGame();
        bool gameOver = true;
        bool showText = false;

    private:
    Player player;
    Brick brick;
    



};