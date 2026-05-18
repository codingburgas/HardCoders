#include "../include/ui.h"
#include "../include/logic.h"
#include "../include/constants.h"
#include "raylib.h"
#include <cstring>

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

void drawSearchPanel(UiState& state, const vector<Book>& books) {
    static int activeField = 0;
    int x = 180, y = 80, w = 400;

    DrawText("Search Books", x, y, 22, WHITE);
    y += 40;

    // Toggle: author / genre
    Color cA = state.searchByAuthor ? Color{ 70,130,180,255 } : Color{ 55,55,70,255 };
    Color cG = state.searchByAuthor ? Color{ 55,55,70,255 } : Color{ 70,130,180,255 };
    if (button("By Author", x,       y, 120, 34, cA)) state.searchByAuthor = true;
    if (button("By Genre",  x + 130, y, 120, 34, cG)) state.searchByAuthor = false;
    y += 50;

    // Search input
    DrawText("Query", x, y - 18, 15, LIGHTGRAY);
    Color border = Color{ 70, 130, 180, 255 };
    DrawRectangle(x, y, w, 32, Color{ 40, 40, 55, 255 });
    DrawRectangleLinesEx({(float)x,(float)y,(float)w,32}, 1.5f, border);
    DrawText(state.searchBuf, x + 6, y + 8, 16, WHITE);

    // Handle typing in search box
    int key = GetCharPressed();
    while (key > 0) {
        int len = (int)strlen(state.searchBuf);
        if (len < 127) {
            state.searchBuf[len]     = (char)key;
            state.searchBuf[len + 1] = '\0';
        }
        key = GetCharPressed();
    }
    if (IsKeyPressed(KEY_BACKSPACE)) {
        int len = (int)strlen(state.searchBuf);
        if (len > 0) state.searchBuf[len - 1] = '\0';
    }
    y += 50;

    if (button("Search", x, y, 120, 36, Color{ 50,100,160,255 })) {
        string q = state.searchBuf;
        state.results = state.searchByAuthor
            ? searchByAuthor(books, q)
            : searchByGenre(books, q);
        state.statusMsg = "Search complete.";
        state.statusOk  = true;
    }
    y += 60;

    // Show results in a table
    drawBookTable(state.results, x, y, WIN_W - x - 10, WIN_H - y - 50);
}
