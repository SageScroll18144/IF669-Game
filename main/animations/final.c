#include "raylib.h"
#include "final.h"


int contador_3d = 0;
int raio_3d = 0;
Vector2 position_;
int circle_, contador_;

void initVicScreen (){
    position_ = (Vector2) {400, 225};
    circle_ = 0; 
    contador_ = 0; 
}
void drawVicScreen (){
        DrawCircle(position_.x, position_.y, (circle_ + 10), BLACK);
        DrawCircle(position_.x, position_.y, circle_, WHITE);
        if(contador_ > 220){
            DrawText("CONGRATS!", 282, 100, 40, RED);
        }
        if(contador_ > 300){
                DrawText("YOU", 360, 150, 40, RED);
        }
        if(contador_ > 330){
                DrawText("ARE", 360, 200, 40, RED);
        }
        if(contador_ > 360){
                DrawText("A", 390, 250, 40, RED);
        }
        if(contador_ > 390){
                DrawText("LEGEND", 320, 300, 40, RED);
        }
        if(contador_ > 460){
                DrawCircle(position_.x, position_.y, (circle_ + 10), BLACK);
                DrawCircle(position_.x, position_.y, circle_, WHITE);
                DrawText("By", 370, 60, 40, RED);
                DrawText("Felipe Santos", 302, 130, 30, RED);
                DrawText("Gabriel Nogueira", 272, 180, 30, RED);
                DrawText("Guilherme Montenegro", 232, 230, 30, RED);
                DrawText("Thyago Soares", 282, 280, 30, RED);
                DrawText("Victor Mendonça", 265, 330, 30, RED);
                DrawText("Press ESC to EXIT", 10, 410, 20, YELLOW);
        }
        
        if(circle_ < 200){
            circle_+=3;
        }
        contador_++;
}
void transiton3Dto2D(){
    while(contador_3d < 5000){
        BeginDrawing();//
        if(contador_3d < 2500){
            DrawCircle(400, 225, raio_3d, BLACK);
            raio_3d = raio_3d + 5;
        }
        
        else{
            DrawCircle(400, 225, raio_3d, BLACK);
            raio_3d = raio_3d - 5;
        }
        
        if(contador_3d > 800 && contador_3d < 4200){
            DrawText("Após gusttavo dos ponteiros largar o mundo da música e derrotar uma leva de morcegos", 50, 120, 17, RED);
            DrawText("Ele caiu em um vórtex para o confronto final!", 220, 160, 17, RED);
            DrawText("Derrote o Peter ACM Griffin e salve os alunos de IP do CIn!", 114, 200, 20, RED);
        }
        contador_3d = contador_3d + 5;
        EndDrawing();//
    }
    return;
}
