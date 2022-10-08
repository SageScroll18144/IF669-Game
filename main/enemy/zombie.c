#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "zombie.h"

//Inicialização do zumbi
Enemy enemyArr[10];
int how_many; 

float animTimeZ = 0;
int currentFramZ = 0;
int axisOrientationZ;
//Função de inicialização
void initEnemy(){
    for(int i=0;i<10;i++) enemyArr[i].position = (Vector2) {rand() % 800, rand() % 450};
    for(int i=0;i<10;i++) enemyArr[i].enemyTex = LoadTexture("sprites/BAT_FLY_SIDES.png");
    how_many = 5;

}

//Função de animação
void goAt(Enemy *enemy, Vector2 player_pos){

   float dist_x = player_pos.x - enemy->position.x;
   float dist_y = player_pos.y - enemy->position.y;
    
    if(dist_x < 0) dist_x = -dist_x;
    if(dist_y < 0) dist_y = -dist_y;

    animTimeZ += GetFrameTime();

    if (animTimeZ >= 0.2f) {
        currentFramZ++;
        animTimeZ = 0.0f;

        if (dist_x >= dist_y && dist_x != 0) {
            if (player_pos.x  > enemy->position.x) {
                axisOrientationZ=0;
                enemy->position.x += 10;
            }
            else{
                axisOrientationZ=1;
                enemy->position.x -= 10;
            } 
        } else if(dist_x < dist_y) {
            if (player_pos.y > enemy->position.y){
                axisOrientationZ=2;
                enemy->position.y += 10;
            } 
            else{
                axisOrientationZ=3;
                enemy->position.y -= 10;
            } 
        }
    }
    enemy->enemyRec.x = (float) currentFramZ * (float) enemy->enemyRec.width;
    enemy->enemyRec.y = (float) currentFramZ * (float) enemy->enemyRec.height;

    if (currentFramZ > 7) {
        currentFramZ = 0;
        animTimeZ = 0;
    }
    
}

void updateEnemyMain(Vector2 toHere) {
    Rectangle frameRec;
    for(int i=0;i<how_many;i++){
        frameRec = (Rectangle){enemyArr[i].position.x, enemyArr[i].position.y, (float) enemyArr[i].enemyTex.width / 4, (float) enemyArr[i].enemyTex.height};
        enemyArr[i].enemyRec = frameRec;
    }

    for(int i=0;i<how_many;i++) goAt(&(enemyArr[i]), toHere);
}

void drawEnemy() {
    for(int i=0;i<how_many;i++) DrawTextureRec(enemyArr[i].enemyTex, enemyArr[i].enemyRec, enemyArr[i].position, WHITE);
}

void setHowManyEnemies(int qtd){
    how_many = qtd;
}
void colision(){
    for(int i=0;i<how_many;i++){
        if (enemyArr[i].position.y<=0) enemyArr[i].position.y += 20;
        if (enemyArr[i].position.y>= GetScreenHeight())  enemyArr[i].position.y  -= 20;
        if (enemyArr[i].position.x <=0) enemyArr[i].position.x  += 20;
        if (enemyArr[i].position.x >= GetScreenWidth())  enemyArr[i].position.x  -= 20;
    }
}
void receiveCharacterAttack(int idx){
    if(axisOrientationZ == 0) enemyArr[idx].position.x -= 10; 
    else if(axisOrientationZ == 1) enemyArr[idx].position.x += 10;
    else if(axisOrientationZ == 2) enemyArr[idx].position.y -= 10;
    else if(axisOrientationZ == 3) enemyArr[idx].position.y += 10;
}
int getHowMany(){
    return how_many;
}
Vector2 getEnemyPos(int idx){
    return enemyArr[idx].position;
}