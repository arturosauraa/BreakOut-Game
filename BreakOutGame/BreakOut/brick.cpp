#include "brick.h"



Brick::Brick()
{
    x = 20;
    y = 50;
    width = 50;
    height = 20;
    Creation();
}


void Brick::Draw()
{
    for(Vector2 brickCreated: bricksPos)
    {
        switch ((int)brickCreated.y)
        {
        case 50:
            DrawRectangle(brickCreated.x, brickCreated.y , width, height, GRAY);
            break;
        case 80:
            DrawRectangle(brickCreated.x, brickCreated.y , width, height, BLUE);
            break;
        case 110:
            DrawRectangle(brickCreated.x, brickCreated.y , width, height, RED);
            break;
        case 140:
            DrawRectangle(brickCreated.x, brickCreated.y , width, height, ORANGE);
            break;
        case 170:
            DrawRectangle(brickCreated.x, brickCreated.y , width, height, YELLOW);
            break;
        case 200:
            DrawRectangle(brickCreated.x, brickCreated.y , width, height, GREEN);
            break;
        case 230:
            DrawRectangle(brickCreated.x, brickCreated.y , width, height, PURPLE);
            break;
        case 260:
            DrawRectangle(brickCreated.x, brickCreated.y , width, height, WHITE);
            break;
        default:
            break;
        }


    
    }


}

void Brick::Update()
{

}

void Brick::Creation()
{
    x = 20;
    y = 50;
    bricksPos.clear();

    for(int i = 0; i <= 71; i++)
    {
        if(x >= GetScreenWidth()-50)
        {
            x = 20;
            y += 30;
        }
        bricksPos.push_back(Vector2{x,y});
        x += 52;

    }
}