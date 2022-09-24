#include "raylib.h"
#include "body.h"

Vector2 ballPosition;

void initCharacter(){
    ballPosition = (Vector2) { (float) GetScreenWidth()/2, (float) GetScreenHeight()/2 };
}

void checkMovement(){
    if (IsKeyDown(KEY_RIGHT)) ballPosition.x += 2.0f;
    if (IsKeyDown(KEY_LEFT)) ballPosition.x -= 2.0f;
    if (IsKeyDown(KEY_UP)) ballPosition.y -= 2.0f;
    if (IsKeyDown(KEY_DOWN)) ballPosition.y += 2.0f;
}
void colision(){
    if (ballPosition.y<=0) ballPosition.y += 2.0f;
    if (ballPosition.y>= GetScreenHeight())  ballPosition.y -= 2.0f;
    if (ballPosition.x<=0) ballPosition.x += 2.0f;
    if (ballPosition.x>= GetScreenWidth())  ballPosition.x -= 2.0f;
}
void drawCharacter(){
    DrawCircleV(ballPosition, 50, MAROON);
}