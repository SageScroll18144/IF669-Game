#include "raylib.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

char title[] = "TITULO DO JOGO";
char msg1[] = "Press Enter to start";
char msg2[] = "Press y for instructions";
char msg3[] = "Press x to exit the game";

Font font;
Vector2 position;
const int spacings = 1;

void initMenu(){
    font = LoadFont("fonts/jupiter_crash.png");

    position.x = 300;
    position.y = 180;
}
void drawMenu(){
    DrawRectangle(0, 0, 50, 450, BLACK);
    DrawRectangle(0, 0, 800, 50, BLACK);
    DrawRectangle(0,450 - 50, 800, 50, BLACK);
    DrawRectangle(800 - 50, 0, 50, 450, BLACK);
    DrawRectangle(270, 240, 250, 40, BLACK);

    DrawTextEx(font, title, position, font.baseSize*2.0f ,(float)spacings, RED);
    DrawText(msg1 , 280, 250, 20, LIGHTGRAY);
    DrawText(msg2 , 280, 400, 20, LIGHTGRAY);
    DrawText(msg3 , 280, 550, 20, LIGHTGRAY);
}

