#include "raylib.h"
#include "character/body.h"
#include "scene/background.h"
#include "enemy/zombie.h"
#include "menu/menu.h"
#include <stdio.h>

void drawGame();

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
    
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    int flag_screen = 0;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // seta a transição de tela
        if(IsKeyDown(KEY_E)) flag_screen = 1;

        if(flag_screen == 1){
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
}