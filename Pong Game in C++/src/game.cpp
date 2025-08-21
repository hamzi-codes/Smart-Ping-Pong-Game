#include <iostream>
#include <raylib.h>

#include "../headers/ball.hpp"
#include "../headers/paddle.hpp"
#include "../headers/game.hpp"

Color Blue = Color{102, 255, 255, 255};
Color lightBlue = Color{153, 255, 255, 255};
Color centerCircle = Color {204, 255, 255, 255};
Color ScoreColor = Color {0, 102, 102, 255};

//constructor
void Game::play() {

    std::cout<<"Starting the Game." << std::endl;

    const int screen_width = 1000; //screen width
    const int screen_height = 600; //screen height
    const int padel_width = 15;
    const int padel_height = 90;
    InitWindow(screen_width, screen_height, "My Pong Game!");

    SetTargetFPS(60);

    Ball ball(screen_width/2, screen_height/2, 7, 7, 10);
    Paddle RightPlayerPaddle(screen_width-padel_width-10, screen_height/2 - padel_height/2, padel_width, padel_height , 12);
    Paddle LeftCpuPaddle(10, screen_height/2 - padel_height/2, padel_width, padel_height, 6);
    while(WindowShouldClose() == false) {
        
        BeginDrawing();
        //Update Game Loops
        ball.BallMove();
        RightPlayerPaddle.PaddleMove();
        LeftCpuPaddle.updateCpuPaddle(ball.get_x(), ball.get_y());

        if(CheckCollisionCircleRec(Vector2{ball.get_x(), ball.get_y()}, ball.get_radius(), Rectangle{RightPlayerPaddle.get_x(), RightPlayerPaddle.get_y(), RightPlayerPaddle.get_width(), RightPlayerPaddle.get_height()})) {
            ball.set_speed_x(-ball.get_speed_x());
        }

        if(CheckCollisionCircleRec(Vector2{ball.get_x(), ball.get_y()}, ball.get_radius(), Rectangle{LeftCpuPaddle.get_x(), LeftCpuPaddle.get_y(), LeftCpuPaddle.get_width(), LeftCpuPaddle.get_height()})) {
            ball.set_speed_x(-ball.get_speed_x());
        }

        //Drawing
        ClearBackground(Blue);
        DrawRectangle(screen_width/2, 0, screen_width/2, screen_height, lightBlue);
        DrawCircle(screen_width/2, screen_height/2, 150, centerCircle);
        DrawLine(screen_width/2, 0, screen_width/2, screen_height, WHITE);
        ball.DrawBall();
        LeftCpuPaddle.DrawPaddle();
        RightPlayerPaddle.DrawPaddle();

        //TEXT on CPU SIDE
        DrawText(TextFormat("%i", ball.get_cpu_score()), screen_width/4 - 20, 20, 40, ScoreColor);
        DrawText("AI", screen_width/4 - 20, screen_height/2-20, 50, lightBlue);

        //TEXT on PLAYER SIDE
        DrawText(TextFormat("%i", ball.get_player_score()), 3 * screen_width/4 - 20, 20, 40, ScoreColor);
        DrawText("HUMAN", 3*screen_width/4 - 20, screen_height/2-20, 50, Blue);

        EndDrawing();
    }

    CloseWindow();
}


