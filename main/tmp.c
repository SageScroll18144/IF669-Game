/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0

*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2013-2022 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "raymath.h"
#include <stdbool.h>

#define PLAYER_HOR_SPD 500.0f

typedef struct {
    Vector2 position;
    Rectangle playerRec;
    float speed;
    bool canJump;
} Player;

typedef struct {
    Rectangle rect;
    int blocking;
    Color color;
} EnvItem;

void updatePlayer(Player *player, int *currentFrame, int *frameCounter, int *currentOrientation, int deltaTime);

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    int currentFrame = 1, currentOrientation = 1, orientation = 1;
    int frameCounter = 0;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    Player player = {0};
    player.position = (Vector2) {400, 280};
    player.speed = 0;
    player.canJump = false;

    EnvItem envItems[] = {
        {{ 0, 0, 1000, 400 }, 0, LIGHTGRAY },
        {{ 0, 400, 1000, 200 }, 1, GRAY },
        {{ 300, 200, 400, 10 }, 1, GRAY },
        {{ 250, 300, 100, 10 }, 1, GRAY },
        {{ 650, 300, 100, 10 }, 1, GRAY }
    };

    int envItemLength = sizeof(envItems) / sizeof(envItems[0]);


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    Texture2D charaTex = LoadTexture("scarfy.png");

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {

        
        // Update
        //----------------------------------------------------------------------------------
        orientation = currentOrientation ? 1 : -1;
        Rectangle frameRec = {player.position.x, player.position.y - 24, (float) orientation * charaTex.width / 6, (float) charaTex.height};
        player.playerRec = frameRec;

        float deltaTime = GetFrameTime();
        
        updatePlayer(&player, &currentFrame, &frameCounter, &currentOrientation, deltaTime);
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            for (int i = 0; i < envItemLength; i++) DrawRectangleRec(envItems[i].rect, envItems[i].color);

            DrawTextureRec(charaTex, player.playerRec, player.position, WHITE);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadTexture(charaTex);
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

void updatePlayer(Player *player, int *currentFrame, int *frameCounter, int *currentOrientation, int deltaTime) {
    int frameSpeed = 8;

    if (*currentFrame > 5) *currentFrame = 0;
    player->playerRec.x = (float)*currentFrame * (float) player->playerRec.width;

    if (IsKeyDown(KEY_RIGHT)) {
        (*frameCounter)++;

        if (*frameCounter >= 60/frameSpeed) {
            (*frameCounter) = 0;
            
            (*currentFrame)++;

            if (!(*currentOrientation)) {
                (*currentOrientation) = 1;
                player->playerRec.width *= -1;
            }
            player->position.x += 20;
        }
    };

    if (IsKeyDown(KEY_LEFT)) {
        (*frameCounter)++;

        if (*frameCounter >= 60/frameSpeed) {
            *frameCounter = 0;
            
            (*currentFrame)++;

            if (*currentOrientation) {
                *currentOrientation = 0;
                player->playerRec.width *= -1;
            }
            player->position.x -= 20;
        }   
            
    }
}