#include "raylib.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

char title[] = "Kill all BatZombie";
char msg1[] = "Start";
char msg2[] = "How to play";
char msg3[] = "Exit";

Sound selection;
Font font;
Image imagem;
Texture2D textura;
Vector2 position;
const int spacings = 1;
int animFrames = 0;
unsigned int nextFrameDataOffset = 0;
int currentAnimFrame = 0;            
int frameCounter1 = 0;          
int menu_pos = 0;

void initMenu(){
    font = LoadFont("fonts/jupiter_crash.png");
    imagem = LoadImageAnim("assets/morcegos.gif", &animFrames);
    textura = LoadTextureFromImage(imagem);
    selection = LoadSound ("sounds/menu_select.mp3");
    SetSoundVolume(selection, 0.5f);
    position.x = 265;
    position.y = 100;
}

void updateMenu(){
    frameCounter1++;
        if (frameCounter1 >= 150)
        {
            currentAnimFrame++;
            if (currentAnimFrame >= animFrames) currentAnimFrame = 0;
            nextFrameDataOffset = (imagem.width)*(imagem.height)*4*currentAnimFrame;
            UpdateTexture(textura, ((unsigned char *)imagem.data) + nextFrameDataOffset);

            frameCounter1 = 0;
        }

       
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
    if (menu_pos == 0)
    {
        DrawTexture(textura, 0, 0, WHITE);
        DrawRectangle(280, 170, 250, 40, RED);
        DrawRectangle(280, 240, 250, 40, BLACK);
        DrawRectangle(280, 310, 250, 40, BLACK);

        DrawRectangle(280, 170, 8, 40, BLACK);
        DrawRectangle(522, 170, 8, 40, BLACK);
        //DrawRectangle(280, 162, 250, 8, BLACK);
        //DrawRectangle(280, 210, 250, 8, BLACK);
        DrawRectangle(280, 240, 8, 40, RED);
        DrawRectangle(522, 240, 8, 40, RED);
        //DrawRectangle(280, 232, 250, 8, RED);
        //DrawRectangle(280, 280, 250, 8, RED);
        DrawRectangle(280, 310, 8, 40, RED);
        DrawRectangle(522, 310, 8, 40, RED);
        //DrawRectangle(280, 302, 250, 8, RED);
        //DrawRectangle(280, 350, 250, 8, RED);
            
        DrawTextEx(font, title, position, font.baseSize*3.0f ,(float)spacings, RED);
        DrawText(msg1 , 375, 180, 20, BLACK);
        DrawText(msg2 , 347, 250, 20, WHITE);
        DrawText(msg3 , 385, 320, 20, WHITE);
    }
    else if (menu_pos == 1)
    {
        DrawTexture(textura, 0, 0, WHITE);
        DrawRectangle(280, 170, 250, 40, BLACK);
        DrawRectangle(280, 240, 250, 40, RED);
        DrawRectangle(280, 310, 250, 40, BLACK);

        DrawRectangle(280, 170, 8, 40, RED);
        DrawRectangle(522, 170, 8, 40, RED);
        // DrawRectangle(280, 162, 250, 8, RED);
        // DrawRectangle(280, 210, 250, 8, RED);
        DrawRectangle(280, 240, 8, 40, BLACK);
        DrawRectangle(522, 240, 8, 40, BLACK);
        //DrawRectangle(280, 232, 250, 8, BLACK);
        //DrawRectangle(280, 280, 250, 8, BLACK);
        DrawRectangle(280, 310, 8, 40, RED);
        DrawRectangle(522, 310, 8, 40, RED);
        //DrawRectangle(280, 302, 250, 8, RED);
        //DrawRectangle(280, 350, 250, 8, RED);
            
        DrawTextEx(font, title, position, font.baseSize*3.0f ,(float)spacings, RED);
        DrawText(msg1 , 375, 180, 20, WHITE);
        DrawText(msg2 , 347, 250, 20, BLACK);
        DrawText(msg3 , 385, 320, 20, WHITE);
    }
    else if (menu_pos == 2)
    {
        DrawTexture(textura, 0, 0, WHITE);
        DrawRectangle(280, 170, 250, 40, BLACK);
        DrawRectangle(280, 240, 250, 40, BLACK);
        DrawRectangle(280, 310, 250, 40, RED);

        DrawRectangle(280, 170, 8, 40, RED);
        DrawRectangle(522, 170, 8, 40, RED);
        //DrawRectangle(280, 162, 250, 8, RED);
        //DrawRectangle(280, 210, 250, 8, RED);
        DrawRectangle(280, 240, 8, 40, RED);
        DrawRectangle(522, 240, 8, 40, RED);
        //DrawRectangle(280, 232, 250, 8, RED);
        //DrawRectangle(280, 280, 250, 8, RED);
        DrawRectangle(280, 310, 8, 40, BLACK);
        DrawRectangle(522, 310, 8, 40, BLACK);
        //DrawRectangle(280, 302, 250, 8, BLACK);
        //DrawRectangle(280, 350, 250, 8, BLACK);
            
        DrawTextEx(font, title, position, font.baseSize*3.0f ,(float)spacings, RED);
        DrawText(msg1 , 375, 180, 20, WHITE);
        DrawText(msg2 , 347, 250, 20, WHITE);
        DrawText(msg3 , 385, 320, 20, BLACK);
    }
}

int getMenuPos(){
    return menu_pos;
}

void unLoadSounds(){
    UnloadSound(selection);
}
