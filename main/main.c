#include "raylib.h"
#include "body.h"

int main(void){
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Joguinho");

    // Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };
    initCharacter(screenWidth, screenHeight);
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 2.0f;
        // if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 2.0f;
        // if (IsKeyDown(KEY_UP)) ballPosition.y -= 2.0f;
        // if (IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0f;
        checkMovement();
        colision();
        //colisao janela
        // if (ballPosition.y<=0) ballPosition.y += 2.0f;
        // if (ballPosition.y>=screenHeight)  ballPosition.y -= 2.0f;
        // if (ballPosition.x<=0) ballPosition.x += 2.0f;
        // if (ballPosition.x>=screenHeight)  ballPosition.x -= 2.0f;

        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("setinha pai", 10, 10, 20, DARKGRAY);

            drawBall();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}