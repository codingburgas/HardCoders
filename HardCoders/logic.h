#pragma once
#include "book.h"
#include <vector>
#include <string>

// Проверява дали полетата на книгата са валидни
bool validateBook(const Book& b);

// Проверява дали книга с такова заглавие и автор вече съществува
bool bookExists(const std::vector<Book>& books, const std::string& title, const std::string& author);

// Добавя книга – връща true при успех
bool addBook(std::vector<Book>& books, Book b);

// Търсене по автор (частично съвпадение)
std::vector<Book> searchByAuthor(const std::vector<Book>& books, const std::string& author);

// Търсене по жанр
std::vector<Book> searchByGenre(const std::vector<Book>& books, const std::string& genre);

// Сортиране по заглавие (bubble sort)
void sortByTitle(std::vector<Book>& books);

// Сортиране по година (bubble sort)
void sortByYear(std::vector<Book>& books);

// Рекурсивно сумиране на годините (демо за рекурсия)
int sumYears(const std::vector<Book>& books, int index);

// Изтрива книга по ID – връща true при успех
bool removeBook(std::vector<Book>& books, int id);
