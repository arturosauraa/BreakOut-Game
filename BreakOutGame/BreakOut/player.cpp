#include <raylib.h>
#include <iostream>
#include "player.h"

Player::Player()
{
    width = 120;
    height = 25;
    x = 500 / 2 - width / 2;
    y = 700 - height - 20;
    speed = 6;
}

void Player::Draw()
{
    {
        //DrawRectangleRounded(Rectangle{x,y, width, height}, 0.8, 0, WHITE);
        DrawRectangle(x,y, width, height, WHITE);
    }
}

void Player::Update()
{
    if(IsKeyDown(KEY_LEFT)){
        x = x - speed;
    }
    if(IsKeyDown(KEY_RIGHT)){
        x = x + speed;
    }
    LimitMovement();
}

void Player::LimitMovement()
{
    if(x <= 0){
        x = 0;
    }
    if(x + width >= GetScreenWidth()){
        x = GetScreenWidth() - width;
    } 
}

void Player::Reset()
{
    x = 500 / 2 - width / 2;
    y = 700 - height - 20;
}

