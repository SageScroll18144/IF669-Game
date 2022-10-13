#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"

int main(){
InitWindow(800, 450, "game over");
Vector2 position = {400, 225};
int circle = 0, contador = 0;

while( contador < 10000){

    BeginDrawing();

    ClearBackground(WHITE);
    DrawCircle(position.x, position.y, circle, BLACK);
    if(contador > 2000){
        DrawText("SE FODEU", 280, 210, 50, RED);
    }

    EndDrawing();
    if(contador%2 == 0){
        circle++;
    }
    contador++;
}
CloseWindow();
return 0;
}
