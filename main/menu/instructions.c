#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

Font fonte;
Image image;
Texture2D texture;

void instructions() {
  while(!IsKeyPressed(KEY_ENTER)) {
     fonte = LoadFont("fonts/jupiter_crash.png");
     DrawTexture(textura, 0, 0, WHITE);
     image = LoadImage("assets/Instructions.png");
     texture = LoadTextureFromImage(imagem);
}
CloseWindow();
  }
