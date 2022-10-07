#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "zombie.h"

//Inicialização do zumbi
Enemy enemyArr[100];
int how_many; 

float animTimeZ = 0;
int currentFramZ = 0;

//Função de inicialização
void initEnemy(){
    for(int i=0;i<100;i++) enemyArr[i].position = (Vector2) {rand() % 800, rand() % 450};
    for(int i=0;i<100;i++) enemyArr[i].enemyTex = LoadTexture("sprites/BAT_FLY_SIDES.png");
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
                enemy->position.x += 20;
            }
            else{
                enemy->position.x -= 20;
            } 
        } else if(dist_x < dist_y) {
            if (player_pos.y > enemy->position.y){
                enemy->position.y += 20;
            } 
            else{
                enemy->position.y -= 20;
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
