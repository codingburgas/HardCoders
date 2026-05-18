#pragma once
#include "book.h"
#include <vector>
#include <string>

bool              validateBook(const Book& b);
bool              bookExists(const std::vector<Book>& books, const std::string& title, const std::string& author);
bool              addBook(std::vector<Book>& books, Book b);
bool              removeBook(std::vector<Book>& books, int id);
std::vector<Book> searchByAuthor(const std::vector<Book>& books, const std::string& query);
std::vector<Book> searchByGenre(const std::vector<Book>& books, const std::string& query);
void              sortByTitle(std::vector<Book>& books);
void              sortByYear(std::vector<Book>& books);
int               sumYears(const std::vector<Book>& books, int index);
