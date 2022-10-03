#include "raylib.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

char title[] = "TITULO DO JOGO";
char msg1[] = "Press Enter to start";
char msg2[] = "Press y for instructions";
char msg3[] = "Press esc to exit the game";

Font font;
Image imagem;
Texture2D textura;
Vector2 position;
const int spacings = 1;

void initMenu(){
    font = LoadFont("fonts/jupiter_crash.png");
    imagem = LoadImage("assets/menu.png"); 
    ImageResize(imagem, 800, 450)
    textura = LoadTextureFromImage(imagem);
   
    position.x = 300;
    position.y = 180;
}

void drawMenu(){
    DrawTexture(textura, 0, 0, WHITE);
    DrawRectangle(0, 0, 50, 450, BLACK);
    DrawRectangle(0, 0, 800, 50, BLACK);
    DrawRectangle(0,450 - 50, 800, 50, BLACK);
    DrawRectangle(800 - 50, 0, 50, 450, BLACK);
    DrawRectangle(270, 240, 250, 40, DARKGREEN);
    DrawRectangle(270, 290, 250, 40, DARKGREEN);
    DrawRectangle(270, 340, 250, 40, DARKGREEN);

    DrawTextEx(font, title, position, font.baseSize*2.0f ,(float)spacings, RED);
    DrawText(msg1 , 280, 250, 20, BLACK);
    DrawText(msg2 , 280, 300, 20, BLACK);
    DrawText(msg3 , 280, 350, 20, BLACK);
}

