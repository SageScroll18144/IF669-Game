#include "raylib.h"
#include "character/body.h"
#include "scene/background.h"
#include "enemy/zombie.h"
#include "menu/menu.h"
#include <stdio.h>
#include <stdlib.h>

void drawGame();
int objectColision(Vector2 a, Vector2 b, int min);

int main(void){
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "BatZombie");
    InitAudioDevice();
    
    initMenu();
    initScene();
    initCharacter();
    initEnemy();
    
    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    int flag_screen = 0;
    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if(flag_screen==0){
            updateMenu();
        }
        if (IsKeyPressed(KEY_ENTER) && getMenuPos() == 2){
            break;
        }
        // seta a transição de tela
        if(IsKeyDown(KEY_ENTER) && getMenuPos()==0) {
            flag_screen = 1;
        }

        if(flag_screen == 1){
            // zombie     
            updateEnemyMain(getCharacterPosition());
            
            //movimentação do personagem
            updatePlayerMain();
            if(hasAColision(getCharacterPosition())){
                Vector2 compensation = orientationForColision();
                
                reboundPlayer(compensation);
            }
            colision();

            for(int i=0;i<getHowMany();i++){
                if(objectColision(getCharacterPosition(), getEnemyPos(i), 30)){
                    if(itsAttacking()){
                        receiveCharacterAttack(i);
                    }else{
                        //receiveEnemyAttack();
                    }
                }
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
    unLoadSounds();
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    closeScene();

    return 0;
}

void drawGame(){
    drawScene();
    drawCharacter();
    drawEnemy();
}
int objectColision(Vector2 a, Vector2 b, int min){
    //printf("%f\n", a.x*b.x + a.y*b.y );
    return abs(a.x-b.x)<=min || abs(a.y-b.y)<=min;

}