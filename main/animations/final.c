#include "raylib.h"
#include "final.h"


int contador_3d = 0;
int raio_3d = 0;
int contador_aux = 0;

void transiton3Dto2D(){
    while(contador_aux < 15){
        BeginDrawing();//
        if(contador_3d < 1500){
            DrawCircle(400, 225, raio_3d, BLACK);
            if(contador_3d%2 == 0){
                raio_3d++;
            }
        }
        
        else{
            DrawCircle(400, 225, raio_3d, BLACK);
            if(contador_3d%2 == 0){
                raio_3d--;
            }
        }
        
        if(contador_3d > 1000 && contador_3d < 3000){
            DrawText("apos gusttavo dos ponteiros largar o mundo da musica e derrotar uma leva de morcegos", 50, 120, 17, RED);
            DrawText("ele passa muito tempo se preparando para o confronto contra o ACM", 110, 160, 17, RED);
            DrawText("derrote o ACM e salve os alunos de IP do CIn!", 154, 200, 20, RED);
        }
        contador_3d++;
        if(contador_3d == 2999) {
             contador_3d = 1001;
            contador_aux++;
        }
        EndDrawing();//
    }
    return;
}
