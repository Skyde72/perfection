#include "raylib.h"
#include <stdlib.h>

int main()
{
    srand (time(NULL));
    int screenWidth = 800;
    int screenHeight = 800;
    int circle = 1;
    int circleY = 300;
    int circleX = 400;
    int oCircleY = rand() % 800 + 1;
    int oCircleX =rand() % 800 + 1;
    int oCircleSize =rand() % 300 + 1;
    int score = 0;
    int circleSz = 30;
    int timeOfExec = time(NULL);
    int isGameOver = 0;

    InitWindow(screenWidth, screenHeight, "Perfectionism");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        srand (time(NULL));

            if (IsKeyDown(KEY_A)) {
                if (isGameOver == 0) {
                    circle++;
                }
            } else if (IsKeyDown(KEY_S)) {
                if (isGameOver == 0)
                    if (circle > 1)
                        circle--;
            } else if (IsKeyDown(KEY_Z)) {
                if (isGameOver == 0)
                    circleSz++;
            } else if (IsKeyDown(KEY_X)) {
                if (isGameOver == 0)
                    circleSz--;
            } else if (IsKeyDown(KEY_RIGHT)) {
                if (isGameOver == 0)
                    circleY = circleY + circle;
            } else if (IsKeyDown(KEY_LEFT)) {
                if (isGameOver == 0)
                    circleY = circleY - circle;
            } else if (IsKeyDown(KEY_UP)) {
                if (isGameOver == 0)
                    circleX = circleX - circle;
            } else if (IsKeyDown(KEY_DOWN)) {
                if (isGameOver == 0)
                    circleX = circleX + circle;
            } else if (IsKeyDown(KEY_END)) {
                if (isGameOver == 0)
                    score++;
            } else if (IsKeyDown(KEY_R)) {
                oCircleY = rand() % 800 + 1;
                oCircleX =rand() % 800 + 1;
                oCircleSize =rand() % 300 + 1;
                circleY = 300;
                circleX = 400;
                circle = 0;
                circleSz = 30;
                if (isGameOver == 1)
                    isGameOver = 0;
            }

        BeginDrawing();

            ClearBackground(LIGHTGRAY);

            DrawText(TextFormat("%1i", score), 300, 300, 300, WHITE);
            DrawCircle(oCircleY, oCircleX, oCircleSize, BLUE);
            DrawCircle(circleY, circleX, circleSz, RED);
            DrawText(TextFormat("Speed: %1i", circle), 20, 10, 20, BLACK);
            DrawText(TextFormat("Size: %1i", circleSz), 20, 30, 20, BLACK);
            DrawText(TextFormat("Size Of Blue: %1i", oCircleSize), 20, 50, 20, BLACK);
            if (circleSz < 1 || circleSz > 800) {
                DrawText(TextFormat("Game Over! \n Score: %1i", score), 300, 300, 40, RED);
                DrawText(TextFormat("Press R to restart", score), 225, 700, 40, RED);
                isGameOver = 1;
            } /*else if (score > 10) {
                int timeSpent = time(NULL) - timeOfExec;
                DrawText(TextFormat("You Win! \n Score: %1i \n Time: %2i", score, timeSpent), 300, 300, 40, RED);
            }*/
        EndDrawing();

        //Checking...
        if (oCircleSize == circleSz && circleX == oCircleX && circleY == oCircleY) {
            score++;
            oCircleY = rand() % 800 + 1;
            oCircleX =rand() % 800 + 1;
            oCircleSize =rand() % 300 + 1;
        }

    }

    CloseWindow();

    return 0;
}
