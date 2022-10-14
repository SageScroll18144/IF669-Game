#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "zombie.h"

//Inicialização do zumbi
Enemy enemyArr[11];
int how_many; 
int hit_kill;

int how_many_already_die = 0;

float animTimeZ = 0;
int currentFramZ = 0;
int sideOrientation = 1;
//Função de inicialização
void initEnemy(){
    for(int i=0;i<11;i++) {
        enemyArr[i].axisOrientation = 0;
        enemyArr[i].position = (Vector2) {rand() % 800, rand() % 450};

        enemyArr[i].enemyTex = LoadTexture("sprites/BAT_FLY_SIDES.png");
        enemyArr[i].enemyUpTex = LoadTexture("sprites/BAT_FLY_UP.png");
        enemyArr[i].enemyDownTex = LoadTexture("sprites/BAT_FLY_DOWN.png");

        enemyArr[i].healthPoints = 100;
    }

    hit_kill = 50;

    how_many = 11;

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
                enemy->axisOrientation = 0;
                enemy->position.x += 10;
            }
            else{
                enemy->axisOrientation = 1;
                enemy->position.x -= 10;
            } 
        } else if(dist_x < dist_y) {
            if (player_pos.y > enemy->position.y){
                enemy->axisOrientation = 2;
                enemy->position.y += 10;
            } 
            else{
                enemy->axisOrientation = 3;
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
        if (enemyArr[i].axisOrientation == 0) sideOrientation = 1;
        else if (enemyArr[i].axisOrientation == 1) sideOrientation = -1;

        frameRec = (Rectangle){enemyArr[i].position.x, enemyArr[i].position.y, (float) sideOrientation * enemyArr[i].enemyTex.width / 4, (float) enemyArr[i].enemyTex.height};
        enemyArr[i].enemyRec = frameRec;
    }

    for(int i=0;i<how_many;i++) goAt(&(enemyArr[i]), toHere);
}

void drawEnemy() {

    for (int i = 0; i < how_many; i++) {
        switch (enemyArr[i].axisOrientation) {
        case 0:
        case 1:
            DrawTextureRec(enemyArr[i].enemyTex, enemyArr[i].enemyRec, enemyArr[i].position, WHITE);
            break;
        
        case 2:
            DrawTextureRec(enemyArr[i].enemyDownTex, enemyArr[i].enemyRec, enemyArr[i].position, WHITE);
            break;

        case 3:
            DrawTextureRec(enemyArr[i].enemyUpTex, enemyArr[i].enemyRec, enemyArr[i].position, WHITE);
            break;

        default:
            break;
        }
    }  
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
void receiveCharacterAttack(int idx, int axis){
    if(axis == 0) enemyArr[idx].position.x -= 300; 
    else if(axis == 1) enemyArr[idx].position.x += 300;
    else if(axis == 2) enemyArr[idx].position.y -= 300;
    else if(axis == 3) enemyArr[idx].position.y += 300;
}
int getHowMany(){
    return how_many;
}
Vector2 getEnemyPos(int idx){
    return enemyArr[idx].position;
}
void receiveCharacterDamage(int idx){
    enemyArr[idx].healthPoints -= hit_kill;
}
void killEnemy(int idx){
    if(enemyArr[idx].healthPoints <= 0){
        enemyArr[idx].position.x=99999;
        enemyArr[idx].position.y=99999;
        how_many_already_die++;
    }
    
}
void setCharacterHitKill(int value){
    hit_kill = value;
}
int getHowManyAlreadyDie(){
    return how_many_already_die;
}
int CompareHowManyAlreadyDie(){
    if(how_many_already_die == how_many) return 1;
    return 0;
}
