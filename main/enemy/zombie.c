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

//Inicialização do zumbi
Zombie zombie;
Texture2D zombieTex;
float animTimeZ = 0;
int currentFramZ = 0;

//Função de inicialização
void initZombie(){
    path_ans = NULL;
    for(int i=0;i<450;i++) for(int j=0;j<450;j++) mark[i][j] = 0;

    zombie.position = (Vector2) {300, 200};
    
    zombieTex = LoadTexture("sprites/ZOMBIE_RUN.png");

    
}

//Função de animação
void goAt(Zombie *zombieObj, Vector2 dest){

    animTimeZ += GetFrameTime();

    if (animTimeZ >= 0.2f) {
        currentFramZ++;
        animTimeZ = 0.0f;

        if (zombieObj->position.x != dest.x) zombieObj->position.x += 20;
        if (zombieObj->position.y != dest.y && zombieObj->position.x == dest.x) zombieObj->position.y += 20;
        
    }

    zombieObj->zombieRec.x = (float) currentFramZ * (float) zombieObj->zombieRec.width;
    zombieObj->zombieRec.y = (float) currentFramZ * (float) zombieObj->zombieRec.height;

    if (currentFramZ > 7) {
        currentFramZ = 0;
        animTimeZ = 0;
    }
    
}

void updateZombieMain() {
    Rectangle frameRec = {zombie.position.x - 55, zombie.position.y - 20, (float) zombieTex.width / 8, (float) zombieTex.height};
    zombie.zombieRec = frameRec;

    goAt(&zombie, (Vector2) {400, 300});
}

void drawZombie() {
    DrawTextureRec(zombieTex, zombie.zombieRec, zombie.position, WHITE);
}

//Funções de perseguição da backtracking
void append(pair **path, int *length, pair element){
    pair *tmp = *path;
    *path = (pair *)realloc(*path, sizeof(pair)*(*length+1));

    if(*path == NULL){
        printf("erro na alocação\n");
        free(tmp);
        exit(1);
    }

    (*path)[(*length)] = element;
    (*length)++;
}
void remover(pair** path, int *length){
    if(*length>1){
        pair *tmp = *path;
        (*length)--;
        *path = (pair *) realloc(*path, (*length)*sizeof(pair));

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

void backtracking(pair** path, int *length, pair player){
    mark[(*path)[*length-1].x][(*path)[*length-1].y] = 1;
    if(player.x == (*path)[*length-1].x && player.y == (*path)[*length-1].y) {
        printf("path.: ");
        for(int k=0;k<(*length);k++){
            printf("(%d, %d) ", (*path)[k].x, (*path)[k].y);
        }
        printf("\n");
        
        return;   
    }
    for(int k=0;k<4;k++){
        //printf("klj");
        int i = (*path)[*length-1].x + l[k];
        int j = (*path)[*length-1].y + c[k];

        if(i<0||j<0||i>=450||j>=800||map[i][j]||mark[i][j]) continue;

        pair next_node;
        next_node.x = i;
        next_node.y = j;
        append(&(*path), length, next_node);
        //printf("%d, %d\n", (*path)[*length-1].x, (*path)[*length-1].y);
        backtracking(&(*path), length, player);
        remover(&(*path), length);
    }
}

void whichDirect(Vector2 player_pos){
    int dist_x = (int)player_pos.x - zombie.position.x;
    int dist_y = (int)player_pos.y - zombie.position.y;
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
void setMap(int a[450][800]){
    for(int i=0;i<450;i++) for(int j=0;j<450;j++) map[i][j] = a[i][j];
}
void setMovementByBacktracking(Vector2 player_pos_arg, int map_input[450][800]){

    Rectangle frameRec = {zombie.position.x - 55, zombie.position.y - 20, (float) zombieTex.width / 8, (float) zombieTex.height};
    zombie.zombieRec = frameRec;

    whichDirect(player_pos_arg);
    setMap(map_input);
    pair player_pos;
    pair zombie_pos;

    zombie_pos.x = (int)zombie.position.x;
    zombie_pos.y = (int)zombie.position.y;

    player_pos.x = (int)player_pos_arg.x;
    player_pos.y = (int)player_pos_arg.y;
    
    pair *path = NULL;
    int length = 0;
    append(&path, &length, zombie_pos);
    printf("(%d, %d)\n", player_pos.x, player_pos.y);
    printf("(%d, %d)\n", zombie_pos.x, zombie_pos.y);
    // for(int i=0;i<450;i++) {
    //     for(int j=0;j<800;j++){
    //         printf("%d", map[i][j]);
    //     }
    //     printf("\n");
    // }
    
    backtracking(&path, &length, player_pos);//certo 

    for(int i=1;i<length_path_ans;i++) {
        printf("(%d, %d)\n", path_ans[i].x, path_ans[i].y);
        goAt(&zombie, path_ans[i]);
    }
    // for(int i=0;i<length_path_ans;i++) {
    //     free((*path_ans)[i]);
    // }
    printf("cheguei aq\n");
    //pop(&path, &length);
    //while(!length_path_ans) pop(&path_ans, &length_path_ans);
    //free(path);
    //free(path_ans);
    
}
Vector2 getZombiePosition(){
    return zombie.position;
}