#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "background.h"





int main()
{
const int screenWidth = 800;
const int screenHeight = 450;
InitWindow(screenWidth, screenHeight, "perseguicao do zumbi");


int cont = 0; //contador pra as imagens da sprite não ficarem passando muito rapido 
Texture2D backTex = LoadTexture("assets/map.png");
Rectangle recSrc = {0, 0, backTex.width, backTex.height};
Rectangle recDest = {0, 0, 800, 450};
Vector2 vecOrigin = {0, 0};
Texture2D zombie = LoadTexture ("sprites/ZOMBIE_RUN.png");
Rectangle recZ;
int i = 0;//variavel pra movimentar a sprite
recZ.x = 0;
recZ.y = 0;
recZ.height = zombie.height;
recZ.width = (float)(zombie.width / 8);
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
                recZ.width = (float)((zombie.width / 8) * (-1));
                Vector2 auxiliar1 = {zombiesPosition.x - distX, zombiesPosition.y};
                Vector2 auxiliar2 = {zombiesPosition.x ,zombiesPosition.y - distY};
                if(HasAColision(auxiliar1) == 1){//checando colisao do zumbi no cenario
                    zombiesPosition.y = zombiesPosition.y - distY;
                }
                else if(HasAColision(auxiliar2) == 1){//checando colisao do zumbi no cenario
                    zombiesPosition.x = zombiesPosition.x - distX;
                }
                else{
                zombiesPosition.x = zombiesPosition.x - distX;
                zombiesPosition.y = zombiesPosition.y - distY;
                }

            }
            else if(zombiesPosition.x <= playerPosition.x && zombiesPosition.y > playerPosition.y){
                recZ.width = (float)(zombie.width / 8);
                Vector2 auxiliar1 = {zombiesPosition.x + distX, zombiesPosition.y};
                Vector2 auxiliar2 = {zombiesPosition.x ,zombiesPosition.y - distY};
                if(HasAColision(auxiliar1) == 1){//checando colisao do zumbi no cenario
                    zombiesPosition.y = zombiesPosition.y - distY;
                }
                else if(HasAColision(auxiliar2) == 1){//checando colisao do zumbi no cenario
                    zombiesPosition.x = zombiesPosition.x + distX;
                }
                else{
                    zombiesPosition.x = zombiesPosition.x + distX;
                    zombiesPosition.y = zombiesPosition.y - distY;
                }
            }
            else if(zombiesPosition.x <= playerPosition.x && zombiesPosition.y <= playerPosition.y){
                recZ.width = (float)(zombie.width / 8);
                    Vector2 auxiliar1 = {zombiesPosition.x + distX, zombiesPosition.y};
                Vector2 auxiliar2 = {zombiesPosition.x ,zombiesPosition.y + distY};
                if(HasAColision(auxiliar1) == 1){//checando colisao do zumbi no cenario
                    zombiesPosition.y = zombiesPosition.y + distY;
                }
                else if(HasAColision(auxiliar2) == 1){//checando colisao do zumbi no cenario
                    zombiesPosition.x = zombiesPosition.x + distX;
                }
                else{
                    zombiesPosition.x = zombiesPosition.x + distX;
                    zombiesPosition.y = zombiesPosition.y + distY;
                }
            }
            else if(zombiesPosition.x >= playerPosition.x && zombiesPosition.y <= playerPosition.y){
                recZ.width = (float)((zombie.width / 8) * (-1));
                Vector2 auxiliar1 = {zombiesPosition.x - distX, zombiesPosition.y};
                Vector2 auxiliar2 = {zombiesPosition.x ,zombiesPosition.y + distY};
                if(HasAColision(auxiliar1) == 1){//checando colisao do zumbi no cenario
                    zombiesPosition.y = zombiesPosition.y + distY;
                }
                else if(HasAColision(auxiliar2) == 1){//checando colisao do zumbi no cenario
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
                if(HasAColision(auxiliar1) == 1){//checando colisao do zumbi no cenario
                    zombiesPosition.x = zombiesPosition.x;
                    zombiesPosition.y = zombiesPosition.y;
                }
                else{
                    zombiesPosition.x = zombiesPosition.x;
                    zombiesPosition.y = zombiesPosition.y - 1;
                }
            }
            else if(zombiesPosition.y < playerPosition.y){
                if(HasAColision(auxiliar2) == 1){//checando colisao do zumbi no cenario
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
     DrawTexturePro(backTex, recSrc, recDest, vecOrigin, 0, WHITE);
    i %= 8;
    recZ.x = i * recZ.width;
    DrawRectangleV(obstaclePosition, obstacleSize, BLACK);
    DrawRectangleV(obstaclePosition2, obstacleSize2, BLACK);
    ClearBackground(WHITE);
    DrawTextureRec(zombie, recZ, zombiesPosition, WHITE);
    DrawCircleV(playerPosition, 5, BLUE);
    cont++;
    if (cont == 4){
        cont = 0;
        i++;
    }
    

    EndDrawing();
}
UnloadTexture(backTex);
UnloadTexture(zombie);
CloseWindow();

    return 0;
}
