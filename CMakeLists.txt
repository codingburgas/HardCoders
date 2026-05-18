cmake_minimum_required(VERSION 3.14)
project(HardCoders CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Download raylib automatically
include(FetchContent)
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG        5.0
)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(raylib)

include_directories(include)

add_executable(library
    src/main.cpp
    src/storage.cpp
    src/utils.cpp
    src/validation.cpp
    src/book_ops.cpp
    src/search.cpp
    src/sort.cpp
    src/ui_sidebar.cpp
    src/ui_table.cpp
    src/ui_form.cpp
    src/ui_search.cpp
    src/ui_sort.cpp
    src/ui_content.cpp
)

target_link_libraries(library PRIVATE raylib)

# Copy data folder next to the executable after build
add_custom_command(TARGET library POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/data $<TARGET_FILE_DIR:library>/data
)
