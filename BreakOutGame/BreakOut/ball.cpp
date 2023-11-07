#include <raylib.h>
#include <iostream>
#include "ball.h"
#include "random"


Ball::Ball()
{
    
    radius = 10;
    x = player.x + player.width /2;
    y = player.y - 12;
    float randomSpeed = ((float) rand()) / (float) RAND_MAX;
    float range = 1 - (-1);
    speed_x = 4 + (randomSpeed*range) + (-1);
    speed_y = 4 + (randomSpeed*range) + (-1);

}


void Ball::Draw()
{
        DrawCircle(x, y, radius, WHITE);
}

void Ball::Update()
{
    x += speed_x;
    y += speed_y;

    if( y + radius >= GetScreenHeight() || y - radius <= 0){
        speed_y *= -1;
    }
    if( x + radius >= GetScreenWidth() || x - radius <= 0){
        speed_x *= -1;
    }
    if( y + radius >= GetScreenHeight())
    {
        gameOver = true;
        showText = true;

    }

}
void Ball::ResetGame()
{
    x = player.x + player.width /2;
    y = player.y - 12;

}