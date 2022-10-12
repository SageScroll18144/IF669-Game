#include "raylib.h"
#include "transition.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float raio = 1;
int contador = 1;
Sound transition = LoadSound ("sounds/batsFlying.mp3");
SetSoundVolume(transition, 0.7f);

void drawTransition(){
    PlaySound (transition);
    while(raio < 1000){
        BeginDrawing();
        ClearBackground(WHITE);
        DrawCircle(400, 225, raio, BLACK);
        
        EndDrawing();
        raio = raio + 10;

    }
    while(contador < 100) {DrawText("SURVIVE!", 350, 220, 20, DARKGRAY);contador = contador + 10;}
}
