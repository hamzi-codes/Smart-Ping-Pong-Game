
#include <raylib.h>
#include "../headers/ball.hpp"

Ball::Ball(float Ball_x, float Ball_y, int Ball_speed_x, int Ball_speed_y, int Ball_radius) : x(Ball_x), y(Ball_y), speed_x(Ball_speed_x), speed_y(Ball_speed_y), radius(Ball_radius) {}

Color Green = Color{0, 255, 0, 255};
void Ball::DrawBall() {
    DrawCircle(x, y, radius, Green);
}

void Ball::ResetBall() {
    x = GetScreenWidth()/2;
    y = GetScreenHeight()/2;

    //randomising ball movement after reset
    int speed_choices[2] = {-1, 1};
    speed_x *= speed_choices[GetRandomValue(0,1)];
    speed_y *= speed_choices[GetRandomValue(0,1)];
}

void Ball::BallMove() {
    x+=speed_x;
    y+=speed_y;

    //checking for collisions and bouncing it from wall!
    if(x + radius >= GetScreenWidth()) {
        cpu_score++;
        ResetBall();
    }
    
    if (x - radius <= 0) {
        player_score++;
        ResetBall();
    }

    //checking for collisions and bouncing it from roof and floor
    if(y + radius >= GetScreenHeight() || y - radius <= 0) {
        speed_y *= -1;
    }
}


float Ball::get_y() {return y;}

float Ball::get_x() {return x;}

int Ball::get_radius() {return radius;}

int Ball::get_speed_x() {return speed_x;}

int Ball::get_player_score() {return player_score;}

int Ball::get_cpu_score() {return cpu_score;}

void Ball::set_speed_x(int b_speed_x) {speed_x = b_speed_x;}