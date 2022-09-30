#include "raylib.h"
#include "raymath.h"
#include "body.h"
#include <stdbool.h>
#include "stdio.h"

Player player = {0};
Texture2D charaTex, charaTexUp, charaTexDown, charaTexIdle, charaTexIdleUp, charaTexIdleDown, charaTexAtkSide, charaTexAtkUp, charaTexAtkDown;
//Rectangle frameRec;
int currentFrame = 1, currentOrientation = 1, orientation = 1, axisOrientation = 0;
int frameCounter = 0, isAttacking = 0, atkCnt = 0;
EnvItem envItems[] = {
    {{ 0, 0, 1000, 400 }, 0, LIGHTGRAY },
    {{ 0, 400, 1000, 200 }, 1, GRAY },
    {{ 300, 200, 400, 10 }, 1, GRAY },
    {{ 250, 300, 100, 10 }, 1, GRAY },
    {{ 650, 300, 100, 10 }, 1, GRAY }
};
int envItemLength = sizeof(envItems) / sizeof(envItems[0]);
Sound walk;

void initCharacter(){
    //player = {0};
    player.position = (Vector2) {400, 280};
    player.speed = 0;
    player.canJump = false;

    charaTex = LoadTexture("sprites/RUN_SIDES.png");
    charaTexUp = LoadTexture("sprites/RUN_UP.png");
    charaTexDown = LoadTexture("sprites/RUN_DOWN.png");

    charaTexIdle = LoadTexture("sprites/IDLE_SIDE.png");
    charaTexIdleUp = LoadTexture("sprites/IDLE_UP.png");
    charaTexIdleDown = LoadTexture("sprites/IDLE_DOWN.png");

    charaTexAtkSide = LoadTexture("sprites/ATTACK_SIDES.png");
    charaTexAtkUp = LoadTexture("sprites/ATTACK_UP.png");
    charaTexAtkDown = LoadTexture("sprites/ATTACK_DOWN.png");

    walk = LoadSound("sounds/walking_sound3.mp3");
    SetSoundVolume(walk, 1.0f);
}

void updatePlayer(Player *player, int *currentFrame, int *frameCounter, int *currentOrientation, int *axisOrientation, int deltaTime) {
    int frameSpeed = 8;

    if (*currentFrame > 5) *currentFrame = 0;
    player->playerRec.x = (float)*currentFrame * (float) player->playerRec.width;
    player->playerRec.y = (float)*currentFrame * (float) player->playerRec.height;


    if (IsKeyDown(KEY_RIGHT)) {
        PlaySound(walk);
        *axisOrientation = 3;
        (*frameCounter)++;

        if (*frameCounter >= 60/frameSpeed) {
            (*frameCounter) = 0;
            
            (*currentFrame)++;

            if (!(*currentOrientation)) {
                (*currentOrientation) = 1;
                player->playerRec.width *= -1;
            }
            player->position.x += 20;
        }
        
        //while();
    }

    else if (IsKeyDown(KEY_LEFT)) {
        *axisOrientation = 3;
        (*frameCounter)++;

        if (*frameCounter >= 60/frameSpeed) {
            *frameCounter = 0;
            
            (*currentFrame)++;

            if (*currentOrientation) {
                *currentOrientation = 0;
                player->playerRec.width *= -1;
            }
            player->position.x -= 20;
        }   
        PlaySound(walk);
    }

    else if (IsKeyDown(KEY_UP)) {
        *axisOrientation = 1;
        (*frameCounter)++;

        if (*frameCounter >= 60/frameSpeed) {
            (*frameCounter) = 0;
            
            (*currentFrame)++;

            player->position.y -= 20;
        }
        PlaySound(walk);
    }
    
    else if (IsKeyDown(KEY_DOWN)) {
        *axisOrientation = 2;
        (*frameCounter)++;

        if (*frameCounter >= 60/frameSpeed) {
            (*frameCounter) = 0;
            
            (*currentFrame)++;

            player->position.y += 20;
        }
        PlaySound(walk);
    }

    else if (IsKeyReleased(KEY_RIGHT) || IsKeyReleased(KEY_LEFT))  *axisOrientation = 0;
    else if (IsKeyReleased(KEY_UP)) *axisOrientation = 4;
    else if (IsKeyReleased(KEY_DOWN)) *axisOrientation = 5;

    if (IsKeyPressed(KEY_SPACE)) {
        isAttacking = 1;
    }
    
}

void drawAttack(Player *player) {

    int frameCounter1 = 0, frameSpeed1 = 1, currentFrame1 = 1;
    while (isAttacking) {
        frameCounter1++;

        if (frameCounter1 >= 60/frameSpeed1) {
            frameCounter1 = 0;
            currentFrame1++;

            switch (axisOrientation) {
            case 0:
                player->playerRec.x = (float) currentFrame1 * (float) player->playerRec.width;
                DrawTextureRec(charaTexAtkSide, player->playerRec, player->position, WHITE);
                break;
            
            case 1:
                player->playerRec.y = (float) currentFrame * (float) player->playerRec.height;
                DrawTextureRec(charaTexAtkUp, player->playerRec, player->position, WHITE);
                break;
            
            case 2:
                player->playerRec.y = (float) currentFrame * (float) player->playerRec.height;
                DrawTextureRec(charaTexAtkDown, player->playerRec, player->position, WHITE);
                break;
            }
        }

        if (currentFrame1 == 6) isAttacking = 0;
    }
          
}

void updatePlayerMain(){
    orientation = currentOrientation ? 1 : -1;
    Rectangle frameRec = {player.position.x, player.position.y - 24, (float) orientation * charaTex.width / 6, (float) charaTex.height};

    player.playerRec = frameRec;
    
    float deltaTime = GetFrameTime();
    
    updatePlayer(&player, &currentFrame, &frameCounter, &currentOrientation, &axisOrientation, deltaTime);

    
}

void colision(){
    if (player.position.y<=0) player.position.y += 20;
    if (player.position.y>= GetScreenHeight())  player.position.y  -= 20;
    if (player.position.x <=0) player.position.x  += 20;
    if (player.position.x >= GetScreenWidth())  player.position.x  -= 20;

}
void drawCharacter(){
    //DrawCircleV(ballPosition, 50, MAROON);
    // for (int i = 0; i < envItemLength; i++) DrawRectangleRec(envItems[i].rect, envItems[i].color);
    if (isAttacking) {
        drawAttack(&player);
        isAttacking = 0;
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
    CloseAudioDevice(); 
}