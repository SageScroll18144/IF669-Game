#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "zombie.h"

//Inicialização do zumbi
Zombie zombie[5];
Texture2D zombieTex[5];
float animTimeZ = 0;
int currentFramZ = 0;

//Função de inicialização
void initZombie(){

    for(int i=0;i<5;i++) zombie[i].position = (Vector2) {rand() % 800, rand() % 450};
    
    for(int i=0;i<5;i++) zombieTex[i] = LoadTexture("sprites/ZOMBIE_RUN.png");
    

}

//Função de animação
void goAt(Zombie *zombieObj, Vector2 player_pos, int idx){

   float dist_x = player_pos.x - zombie[idx].position.x;
    float dist_y = player_pos.y - zombie[idx].position.y;
    
    if(dist_x < 0) dist_x = -dist_x;
    if(dist_y < 0) dist_y = -dist_y;

    animTimeZ += GetFrameTime();

    if (animTimeZ >= 0.2f) {
        currentFramZ++;
        animTimeZ = 0.0f;

        if (dist_x >= dist_y && dist_x != 0) {
            if (player_pos.x  > zombieObj->position.x) {
                zombieObj->position.x += 20;
            }
            else{
                zombieObj->position.x -= 20;
            } 
        } else if(dist_x < dist_y) {
            if (player_pos.y > zombieObj->position.y){
                zombieObj->position.y += 20;
            } 
            else{
                zombieObj->position.y -= 20;
            } 
        }
    }
    zombieObj->zombieRec.x = (float) currentFramZ * (float) zombieObj->zombieRec.width;
    zombieObj->zombieRec.y = (float) currentFramZ * (float) zombieObj->zombieRec.height;

    if (currentFramZ > 7) {
        currentFramZ = 0;
        animTimeZ = 0;
    }
    
}

void updateZombieMain(Vector2 toHere) {
    Rectangle frameRec;
    for(int i=0;i<5;i++){
        frameRec = (Rectangle){zombie[i].position.x - 55, zombie[i].position.y - 20, (float) zombieTex[i].width / 8, (float) zombieTex[i].height};
        zombie[i].zombieRec = frameRec;
    }
    //Rectangle frameRec = {zombie.position.x - 55, zombie.position.y - 20, (float) zombieTex.width / 8, (float) zombieTex.height};
    //for(int i=0;i<5;i++) zombie[i].zombieRec = frameRec;

    for(int i=0;i<5;i++) goAt(&(zombie[i]), toHere, i);
}

void drawZombie() {
    for(int i=0;i<5;i++) DrawTextureRec(zombieTex[i], zombie[i].zombieRec, zombie[i].position, WHITE);
}