#include "../include/ui.h"
#include "../include/logic.h"
#include "../include/storage.h"
#include <vector>
#include <iostream>

// File to store book data
static const std::string DATA_FILE = "../Data/books.txt";

int main() {
	// Load books from file
    std::vector<Book> books = loadBooks(DATA_FILE);

    bool running = true;
    while (running) {
        int choice = showMainMenu();

        switch (choice) {
        case 1:
            printBooks(books);
            waitEnter();
            break;

        case 2: {
            Book b = promptBook();
            if (addBook(books, b)) {
                saveBooks(DATA_FILE, books);
                printSuccess("Книгата е добавена.");
            } else {
                printError("Невалидни данни или книгата вече съществува.");
            }
            waitEnter();
            break;
        }

        case 3: {
            std::string query    = promptString("Въведи автор");
            std::vector<Book> res = searchByAuthor(books, query);
            printBooks(res);
            waitEnter();
            break;
        }

        case 4: {
            std::string query    = promptString("Въведи жанр");
            std::vector<Book> res = searchByGenre(books, query);
            printBooks(res);
            waitEnter();
            break;
        }

        case 5:
            sortByTitle(books);
            saveBooks(DATA_FILE, books);
            printSuccess("Сортирано по заглавие.");
            printBooks(books);
            waitEnter();
            break;

        case 6:
            sortByYear(books);
            saveBooks(DATA_FILE, books);
            printSuccess("Сортирано по година.");
            printBooks(books);
            waitEnter();
            break;

        case 7: {
            int id = promptInt("ID на книгата за изтриване");
            if (removeBook(books, id)) {
                saveBooks(DATA_FILE, books);
                printSuccess("Книгата е изтрита.");
            } else {
                printError("Книга с това ID не е намерена.");
            }
            waitEnter();
            break;
        }

        case 8: {
            int total = sumYears(books, 0);
            std::cout << "Сумата на годините (рекурсивно): " << total << "\n";
            waitEnter();
            break;
        }

        case 0:
            running = false;
            break;

        default:
            printError("Невалиден избор.");
            waitEnter();
            break;
        }
    }

    std::cout << "Довиждане!\n";
    return 0;
}
