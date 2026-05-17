# HardCoders – Система за управление на библиотека

Конзолна програма на C++17 за управление на книги в училищна библиотека.

## Функционалности
- Добавяне на книга (с валидация и проверка за дублиране)
- Преглед на всички книги
- Търсене по автор и жанр
- Сортиране по заглавие и година (bubble sort)
- Изтриване на книга по ID
- Рекурсивно сумиране на годините (демо рекурсия)
- Запазване на данните в `data/books.txt`

## Структура на проекта

```
HardCoders/
├── include/
│   ├── book.h        ← структура Book
│   ├── storage.h     ← четене/запис от файл
│   ├── logic.h       ← бизнес логика
│   └── ui.h          ← потребителски интерфейс
├── src/
│   ├── main.cpp      ← входна точка
│   ├── storage.cpp
│   ├── validation.cpp
│   ├── book_ops.cpp
│   ├── search.cpp
│   ├── sort.cpp
│   ├── ui_display.cpp
│   └── ui_input.cpp
├── data/
│   └── books.txt     ← файл с данни
├── docs/
│   └── architecture.md
├── CMakeLists.txt
└── README.md
```

## Компилация

### С CMake
```bash
mkdir build && cd build
cmake ..
cmake --build .
./library
```

### Директно с g++
```bash
g++ -std=c++17 -Iinclude src/*.cpp -o library
./library
```

## Архитектура

Проектът използва **трислойна архитектура**:

| Слой | Файлове | Отговорност |
|------|---------|-------------|
| Data | `book.h`, `storage.h/.cpp` | Структурата Book + четене/запис от файл |
| Logic | `logic.h`, `validation.cpp`, `book_ops.cpp`, `search.cpp`, `sort.cpp` | Валидация, търсене, сортиране |
| UI | `ui.h`, `ui_display.cpp`, `ui_input.cpp` | Менюта, вход/изход |

Потокът е: **UI → Logic → Data**. UI не докосва файловете директно.

## Екип
- **HardCoders** – 9. клас
