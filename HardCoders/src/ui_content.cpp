#include "../include/ui.h"
#include "raylib.h"
#include "../include/constants.h"

using namespace std;

void drawContent(UiState& state, vector<Book>& books) {
    // Content background
    DrawRectangle(160, 0, WIN_W - 160, WIN_H, Color{ 32, 32, 44, 255 });

    switch (state.screen) {
    case Screen::MAIN:
        DrawText("All Books", 180, 80, 22, WHITE);
        drawBookTable(books, 180, 115, WIN_W - 190, WIN_H - 165);
        break;

    case Screen::ADD_BOOK:
        drawAddForm(state, books);
        break;

    case Screen::SEARCH:
        drawSearchPanel(state, books);
        break;

    case Screen::SORT_DONE:
        drawSortPanel(state, books);
        break;

    default:
        break;
    }

    drawStatusBar(state);
}

void drawStatusBar(const UiState& state) {
    if (state.statusMsg.empty()) return;
    Color bg = state.statusOk ? Color{ 40, 90, 50, 230 } : Color{ 100, 35, 35, 230 };
    DrawRectangle(160, WIN_H - 36, WIN_W - 160, 36, bg);
    DrawText(state.statusMsg.c_str(), 172, WIN_H - 26, 15, WHITE);
}
