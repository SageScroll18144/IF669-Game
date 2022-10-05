#include "raylib.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

char title[] = "Killer all BatZombie";
char msg1[] = "Play";
char msg2[] = "Instructions";
char msg3[] = "Exit";

Sound selection;
Font font;
Image imagem;
Texture2D textura;
Vector2 position;
const int spacings = 1;

int menu_pos = 0;

void initMenu(){
    font = LoadFont("fonts/jupiter_crash.png");
    imagem = LoadImage("assets/menu.png"); 
    ImageResize(&imagem, 800, 450);
    textura = LoadTextureFromImage(imagem);
    selection = LoadSound ("sounds/menu_select.mp3");
    SetSoundVolume(selection, 1.0f);
   
    position.x = 300;
    position.y = 180;
}

void updateMenu(){
    if (IsKeyPressed (KEY_DOWN)) {
        menu_pos++;
        menu_pos %= 3;
        PlaySound(selection);
    }
    else if (IsKeyPressed (KEY_UP)){
        menu_pos--; 
        if (menu_pos < 0) menu_pos = 2;
        PlaySound(selection);
    }
    
}

void drawMenu(){
    if (menu_pos == 0){
        DrawTexture(textura, 0, 0, WHITE);
        DrawRectangle(0, 0, 50, 450, BLACK);
        DrawRectangle(0, 0, 800, 50, BLACK);
        DrawRectangle(0,450 - 50, 800, 50, BLACK);
        DrawRectangle(800 - 50, 0, 50, 450, BLACK);
        DrawRectangle(270, 240, 250, 40, YELLOW);
        DrawRectangle(270, 290, 250, 40, DARKGREEN);
        DrawRectangle(270, 340, 250, 40, DARKGREEN);

        DrawTextEx(font, title, position, font.baseSize*2.0f ,(float)spacings, RED);
        DrawText(msg1 , 280, 250, 20, BLACK);
        DrawText(msg2 , 280, 300, 20, BLACK);
        DrawText(msg3 , 280, 350, 20, BLACK);
    }
    else if (menu_pos == 1){
        DrawTexture(textura, 0, 0, WHITE);
        DrawRectangle(0, 0, 50, 450, BLACK);
        DrawRectangle(0, 0, 800, 50, BLACK);
        DrawRectangle(0,450 - 50, 800, 50, BLACK);
        DrawRectangle(800 - 50, 0, 50, 450, BLACK);
        DrawRectangle(270, 240, 250, 40, DARKGREEN);
        DrawRectangle(270, 290, 250, 40, YELLOW);
        DrawRectangle(270, 340, 250, 40, DARKGREEN);

        DrawTextEx(font, title, position, font.baseSize*2.0f ,(float)spacings, RED);
        DrawText(msg1 , 280, 250, 20, BLACK);
        DrawText(msg2 , 280, 300, 20, BLACK);
        DrawText(msg3 , 280, 350, 20, BLACK);
    }
    else if (menu_pos == 2){
        DrawTexture(textura, 0, 0, WHITE);
        DrawRectangle(0, 0, 50, 450, BLACK);
        DrawRectangle(0, 0, 800, 50, BLACK);
        DrawRectangle(0,450 - 50, 800, 50, BLACK);
        DrawRectangle(800 - 50, 0, 50, 450, BLACK);
        DrawRectangle(270, 240, 250, 40, DARKGREEN);
        DrawRectangle(270, 290, 250, 40, DARKGREEN);
        DrawRectangle(270, 340, 250, 40, YELLOW);

        DrawTextEx(font, title, position, font.baseSize*2.0f ,(float)spacings, RED);
        DrawText(msg1 , 280, 250, 20, BLACK);
        DrawText(msg2 , 280, 300, 20, BLACK);
        DrawText(msg3 , 280, 350, 20, BLACK);
    }

}

int getMenuPos(){
    return menu_pos;
}

void unLoadSounds(){
    UnloadSound(selection);
}