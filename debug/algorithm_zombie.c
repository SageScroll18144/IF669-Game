#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int x, y;
}pair;

int l[] = {0,1,0,-1};
int c[] = {1,0,-1,0};
int bitmap[5][5];
int mark[5][5];

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
        int i = (*path)[*length-1].x + l[k];
        int j = (*path)[*length-1].y + c[k];

        if(i<0||j<0||i>=5||j>=5||bitmap[i][j]||mark[i][j]) continue;

        pair next_node;
        next_node.x = i;
        next_node.y = j;
        append(&(*path), length, next_node);
        //printf("%d, %d\n", (*path)[*length-1].x, (*path)[*length-1].y);
        backtracking(&(*path), length, player);
        remover(&(*path), length);
    }
}

int main(){
    for(int i=0;i<5;i++) for(int j=0;j<5;j++) {
        mark[i][j]=0;
        scanf("%d", &bitmap[i][j]);
    }
    pair *path = NULL;
    int length = 0;
    pair init;
    init.x=0;
    init.y=0;

    pair player;
    player.x=4;
    player.y=4;
    append(&path, &length, init);
    backtracking(&path, &length, player);
    printf("%d\n", length);
    return 0;
}
