#include "logic.h"
#include "utils.h"

std::vector<Book> searchByAuthor(const std::vector<Book>& books, const std::string& author) {
    std::vector<Book> result;
    for (const Book& b : books) {
        if (containsIgnoreCase(b.author, author)) {
            result.push_back(b);
        }
    }
    return result;
}

std::vector<Book> searchByGenre(const std::vector<Book>& books, const std::string& genre) {
    std::vector<Book> result;
    for (const Book& b : books) {
        if (containsIgnoreCase(b.genre, genre)) {
            result.push_back(b);
        }
    }
    return result;
}
