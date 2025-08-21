#include "../headers/paddle.hpp"
#include "raylib.h"


Paddle::Paddle(float x_pos, float y_pos, float p_width, float p_height, float p_speed) : x(x_pos), y(y_pos), width(p_width), height(p_height), speed(p_speed) {}

Color paddleColor = {0, 102, 102, 255};
void Paddle::DrawPaddle() {
    DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, paddleColor);
}

void Paddle::PaddleMove() {
    if(IsKeyDown(KEY_UP)) {
        y-= speed;
    }

    if(IsKeyDown(KEY_DOWN)) {
        y+= speed;
    }

    //paddle cannot move out of the screen after this:-
    if(y<=0) y = 0;
    
    if(y+height>=GetScreenHeight()) y=GetScreenHeight()-height;

}

void Paddle::updateCpuPaddle(int ball_x, int ball_y) {

    if(y + height/2 > ball_y && ball_x < GetScreenWidth()/2) y = y - speed;

    if(y + height/2 <= ball_y && ball_x < GetScreenWidth()/2) y = y + speed;

    //paddle cannot move out of the screen after this:-
    if(y<=0) y = 0;
    
    if(y+height>=GetScreenHeight()) y=GetScreenHeight()-height;
}

//getters
float Paddle::get_x() {return x;}
float Paddle::get_y() {return y;}
float Paddle::get_width() {return width;}
float Paddle::get_height() {return height;}
