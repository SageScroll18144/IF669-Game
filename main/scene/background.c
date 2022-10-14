#include "raylib.h"
#include "background.h"
#include <stdio.h>
#include <stdlib.h>

Font font_counter;
Texture2D backTex;
int bitmap[450][800];
Sound backMusic;

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
    font_counter = LoadFont("fonts/jupiter_crash.png"); 
    backMusic = LoadSound ("sounds/background.mp3");
}
void drawScene(int cnt){
    if (!IsSoundPlaying (backMusic)) PlaySound (backMusic);
    Rectangle recSrc = {0, 0, backTex.width, backTex.height};
    Rectangle recDest = {0, 0, 800, 450};
    Vector2 vecOrigin = {0, 0};

    DrawTexturePro(backTex, recSrc, recDest, vecOrigin, 0, WHITE);

    char strcnt[50];
    sprintf(strcnt, "x%d", cnt);

    DrawTextEx(font_counter, strcnt, (Vector2){GetScreenWidth()/2,10}, font_counter.baseSize*2.0f , 1.0, YELLOW);
}
void closeScene(){
    UnloadTexture(backTex);
    UnloadSound(backMusic);
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
