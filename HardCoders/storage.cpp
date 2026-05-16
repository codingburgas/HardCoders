#include "../include/storage.h"
#include <fstream>
#include <sstream>

std::vector<Book> loadBooks(const std::string& filename) {
    std::vector<Book> books;
    std::ifstream file(filename);
    if (!file.is_open()) {
        return books;
    }

    std::string line;
    while (std::getline(file, line)) {
        if (line.empty()) continue;

        // Редовете са разделени с '|'
        std::istringstream ss(line);
        std::string part;
        Book b;
        b.id   = 0;
        b.year = 0;

        std::getline(ss, part, '|'); b.id     = std::stoi(part);
        std::getline(ss, part, '|'); b.title  = part;
        std::getline(ss, part, '|'); b.author = part;
        std::getline(ss, part, '|'); b.genre  = part;
        std::getline(ss, part, '|'); b.year   = std::stoi(part);

        books.push_back(b);
    }
    return books;
}

bool saveBooks(const std::string& filename, const std::vector<Book>& books) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    for (const Book& b : books) {
        file << b.id     << '|'
             << b.title  << '|'
             << b.author << '|'
             << b.genre  << '|'
             << b.year   << '\n';
    }
    return true;
}

int nextId(const std::vector<Book>& books) {
    int maxId = 0;
    for (const Book& b : books) {
        if (b.id > maxId) maxId = b.id;
    }
    return maxId + 1;
}
