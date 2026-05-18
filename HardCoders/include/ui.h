#pragma once
#include "ui_state.h"
#include "book.h"
#include <vector>

// Draws the sidebar navigation buttons; returns true if window should close
bool drawSidebar(UiState& state);

// Draws the main content area based on current screen
void drawContent(UiState& state, std::vector<Book>& books);

// Draws a table of books inside a scrollable area
void drawBookTable(const std::vector<Book>& books, int x, int y, int w, int h);

// Draws the add-book form and handles submit
void drawAddForm(UiState& state, std::vector<Book>& books);

// Draws the search form and results
void drawSearchPanel(UiState& state, const std::vector<Book>& books);

// Draws the sort controls
void drawSortPanel(UiState& state, std::vector<Book>& books);

// Draws the status bar at the bottom
void drawStatusBar(const UiState& state);