#include "raylib.h"
#include "final.h"


int contador_3d = 0;
int raio_3d = 0;

void transiton3Dto2D(){
    while(contador_3d < 5000){
        BeginDrawing();//
        if(contador_3d < 2500){
            DrawCircle(400, 225, raio_3d, BLACK);
            raio_3d = raio_3d + 5;
        }
        
        else{
            DrawCircle(400, 225, raio_3d, BLACK);
            raio_3d = raio_3d - 5;
        }
        
        if(contador_3d > 800 && contador_3d < 4200){
            DrawText("apos gusttavo dos ponteiros largar o mundo da musica e derrotar uma leva de morcegos", 50, 120, 17, RED);
            DrawText("ele passa muito tempo se preparando para o confronto contra o ACM", 110, 160, 17, RED);
            DrawText("derrote o ACM e salve os alunos de IP do CIn!", 154, 200, 20, RED);
        }
        contador_3d = contador_3d + 5;
        EndDrawing();//
    }
    return;
}
