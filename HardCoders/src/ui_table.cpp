#include "../include/ui.h"
#include "raylib.h"
#include <string>

using namespace std;

// Column widths
static const int COL_ID     = 40;
static const int COL_TITLE  = 220;
static const int COL_AUTHOR = 160;
static const int COL_GENRE  = 120;
static const int COL_YEAR   = 60;

static void drawCell(const string& text, int x, int y, int w, Color fg) {
    // Clip text to column width
    string display = text;
    while (!display.empty() && MeasureText(display.c_str(), 15) > w - 8)
        display.pop_back();
    DrawText(display.c_str(), x + 4, y + 5, 15, fg);
}

void drawBookTable(const vector<Book>& books, int x, int y, int w, int h) {
    // Header row
    DrawRectangle(x, y, w, 28, Color{ 50, 80, 120, 255 });
    int cx = x + 4;
    DrawText("ID",     cx,             y + 7, 15, WHITE); cx += COL_ID;
    DrawText("Title",  cx,             y + 7, 15, WHITE); cx += COL_TITLE;
    DrawText("Author", cx,             y + 7, 15, WHITE); cx += COL_AUTHOR;
    DrawText("Genre",  cx,             y + 7, 15, WHITE); cx += COL_GENRE;
    DrawText("Year",   cx,             y + 7, 15, WHITE);

    if (books.empty()) {
        DrawText("No books found.", x + 10, y + 40, 16, GRAY);
        return;
    }

    int rowH = 26;
    int maxRows = (h - 28) / rowH;
    int shown   = (int)books.size() < maxRows ? (int)books.size() : maxRows;

    for (int i = 0; i < shown; i++) {
        const Book& b  = books[i];
        int ry         = y + 28 + i * rowH;
        Color rowBg = (i % 2 == 0) ? Color{ 38, 38, 50, 255 } : Color{ 44, 44, 58, 255 };
        DrawRectangle(x, ry, w, rowH, rowBg);

        cx = x + 4;
        drawCell(to_string(b.id),   cx, ry, COL_ID,     LIGHTGRAY); cx += COL_ID;
        drawCell(b.title,           cx, ry, COL_TITLE,  WHITE);     cx += COL_TITLE;
        drawCell(b.author,          cx, ry, COL_AUTHOR, LIGHTGRAY); cx += COL_AUTHOR;
        drawCell(b.genre,           cx, ry, COL_GENRE,  LIGHTGRAY); cx += COL_GENRE;
        drawCell(to_string(b.year), cx, ry, COL_YEAR,   LIGHTGRAY);
    }
}
