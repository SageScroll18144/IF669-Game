#ifndef _ZOMBIE_H 
#define _ZOMBIE_H

#include "raylib.h"

typedef struct {
    Vector2 position;
    Rectangle zombieRec;
} Zombie;

void initZombie();
void drawZombie();
void updateZombieMain(Vector2 toHere);
void goAt(Zombie *zombie, Vector2 player_pos);

#endif
