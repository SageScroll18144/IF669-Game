#include "raylib.h"
#include "threeD_plan.h"
#include "../character/body.h"
#include <stdio.h>

Camera camera = { 0 };
Vector3 acm;//inimigo
int sen, healthPoints = 6;
Model model;

void init3DScene(){
    camera.position = (Vector3){ 4.0f, 2.0f, 4.0f };
    camera.target = (Vector3){ 0.0f, 1.8f, 0.0f };
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };
    camera.fovy = 60.0f;
    camera.projection = CAMERA_PERSPECTIVE;

    SetCameraMode(camera, CAMERA_FIRST_PERSON); // Set a first person camera mode

    model = LoadModel("resources/models/peter_griffin.obj");  

    acm = (Vector3){ 0.0f, 3.0f, 0.0f };
    sen = 1;
}

void update3DScene(){
    UpdateCamera(&camera);
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

        printf("ATACOU\n");
    } 
    else printf("NAO\n");

    printf("%f %f %f\n", camera.position.x, camera.position.y, camera.position.z);
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
        
    EndMode3D();

    DrawRectangle( 10, 10, 220, 70, Fade(SKYBLUE, 0.5f));
    DrawRectangleLines( 10, 10, 220, 70, BLUE);

    DrawText("First person camera default controls:", 20, 20, 10, BLACK);
    DrawText("- Move with keys: W, A, S, D", 40, 40, 10, DARKGRAY);
    DrawText("- Mouse move to look around", 40, 60, 10, DARKGRAY);
    drawHpBar();
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

void drawBullet() {
    DrawSphere((Vector3) {camera.position.x + 40.0f, camera.position.y - 100.0f, camera.position.z + 40.0f}, 100.0f, RED);
}

void unLoadModels(){
    UnloadModel(model);  
}
float mod(float a){
    if(a<0) return -a;
    return a;
} 