#ifndef _ZOMBIE_H 
#define _ZOMBIE_H

#include "raylib.h"

typedef struct {
    int axisOrientation;
    Vector2 position;
    Rectangle enemyRec;
    Texture2D enemyTex, enemyUpTex, enemyDownTex;
} Enemy;

void initEnemy();
void drawEnemy();
void updateEnemyMain(Vector2 toHere);
void goAt(Enemy *enemy, Vector2 player_pos);
void setHowManyEnemies(int qtd);
void colision();
void receiveCharacterAttack(int idx, int axis);
int getHowMany();
Vector2 getEnemyPos(int idx);
void receiveCharacterDamage(int idx);
void killEnemy(int idx);
void setCharacterHitKill(int value);
int getHowManyAlreadyDie();

#endif
