#pragma once
#include "book.h"
#include <vector>
#include <string>

// Зарежда книгите от файл
std::vector<Book> loadBooks(const std::string& filename);

// Записва книгите във файл
bool saveBooks(const std::string& filename, const std::vector<Book>& books);

// Дава следващото свободно ID
int nextId(const std::vector<Book>& books);
