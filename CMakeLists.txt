cmake_minimum_required(VERSION 3.14)
project(HardCoders CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(library
    src/main.cpp
    src/storage.cpp
    src/validation.cpp
    src/book_ops.cpp
    src/search.cpp
    src/sort.cpp
    src/utils.cpp
    src/ui_display.cpp
    src/ui_input.cpp
)
