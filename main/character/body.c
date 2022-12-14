#include "raylib.h"
#include "raymath.h"
#include "body.h"
#include <stdbool.h>
#include "stdio.h"
#include <stdio.h>
#include <stdlib.h>

Player player;
Texture2D charaTex, charaTexUp, charaTexDown, charaTexIdle, charaTexIdleUp, charaTexIdleDown, charaTexAtkSide, charaTexAtkUp, charaTexAtkDown, charaTexDead;
Texture2D healthBarTex, healthBarTex2, healthBarTex3, healthBarTex4, healthBarTex5, healthBarTex6;
//Rectangle frameRec;
int currentFrame = 1, currentOrientation = 1, orientation = 1, axisOrientation = 0;
int frameCounter = 0, isAttacking = 0, atkCnt = 0;
int flag_attack = 0, count_attack = 0, count_aux = 0;

char frontendHS[110];
Font font_counter_est;

float animTime = 0;
int currentFram = 0;

Sound walk;
Sound attack_sound;

void initCharacter(){
    //player = {0};
    player.position = (Vector2) {400, 280};
    player.healthPoints = 6;
    player.immunityIndex = 0;

    charaTex = LoadTexture("sprites/RUN_SIDES.png");
    charaTexUp = LoadTexture("sprites/RUN_UP.png");
    charaTexDown = LoadTexture("sprites/RUN_DOWN.png");

    charaTexIdle = LoadTexture("sprites/IDLE_SIDE.png");
    charaTexIdleUp = LoadTexture("sprites/IDLE_UP.png");
    charaTexIdleDown = LoadTexture("sprites/IDLE_DOWN.png");

    charaTexAtkSide = LoadTexture("sprites/ATTACK_SIDES.png");
    charaTexAtkUp = LoadTexture("sprites/ATTACK_UP.png");
    charaTexAtkDown = LoadTexture("sprites/ATTACK_DOWN.png");
    charaTexDead = LoadTexture("sprites/morto.png");

    healthBarTex = LoadTexture("sprites/health_bar/b1.png");
    healthBarTex2 = LoadTexture("sprites/health_bar/b2.png");
    healthBarTex3 = LoadTexture("sprites/health_bar/b3.png");
    healthBarTex4 = LoadTexture("sprites/health_bar/b4.png");
    healthBarTex5 = LoadTexture("sprites/health_bar/b5.png");
    healthBarTex6 = LoadTexture("sprites/health_bar/b6.png");

    walk = LoadSound("sounds/walking_sound4.mp3");
    SetSoundVolume(walk, 1.0f);

    attack_sound = LoadSound("sounds/sword.wav");
    SetSoundVolume(attack_sound, 0.5f);
    
    font_counter_est = LoadFont("fonts/jupiter_crash.png"); 
    
}

