#include "raylib.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
InitWindow(800, 450, "transicao");
float raio = 1;
int contador = 1;

while(contador < 10000){
    BeginDrawing();
    ClearBackground(GREEN);
    DrawCircle(400, 225, raio, BLACK);
    if(raio > 2000){
        DrawText("sobreviva!", 350, 220, 20, DARKGRAY);
    }
    EndDrawing();
    raio = raio + 1;
    contador = contador + 1;

}

CloseWindow();
return 0;
}
