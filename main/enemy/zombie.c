#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"
#include "zombie.h"

//Variaveis da perseguição do backtracking
int l[4];
int c[4];
int map[450][800];
int mark[450][800];
Vector2 *path_ans;
int length_path_ans;

//Função de inicialização
void initZombie(){
    path_ans = NULL;
}

//Função de animação
void goAt(Vector2 point){

}

//Funções de perseguição da backtracking
void append(Vector2 **path, int *length, Vector2 element){
    Vector2 *tmp = *path;
    *path = (Vector2 *)realloc(*path, sizeof(Vector2)*(*length+1));

    if(*path == NULL){
        printf("erro na alocação\n");
        free(tmp);
        exit(1);
    }

    (*path)[(*length)] = element;
    (*length)++;
}

void pop(Vector2** path, int *length){
    if(*length>1){
        Vector2 *tmp = *path;
        (*length)--;
        *path = (Vector2 *) realloc(*path, (*length)*sizeof(Vector2));

        if(*path == NULL){
            printf("erro na alocação\n");
            free(tmp);
            exit(1);
        }
    }else if(*length>0){
        (*length)--;
        *path = NULL;
    }
}

void backtracking(Vector2 **path, int *length, Vector2 player){
    mark[(int)((*path)[*length-1].x)][(int)((*path)[*length-1].y)] = 1;
    if(player.x == (*path)[*length-1].x && player.y == (*path)[*length-1].y) {
        // printf("path.: ");
        // for(int k=0;k<(*length);k++){
        //     printf("(%d, %d) ", (*path)[k].x, (*path)[k].y);
        // }
        // printf("\n");
        Vector2 *tmp = path_ans;
        path_ans = (Vector2 *) malloc((*length)*sizeof(Vector2));

        if(path_ans == NULL){
            printf("erro na alocação da resposta\n");
            free(tmp);
            exit(1);
        }
        
        for(int k=0;k<(*length);k++) path_ans[k] = (*path)[k];
        length_path_ans = (*length);
        return;   
    }
    for(int k=0;k<4;k++){
        int i = (*path)[*length-1].x + l[k];
        int j = (*path)[*length-1].y + c[k];

        if(i<0||j<0||i>=450||j>=800||map[i][j]||mark[i][j]) continue;

        Vector2 next_node;
        next_node.x = i;
        next_node.y = j;
        append(&(*path), length, next_node);
        //printf("%d, %d\n", (*path)[*length-1].x, (*path)[*length-1].y);
        backtracking(&(*path), length, player);
        pop(&(*path), length);
    }
}

void whichDirect(Vector2 zombie_pos, Vector2 player_pos){
    int dist_x = player_pos.x - zombie_pos.x;
    int dist_y = player_pos.y - zombie_pos.y;
    if(dist_x > 0){
        l[1] = 1;
        c[1] = 0;

        l[3] = -1;
        c[3] = 0;
    }else{
        l[1] = -1;
        c[1] = 0;

        l[3] = 1;
        c[3] = 0;
    }
    
    if(dist_y > 0) {
        l[0] = 0;
        c[0] = 1;

        l[2] = 0;
        c[2] = -1;
    }else{
        l[0] = 0;
        c[0] = -1;

        l[2] = 0;
        c[2] = 1;
    }
}

void setMovementByBacktracking(Vector2 zombie_pos, Vector2 player_pos){
    //l & c
    whichDirect(zombie_pos, player_pos);

    Vector2 *path = NULL;
    int length = 0;
    append(&path, &length, zombie_pos);
    backtracking(&path, &length, player_pos);

    for(int i=1;i<length_path_ans;i++) goAt(path_ans[i]);
}