#ifndef _BODY_H 
#define _BODY_H

#include "raylib.h"
#define PLAYER_HOR_SPD 500.0f

extern Texture2D healthBarTex, healthBarTex2, healthBarTex3, healthBarTex4, healthBarTex5, healthBarTex6;

typedef struct {
    Vector2 position;
    Rectangle playerRec;
    int healthPoints, immunityIndex;
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
void drawHealthBar();
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
Vector2 getCharacterOrientation();
void receiveEnemyDamage();
int itsDead();

#endif