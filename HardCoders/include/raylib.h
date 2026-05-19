#pragma once

// Minimal fake raylib header to allow building/running the project without
// installing raylib. This provides lightweight stubs for the handful of
// functions/types used by the UI so the program can compile and run in a
// console-only fallback mode.

#include <cstdio>
#include <cstring>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Color { unsigned char r, g, b, a; } Color;
typedef struct Vector2 { float x, y; } Vector2;
typedef struct Rectangle { float x, y, width, height; } Rectangle;

// Common colors
static const Color WHITE     = {255,255,255,255};
static const Color GRAY      = {180,180,180,255};
static const Color LIGHTGRAY = {200,200,200,255};

// Mouse button
#define MOUSE_LEFT_BUTTON 0

// Keyboard keys
#define KEY_BACKSPACE 259

// Window management (stubs)
static inline void InitWindow(int width, int height, const char* title) {
    std::printf("[raylib stub] InitWindow %dx%d '%s'\n", width, height, title);
}
static inline void SetTargetFPS(int fps) {
    (void)fps;
}
static inline void CloseWindow(void) {
    std::printf("[raylib stub] CloseWindow\n");
}

// Simple frame loop control: run a few frames then exit. This keeps the app
// from hanging if there's no graphical backend. Adjust MAX_FRAMES if needed.
static inline int WindowShouldClose(void) {
    static int frames = 0;
    const int MAX_FRAMES = 60; // run ~1 second at 60FPS
    return (++frames >= MAX_FRAMES);
}

// Drawing stubs
static inline void BeginDrawing(void) { }
static inline void EndDrawing(void) { }
static inline void ClearBackground(Color c) { (void)c; }
static inline void DrawRectangle(int x, int y, int w, int h, Color c) { (void)x; (void)y; (void)w; (void)h; (void)c; }
static inline void DrawRectangleRec(Rectangle rec, Color c) { (void)rec; (void)c; }
static inline void DrawRectangleLinesEx(Rectangle rec, float lineThick, Color c) { (void)rec; (void)lineThick; (void)c; }
static inline void DrawLine(int x1, int y1, int x2, int y2, Color c) { (void)x1; (void)y1; (void)x2; (void)y2; (void)c; }
static inline void DrawText(const char* text, int posX, int posY, int fontSize, Color c) {
    // Minimal console-friendly output for visibility
    (void)posX; (void)posY; (void)fontSize; (void)c;
    std::printf("%s\n", text);
}

// Input / utils
static inline int MeasureText(const char* text, int fontSize) {
    if (!text) return 0;
    return (int)std::strlen(text) * (fontSize / 2);
}
static inline Vector2 GetMousePosition(void) { return Vector2{0,0}; }
static inline int CheckCollisionPointRec(Vector2 pt, Rectangle rec) { (void)pt; (void)rec; return 0; }
static inline int IsMouseButtonReleased(int btn) { (void)btn; return 0; }
static inline int IsMouseButtonPressed(int btn) { (void)btn; return 0; }
static inline int IsKeyPressed(int key) { (void)key; return 0; }
static inline int GetCharPressed(void) { return 0; }
static inline int GetKeyPressed(void) { return 0; }

#ifdef __cplusplus
}
#endif
