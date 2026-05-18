#include "../include/storage.h"
#include <fstream>
#include <sstream>

using namespace std;

vector<Book> loadBooks(const string& filename) {
    vector<Book> books;
    ifstream file(filename);
    if (!file.is_open()) return books;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        istringstream ss(line);
        string part;
        Book b;
        b.id   = 0;
        b.year = 0;

        getline(ss, part, '|'); b.id     = stoi(part);
        getline(ss, part, '|'); b.title  = part;
        getline(ss, part, '|'); b.author = part;
        getline(ss, part, '|'); b.genre  = part;
        getline(ss, part, '|'); b.year   = stoi(part);

        books.push_back(b);
    }
    return books;
}

bool saveBooks(const string& filename, const vector<Book>& books) {
    ofstream file(filename);
    if (!file.is_open()) return false;

    for (const Book& b : books) {
        file << b.id     << '|'
             << b.title  << '|'
             << b.author << '|'
             << b.genre  << '|'
             << b.year   << '\n';
    }
    return true;
}

int nextId(const vector<Book>& books) {
    int maxId = 0;
    for (const Book& b : books) {
        if (b.id > maxId) maxId = b.id;
    }
    return maxId + 1;
}
