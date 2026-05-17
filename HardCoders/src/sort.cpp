#include "logic.h"

// Bubble sort по заглавие
void sortByTitle(std::vector<Book>& books) {
    int n = static_cast<int>(books.size());
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (books[j].title > books[j + 1].title) {
                Book tmp      = books[j];
                books[j]      = books[j + 1];
                books[j + 1]  = tmp;
            }
        }
    }
}

// Bubble sort по година
void sortByYear(std::vector<Book>& books) {
    int n = static_cast<int>(books.size());
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (books[j].year > books[j + 1].year) {
                Book tmp      = books[j];
                books[j]      = books[j + 1];
                books[j + 1]  = tmp;
            }
        }
    }
}

// Рекурсивно събиране на годините на всички книги
int sumYears(const std::vector<Book>& books, int index) {
    if (index >= static_cast<int>(books.size())) return 0;
    return books[index].year + sumYears(books, index + 1);
}
