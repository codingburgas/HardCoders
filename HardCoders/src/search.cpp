#include "../include/logic.h"
#include "../include/utils.h"

using namespace std;

vector<Book> searchByAuthor(const vector<Book>& books, const string& query) {
    vector<Book> result;
    for (const Book& b : books) {
        if (containsIgnoreCase(b.author, query))
            result.push_back(b);
    }
    return result;
}

vector<Book> searchByGenre(const vector<Book>& books, const string& query) {
    vector<Book> result;
    for (const Book& b : books) {
        if (containsIgnoreCase(b.genre, query))
            result.push_back(b);
    }
    return result;
}
