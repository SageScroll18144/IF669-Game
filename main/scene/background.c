#include "raylib.h"
#include "background.h"

Texture2D backTex;

void initScene(){
    backTex = LoadTexture("assets/map.png");
}
void drawScene(){
    Rectangle recSrc = {0, 0, backTex.width, backTex.height};
    Rectangle recDest = {0, 0, 800, 450};
    Vector2 vecOrigin = {0, 0};

    DrawTexturePro(backTex, recSrc, recDest, vecOrigin, 0, WHITE);
    //DrawTexturePro(backTex, recSrc, recDest, vecOrigin, 0, WHITE);
}
void closeScene(){
    UnloadTexture(backTex);
}