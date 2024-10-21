#include <raylib.h>
#include <rcamera.h>

#include "gfx/window.hpp"
#include "core/game.hpp"


int main() {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "minesPlusPlus");
    //SetTargetFPS(120);

    Level newLevel(10, 10, 10);

    while(!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(WHITE);
        
        EndDrawing();
    }

    CloseWindow();
}
