#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"


int contador = 0;
int raio = 0;

void transiton3Dto2D(){
    while(contador <30000){
        
        if(contador < 15000){
            DrawCircle(400, 225, raio, BLACK);
            if(contador%2 == 0){
                raio++;
            }
        }
        
        else{
            DrawCircle(400, 225, raio, BLACK);
            if(contador%2 == 0){
                raio--;
            }
        }
        
        if(contador > 1000 && contador < 29000){
            DrawText("apos gusttavo dos ponteiros largar o mundo da musica e derrotar uma leva de morcegos", 50, 120, 17, RED);
            DrawText("ele passa muito tempo se preparando para o confronto contra o ACM", 110, 160, 17, RED);
            DrawText("derrote o ACM e salve os alunos de IP do CIn!", 154, 200, 20, RED);
        }
        contador++;
    }
    return;
}


