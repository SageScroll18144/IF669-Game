#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;
    char title[] = "Zumbis S.A";
    char msg1[] = "Play";
    char msg2[] = "Instructions";
    char msg3[] = "Exit";

    Font font;
    Image imagem;
    Texture2D textura;
    Vector2 position;
    const int spacings = 1;
    int menu_pos = 0;

    InitWindow(screenWidth, screenHeight, "jogo");
    font = LoadFont("fonts/jupiter_crash.png");
    imagem = LoadImage("assets/menu.png"); 
    ImageResize(&imagem, 800, 450);
    textura = LoadTextureFromImage(imagem);
   
    position.x = 300;
    position.y = 180;
    int flag_screen = 0;

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        if (IsKeyPressed (KEY_DOWN)) 
        {
            menu_pos++;
            menu_pos %= 3;
        }
        else if (IsKeyPressed (KEY_UP))
        { 
            menu_pos--; 
            if (menu_pos < 0) menu_pos = 2; 
        }
        BeginDrawing();
            if (menu_pos == 0)
            {
                DrawTexture(textura, 0, 0, WHITE);
                DrawRectangle(0, 0, 50, 450, BLACK);
                DrawRectangle(0, 0, 800, 50, BLACK);
                DrawRectangle(0,450 - 50, 800, 50, BLACK);
                DrawRectangle(800 - 50, 0, 50, 450, BLACK);
                DrawRectangle(270, 240, 250, 40, YELLOW);
                DrawRectangle(270, 290, 250, 40, DARKGREEN);
                DrawRectangle(270, 340, 250, 40, DARKGREEN);

                DrawTextEx(font, title, position, font.baseSize*2.0f ,(float)spacings, RED);
                DrawText(msg1 , 280, 250, 20, BLACK);
                DrawText(msg2 , 280, 300, 20, BLACK);
                DrawText(msg3 , 280, 350, 20, BLACK);
            }
            else if (menu_pos == 1)
            {
                    DrawTexture(textura, 0, 0, WHITE);
                DrawRectangle(0, 0, 50, 450, BLACK);
                DrawRectangle(0, 0, 800, 50, BLACK);
                DrawRectangle(0,450 - 50, 800, 50, BLACK);
                DrawRectangle(800 - 50, 0, 50, 450, BLACK);
                DrawRectangle(270, 240, 250, 40, DARKGREEN);
                DrawRectangle(270, 290, 250, 40, YELLOW);
                DrawRectangle(270, 340, 250, 40, DARKGREEN);

                DrawTextEx(font, title, position, font.baseSize*2.0f ,(float)spacings, RED);
                DrawText(msg1 , 280, 250, 20, BLACK);
                DrawText(msg2 , 280, 300, 20, BLACK);
                DrawText(msg3 , 280, 350, 20, BLACK);
            }
            else if (menu_pos == 2)
            {
                DrawTexture(textura, 0, 0, WHITE);
                DrawRectangle(0, 0, 50, 450, BLACK);
                DrawRectangle(0, 0, 800, 50, BLACK);
                DrawRectangle(0,450 - 50, 800, 50, BLACK);
                DrawRectangle(800 - 50, 0, 50, 450, BLACK);
                DrawRectangle(270, 240, 250, 40, DARKGREEN);
                DrawRectangle(270, 290, 250, 40, DARKGREEN);
                DrawRectangle(270, 340, 250, 40, YELLOW);

                DrawTextEx(font, title, position, font.baseSize*2.0f ,(float)spacings, RED);
                DrawText(msg1 , 280, 250, 20, BLACK);
                DrawText(msg2 , 280, 300, 20, BLACK);
                DrawText(msg3 , 280, 350, 20, BLACK);
            }

        EndDrawing();
        if (IsKeyPressed(KEY_ENTER) && menu_pos == 2) CloseWindow();
        else if (IsKeyPressed (KEY_ENTER) && menu_pos == 1) flag_screen = 1;
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
            // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
