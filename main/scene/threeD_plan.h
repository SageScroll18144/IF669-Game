#ifndef _THREED_PLAN_H 
#define _THREED_PLAN_H

#include "raylib.h"

void init3DScene();
void update3DScene();
void draw3DScene();
void drawHpBar();
void drawAcmBar();
void drawBullet();
void unLoadModels();
float mod(float a);
void shotABullet();
int get3DPlayerHp();
int ACMDie();

#endif