#include "raylib.h"
#include "deathscreen.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void initdeathScreen(){
    Sound death = LoadSound ("sounds/death_sound_effect.mp3");
    SetSoundVolume(death, 0.7f);
    Shader shaders = LoadShader(0, TextFormat("fonts/grayscale.fs", 330)); 
    Vector2 position0 = {400, 225};
    int circle0 = 0, contador0 = 0;
    int animFrames0 = 0;
    unsigned int nextFrameDataOffset0 = 0;
    int currentAnimFrame0 = 0;            
    int frameCounter10 = 0;  
    Image batgif = LoadImageAnim ("assets/flyingBat.gif", &animFrames0);
    Image batgif2 = LoadImageAnim ("assets/flyingBat2.gif", &animFrames0); 
    Texture battext = LoadTextureFromImage(batgif); 
    Texture battext2 = LoadTextureFromImage(batgif2); 
    int jaTocou = 0;      
}

void DrawDeathScreen (){
    if (jaTocou == 0) {
        PlaySound (death);
        jaTocou = 1;
    }

    frameCounter10++;

    if (frameCounter10 >= 200){
        currentAnimFrame0++;

        if (currentAnimFrame0 >= animFrames0) currentAnimFrame0 = 0;

        nextFrameDataOffset0 = (batgif.width)*(batgif.height)*4*currentAnimFrame0;
        UpdateTexture(battext, ((unsigned char *)batgif.data) + nextFrameDataOffset0);
        UpdateTexture(battext2, ((unsigned char *)batgif2.data) + nextFrameDataOffset0);

        frameCounter10 = 0;
    }
    BeginDrawing();
        EndShaderMode();
        DrawCircle(position0.x, position0.y, circle0, BLACK);
        if(contador0 > 2700){
            DrawText("SE FODEU", 298, 210, 40, RED);
            DrawTexture (battext, 210, 180, WHITE);
            DrawTexture (battext2, 510, 180, WHITE);
        }
        if(contador0%12 == 0 && circle0 < 200){
            circle0++;
        }
        if (contador0 > 7000) DrawText ("Press ENTER to back to menu", 20, 420, 20, RED);
        contador0++;
    EndDrawing();
}

void unLoadSoundDS (){
    UnloadSound(death);
}
