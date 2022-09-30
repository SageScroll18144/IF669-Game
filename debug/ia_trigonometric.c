#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>





int main()
{
const int screenWidth = 800;
const int screenHeight = 450;
InitWindow(screenWidth, screenHeight, "raylib [shapes] example - following eyes");


Vector2 zombiesPosition = { GetScreenWidth()/2.0f, GetScreenHeight()/2.0f };
Vector2 playerPosition = {100 , 50};
SetTargetFPS(60);
Rectangle obst = {150, 200, 40, 40};
Vector2 obstaclePosition = {150, 200};
Vector2 obstacleSize = {40 , 40};
float angulo, distX, distY;
while(!WindowShouldClose()){
    //CheckCollisionPointRec()
    playerPosition = GetMousePosition();
    if (zombiesPosition.x == obstaclePosition.x && zombiesPosition.x == obstaclePosition.x + obstacleSize.x && zombiesPosition.y == obstaclePosition.y && zombiesPosition.y == obstaclePosition.y + obstacleSize.y){
        zombiesPosition.x = zombiesPosition.x;
        zombiesPosition.y = zombiesPosition.y;
    }
    else{
        if(zombiesPosition.x != playerPosition.x){
            angulo = atan((zombiesPosition.y - playerPosition.y)/(zombiesPosition.x - playerPosition.x));
            distX = cos(angulo);
            distY = sin(angulo);
            if(zombiesPosition.x > playerPosition.x && zombiesPosition.y > playerPosition.y){
                Vector2 auxiliar1 = {zombiesPosition.x - distX, zombiesPosition.y};
                Vector2 auxiliar2 = {zombiesPosition.x ,zombiesPosition.y - distY};
                if(CheckCollisionPointRec(auxiliar1, obst) == true){
                    zombiesPosition.y = zombiesPosition.y - distY;
                }
                else if(CheckCollisionPointRec(auxiliar2 , obst) == true){
                    zombiesPosition.x = zombiesPosition.x - distX;
                }
                else{
                zombiesPosition.x = zombiesPosition.x - distX;
                zombiesPosition.y = zombiesPosition.y - distY;
                }

            }
            else if(zombiesPosition.x <= playerPosition.x && zombiesPosition.y >= playerPosition.y){
                Vector2 auxiliar1 = {zombiesPosition.x + distX, zombiesPosition.y};
                Vector2 auxiliar2 = {zombiesPosition.x ,zombiesPosition.y + distY};
                if(CheckCollisionPointRec(auxiliar1, obst) == true){
                    zombiesPosition.y = zombiesPosition.y + distY;
                }
                else if(CheckCollisionPointRec(auxiliar2 , obst) == true){
                    zombiesPosition.x = zombiesPosition.x + distX;
                }
                else{
                    zombiesPosition.x = zombiesPosition.x + distX;
                    zombiesPosition.y = zombiesPosition.y + distY;
                }
            }
            else if(zombiesPosition.x <= playerPosition.x && zombiesPosition.y < playerPosition.y){
                    Vector2 auxiliar1 = {zombiesPosition.x + distX, zombiesPosition.y};
                Vector2 auxiliar2 = {zombiesPosition.x ,zombiesPosition.y + distY};
                if(CheckCollisionPointRec(auxiliar1, obst) == true){
                    zombiesPosition.y = zombiesPosition.y + distY;
                }
                else if(CheckCollisionPointRec(auxiliar2 , obst) == true){
                    zombiesPosition.x = zombiesPosition.x + distX;
                }
                else{
                    zombiesPosition.x = zombiesPosition.x + distX;
                    zombiesPosition.y = zombiesPosition.y + distY;
                }
            }
            else if(zombiesPosition.x >= playerPosition.x && zombiesPosition.y <= playerPosition.y){
                    Vector2 auxiliar1 = {zombiesPosition.x - distX, zombiesPosition.y};
                Vector2 auxiliar2 = {zombiesPosition.x ,zombiesPosition.y - distY};
                if(CheckCollisionPointRec(auxiliar1, obst) == true){
                    zombiesPosition.y = zombiesPosition.y - distY;
                }
                else if(CheckCollisionPointRec(auxiliar2 , obst) == true){
                    zombiesPosition.x = zombiesPosition.x - distX;
                }
                else{
                    zombiesPosition.x = zombiesPosition.x - distX;
                    zombiesPosition.y = zombiesPosition.y - distY;
                }
            }
        }
        else{
            if(zombiesPosition.y > playerPosition.y){
                zombiesPosition.x = zombiesPosition.x;
                zombiesPosition.y = zombiesPosition.y - 1.0f;
            }
            else if(zombiesPosition.y < playerPosition.y){
                zombiesPosition.x = zombiesPosition.x;
                zombiesPosition.y = zombiesPosition.y + 1.0f;
            }
        }
    }
    BeginDrawing();
    DrawRectangleV(obstaclePosition, obstacleSize, BLACK);
    ClearBackground(WHITE);
    DrawCircleV(zombiesPosition, 5, RED);
    DrawCircleV(playerPosition, 5, BLUE);

    EndDrawing();
}

CloseWindow();

    return 0;
}