void updatePlayer(Player *player, int *currentFrame, int *frameCounter, int *currentOrientation, int *axisOrientation, int deltaTime) {
    int frameSpeed = 8;

    if (*currentFrame > 5) *currentFrame = 0;
    player->playerRec.x = (float)*currentFrame * (float) player->playerRec.width;
    player->playerRec.y = (float)*currentFrame * (float) player->playerRec.height;

    if (IsKeyPressed(KEY_SPACE) && !flag_attack) {//== 0
        //animacao stamina
        //printf("ATAQUE\n");
        count_attack++;
        if(count_attack == 7){
            flag_attack = 1;
            count_attack = 0;
        }

        isAttacking = 1;
        if(!IsSoundPlaying(attack_sound)) PlaySound(attack_sound);
    }
    if(flag_attack){ count_aux++;}
    if(count_aux == 700) {
        count_aux = 0;
        flag_attack = 0;
    }

    if(!flag_attack) sprintf(frontendHS, "x%d", 7-count_attack);
    else if(flag_attack) sprintf(frontendHS, "x%d", count_aux/100);
    if (!isAttacking) {
        if (IsKeyDown(KEY_RIGHT)) {
            
            *axisOrientation = 3;
            (*frameCounter)++;

            if (*frameCounter >= 60/frameSpeed) {
                
                (*frameCounter) = 0;
                
                (*currentFrame)++;
                if(!IsSoundPlaying(walk)) PlaySound(walk);
                
                if (!(*currentOrientation)) {
                    (*currentOrientation) = 1;
                    player->playerRec.width *= -1;
                }
                player->position.x += 20;
            }
            
        
        }

        else if (IsKeyDown(KEY_LEFT)) {
            *axisOrientation = 3;
            (*frameCounter)++;

            if (*frameCounter >= 60/frameSpeed) {
                *frameCounter = 0;
                
                (*currentFrame)++;
                if(!IsSoundPlaying(walk)) PlaySound(walk);
                
                if (*currentOrientation) {
                    *currentOrientation = 0;
                    player->playerRec.width *= -1;
                }
                player->position.x -= 20;
            }   
            
        }

        else if (IsKeyDown(KEY_UP)) {
            *axisOrientation = 1;
            (*frameCounter)++;

            if (*frameCounter >= 60/frameSpeed) {
                (*frameCounter) = 0;
                
                (*currentFrame)++;
                if(!IsSoundPlaying(walk)) PlaySound(walk);
                

                player->position.y -= 20;
            }
        }
        
        else if (IsKeyDown(KEY_DOWN)) {
            *axisOrientation = 2;
            (*frameCounter)++;

            if (*frameCounter >= 60/frameSpeed) {
                (*frameCounter) = 0;
                
                (*currentFrame)++;
                if(!IsSoundPlaying(walk)) PlaySound(walk);

                player->position.y += 20;
            }
        }

        else if (IsKeyReleased(KEY_RIGHT) || IsKeyReleased(KEY_LEFT))  *axisOrientation = 0;
        else if (IsKeyReleased(KEY_UP)) *axisOrientation = 4;
        else if (IsKeyReleased(KEY_DOWN)) *axisOrientation = 5;
    }
    
    
    
}

void drawAttack(Player *player) {

        animTime += GetFrameTime();

        if (animTime > 0.2f) {
            currentFram++;
            animTime = 0.0f;     
        }
       
        switch (axisOrientation) {
        case 3:
        case 0:
            player->playerRec.x = (float) currentFram * (float) player->playerRec.width;
            DrawTextureRec(charaTexAtkSide, player->playerRec, player->position, WHITE);
            break;
        
        case 1:
        case 4:
            player->playerRec.y = (float) currentFram * (float) player->playerRec.height;
            DrawTextureRec(charaTexAtkUp, player->playerRec, player->position, WHITE);
            break;

        case 2:
        case 5:
            player->playerRec.y = (float) currentFram * (float) player->playerRec.height;
            DrawTextureRec(charaTexAtkDown, player->playerRec, player->position, WHITE);
            break;

        default:
            break;
        }
        
        if (currentFram > 2) {
            isAttacking = 0;
            currentFram = 0;
            animTime = 0;
        };
        
}

void updatePlayerMain(){
    orientation = currentOrientation ? 1 : -1;
    Rectangle frameRec = {player.position.x , player.position.y, (float) orientation * charaTex.width / 6, (float) charaTex.height};
  
    player.playerRec = frameRec;
    
    float deltaTime = GetFrameTime();
    
    updatePlayer(&player, &currentFrame, &frameCounter, &currentOrientation, &axisOrientation, deltaTime);

}

void drawCharacter(){
    //DrawCircleV(ballPosition, 50, MAROON);
    // for (int i = 0; i < envItemLength; i++) DrawRectangleRec(envItems[i].rect, envItems[i].color);
    
    if (isAttacking) {
        drawAttack(&player);
    } else {

        if (itsDead()) {
            DrawTextureRec(charaTexDead, player.playerRec, player.position, RED);
           
        } else {

            switch (axisOrientation) {
            case 0:
                DrawTextureRec(charaTexIdle, player.playerRec, player.position, WHITE);
                break;
            case 1:
                DrawTextureRec(charaTexUp, player.playerRec, player.position, WHITE);
                break;
            case 2:
                DrawTextureRec(charaTexDown, player.playerRec, player.position, WHITE);
                break;
            case 3:
                DrawTextureRec(charaTex, player.playerRec, player.position, WHITE);
                break;
            case 4:
                DrawTextureRec(charaTexIdleUp, player.playerRec, player.position, WHITE);
                break;
            case 5:
                DrawTextureRec(charaTexIdleDown, player.playerRec, player.position, WHITE);
                break;
            }

        }
    }
}

