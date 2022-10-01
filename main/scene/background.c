#include "raylib.h"
#include "background.h"
#include <stdio.h>
#include <stdlib.h>

Texture2D backTex;
int bitmap[450][800];

void loadImageColision(char *file_name){
    FILE *file = fopen(file_name, "r");
    int l[2];

    if(file == NULL) {
        printf("*ERRO DE ABERTURA*\n");
        exit(1);
    }
    fscanf(file, "%d %d", &l[0], &l[1]);

    if(l[0]!=800 && l[1]!=450){
        printf("*ERRO NA DIMENSÃO DA IMAGEM*\n");
        exit(1);
    }
    
    for(int i=0;i<l[1];i++) for(int j=0;j<l[0];j++) fscanf(file, "%d", &bitmap[i][j]);
    
    fclose(file);

}

void initScene(){
    backTex = LoadTexture("assets/map.png");
    loadImageColision("bitmaps/mat.txt");   
}
void drawScene(){
    Rectangle recSrc = {0, 0, backTex.width, backTex.height};
    Rectangle recDest = {0, 0, 800, 450};
    Vector2 vecOrigin = {0, 0};

    DrawTexturePro(backTex, recSrc, recDest, vecOrigin, 0, WHITE);
}
void closeScene(){
    UnloadTexture(backTex);
}
int hasAColision(Vector2 object){
    int x = (int)object.x+40;
    int y = (int)object.y+80;
    
    //printf("(%d,  %d) ", x, y); 

    // if(x<0||y<0||x>=800||y>=450||bitmap[y][x]) printf("COLISAO\n");
    // else printf("NAO\n");
    
    return (x<0||y<0||x>=800||y>=450||bitmap[y][x]);
}

int** getBitmap(){
    int **ans;

    ans = (int **) malloc(sizeof(int *) * 450);
    for(int i=0;i<450;i++) ans[i] = (int *) malloc(sizeof(int) * 800); 

    for(int i=0;i<450;i++) for(int j=0;j<800;j++) ans[i][j] = bitmap[i][j];

    return ans;
}