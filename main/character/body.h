#ifndef _BODY_H 
#define _BODY_H

#include "raylib.h"
#define PLAYER_HOR_SPD 500.0f

typedef struct {
    Vector2 position;
    Rectangle playerRec;
    float speed;
    bool canJump;
} Player;

typedef struct {
    Rectangle rect;
    int blocking;
    Color color;
} EnvItem;

void initCharacter();
void checkMovement();
void colision();
void drawCharacter();
void updatePlayerMain();
void updatePlayer(Player *player, int *currentFrame, int *frameCounter, int *currentOrientation, int *axisOrientation, int deltaTime);
void unloadBodyTextures();
Vector2 getCharacterPosition();

#endif