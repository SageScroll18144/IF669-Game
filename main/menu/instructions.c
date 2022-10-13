#include "raylib.h"
#include "instructions.h"
#include <stdio.h>
#include <stdlib.h>

Image imagem;
Texture2D texture;

void initInstructions(){
    image = LoadImage("assets/Instructions.png");
    texture = LoadTextureFromImage(image);
}

void drawInstructions(){
        DrawTexture(texture, 0, 0, WHITE);
   }
