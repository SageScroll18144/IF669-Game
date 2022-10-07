#ifndef _ZOMBIE_H 
#define _ZOMBIE_H

#include "raylib.h"

typedef struct {
    Vector2 position;
    Rectangle enemyRec;
    Texture2D enemyTex;
} Enemy;

void initEnemy();
void drawEnemy();
void updateEnemyMain(Vector2 toHere);
void goAt(Enemy *enemy, Vector2 player_pos);
void setHowManyEnemies(int qtd);
void colision();

#endif
