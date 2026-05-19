#include "../include/ui.h"
#include "../include/logic.h"
#include "../include/storage.h"
#include "../include/constants.h"
#include "../include/raylib.h"
#include <string>
#include <cstring>

using namespace std;

// Draws a labelled text box; returns true when it is the active field
static void labeledBox(const char* label, char* buf, int maxLen,
                       int x, int y, int w, bool& active, int id, int& activeId) {
    DrawText(label, x, y - 18, 15, LIGHTGRAY);
    Color border = (activeId == id) ? Color{ 70, 130, 180, 255 } : Color{ 80, 80, 100, 255 };
    DrawRectangle(x, y, w, 32, Color{ 40, 40, 55, 255 });
    DrawRectangleLinesEx({(float)x, (float)y, (float)w, 32}, 1.5f, border);
    DrawText(buf, x + 6, y + 8, 16, WHITE);

    Rectangle r = {(float)x, (float)y, (float)w, 32};
    if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), r))
        activeId = id;

    if (activeId == id) {
        int key = GetCharPressed();
        while (key > 0) {
            int len = (int)strlen(buf);
            if (len < maxLen - 1) {
                buf[len]     = (char)key;
                buf[len + 1] = '\0';
            }
            key = GetCharPressed();
        }
        if (IsKeyPressed(KEY_BACKSPACE)) {
            int len = (int)strlen(buf);
            if (len > 0) buf[len - 1] = '\0';
        }
    }
    active = (activeId == id);
}

static bool button(const char* label, int x, int y, int w, int h, Color bg) {
    Rectangle r = {(float)x, (float)y, (float)w, (float)h};
    if (CheckCollisionPointRec(GetMousePosition(), r))
        bg = Color{ (unsigned char)(bg.r + 20),(unsigned char)(bg.g + 20),(unsigned char)(bg.b + 20),255 };
    DrawRectangleRec(r, bg);
    int tw = MeasureText(label, 16);
    DrawText(label, x + (w - tw) / 2, y + h / 2 - 8, 16, WHITE);
    return IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), r);
}

void drawAddForm(UiState& state, vector<Book>& books) {
    static int activeField = -1;
    int x = 180, y = 80, w = 400;

    DrawText("Add New Book", x, y, 22, WHITE);
    y += 40;

    bool dummy = false;
    labeledBox("Title",  state.title,     127, x, y,       w, dummy, 0, activeField); y += 60;
    labeledBox("Author", state.author,    127, x, y,       w, dummy, 1, activeField); y += 60;
    labeledBox("Genre",  state.genre,     127, x, y,       w, dummy, 2, activeField); y += 60;
    labeledBox("Year",   state.yearBuf,   7,   x, y,       w, dummy, 3, activeField); y += 60;

    if (button("Add Book", x, y, 160, 38, Color{ 50, 120, 80, 255 })) {
        Book b;
        b.id     = 0;
        b.title  = state.title;
        b.author = state.author;
        b.genre  = state.genre;
        b.year   = (strlen(state.yearBuf) > 0) ? stoi(state.yearBuf) : 0;

        if (addBook(books, b)) {
            saveBooks(DATA_FILE, books);
            state.statusMsg = "Book added successfully.";
            state.statusOk  = true;
            // Clear form
            memset(state.title,   0, sizeof(state.title));
            memset(state.author,  0, sizeof(state.author));
            memset(state.genre,   0, sizeof(state.genre));
            memset(state.yearBuf, 0, sizeof(state.yearBuf));
            activeField = -1;
        } else {
            state.statusMsg = "Error: invalid data or duplicate book.";
            state.statusOk  = false;
        }
    }
}
