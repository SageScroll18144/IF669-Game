#ifndef _ZOMBIE_H 
#define _ZOMBIE_H

#include "raylib.h"

void append(Vector2 **path, int *length, Vector2 element);
void pop(Vector2 **path, int *length);

#endif