

#include "raylib.h"

int main(void)
{

	const int screenWidth = 800;
	const int screenHeight = 450;
	
	InitWindow(screenWidth, screenHeight, "Game");//
	
	SetTargetFPS(60);               

  // Carregamento do asset em forma de imagem e redimensionamento
  // Image background = LoadImage("background.png");
  // ImageResize(&background, 800, 450);

  Image plantIm = LoadImage("plant.png");

  // Carregamento de asset em forma de textura
  Texture2D backTex = LoadTexture("background.png");
  Texture2D plantTex = LoadTextureFromImage(plantIm);
  Texture2D groundTex = LoadTexture("stoneGround.png");
  

	while (!WindowShouldClose())    
	{

		BeginDrawing();

			ClearBackground(RAYWHITE);

			// DrawTexture(backTex, 0, 0, WHITE);

      // Redimensionamento do background feito quando o tipo carregado é Texture
      Rectangle recSrc = {0, 0, backTex.width, backTex.height};
      Rectangle recDest = {0, 0, 800, 450};
      Vector2 vecOrigin = {0, 0};
    
      DrawTexturePro(backTex, recSrc, recDest, vecOrigin, 0, WHITE);

      DrawTexturePro(backTex, recSrc, recDest, vecOrigin, 0, WHITE);
    
      DrawTexture(plantTex, -10, -20, WHITE);
    

		EndDrawing();
		
	}


  // UnloadImage(background);
  UnloadTexture(backTex);
  
	CloseWindow();     

	return 0;
}