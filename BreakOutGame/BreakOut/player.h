#pragma once

class Player
{
    public:
    float x, y;
    float width, height;
    int speed;
    void Draw();
    void Update();
    Player();
    void Reset();

    private:
    void LimitMovement();
};