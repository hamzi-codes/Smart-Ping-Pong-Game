#ifndef BALL_H
#define BALL_H

class Ball {
private:
float x;
float y;
int speed_x;
int speed_y;
int radius;

int player_score, cpu_score = 0;

public:

Ball(float Ball_x, float Ball_y, int Ball_speed_x, int Ball_speed_y, int Ball_radius);

void DrawBall();
void BallMove();
void ResetBall();

//getters
float get_y();
float get_x();
int get_radius();
int get_speed_x();
int get_player_score();
int get_cpu_score();
void set_speed_x(int b_speed_x);

};

#endif