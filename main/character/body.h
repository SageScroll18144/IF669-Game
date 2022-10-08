#ifndef _BODY_H 
#define _BODY_H

#include "raylib.h"
#define PLAYER_HOR_SPD 500.0f

typedef struct {
    Vector2 position;
    Rectangle playerRec;
    float speed;
} Player;

typedef struct {
    Rectangle rect;
    int blocking;
    Color color;
} EnvItem;

void initCharacter();
void checkMovement();
//void colision();
void drawCharacter();
void updatePlayerMain();
void updatePlayer(Player *player, int *currentFrame, int *frameCounter, int *currentOrientation, int *axisOrientation, int deltaTime);
void drawAttack(Player *player);
void unloadBodyTextures();
Vector2 getCharacterPosition();
Vector2 orientationForColision();
void reboundPlayer(Vector2 rebound_cononic);
void unloadAudios();
void receiveEnemyAttack();
int itsAttacking();
int getCharacterOrientation();

#endif