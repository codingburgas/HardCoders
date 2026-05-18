#include "../include/ui.h"
#include "../include/logic.h"
#include "../include/storage.h"
#include "../include/constants.h"
#include "raylib.h"

using namespace std;

int main() {
    InitWindow(WIN_W, WIN_H, "HardCoders Library");
    SetTargetFPS(FPS);

    vector<Book> books = loadBooks(DATA_FILE);
    UiState state;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(Color{ 25, 25, 35, 255 });

        bool exitClicked = drawSidebar(state);
        drawContent(state, books);

        EndDrawing();

        if (exitClicked) break;
    }

    CloseWindow();
    return 0;
}
