#include <raylib.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <raymath.h>
#include <deque>


#include "game.h"

using namespace std;




int main()
{

    //Window Variables
    const int screen_width = 500;
    const int screen_height = 720;

    InitWindow(screen_width, screen_height, "BreakOut Game");
    SetTargetFPS(60);

    Player player = Player();
    Ball ball = Ball();
    Brick brick = Brick();
    Game game = Game();
    int score = 0;

    

    while(WindowShouldClose() == false)
    {

        BeginDrawing();

        player.Update();
        ball.Update();
        brick.Update();
       
        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y , player.width, player.height})){
            ball.speed_y *= -1;
        }

        for(int i = 0; i < brick.bricksPos.size(); i++ )
        {
            if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle{brick.bricksPos[i].x, brick.bricksPos[i].y, brick.width, brick.height}))
            {           
                brick.bricksPos.erase(brick.bricksPos.begin() + i);
                if(ball.y  <= brick.bricksPos[i].y + 25 &&  ball.y >= brick.bricksPos[i].y)
                {
                    
                    ball.speed_x *= -1;
                    score++;
                    

                } else 
                {
                    
                    ball.speed_y *= -1;
                    score++;
                    
                } 

            }     
        }


        if(ball.gameOver)
        {

            if(ball.showText && brick.bricksPos.size() >=1)
            {
                DrawText("Game Over", screen_width / 2 - 100, screen_height / 2, 40, WHITE);
                ball.ResetGame();
                player.Reset();
                brick.Creation();
                score = 0;
            }
            if(brick.bricksPos.empty())
            {
                DrawText("You Won", screen_width / 2 - 100, screen_height / 2, 40, WHITE);
                ball.ResetGame();
                player.Reset();
            }
        }
        
        if(ball.gameOver)
        {
            if(!brick.bricksPos.empty())
            {
                if(IsKeyDown(KEY_UP))
                {
                    ball.gameOver = false;

                }
            }
        }

        DrawText(TextFormat("%i", score), screen_width / 2, 10, 40, WHITE);
        


        ClearBackground(BLACK);

        player.Draw();
        ball.Draw();
        brick.Draw();




        EndDrawing();

    }
    
    
    CloseWindow();
    return 0;
} 