#include "raylib.h"
#include "background.h"
#include <stdbool.h>
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

    if(l[0]!=450 && l[1]!=800){
        printf("*ERRO NA DIMENSÃO DA IMAGEM*\n");
        exit(1);
    }
    
    for(int i=0;i<l[0];i++) for(int j=0;j<l[1];j++) fscanf(file, "%d", &bitmap[i][j]);
    
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
void hasAColision(Vector2 object){
    if(bitmap[(int)object.x][(int)object.y]) printf("COLISAO\n");
    else printf("NAO\n");
}