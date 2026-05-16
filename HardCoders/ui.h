#pragma once
#include "book.h"
#include <vector>
#include <string>

// Показва главното меню и връща избора
int showMainMenu();

// Пита потребителя за данни и връща попълнена книга
Book promptBook();

// Показва списък с книги
void printBooks(const std::vector<Book>& books);

// Пита за низ (за търсене)
std::string promptString(const std::string& label);

// Пита за число
int promptInt(const std::string& label);

// Показва съобщение за грешка
void printError(const std::string& msg);

// Показва съобщение за успех
void printSuccess(const std::string& msg);

// Изчаква Enter от потребителя
void waitEnter();
