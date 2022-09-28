#ifndef _BACKGROUND_H 
#define _BACKGROUND_H

#include "raylib.h"

void loadImageColision(char *file_name);
void initScene();
void drawScene();
void closeScene();
int hasAColision(Vector2 object);

#endif