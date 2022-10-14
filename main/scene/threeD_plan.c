#include "raylib.h"
#include "threeD_plan.h"
#include "../character/body.h"
#include "../animations/deathscreen.h"
#include <stdio.h>
#include <math.h>

Camera camera = { 0 };
Vector3 acm;//inimigo
float acm_life = 100.0;
int sen, healthPoints = 6, flagBullet = 0;
Model model;

Vector3 bullet;
const int K = 50;

Sound walk3d;
Sound shotsound;

Texture2D acmBar1, acmBar2, acmBar3, acmBar4, acmBar5, acmBar6;

void init3DScene(){
    camera.position = (Vector3){ 4.0f, 2.0f, 4.0f };
    camera.target = (Vector3){ 0.0f, 1.8f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetCameraMode(camera, CAMERA_FIRST_PERSON); // Set a first person camera mode

    model = LoadModel("resources/models/peter_griffin.obj");  

    acm = (Vector3){ 0.0f, 3.0f, 0.0f };
    acmBar1 = LoadTexture("sprites/health_bar/a1.png");
    acmBar2 = LoadTexture("sprites/health_bar/a2.png");
    acmBar3 = LoadTexture("sprites/health_bar/a3.png");
    acmBar4 = LoadTexture("sprites/health_bar/a4.png");
    acmBar5 = LoadTexture("sprites/health_bar/a5.png");
    acmBar6 = LoadTexture("sprites/health_bar/a6.png");

    walk3d = LoadSound("sounds/walking_sound4.mp3");
    shotsound = LoadSound("sounds/plasma.mp3");
}

void update3DScene(){
    if (healthPoints > 0) {
        UpdateCamera(&camera);
        if(IsKeyDown(KEY_W) || IsKeyDown(KEY_S) || IsKeyDown(KEY_A) || IsKeyDown(KEY_D)) if(!IsSoundPlaying(walk3d)) PlaySound(walk3d);
    }
    //colisao
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

    if((acm.x>=12)) {
        acm.x -= 0.05f;
    }
    if((acm.x<=-12)) {
        acm.x += 0.05f;
    }
    if((acm.z>=12)) {
        acm.z -= 0.05f;
        
    }
    if((camera.position.z<=-12)) {
        acm.z += 0.05f;
    
    }

    // if(acm.x>=10) sen = -1;
    // else if(acm.x<=-10) sen = 1; 
    // acm.x+=(0.5f*sen);
    if(acm.x > camera.position.x + 3.0f) acm.x -= 0.01f;
    else if(acm.x < camera.position.x + 3.0f) acm.x += 0.01f;
    if(acm.z > camera.position.z  + 3.0f) acm.z -= 0.01f;
    else if(acm.z < camera.position.z  + 3.0f) acm.z += 0.01f;

    if(mod(acm.z - camera.position.z)  <= 3.01f && mod(acm.x - camera.position.x)  <= 3.01f){
        if(acm.z>camera.position.z) acm.z+=2.0f;
        else acm.z-=2.0f;
        if(acm.x>camera.position.x) acm.x+=2.0f;
        else acm.x-=2.0f;

        healthPoints--;

        //printf("ATACOU\n");
    } 
    //else printf("NAO\n");

    //if()
}

void draw3DScene(){
    BeginMode3D(camera);

        DrawPlane((Vector3){ 0.0f, 0.0f, 0.0f }, (Vector2){ 32.0f, 32.0f }, GRAY); // Draw ground
        DrawCube((Vector3){ -16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, BLACK);     // Draw a blue wall
        DrawCube((Vector3){ 16.0f, 2.5f, 0.0f }, 1.0f, 5.0f, 32.0f, BLACK);      // Draw a green wall
        DrawCube((Vector3){ 0.0f, 2.5f, 16.0f }, 32.0f, 5.0f, 1.0f, BLACK);      // Draw a yellow wall
        DrawCube((Vector3){ 0.0f, 2.5f, -16.0f }, 32.0f, 5.0f, 1.0f, BLACK);      // Draw a yellow wall
        //DrawCube(acm, 5.0f, 5.0f, 5.0f, GOLD);
        DrawModel(model, acm, 3.0f, RED);
        //DrawCircle3D((Vector3){ 0.0f, 2.0f, 0.0f }, earthOrbitRadius, (Vector3){ 1, 0, 0 }, 90.0f, Fade(RED, 0.5f));
        if(IsKeyPressed(KEY_P)){
            flagBullet = 1;   
            bullet = camera.target; 
            PlaySound(shotsound);
        }
        if (flagBullet) shotABullet();
    EndMode3D();

    DrawRectangle( 300, 10, 220, 70, Fade(SKYBLUE, 0.5f));
    DrawRectangleLines( 300, 10, 220, 70, BLUE);

    DrawText("First person camera default controls:", 310, 20, 10, BLACK);
    DrawText("- Move with keys: W, A, S, D", 340, 40, 10, DARKGRAY);
    DrawText("- Mouse move to look around", 340, 60, 10, DARKGRAY);
    drawHpBar();
    drawAcmBar();

}

void drawHpBar() {
    Vector2 barPos = {0, 0};
    Rectangle barRec = {barPos.x, barPos.y, (float) healthBarTex.width, (float) healthBarTex.height};
    
    switch (healthPoints) {
    case 6:
        DrawTextureRec(healthBarTex, barRec, barPos, WHITE);
        break;
    case 5:
        DrawTextureRec(healthBarTex2, barRec, barPos, WHITE);
        break;
    case 4:
        DrawTextureRec(healthBarTex3, barRec, barPos, WHITE);
        break;
    case 3:
        DrawTextureRec(healthBarTex4, barRec, barPos, WHITE);
        break;
    case 2:
        DrawTextureRec(healthBarTex5, barRec, barPos, WHITE);
        break;
    case 1:
        DrawTextureRec(healthBarTex6, barRec, barPos, WHITE);
        break;
    default:
        break;
    }
}

void drawAcmBar() {
    Vector2 barPos = {GetScreenWidth() / 2 - 100, 380};
    Rectangle barRec = {barPos.x, barPos.y, (float) acmBar1.width, (float) acmBar1.height};
    barRec.x = 220;
    barRec.y = 300;
    
    switch ((int) (6 * acm_life) / 100) {
    case 0:
    case 1:
        DrawTextureRec(acmBar1, barRec, barPos, WHITE);
        break;
    case 2:
        DrawTextureRec(acmBar2, barRec, barPos, WHITE);
        break;
    case 3:
        DrawTextureRec(acmBar3, barRec, barPos, WHITE);
        break;
    case 4:
        DrawTextureRec(acmBar4, barRec, barPos, WHITE);
        break;
    case 5:
        DrawTextureRec(acmBar5, barRec, barPos, WHITE);
        break;
    case 6:
        DrawTextureRec(acmBar6, barRec, barPos, WHITE);
        break;

    default:
        break;
    }

    
}

void unLoadModels(){
    UnloadModel(model);  
    UnloadSound(walk3d);
    UnloadSound(shotsound);
}

float mod(float a){
    if(a<0) return -a;
    return a;
}

void shotABullet(){
    
    int sen_x, sen_z;
    
    DrawSphere(bullet, 2.0f, BLUE); 

    if (camera.position.x <= camera.target.x) bullet.x += ((camera.target.x - camera.position.x) * 0.5f);
    else bullet.x -= ((camera.position.x - camera.target.x) * 0.5f);

    if (camera.position.z <= camera.target.z) bullet.z += ((camera.target.z - camera.position.z) * 0.5f);
    else bullet.z -= ((camera.position.z - camera.target.z) * 0.5f);;

    if (camera.position.y <= camera.target.y) bullet.y += ((camera.target.y - camera.position.y) * 0.5f);
    else bullet.y -= ((camera.position.y - camera.target.y) * 0.5f);;
    
    if(mod(bullet.x - acm.x) <= 3.0f && mod(bullet.z - acm.z) <= 3.0f) acm_life -= 0.5;

    if(bullet.x > K * camera.target.x && bullet.z > K * camera.target.z) flagBullet = 0;
    printf("->%.2f\n", acm_life);
}

int get3DPlayerHp() {
    return healthPoints;
}
int ACMDie(){
    return acm_life < 0;
}