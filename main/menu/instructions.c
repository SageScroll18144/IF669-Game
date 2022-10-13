#include "raylib.h"
#include "instructions.h"
#include <stdio.h>
#include <stdlib.h>

Font font;
Image imagem;
Texture2D texture;

void initInstructions(){
    fonte = LoadFont("fonts/jupiter_crash.png");
    image = LoadImage("assets/Instructions.png");
    texture = LoadTextureFromImage(image);
}

void drawInstructions(){
        DrawTexture(texture, 0, 0, WHITE);
   }
