#pragma once
#include "book.h"
#include <vector>
#include <string>

std::vector<Book> loadBooks(const std::string& filename);
bool              saveBooks(const std::string& filename, const std::vector<Book>& books);
int               nextId(const std::vector<Book>& books);
