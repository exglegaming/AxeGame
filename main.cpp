#include "raylib.h"

int main() {
    // window dimesnsions
    int width{800};
    int height{450};
    InitWindow(width, height, "Axe Game");

    // circle coordinates
    int circleX{200};
    int circleY{200};
    int circleRadius{25};
    // circle edges
    int l_circleX{circleX - circleRadius};
    int r_circleX{circleX + circleRadius};
    int u_circleY{circleY - circleRadius};
    int b_circleY{circleY + circleRadius};

    // axe coords
    int axeX{400};
    int axeY{0};
    int axeLength{50};
    // axe edges
    int l_axeX{axeX};
    int r_axeX{axeX + axeLength};
    int u_axeY{axeY};
    int b_axeY{axeY + axeLength};

    int direction{10};

    bool collision_with_axe{(b_axeY >= u_circleY) && (u_axeY <= b_circleY) && (l_axeX <= r_circleX) && (r_axeX >= l_circleX)};

    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);

        if (collision_with_axe) {
            DrawText("Game Over!", 400, 200, 20, RED);
        } else {
            // Game logic begins

            // update the edges
            l_circleX = circleX - circleRadius;
            r_circleX = circleX + circleRadius;
            u_circleY = circleY - circleRadius;
            b_circleY = circleY + circleRadius;

            l_axeX = axeX;
            r_axeX = axeX + axeLength;
            u_axeY = axeY;
            b_axeY = axeY + axeLength;

            // update collision with axe
            collision_with_axe = (b_axeY >= u_circleY) && (u_axeY <= b_circleY) && (l_axeX <= r_circleX) && (r_axeX >= l_circleX);

            DrawCircle(circleX, circleY, circleRadius, BLUE);
            DrawRectangle(axeX, axeY, axeLength, axeLength, RED);

            // move the axe
            axeY += direction;
            if (axeY > height || axeY < 0) {
                direction = -direction;
            }

            if (IsKeyDown(KEY_D) && circleX < width) {
                circleX += 10;
            }
            if (IsKeyDown(KEY_A) && circleX > 25) {
                circleX -= 10;
            }
            // Game logic ends
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
