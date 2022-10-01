#ifndef _ZOMBIE_H 
#define _ZOMBIE_H

#include "raylib.h"

void initZombie();
void goAt(Vector2 point);

void append(Vector2 **path, int *length, Vector2 element);
void pop(Vector2 **path, int *length);
void backtracking(Vector2 **path, int *length, Vector2 player);
void whichDirect(Vector2 zombie_pos, Vector2 player_pos);
void setMap(int a[450][800]);
void setMovementByBacktracking(Vector2 zombie_pos, Vector2 player_pos, int map_input[450][800]);

#endif