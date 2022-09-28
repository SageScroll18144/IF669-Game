#include "raylib.h"
#include "character/body.h"
#include "scene/background.h"

int main(void){
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Joguinho");

    // Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };
    initScene();
    initCharacter();
    
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        //movimentação do personagem
        //checkMovement();
        updatePlayerMain();
        //colision();
        //colisao janela
        //colision();
        hasAColision(getCharacterPosition());
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("setinha pai", 10, 10, 20, DARKGRAY);

            drawScene();
            drawCharacter();

            
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    unloadBodyTextures();
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    closeScene();

    return 0;
}