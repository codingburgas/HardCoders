#include "../include/logic.h"
#include "../include/storage.h"

using namespace std;

bool addBook(vector<Book>& books, Book b) {
    if (!validateBook(b)) return false;
    if (bookExists(books, b.title, b.author)) return false;
    b.id = nextId(books);
    books.push_back(b);
    return true;
}

bool removeBook(vector<Book>& books, int id) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->id == id) {
            books.erase(it);
            return true;
        }
    }
    return false;
}
