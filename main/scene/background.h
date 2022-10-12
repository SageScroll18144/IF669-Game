#ifndef _BACKGROUND_H 
#define _BACKGROUND_H

#include "raylib.h"

void loadImageColision(char *file_name);
void initScene();
void drawScene(int cnt);
void closeScene();
int hasAColision(Vector2 object);
int** getBitmap();

#endif