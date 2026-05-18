#include "../include/ui.h"
#include "../include/logic.h"
#include "../include/storage.h"
#include "../include/constants.h"
#include "raylib.h"

using namespace std;

static bool button(const char* label, int x, int y, int w, int h, Color bg) {
    Rectangle r = {(float)x, (float)y, (float)w, (float)h};
    if (CheckCollisionPointRec(GetMousePosition(), r))
        bg = Color{ (unsigned char)(bg.r + 20),(unsigned char)(bg.g + 20),(unsigned char)(bg.b + 20),255 };
    DrawRectangleRec(r, bg);
    int tw = MeasureText(label, 16);
    DrawText(label, x + (w - tw) / 2, y + h / 2 - 8, 16, WHITE);
    return IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), r);
}

void drawSortPanel(UiState& state, vector<Book>& books) {
    int x = 180, y = 80;

    DrawText("Sort & Stats", x, y, 22, WHITE);
    y += 50;

    if (button("Sort by Title", x, y, 160, 40, Color{ 60, 100, 150, 255 })) {
        sortByTitle(books);
        saveBooks(DATA_FILE, books);
        state.statusMsg = "Sorted by title.";
        state.statusOk  = true;
    }
    if (button("Sort by Year", x + 180, y, 160, 40, Color{ 60, 100, 150, 255 })) {
        sortByYear(books);
        saveBooks(DATA_FILE, books);
        state.statusMsg = "Sorted by year.";
        state.statusOk  = true;
    }
    y += 70;

    // Recursion demo: sum of years
    int total = sumYears(books, 0);
    string info = "Sum of all years (recursive): " + to_string(total);
    DrawText(info.c_str(), x, y, 17, Color{ 150, 200, 150, 255 });
    y += 40;

    // Show sorted list
    drawBookTable(books, x, y, WIN_W - x - 10, WIN_H - y - 50);
}