void drawHealthBar() {
    Vector2 barPos = {0, 0};
    Rectangle barRec = {barPos.x, barPos.y, (float) healthBarTex.width, (float) healthBarTex.height};
    switch (player.healthPoints) {
    case 6:
        DrawTextureRec(healthBarTex, barRec, barPos, WHITE);
        break;
    case 5:
        DrawTextureRec(healthBarTex2, barRec, barPos, WHITE);
        break;
    case 4:
        DrawTextureRec(healthBarTex3, barRec, barPos, WHITE);
        break;
    case 3:
        DrawTextureRec(healthBarTex4, barRec, barPos, WHITE);
        break;
    case 2:
        DrawTextureRec(healthBarTex5, barRec, barPos, WHITE);
        break;
    case 1:
        DrawTextureRec(healthBarTex6, barRec, barPos, WHITE);
        break;
    default:
        break;
    }
    
    //desenha est
    if(!flag_attack)DrawTextEx(font_counter_est, frontendHS, (Vector2){GetScreenWidth()*3/4,10}, font_counter_est.baseSize*2.0f , 1.0, BLUE);
    else if(flag_attack) DrawTextEx(font_counter_est, frontendHS, (Vector2){GetScreenWidth()*3/4,10}, font_counter_est.baseSize*2.0f , 1.0, ORANGE);

}

void unloadBodyTextures() {
    UnloadTexture(charaTex);
    UnloadTexture(charaTexDown);
    UnloadTexture(charaTexUp);
    UnloadTexture(charaTexIdle);
    UnloadTexture(charaTexIdleUp);
    UnloadTexture(charaTexDown);
    UnloadTexture(charaTexAtkSide);
    UnloadTexture(charaTexAtkUp);
}

Vector2 getCharacterPosition(){
    return player.position;
}

Vector2 orientationForColision(){
    Vector2 ans = {0,0};
    //printf("-> %d ", axisOrientation);
    if(axisOrientation == 3){
        if(currentOrientation == 1) ans.x = -1;
        else ans.x = 1;
    }
    else if(axisOrientation == 1) ans.y = 1;
    else if(axisOrientation == 2) ans.y = -1;

    return ans;
}

void reboundPlayer(Vector2 rebound_cononic){
    player.position.x += rebound_cononic.x * 20;
    player.position.y += rebound_cononic.y * 20;
}

void unloadAudios(){
    UnloadSound(walk);
    UnloadSound(attack_sound);
    CloseAudioDevice(); 
}

void receiveEnemyAttack(){
    // if(axisOrientation == 3){
    //     if(currentOrientation == 1) player.position.x -= 20;
    //     else player.position.x -= 20;
    // }
    // else if(axisOrientation == 1) player.position.y += 20;
    // else if(axisOrientation == 2) player.position.y -= 20;
    player.immunityIndex++;
    if (player.immunityIndex > 10) {
        if(axisOrientation==0&&currentOrientation==0) player.position.x += 30;
        if(axisOrientation==0&&currentOrientation==1) player.position.x -= 30;
        else if(axisOrientation==4) player.position.y += 30;
        else if(axisOrientation==5) player.position.y -= 30;

        player.immunityIndex = 0;
    }
 
}
int itsAttacking(){
    return isAttacking;
}

Vector2 getCharacterOrientation(){
    Vector2 ans;
    ans.x = (float)axisOrientation;
    ans.y = (float)currentOrientation;

    return ans; 
}
void receiveEnemyDamage(){
    player.immunityIndex++;

    if (player.immunityIndex > 10) {
        player.healthPoints -= 1;
        player.immunityIndex = 0;
    }
    
}
int itsDead(){
    return player.healthPoints <= 0; 
}
