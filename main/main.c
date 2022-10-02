#include "raylib.h"
#include "character/body.h"
#include "scene/background.h"
#include "enemy/zombie.h"
#include "menu/menu.h"
#include <stdio.h>

void drawGame();
void getBitmapForMain();

int bit[450][800];

int main(void){
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Joguinho");
    InitAudioDevice();
    
    initMenu();
    initScene();
    initCharacter();
    initZombie();
    
    getBitmapForMain();
    // for(int i=0;i<450;i++) {
    //     for(int j=0;j<800;j++){
    //         printf("%d ", bit[i][j]);
    //     } 
    //     printf("\n");
    // }
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    int flag_screen = 0;
    //updateZombieMain();
    // Main game loop
    int teste=1;
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // seta a transição de tela
        if(IsKeyDown(KEY_E)) flag_screen = 1;

        if(flag_screen == 1){
            // zombie
            updateZombieMain(getCharacterPosition());
            if(hasAColision(getZombiePosition())){
                Vector2 compensation = orientationForColisionZombie();
                
                reboundZombie(compensation);
            }
            //setMovementByBacktracking(getCharacterPosition(), bit);
            
            //movimentação do personagem
            updatePlayerMain();
            if(hasAColision(getCharacterPosition())){
                Vector2 compensation = orientationForColision();
                
                reboundPlayer(compensation);
            }
        }
        
        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
            if(flag_screen == 0) drawMenu();
            if(flag_screen == 1) drawGame();

            
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    unloadBodyTextures();
    unloadAudios();
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    closeScene();

    return 0;
}

void drawGame(){
    drawScene();
    drawCharacter();
    drawZombie();
}
void getBitmapForMain(){
    int **ans = getBitmap();
    for(int i=0;i<450;i++){
        for(int j=0;j<800;j++){
            bit[i][j] = ans[i][j];
        }
    }    
    
}