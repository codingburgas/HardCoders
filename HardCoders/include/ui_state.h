#pragma once
#include "book.h"
#include <vector>
#include <string>

// Which screen is currently shown
enum class Screen {
    MAIN,
    ADD_BOOK,
    SEARCH,
    RESULTS,
    SORT_DONE
};

// All mutable UI state in one place
struct UiState {
    Screen            screen      = Screen::MAIN;

    // Input buffers for the add-book form
    char              title[128]  = {};
    char              author[128] = {};
    char              genre[128]  = {};
    char              yearBuf[8]  = {};

    // Search fields
    char              searchBuf[128] = {};
    bool              searchByAuthor = true;

    // Books currently shown in the results panel
    std::vector<Book> results;

    // Status message shown at the bottom
    std::string       statusMsg;
    bool              statusOk    = true;
};
