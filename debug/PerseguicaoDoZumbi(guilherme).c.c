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
Rectangle obst2 = {450, 140, 100, 80};
Vector2 obstaclePosition2 = {450, 140};
Vector2 obstacleSize2 = {100 , 80};
float angulo;
int controlVelocity = 1;
int distX, distY;
while(!WindowShouldClose()){
    //CheckCollisionPointRec()
    playerPosition = GetMousePosition();
    //comeco do controle do movimento do zumbi
    if(controlVelocity == 1){
        if(zombiesPosition.x != playerPosition.x){
            angulo = atan((zombiesPosition.y - playerPosition.y)/(zombiesPosition.x - playerPosition.x));
            if(cos(angulo) > sin(angulo)){
                distX = 2;
                distY = 1;
            }
            else if(cos(angulo) < sin(angulo)){
                distX = 1;
                distY = 2;
            }
            else if(cos(angulo) == sin(angulo)){
                distX = 1;
                distY = 1;
            }
            if(zombiesPosition.x > playerPosition.x && zombiesPosition.y > playerPosition.y){
                Vector2 auxiliar1 = {zombiesPosition.x - distX, zombiesPosition.y};
                Vector2 auxiliar2 = {zombiesPosition.x ,zombiesPosition.y - distY};
                if(CheckCollisionPointRec(auxiliar1, obst) == true || CheckCollisionPointRec(auxiliar1, obst2) == true){
                    zombiesPosition.y = zombiesPosition.y - distY;
                }
                else if(CheckCollisionPointRec(auxiliar2 , obst) == true || CheckCollisionPointRec(auxiliar2 , obst2) == true){
                    zombiesPosition.x = zombiesPosition.x - distX;
                }
                else{
                zombiesPosition.x = zombiesPosition.x - distX;
                zombiesPosition.y = zombiesPosition.y - distY;
                }

            }
            else if(zombiesPosition.x <= playerPosition.x && zombiesPosition.y > playerPosition.y){
                Vector2 auxiliar1 = {zombiesPosition.x + distX, zombiesPosition.y};
                Vector2 auxiliar2 = {zombiesPosition.x ,zombiesPosition.y - distY};
                if(CheckCollisionPointRec(auxiliar1, obst) == true || CheckCollisionPointRec(auxiliar1, obst2) == true){
                    zombiesPosition.y = zombiesPosition.y - distY;
                }
                else if(CheckCollisionPointRec(auxiliar2 , obst) == true || CheckCollisionPointRec(auxiliar2 , obst2) == true){
                    zombiesPosition.x = zombiesPosition.x + distX;
                }
                else{
                    zombiesPosition.x = zombiesPosition.x + distX;
                    zombiesPosition.y = zombiesPosition.y - distY;
                }
            }
            else if(zombiesPosition.x <= playerPosition.x && zombiesPosition.y <= playerPosition.y){
                    Vector2 auxiliar1 = {zombiesPosition.x + distX, zombiesPosition.y};
                Vector2 auxiliar2 = {zombiesPosition.x ,zombiesPosition.y + distY};
                if(CheckCollisionPointRec(auxiliar1, obst) == true || CheckCollisionPointRec(auxiliar1, obst2) == true){
                    zombiesPosition.y = zombiesPosition.y + distY;
                }
                else if(CheckCollisionPointRec(auxiliar2 , obst) == true || CheckCollisionPointRec(auxiliar2 , obst2) == true){
                    zombiesPosition.x = zombiesPosition.x + distX;
                }
                else{
                    zombiesPosition.x = zombiesPosition.x + distX;
                    zombiesPosition.y = zombiesPosition.y + distY;
                }
            }
            else if(zombiesPosition.x >= playerPosition.x && zombiesPosition.y <= playerPosition.y){
                Vector2 auxiliar1 = {zombiesPosition.x - distX, zombiesPosition.y};
                Vector2 auxiliar2 = {zombiesPosition.x ,zombiesPosition.y + distY};
                if(CheckCollisionPointRec(auxiliar1, obst) == true || CheckCollisionPointRec(auxiliar1, obst2) == true){
                    zombiesPosition.y = zombiesPosition.y + distY;
                }
                else if(CheckCollisionPointRec(auxiliar2 , obst) == true || CheckCollisionPointRec(auxiliar2 , obst2) == true){
                    zombiesPosition.x = zombiesPosition.x - distX;
                }
                else{
                    zombiesPosition.x = zombiesPosition.x - distX;
                    zombiesPosition.y = zombiesPosition.y + distY;
                }
            }
        }
        else{
            Vector2 auxiliar1 = {zombiesPosition.x, zombiesPosition.y - 1};
            Vector2 auxiliar2 = {zombiesPosition.x, zombiesPosition.y + 1};

            if(zombiesPosition.y > playerPosition.y){
                if(CheckCollisionPointRec(auxiliar1 , obst) == true || CheckCollisionPointRec(auxiliar1 , obst2) == true){
                    zombiesPosition.x = zombiesPosition.x;
                    zombiesPosition.y = zombiesPosition.y;
                }
                else{
                    zombiesPosition.x = zombiesPosition.x;
                    zombiesPosition.y = zombiesPosition.y - 1;
                }
            }
            else if(zombiesPosition.y < playerPosition.y){
                if(CheckCollisionPointRec(auxiliar2 , obst) == true || CheckCollisionPointRec(auxiliar2 , obst2) == true){
                    zombiesPosition.x = zombiesPosition.x;
                    zombiesPosition.y = zombiesPosition.y;
                }
                else{
                    zombiesPosition.x = zombiesPosition.x;
                    zombiesPosition.y = zombiesPosition.y + 1;
            }
        }

    }
    controlVelocity = 0;
    }
    else{
        //sem movimento
        controlVelocity = 1;
    }
    //fim do controle do movimento do zumbi
    BeginDrawing();
    DrawRectangleV(obstaclePosition, obstacleSize, BLACK);
    DrawRectangleV(obstaclePosition2, obstacleSize2, BLACK);
    ClearBackground(WHITE);
    DrawCircleV(zombiesPosition, 5, RED);
    DrawCircleV(playerPosition, 5, BLUE);

    EndDrawing();
}

CloseWindow();

    return 0;
}
