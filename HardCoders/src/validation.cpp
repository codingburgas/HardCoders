#include "../include/logic.h"
#include "../include/constants.h"

using namespace std;

bool validateBook(const Book& b) {
    if (b.title.empty())  return false;
    if (b.author.empty()) return false;
    if (b.genre.empty())  return false;
    if (b.year < MIN_YEAR || b.year > MAX_YEAR) return false;
    return true;
}

bool bookExists(const vector<Book>& books, const string& title, const string& author) {
    for (const Book& b : books) {
        if (b.title == title && b.author == author) return true;
    }
    return false;
}
