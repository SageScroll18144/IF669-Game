#include "raylib.h"
#include "raymath.h"
#include "body.h"
#include <stdbool.h>

Player player = {0};
Texture2D charaTex, charaTexUp, charaTexDown, charaTexIdle, charaTexIdleUp, charaTexIdleDown;
//Rectangle frameRec;
int currentFrame = 1, currentOrientation = 1, orientation = 1, axisOrientation = 0;
int frameCounter = 0;
EnvItem envItems[] = {
    {{ 0, 0, 1000, 400 }, 0, LIGHTGRAY },
    {{ 0, 400, 1000, 200 }, 1, GRAY },
    {{ 300, 200, 400, 10 }, 1, GRAY },
    {{ 250, 300, 100, 10 }, 1, GRAY },
    {{ 650, 300, 100, 10 }, 1, GRAY }
};
int envItemLength = sizeof(envItems) / sizeof(envItems[0]);

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
}

void updatePlayer(Player *player, int *currentFrame, int *frameCounter, int *currentOrientation, int *axisOrientation, int deltaTime) {
    int frameSpeed = 8;

    if (*currentFrame > 5) *currentFrame = 0;
    player->playerRec.x = (float)*currentFrame * (float) player->playerRec.width;
    player->playerRec.y = (float)*currentFrame * (float) player->playerRec.height;


    if (IsKeyDown(KEY_RIGHT)) {
        *axisOrientation = 0;
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
    }

    else if (IsKeyDown(KEY_LEFT)) {
        *axisOrientation = 0;
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
            
    }

    else if (IsKeyDown(KEY_UP)) {
        *axisOrientation = 1;
        (*frameCounter)++;

        if (*frameCounter >= 60/frameSpeed) {
            (*frameCounter) = 0;
            
            (*currentFrame)++;

            if (!(*currentOrientation)) {
                (*currentOrientation) = 1;
                player->playerRec.height *= -1;
            }
            player->position.y -= 20;
        }
    }
    
    else if (IsKeyDown(KEY_DOWN)) {
        *axisOrientation = 2;
        (*frameCounter)++;

        if (*frameCounter >= 60/frameSpeed) {
            (*frameCounter) = 0;
            
            (*currentFrame)++;

            if (!(*currentOrientation)) {
                (*currentOrientation) = 1;
                player->playerRec.height *= -1;
            }
            player->position.y += 20;
        }
    }

    else if (IsKeyReleased(KEY_RIGHT) || IsKeyReleased(KEY_LEFT))  *axisOrientation = 3;
    else if (IsKeyReleased(KEY_UP)) *axisOrientation = 4;
    else if (IsKeyReleased(KEY_DOWN)) *axisOrientation = 5;
    
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

    switch (axisOrientation) {
    case 0:
        DrawTextureRec(charaTex, player.playerRec, player.position, WHITE);
        break;
    case 1:
        DrawTextureRec(charaTexUp, player.playerRec, player.position, WHITE);
        break;
    case 2:
        DrawTextureRec(charaTexDown, player.playerRec, player.position, WHITE);
        break;
    case 3:
        DrawTextureRec(charaTexIdle, player.playerRec, player.position, WHITE);
        break;
    case 4:
        DrawTextureRec(charaTexIdleUp, player.playerRec, player.position, WHITE);
        break;
    case 5:
        DrawTextureRec(charaTexIdleDown, player.playerRec, player.position, WHITE);
        break;
    }

}

void unloadBodyTextures() {
    UnloadTexture(charaTex);
    UnloadTexture(charaTexDown);
    UnloadTexture(charaTexUp);
    UnloadTexture(charaTexIdle);
    UnloadTexture(charaTexIdleUp);
    UnloadTexture(charaTexDown);
}

Vector2 getCharacterPosition(){
    return player.position;
}