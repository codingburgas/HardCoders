#include "../include/ui.h"
#include "../include/constants.h"
#include "raylib.h"

using namespace std;

// Simple button helper — returns true when clicked
static bool sideBtn(const char* label, int y, bool active) {
    Rectangle r = { 0, (float)y, 160, 40 };
    Color bg = active ? Color{ 70, 130, 180, 255 } : Color{ 45, 45, 55, 255 };
    Color hover = active ? bg : Color{ 60, 60, 75, 255 };

    if (CheckCollisionPointRec(GetMousePosition(), r)) bg = hover;
    DrawRectangleRec(r, bg);
    DrawText(label, 14, y + 12, 16, WHITE);
    return IsMouseButtonReleased(MOUSE_LEFT_BUTTON) &&
           CheckCollisionPointRec(GetMousePosition(), r);
}

bool drawSidebar(UiState& state) {
    // Dark sidebar background
    DrawRectangle(0, 0, 160, WIN_H, Color{ 30, 30, 40, 255 });
    DrawText("HardCoders", 10, 14, 18, Color{ 70, 130, 180, 255 });
    DrawText("Library", 10, 34, 18, Color{ 70, 130, 180, 255 });
    DrawLine(0, 58, 160, 58, Color{ 60, 60, 80, 255 });

    if (sideBtn("All Books",   70,  state.screen == Screen::MAIN))        state.screen = Screen::MAIN;
    if (sideBtn("Add Book",    120, state.screen == Screen::ADD_BOOK))    state.screen = Screen::ADD_BOOK;
    if (sideBtn("Search",      170, state.screen == Screen::SEARCH))      state.screen = Screen::SEARCH;
    if (sideBtn("Sort",        220, state.screen == Screen::SORT_DONE))   state.screen = Screen::SORT_DONE;

    // Exit button at the bottom
    return sideBtn("Exit", WIN_H - 50, false);
}
