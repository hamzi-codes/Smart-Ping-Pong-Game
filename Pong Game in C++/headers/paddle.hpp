#ifndef PADDLE_H
#define PADDLE_H


class Paddle {
private:
    float x, y, width, height, speed;

public:
Paddle(float x_pos, float y_pos, float p_width, float p_height, float p_speed);
void DrawPaddle();
void PaddleMove ();

void updateCpuPaddle(int ball_x, int ball_y);

//getters
float get_x();
float get_y();
float get_width();
float get_height();

};

#endif