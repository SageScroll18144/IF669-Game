#include "raylib.h"
#include "character/body.h"
#include "scene/background.h"
#include "enemy/zombie.h"
#include "menu/menu.h"
#include "menu/instructions.h"
#include <stdio.h>
#include <stdlib.h>
#include "animations/transition.h"
#include "scene/threeD_plan.h"
#include "animations/deathscreen.h"
#include "animations/final.h"

//int count_aux = 0;

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
    initInstructions();
    initScene();
    initCharacter();
    initEnemy();
    initTransition();
    init3DScene();
    initDeathScreen();
    initVicScreen();

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
        
        if (IsKeyPressed(KEY_ENTER) && getMenuPos() == 1){
             flag_screen = 6;
            
           }

        if(flag_screen == 2){
            // zombie     
            updateEnemyMain(getCharacterPosition());
            
            //movimentação do personagem
            if (!itsDead()) updatePlayerMain();
            if(hasAColision(getCharacterPosition())){
                Vector2 compensation = orientationForColision();
                
                reboundPlayer(compensation);
            }
            colision();

            //ataque
            for(int i=0;i<getHowMany();i++){
                if(objectColision(getCharacterPosition(), getEnemyPos(i), 30)){
                    if(itsAttacking()){
                        
                        Vector2 ret = getCharacterOrientation();
                        //printf("-> %d %d\n", (int)ret.x, (int)ret.y);
                        if((int)ret.x==0&&(int)ret.y==0)receiveCharacterAttack(i, 0);
                        else if((int)ret.x==0&&(int)ret.y==1)receiveCharacterAttack(i, 1);
                        else if((int)ret.x==4)receiveCharacterAttack(i, 2);
                        else if((int)ret.x==5)receiveCharacterAttack(i, 3);

                        receiveCharacterDamage(i);
                        killEnemy(i);

                    } else if (!itsDead()) {
                        receiveEnemyAttack();
                        receiveEnemyDamage();
                        if(itsDead()) flag_screen = 3;
                    }
                }
            }
            if(CompareHowManyAlreadyDie()) flag_screen = 4;
        }
        if(flag_screen == 5) {
            update3DScene();
            if(ACMDie()) flag_screen = 7;
        }// Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);
            
            if(flag_screen == 0) drawMenu();
            if(flag_screen == 1){
                drawTransition();
                BeginDrawing();
                flag_screen = 2;
            }
            if(flag_screen == 2) {
                drawGame();
                // if(flag_attack == 1) count_aux++;
                // if(count_aux == 1000) flag_attack = 0;
             }
            if(flag_screen == 3){
                blackAndWhite();
                if (get3DPlayerHp() < 1) draw3DScene();
                else drawGame();
                EndShaderMode();
                drawDeathScreen();
                if(IsKeyPressed(KEY_F)) break;
            }
            if(flag_screen == 4) {
                //draw transição
                transiton3Dto2D();
                flag_screen = 5;
            }
            if(flag_screen == 5) {
                draw3DScene();

                if (get3DPlayerHp() < 1) {
                    flag_screen = 3;
                }
            }
            if(flag_screen == 6) {
                
               drawInstructions();
                if(IsKeyPressed(KEY_B)) flag_screen = 0;
            }
            if(flag_screen == 7){
                draw3DScene();
                drawVicScreen();
                //if(IsKeyPressed(KEY_ESC)) break;
            }
            
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    unloadBodyTextures();
    unloadAudios();
    unLoadSounds();
    unLoadSoundTransition();
    unLoadSoundDS();
    unLoadModels();
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    closeScene();

    return 0;
}

void drawGame(){
    drawScene(getHowManyAlreadyDie());
    drawCharacter();
    drawHealthBar();
    drawEnemy();
}
int objectColision(Vector2 a, Vector2 b, int min){
    return abs((int)a.x-(int)b.x)<=min && abs((int)a.y-(int)b.y)<=min;
}
