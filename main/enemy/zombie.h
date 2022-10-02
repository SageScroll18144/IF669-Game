#ifndef _ZOMBIE_H 
#define _ZOMBIE_H

#include "raylib.h"

typedef struct {
    Vector2 position;
    Rectangle zombieRec;
} Zombie;

typedef struct{
    int x, y;
}pair;

void initZombie();
void drawZombie();
void updateZombieMain(Vector2 toHere);
void goAt(Zombie *zombie, Vector2 dest);

void append(pair **path, int *length, pair element);
void remover(pair** path, int *length);
void backtracking(pair** path, int *length, pair player);
void whichDirect(Vector2 player_pos);
void setMap(int a[450][800]);
void setMovementByBacktracking(Vector2 player_pos_arg, int map_input[450][800]);
Vector2 getZombiePosition();
int hasAMovement();

#endif