#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_COLUMNS 20

int euclidianDistance(Vector3 a, Vector3 b, float param);

//------------------------------------------------------------------------------------
// Program main entry point
//------------------------------------------------------------------------------------
int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - 3d camera first person");

    // Define the camera to look into our 3d world (position, target, up vector)
    Camera camera = { 0 };
    camera.position = (Vector3){ 4.0f, 2.0f, 4.0f };
    camera.target = (Vector3){ 0.0f, 1.8f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetCameraMode(camera, CAMERA_FIRST_PERSON); // Set a first person camera mode

    SetTargetFPS(60);                           // Set our game to run at 60 frames-per-second
    
    Vector3 wall_pos[4] = {(Vector3){ -16.0f, 2.5f, 0.0f }, (Vector3){ 16.0f, 2.5f, 0.0f }, (Vector3){ 0.0f, 2.5f, 16.0f }, (Vector3){ 0.0f, 2.5f, -16.0f }};

    // Main game loop
    while (!WindowShouldClose())                // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        UpdateCamera(&camera);
        
        //----------------------------------------------------------------------------------
        for(int i=0;i<4;i++) {
            if(euclidianDistance(wall_pos[i], camera.position, 5)){
                //printf("colidiu\n");
            }// else// printf("nao nao\n");  
        }
        if((camera.position.x>=15)) {
            camera.position.x -= 0.05f;
            camera.target.x -= 0.05f;
        }
        if((camera.position.x<=-15)) {
            camera.position.x += 0.05f;
            camera.target.x += 0.05f;
        }
        if((camera.position.z>=15)) {
            camera.position.z -= 0.05f;
            camera.target.z -= 0.05f;
        }
        if((camera.position.z<=-15)) {
            camera.position.z += 0.05f;
            camera.target.z += 0.05f;
        }
        printf("(%.2f,%.2f,%.2f)\n", camera.position.x, camera.position.y, camera.position.z);
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, LIGHTGRAY); // Draw ground
                DrawCube((Vector3){ -16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, BLUE);     // Draw a blue wall
                DrawCube((Vector3){ 16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, LIME);      // Draw a green wall
                DrawCube((Vector3){ 0.0f, 2.5f, 16.0f }, 32.0f, 5.0f, 1.0f, GOLD);      // Draw a yellow wall
                DrawCube((Vector3){ 0.0f, 2.5f, -16.0f }, 32.0f, 5.0f, 1.0f, GOLD);      // Draw a yellow wall

                
            EndMode3D();

            DrawRectangle( 10, 10, 220, 70, Fade(SKYBLUE, 0.5f));
            DrawRectangleLines( 10, 10, 220, 70, BLUE);

            DrawText("First person camera default controls:", 20, 20, 10, BLACK);
            DrawText("- Move with keys: W, A, S, D", 40, 40, 10, DARKGRAY);
            DrawText("- Mouse move to look around", 40, 60, 10, DARKGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}

int euclidianDistance(Vector3 a, Vector3 b, float param){
    return ((a.x-b.x<=0)+(a.y-b.y<=0)+(a.z-b.z<=0)) >= 2;
}