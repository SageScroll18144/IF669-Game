#ifndef _ZOMBIE_H 
#define _ZOMBIE_H

#include "raylib.h"

typedef struct {
    Vector2 position;
    Rectangle enemyRec;
    Texture 2D enemyTex;
} Enemy;

void initEnemy();
void drawEnemy();
void updateEnemyMain(Vector2 toHere);
void goAt(Enemy *enemy, Vector2 player_pos, int idx);
void setHowManyEnemys(int qtd);

#endif
