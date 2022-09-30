#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>



int main()
{

const int tamLinha = 800;
const int tamColuna = 450;
InitWindow(tamLinha, tamColuna, "tecla");
InitAudioDevice();

char title[] = "TITULO DO JOGO";
char msg1[] = "press SPACE to start";
char msg2[] = "press P to stop the music";

Font font = LoadFont("resources/fonts/jupiter_crash.png");

Music music = LoadMusicStream("C:\\Users\\Guilherme\\OneDrive\\Área de Trabalho\\Gusttavo Lima - Bloqueado (Buteco In Boston) (320 kbps).mp3");
SetTargetFPS(60);
PlayMusicStream(music);
int ifPause = 0;
Vector2 position = {0};
const int spacings = 1;
while(!WindowShouldClose()){
    //Controle da musica
    if(IsKeyPressed(KEY_P)){
        if(ifPause == 1){

            ResumeMusicStream(music);
            ifPause = 0;
        }
        else if(ifPause == 0){

            PauseMusicStream(music);
            ifPause = 1;
        }

    }
    //Para iniciar o jogo
    if(IsKeyPressed(KEY_SPACE)){
        //comecar o jogo!!
    }

    //*******parte de Design******

    UpdateMusicStream(music);

    position.x = 300;
    position.y = 180;
    //*****Começo do desenho*****
    BeginDrawing();

    ClearBackground(DARKGREEN);

    DrawRectangle(0, 0, 50, tamColuna, BLACK);
    DrawRectangle(0, 0, tamLinha, 50, BLACK);
    DrawRectangle(0,tamColuna - 50, tamLinha, 50, BLACK);
    DrawRectangle(tamLinha - 50, 0, 50, tamColuna, BLACK);
    DrawRectangle(270, 240, 250, 40, BLACK);

    DrawTextEx(font, title, position, font.baseSize*2.0f ,(float)spacings, RED);
    DrawText(msg1 , 280, 250, 20, LIGHTGRAY);
    DrawText(msg2, 320, 300, 10, BLACK);

    EndDrawing();
}
UnloadMusicStream(music);
UnloadFont(font);
CloseAudioDevice();
CloseWindow();

    return 0;
}
